#include <QCoreApplication>
#include <QCommandLineParser>
#include <QFile>
#include <QTextStream>

enum class Direction {
    Decrypt,
    Encrypt
};

void printVigenereTable(QString fileName, QString alphabet)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream consoleStream(stdout);
        consoleStream.setCodec("cp-1251");
        consoleStream << QString::fromUtf8(file.errorString().toUtf8());
    }

    alphabet = alphabet.toLower();

    QTextStream out(&file);
    out.setCodec("UTF-8");

    for(int i = 0; i < alphabet.length(); i++)
    {
        for(int j = 0; j < alphabet.length(); j++)
        {
            out << alphabet.at((i + j) % alphabet.length()) << " ";
        }
        out << "\r\n";
    }

    file.close();
}

QChar shift(QChar &ch, int 	distance, Direction d, QString &alphabet)
{
    int pos = alphabet.indexOf(ch.toLower());
    pos = d == Direction::Encrypt ? (pos + distance) % alphabet.length()
                                  : (pos - distance + alphabet.length()) % alphabet.length();
    return ch.isUpper() ? alphabet.at(pos).toUpper()
                        : alphabet.at(pos).toLower();
}

QString process(QString source, QString key, QString alphabet, Direction dir)
{
    if(source.isEmpty() || alphabet.isEmpty() || key.isEmpty())
        return "";

    alphabet = alphabet.toLower();
    QString keyString = key.repeated(static_cast<int>(ceil(source.length() / key.length())) + 1);
    if(keyString.length() > source.length())
        keyString.truncate(source.length());

    QString result;
    for (int i = 0; i < source.length(); i++)
    {
        QChar ch = source.at(i);
        if(!alphabet.contains(ch.toLower()))
        {
            result.append(ch);
        }
        else
        {
            int d = alphabet.indexOf(keyString.at(i));
            result.append(shift(ch,d,dir,alphabet));
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("Simple encryption");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;

    parser.setApplicationDescription("Simple encryption helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source",  QCoreApplication::translate("main", "Source data."));

    QCommandLineOption decryption({{"d", "decryption"},
                                   QCoreApplication::translate("main", "Decrypting the encrypted <source> text by key <key>")});
    QCommandLineOption caesar({{"C", "caesar"},
                               QCoreApplication::translate("main", "Specify encription cipher to Caesar with int key <key>."),
                               QCoreApplication::translate("main", "key")});
    QCommandLineOption vigenere({{"V", "vigenere"},
                                 QCoreApplication::translate("main", "Specify encription cipher to Vigenere with string key <key>."),
                                 QCoreApplication::translate("main", "key")});
    QCommandLineOption vigenereTable({{"t", "table"},
                                      QCoreApplication::translate("main", "Form Vigenere table and out to <file>"),
                                      QCoreApplication::translate("main", "file")});
    QCommandLineOption alphabet({{"a", "alphabet"},
                                 QCoreApplication::translate("main", "Specify crypto alphabet in lower case. Default English alphabet."),
                                 QCoreApplication::translate("main", "alphabet")});
    alphabet.setDefaultValue("abcdefghijklmnopqrstuvwxyz");
    QCommandLineOption out({{"o", "out-file"},
                            QCoreApplication::translate("main", "Specify output file name[path]. Default used console output."),
                            QCoreApplication::translate("main", "name")});
    QCommandLineOption file({{"f", "file"},
                             QCoreApplication::translate("main", "Specify <source> as file name[path]")});

    parser.addOption(decryption);
    parser.addOption(file);
    parser.addOption(caesar);
    parser.addOption(vigenere);
    parser.addOption(alphabet);
    parser.addOption(vigenereTable);
    parser.addOption(out);

    parser.process(a);

    const QStringList args = parser.positionalArguments();
    if((!parser.isSet(caesar) || !parser.isSet(vigenere)) && args.isEmpty()) {
        parser.showHelp(1);
    }

    QString source = QString::fromUtf8(args.at(0).toUtf8());
    QString alph = QString::fromUtf8(parser.value(alphabet).toUtf8());

    if(parser.isSet(file))
    {
        QFile file(source);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return file.error();
        source = file.readAll();
        file.close();
    }

    QString key;
    if(parser.isSet(caesar))
    {
        key = parser.value(caesar);
        bool ok = false;
        int p = key.toInt(&ok);
        if(ok && p < alph.length())
            key = alph.at(p);
    }
    else if(parser.isSet(vigenere))
    {
        key = parser.value(vigenere);
    }

    QString result = process(source, key, alph,parser.isSet(decryption) ? Direction::Decrypt
                                                                        : Direction::Encrypt);
    if(parser.isSet(out))
    {
        QFile file(parser.value(out));
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream consoleStream(stdout);
            consoleStream.setCodec("cp-1251");
            consoleStream << QString::fromUtf8(file.errorString().toUtf8());
            return file.error();
        }

        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << result;
        file.close();
    }
    else
    {
        QTextStream consoleStream(stdout);
        consoleStream.setCodec("cp-1251");
        consoleStream << QString::fromUtf8(result.toUtf8());
    }

    if(parser.isSet(vigenereTable))
    {
        printVigenereTable(parser.value(vigenereTable), alph);
    }

    return 0;
}

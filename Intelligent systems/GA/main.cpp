#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <gproxima.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    GProxima GA;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("GProxima", &GA);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#ifndef GPROXIMA_H
#define GPROXIMA_H

#include <QObject>
#include <QPointF>

#include <functional>
#include <QRandomGenerator>

#include <QVariant>

struct Individ
{
    Individ() {}
    Individ(qreal x, qreal y)
    {
        genes.setX(x);
        genes.setY(y);
    }

    QPointF genes;
    qreal fitness;
    //double likelihood;
};

class Population
{
public:
    Population() {}
    void generate(int size, double min, double max);

    void updateFitness(QList<QPointF> &points);

    double getFitness(QList<QPointF> &points, Individ &individ);

    double getFunction(QPointF &p, Individ &i);

    void selection(QList<QPointF> &points);

    void crossing(double likekihood);

    void mutation(double likelihood, double bottom, double top);

    QList<Individ> individuals;

private:
    QList<Individ> arithmeticCrossing(Individ first, Individ second);

    double mutate(double allele, double likelihood, double bottom, double top);

};

class GProxima : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int population READ population WRITE setPopulation NOTIFY populationChanged)
    Q_PROPERTY(int generation READ generation WRITE setGeneration NOTIFY generationChanged)

    Q_PROPERTY(double krossengoverLikelihood READ krossengoverLikelihood WRITE setKrossengoverLikelihood NOTIFY krossengoverLikelihoodChanged)
    Q_PROPERTY(double mutationLilelihood READ mutationLilelihood WRITE setMutationLilelihood NOTIFY mutationLilelihoodChanged)
    Q_PROPERTY(double bottomBorder READ bottomBorder WRITE setBottomBorder NOTIFY bottomBorderChanged)
    Q_PROPERTY(double topBorder READ topBorder WRITE setTopBorder NOTIFY topBorderChanged)

    Q_PROPERTY(QPointF answer READ answer WRITE setAnswer NOTIFY answerChanged)

    Q_PROPERTY(QVariantList points READ points /*WRITE setPoints*/ NOTIFY pointsChanged)


public:
    explicit GProxima(QObject *parent = nullptr);

    double krossengoverLikelihood() const;

    double mutationLilelihood() const;

    double bottomBorder() const;

    double topBorder() const;

    int population() const;

    int generation() const;

    QVariantList points();

    QPointF answer() const;

signals:
    void krossengoverLikelihoodChanged(double krossengoverLikelihood);

    void mutationLilelihoodChanged(double mutationLilelihood);

    void bottomBorderChanged(double bottomBorder);

    void topBorderChanged(double topBorder);

    void populationChanged(int population);

    void generationChanged(int generation);

    void pointsChanged();

    void answerChanged(QPointF answer);

public slots:
    void setKrossengoverLikelihood(double krossengoverLikelihood);

    void setMutationLilelihood(double mutationLilelihood);

    void setBottomBorder(double bottomBorder);

    void setTopBorder(double topBorder);

    void setPopulation(int population);

    void setGeneration(int generation);

    void appendToResults(Individ ind);

    void loadPoints();

    void solve();

    void addPoint(double x, double y);

    void clear();

    void setAnswer(QPointF answer);

    void fillRandPoints();

private:
    double getFitness(QList<QPointF> &points, Individ &individ);
    double getFunction(QPointF &p, Individ &i);

private:
    QList<QPointF> m_points;
    QList<QPointF> m_results;
    double m_krossengoverLikelihood;
    double m_mutationLilelihood;
    double m_bottomBorder;
    double m_topBorder;
    int m_population;
    int m_generation;
    QPointF m_answer;
};

#endif // GPROXIMA_H

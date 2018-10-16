#include "gproxima.h"

#include <QDebug>

GProxima::GProxima(QObject *parent)
    : QObject(parent)
    , m_krossengoverLikelihood(0.6)
    , m_mutationLilelihood(0.5)
    , m_bottomBorder(0.0)
    , m_topBorder(25.0)
    , m_population(100)
    , m_generation(10)
{

}

double GProxima::krossengoverLikelihood() const
{
    return m_krossengoverLikelihood;
}

double GProxima::mutationLilelihood() const
{
    return m_mutationLilelihood;
}

double GProxima::bottomBorder() const
{
    return m_bottomBorder;
}

double GProxima::topBorder() const
{
    return m_topBorder;
}

int GProxima::population() const
{
    return m_population;
}

int GProxima::generation() const
{
    return m_generation;
}

QVariantList GProxima::points()
{
    QVariantList l;
    std::for_each(m_points.begin(), m_points.end(), [&l](QPointF &p){
        l.append(QVariant(p));
    });
    return l;
}

QPointF GProxima::answer() const
{
    return m_answer;
}

void GProxima::setKrossengoverLikelihood(double krossengoverLikelihood)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_krossengoverLikelihood, krossengoverLikelihood))
        return;

    m_krossengoverLikelihood = krossengoverLikelihood;
    emit krossengoverLikelihoodChanged(m_krossengoverLikelihood);
}

void GProxima::setMutationLilelihood(double mutationLilelihood)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_mutationLilelihood, mutationLilelihood))
        return;

    m_mutationLilelihood = mutationLilelihood;
    emit mutationLilelihoodChanged(m_mutationLilelihood);
}

void GProxima::setBottomBorder(double bottomBorder)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_bottomBorder, bottomBorder))
        return;

    m_bottomBorder = bottomBorder;
    emit bottomBorderChanged(m_bottomBorder);
}

void GProxima::setTopBorder(double topBorder)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_topBorder, topBorder))
        return;

    m_topBorder = topBorder;
    emit topBorderChanged(m_topBorder);
}

void GProxima::setPopulation(int population)
{
    if (m_population == population)
        return;

    m_population = population;
    emit populationChanged(m_population);
}

void GProxima::setGeneration(int generation)
{
    if (m_generation == generation)
        return;

    m_generation = generation;
    emit generationChanged(m_generation);
}

void GProxima::appendToResults(Individ ind)
{
    m_results.append(ind.genes);
    qDebug() << "Results" << m_results;
}

void GProxima::loadPoints()
{
    m_points.clear();
    m_points.append({1,10});
    m_points.append({2,12});
    m_points.append({3,14});
    m_points.append({4,9});
    m_points.append({5,4});
    m_points.append({6,6});
    m_points.append({7,16});
    m_points.append({8,18});
    m_points.append({9,19});
    m_points.append({10,20});
}

void Population::generate(int size, double min, double max)
{
    for(int i = 0; i < size; i++)
    {
        individuals.append(Individ(QRandomGenerator::system()->bounded(max - min) + min,
                                   QRandomGenerator::system()->bounded(max - min) + min ));
    }
}

void Population::updateFitness(QList<QPointF> &points)
{
    std::for_each(individuals.begin(), individuals.end(), [this,&points](Individ &ind){
        ind.fitness = getFitness(points, ind);
    });
}

double Population::getFitness(QList<QPointF> &points, Individ &individ)
{
    double sum = 0.0;

    std::for_each(points.begin(), points.end(),[this, &sum, &individ](QPointF &p){
        sum += pow(getFunction(p,individ),2);
    });

    return sum;
}

double Population::getFunction(QPointF &p, Individ &i)
{
    return p.y() - i.genes.x() * p.x() - i.genes.y(); // y - a*x - b
}

void Population::selection(QList<QPointF> &points)
{
    QList<Individ> selected;
    for(int i = 0; i < individuals.size(); i++)
    {
        int next = i >= individuals.size() - 1 ? 0 : i + 1;
        if(getFitness(points,individuals[i]) < getFitness(points,individuals[next]))
            selected.push_back(individuals[i]);
        else
            selected.push_back(individuals[next]);
    }
    individuals = selected;
}

void Population::crossing(double likekihood)
{
    QList<Individ> nextGeneration;
    int size = individuals.size();

    while (nextGeneration.size() != size)
    {
        int father = QRandomGenerator::system()->bounded(size - 1);
        int mother = QRandomGenerator::system()->bounded(size - 1);

        double crossingLikelihood = QRandomGenerator::system()->generateDouble();

        if(crossingLikelihood < likekihood)
        {
            auto childs = arithmeticCrossing(individuals.at(father),
                                             individuals.at(mother));

            std::for_each(childs.begin(), childs.end(), [this, &nextGeneration](Individ &ind){
                nextGeneration.push_back(ind);
            });
            //std::copy(childs.begin(), childs.end(),)
        }
        else
        {
            nextGeneration.push_back(individuals.at(father));
            nextGeneration.push_back(individuals.at(mother));
        }
    }

    individuals = nextGeneration;
}

void Population::mutation(double likelihood, double bottom, double top)
{
    std::for_each(individuals.begin(), individuals.end(), [this,&likelihood, &bottom, &top](Individ &ind){
        ind.genes.setX(mutate(ind.genes.x(),likelihood,bottom,top));
        ind.genes.setY(mutate(ind.genes.y(),likelihood,bottom,top));
    });
}

//h1 = a*g1 + (1-a)*g2;
//h2 = a*g2 + (1-a)*g1;
QList<Individ> Population::arithmeticCrossing(Individ first, Individ second)
{
    QList<Individ> result;
    int genN = QRandomGenerator::system()->bounded(2);
    double a = QRandomGenerator::system()->generateDouble();

    if(genN == 0)
    {
        result.append(Individ(a * first.genes.x() + (1 - a) * second.genes.x(), first.genes.y()));
        result.append(Individ(a * second.genes.x() + (1 - a) * first.genes.x(), second.genes.y()));
    }
    else
    {
        result.append(Individ(first.genes.y(), a * first.genes.x() + (1 - a) * second.genes.x()));
        result.append(Individ(second.genes.y(), a * second.genes.x() + (1 - a) * first.genes.x()));
    }

    return result;
}

double Population::mutate(double allele, double likelihood, double bottom, double top)
{
    double result = allele;
    double mutationLikelihood = QRandomGenerator::system()->generateDouble();
    if(mutationLikelihood > likelihood)
    {
        double s_min = std::max(-1.0, bottom - allele);
        double s_max = std::min(1.0, top - allele);
        double sigma = QRandomGenerator::system()->bounded(s_max - s_min) + s_min;
        result += sigma;
    }
    return result;
}

void GProxima::solve()
{
    Population population;
    population.generate(m_population, m_bottomBorder, m_topBorder);

    population.updateFitness(m_points);

    Individ best;
    best.fitness = std::numeric_limits<double>::max();

    int g = 0;
    while (g < m_generation) {
        //qDebug() << g << best.fitness << best.genes;
        for(auto it = population.individuals.begin(); it != population.individuals.end(); ++it)
        {
            if(it->fitness < best.fitness)
            {
                best.genes = it->genes;
                best.fitness = it->fitness;
            }
        }

        population.selection(m_points);
        population.crossing(m_krossengoverLikelihood);
        population.mutation(m_mutationLilelihood, m_bottomBorder, m_topBorder);
        population.updateFitness(m_points);
        g++;
    }

    appendToResults(best);

    setAnswer(best.genes);

}

void GProxima::addPoint(double x, double y)
{
    qDebug() << __FUNCTION__ << x << y;
    m_points.append(QPointF(x,y));
    emit pointsChanged();
}

void GProxima::clear()
{
    m_points.clear();

    setAnswer(QPointF());
    emit pointsChanged();
}

void GProxima::setAnswer(QPointF answer)
{
    if (m_answer == answer)
        return;

    m_answer = answer;
    emit answerChanged(m_answer);
}

void GProxima::fillRandPoints()
{
    m_points.clear();
    int size = QRandomGenerator::system()->bounded(100);
    for(int i = 0; i < size; i++)
    {
        m_points.append(QPointF(
                            QRandomGenerator::system()->bounded(100.0),
                            QRandomGenerator::system()->bounded(100.0)));
    }

    emit pointsChanged();
}











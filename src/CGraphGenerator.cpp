#include "CGraphGenerator.hpp"

int CGraphGenerator::calcEdgesFromDensity()
{
    return m_density * m_verticesCount * (m_verticesCount - 1);
}

CGraphGenerator::CGraphGenerator(int verticesCount, double density, representationType type) : m_verticesCount(verticesCount), m_density(density),
                                                                                               m_type(type)
{
}

std::unique_ptr<CGraph> CGraphGenerator::makeGraph()
{
    int i = 0;
    int edgesCount = calcEdgesFromDensity();
    std::vector<CEdge> edges(edgesCount);

    srand(time(NULL));
    while (i < edgesCount)
    {
        edges[i].setBeg(rand() % m_verticesCount);
        edges[i].setEnd(rand() % m_verticesCount);
        edges[i].setWeight(rand() % MAX_WEIGHT + 1);

        if (edges[i].getBeg() == edges[i].getEnd())
        {
            continue;
        }
        else
        {
            for (int j = 0; j < i; ++j)
            {
                if ((edges[i].getBeg() == edges[j].getBeg() && edges[i].getEnd() == edges[j].getEnd()) ||
                    (edges[i].getBeg() == edges[j].getEnd() && edges[i].getEnd() == edges[j].getBeg()))
                {
                    --i;
                }
            }
        }
        ++i;
    }
    return std::make_unique<CGraph>(edgesCount, m_verticesCount, edges, m_type);
}
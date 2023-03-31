#include "CGraphGenerator.hpp"

constexpr int CGraphGenerator::calcEdgesFromDensity()
{
    return m_density * m_verticesCount * (m_verticesCount - 1);
}

CGraphGenerator::CGraphGenerator(int verticesCount, int density) : m_verticesCount(verticesCount), m_density(density)
{
}

std::unique_ptr<CGraph> CGraphGenerator::makeGraph()
{
    int edgesCount = calcEdgesFromDensity();
    std::vector<CEdge> edges(edgesCount);

    for (int i = 0; i < edgesCount; ++i)
    {
        edges[i].setBeg(rand() % m_verticesCount + 1);
        edges[i].setEnd(rand() % m_verticesCount + 1);
        edges[i].setWeight(rand() % m_maxWeight + 1);

        if (edges[i].getBeg() == edges[i].getEnd())
        {
            continue;
        }
        else
        {
            for (int j = 0; j < i; ++j)
            {
                if ((edges[i].getBeg() == edges[j].getBeg() && edges[i].getEnd() == edges[j].getEnd()) || (edges[i].getBeg() == edges[j].getEnd() && edges[i].getEnd() == edges[j].getBeg()))
                {
                    --i;
                }
            }
        }
    }
    return std::make_unique<CGraph>(edgesCount, m_verticesCount, edges, m_type);
}
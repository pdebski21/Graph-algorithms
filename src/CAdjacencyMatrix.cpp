#include "CAdjacencyMatrix.hpp"

CAdjacencyMatrix::CAdjacencyMatrix(int verticesCount, std::vector<CEdge> &edges) : m_adjacencyMatrix(std::vector<std::vector<int>>(verticesCount, std::vector<int>(verticesCount)))
{
    for (auto &edge : edges)
    {
        m_adjacencyMatrix[edge.getBeg()][edge.getEnd()] = edge.getWeight();
    }
}

double CAdjacencyMatrix::getWeight(int beg, int end)
{
    return m_adjacencyMatrix[beg][end];
}
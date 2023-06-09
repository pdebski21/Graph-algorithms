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

std::forward_list<std::pair<int, double>> CAdjacencyMatrix::getAdjacentVertices(int vertex)
{
    std::forward_list<std::pair<int, double>> adjacentVertices;
    int size = m_adjacencyMatrix.size();
    for (int v = 0; v < size; ++v)
    {
        double weight = m_adjacencyMatrix[vertex][v];
        if (weight > 0)
        {
            adjacentVertices.push_front(std::pair<int, double>(v, weight));
        }
    }
    return adjacentVertices;
}

std::vector<CEdge> CAdjacencyMatrix::getAllEdges()
{
    int size = m_adjacencyMatrix.size();
    std::vector<CEdge> edges;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            auto weight = getWeight(i, j);
            if (weight != 0)
            {
                edges.push_back(CEdge(i, j, weight));
            }
        }
    }

    return edges;
}

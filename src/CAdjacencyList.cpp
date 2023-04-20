#include "CAdjacencyList.hpp"

CAdjacencyList::CAdjacencyList(int verticesCount, std::vector<CEdge> &edges) : m_adjacencyList(std::vector<std::forward_list<std::pair<int, double>>>(verticesCount))
{
    for (auto &edge : edges)
    {
        m_adjacencyList[edge.getBeg()].push_front(std::pair<int, double>(edge.getEnd(), edge.getWeight()));
    }
}

double CAdjacencyList::getWeight(int beg, int end)
{
    auto it = find_if(m_adjacencyList[beg].begin(), m_adjacencyList[beg].end(),
                      [&](const std::pair<int, double> node)
                      { return node.first == end; });
    return it != m_adjacencyList[beg].end() ? it->second : 0;
}

std::forward_list<std::pair<int, double>> CAdjacencyList::getAdjacentVertices(int vertex)
{
    return m_adjacencyList[vertex];
}

std::vector<CEdge> CAdjacencyList::getAllEdges()
{
    std::vector<CEdge> edges;
    int size = m_adjacencyList.size();
    for (int i = 0; i < size; ++i)
    {
        for (auto &e : m_adjacencyList[i])
        {
            edges.push_back(CEdge(i, e.first, e.second));
        }
    }

    return edges;
}

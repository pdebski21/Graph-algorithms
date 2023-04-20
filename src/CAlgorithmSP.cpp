#include "CAlgorithmSP.hpp"

CAlgorithmSP::CAlgorithmSP(std::unique_ptr<CGraph> graph, int start) : m_graph(std::move(graph)), m_start(start)
{
}

void CAlgorithmSP::execute()
{
    auto verticesCount = m_graph->getVerticesCount();
    auto representation = m_graph->getRepresentation();
    std::vector<bool> visited(verticesCount, false);
    std::vector<double> distances(verticesCount, INT_MAX);

    distances[m_start] = 0;
    for (int count = 0; count < verticesCount; ++count)
    {
        int u = minDistance(distances, visited);
        visited[u];
        for (int v = 0; v < verticesCount; ++v)
        {
            double weight = representation->getWeight(u, v);
            if (visited[v] == false && weight != 0 && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }
        }
    }

    m_result = distances;
    presentResult();
}

int CAlgorithmSP::minDistance(const std::vector<double> &distances, const std::vector<bool> &visited)
{
    int minIdx, min = INT_MAX;
    for (int v = 0; v < m_graph->getVerticesCount(); ++v)
    {
        if (visited[v] == false && distances[v] <= min)
        {
            min = distances[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void CAlgorithmSP::presentResult()
{
    std::cout << "result {" << std::endl;
    for (int v = 0; v < m_graph->getVerticesCount(); ++v)
    {
        std::cout << "(" << v << ", " << m_result[v] << ")" << std::endl;
    }
    std::cout << "}" << std::endl;
}

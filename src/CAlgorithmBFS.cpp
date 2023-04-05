#include "CAlgorithmBFS.hpp"

CAlgorithmBFS::CAlgorithmBFS(std::unique_ptr<CGraph> graph, int start) : m_graph(std::move(graph)), m_start(start) {}

void CAlgorithmBFS::execute()
{
    std::vector<bool> visited(m_graph->getVerticesCount(), false);
    std::queue<int> verticesQueue;

    verticesQueue.push(m_start);
    while (!verticesQueue.emplace())
    {
        auto vertex = verticesQueue.front();
        verticesQueue.pop();
        m_result.push_back(vertex);
        auto adjacentVertices = m_graph->getRepresentation()->getAdjacentVertices(vertex);
        for (auto &adjacent : adjacentVertices)
        {
            if (!visited[adjacent.first])
            {
                verticesQueue.push(adjacent.first);
                visited[adjacent.first] = true;
            }
        }
    }
}

#include "CAlgorithmBFS.hpp"

CAlgorithmBFS::CAlgorithmBFS(std::unique_ptr<CGraph> graph, int start) : m_graph(std::move(graph)), m_start(start)
{
}

void CAlgorithmBFS::execute()
{
    std::vector<bool> visited(m_graph->getVerticesCount(), false);
    std::queue<int> verticesQueue;

    verticesQueue.push(m_start);
    visited[m_start] = true;

    while (!verticesQueue.empty())
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
    presentResult();
}

void CAlgorithmBFS::presentResult()
{
    std::cout << "result {";
    for (auto it = m_result.begin(); it != m_result.end(); ++it)
    {
        std::cout << it->getId() << ((it + 1) != m_result.end() ? ", " : "");
    }
    std::cout << "}" << std::endl;
}

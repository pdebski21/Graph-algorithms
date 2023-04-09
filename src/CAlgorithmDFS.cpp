#include "CAlgorithmDFS.hpp"

CAlgorithmDFS::CAlgorithmDFS(std::unique_ptr<CGraph> graph, int start) : m_graph(std::move(graph)), m_start(start)
{
}

void CAlgorithmDFS::execute()
{
    std::vector<bool> visited(m_graph->getVerticesCount(), false);
    DFS(visited, m_start);
    presentResult();
}

void CAlgorithmDFS::DFS(std::vector<bool> &visited, int v)
{
    if (visited[v])
    {
        return;
    }
    visited[v] = true;
    m_result.push_back(v);
    auto adjacentVertices = m_graph->getRepresentation()->getAdjacentVertices(v);
    for (auto &adj : adjacentVertices)
    {
        DFS(visited, adj.first);
    }
}

void CAlgorithmDFS::presentResult()
{
    std::cout << "result {";
    for (auto it = m_result.begin(); it != m_result.end(); ++it)
    {
        std::cout << it->getId() << ((it + 1) != m_result.end() ? ", " : "");
    }
    std::cout << "}" << std::endl;
}
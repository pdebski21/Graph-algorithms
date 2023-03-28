#include "CGraph.hpp"

CGraph::CGraph(int edgesCount, int verticesCount, std::vector<CEdge> &edges, representationType type) : m_edgesCount(edgesCount), m_verticesCount(verticesCount)
{
    switch (type)
    {
    case 1:
        m_representation = std::make_unique<CAdjacencyMatrix>(verticesCount, edges);
        break;
    case 2:
        m_representation = std::make_unique<CAdjacencyList>(verticesCount, edges);
        break;
    default:
        throw RepresentationtypeException("Undefined representation type!");
    }
}
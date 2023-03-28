#ifndef IGRAPH_HPP
#define IGRAPH_HPP

#include "IGraphRepresentation.hpp"
#include "CAdjacencyMatrix.hpp"
#include "CAdjacencyList.hpp"
#include "CEdge.hpp"
#include "Expcetions.hpp"
#include <memory>
#include <vector>

enum representationType
{
    adjacencyMatrix = 1,
    adjacencyList = 2
};

class CGraph
{
private:
    int m_edgesCount;
    int m_verticesCount;
    std::unique_ptr<IGraphRepresentation> m_representation;

public:
    CGraph(int edgesCount, int verticesCount, std::vector<CEdge> &edges, representationType type);
};

#endif
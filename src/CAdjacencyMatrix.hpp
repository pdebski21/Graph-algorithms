#ifndef CADJACENCYMATRIX_HPP
#define CADJACENCYMATRIX_HPP

#include "IGraphRepresentation.hpp"
#include "CEdge.hpp"
#include <vector>
#include <forward_list>

class CAdjacencyMatrix : public IGraphRepresentation
{
private:
    std::vector<std::vector<int>> m_adjacencyMatrix;

public:
    CAdjacencyMatrix(int verticesCount, std::vector<CEdge> &edges);
    double getWeight(int beg, int end) override;
    std::forward_list<std::pair<int, double>> getAdjacentVertices(int vertex) override;
};

#endif
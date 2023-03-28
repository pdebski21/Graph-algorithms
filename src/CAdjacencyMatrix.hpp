#ifndef CADJACENCYMATRIX_HPP
#define CADJACENCYMATRIX_HPP

#include "IGraphRepresentation.hpp"
#include "CEdge.hpp"
#include <vector>

class CAdjacencyMatrix : public IGraphRepresentation
{
private:
    std::vector<std::vector<int>> m_adjacencyMatrix;

public:
    CAdjacencyMatrix(int verticesCount, std::vector<CEdge> &edges);
    double getWeight(int beg, int end);
};

#endif
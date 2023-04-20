#ifndef IGRAPHREPRESENTATION_HPP
#define IGRAPHREPRESENTATION_HPP

#include "CEdge.hpp"
#include <forward_list>
#include <utility>
#include <vector>

class IGraphRepresentation
{
public:
    virtual double getWeight(int beg, int end) = 0;
    virtual std::forward_list<std::pair<int, double>> getAdjacentVertices(int vertex) = 0;
    virtual std::vector<CEdge> getAllEdges() = 0;
};

#endif
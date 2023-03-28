#ifndef CADJACENCYLIST_HPP
#define CADJACENCYLIST_HPP

#include "IGraphRepresentation.hpp"
#include "CEdge.hpp"
#include <vector>
#include <forward_list>
#include <utility>
#include <algorithm>

class CAdjacencyList : public IGraphRepresentation
{
private:
    std::vector<std::forward_list<std::pair<int, double>>> m_adjacencyList;

public:
    CAdjacencyList(int verticesCount, std::vector<CEdge> &edges);
    double getWeight(int beg, int end);
};

#endif
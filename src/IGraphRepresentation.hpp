#ifndef IGRAPHREPRESENTATION_HPP
#define IGRAPHREPRESENTATION_HPP

#include <forward_list>

class IGraphRepresentation
{
private:
public:
    virtual double getWeight(int beg, int end) = 0;
    virtual std::forward_list<std::pair<int, double>> getAdjacentVertices(int vertex) = 0;
};

#endif
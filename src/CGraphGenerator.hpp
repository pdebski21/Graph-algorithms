#ifndef CGRAPHGENERATOR_HPP
#define CGRAPHGENERATOR_HPP

#include "IGraphLoader.hpp"
#include "CEdge.hpp"
#include "CGraph.hpp"
#include <vector>
#include <ctime>
#include <iostream>

#define MAX_WEIGHT 30

class CGraphGenerator : public IGraphLoader
{
private:
    int m_verticesCount;
    double m_density;
    representationType m_type;

    int calcEdgesFromDensity();

public:
    CGraphGenerator(int verticesCount, double density, representationType type);
    std::unique_ptr<CGraph> makeGraph() override;
};

#endif
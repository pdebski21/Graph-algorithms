#ifndef CGRAPHGENERATOR_HPP
#define CGRAPHGENERATOR_HPP

#include "IGraphLoader.hpp"
#include "CEdge.hpp"
#include "CGraph.hpp"
#include <vector>

class CGraphGenerator : public IGraphLoader
{
private:
    int m_verticesCount;
    int m_density;
    int m_maxWeight;
    representationType m_type;

    constexpr int calcEdgesFromDensity();

public:
    CGraphGenerator(int verticesCount, int density, representationType type);
    std::unique_ptr<CGraph> makeGraph() override;
};

#endif
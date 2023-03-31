#ifndef IGRAPHLOADER_HPP
#define IGRAPHLOADER_HPP

#include "IGraphLoader.hpp"
#include "CGraph.hpp"
#include <memory>

class IGraphLoader
{
public:
    virtual std::unique_ptr<CGraph> makeGraph() = 0;
};

#endif
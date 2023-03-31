#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include "CGraph.hpp"

class IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;

public:
    virtual void execute() = 0;
};

#endif
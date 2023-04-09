#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include "CGraph.hpp"
#include <iostream>
#include <vector>

enum algorithmType
{
    DFS = 0,
    BFS = 1,
    SP = 2,
    MST = 3,
};

class IAlgorithm
{
protected:
public:
    virtual void execute() = 0;
    virtual void presentResult() = 0;
};

#endif
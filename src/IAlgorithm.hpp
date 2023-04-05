#ifndef IALGORITHM_HPP
#define IALGORITHM_HPP

#include "CGraph.hpp"

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
};

#endif
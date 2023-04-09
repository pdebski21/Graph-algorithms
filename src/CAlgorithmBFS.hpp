#ifndef CALGORITHMBFS_HPP
#define CALGORITHMBFS_HPP

#include "IAlgorithm.hpp"
#include "CVertex.hpp"
#include "CGraph.hpp"
#include <vector>
#include <queue>
#include <iostream>

class CAlgorithmBFS : public IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;
    std::vector<CVertex> m_result;
    int m_start;

public:
    CAlgorithmBFS(std::unique_ptr<CGraph> graph, int start);
    void execute() override;
    void presentResult() override;
};



#endif
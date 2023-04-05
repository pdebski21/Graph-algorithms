#ifndef CALGORITHMBFS_HPP
#define CALGORITHMBFS_HPP

#include "IAlgorithm.hpp"
#include "CVertex.hpp"
#include "CGraph.hpp"
#include <vector>
#include <queue>

class CAlgorithmBFS : public IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;
    int m_start;
    std::vector<CVertex> m_result;

public:
    CAlgorithmBFS(std::unique_ptr<CGraph> graph, int start);
    void execute() override;
};


#endif
#ifndef CALGORITHMDFS_HPP
#define CALGORITHMDFS_HPP

#include "IAlgorithm.hpp"
#include "CVertex.hpp"
#include <vector>
#include <iostream>

class CAlgorithmDFS : public IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;
    std::vector<CVertex> m_result;
    int m_start;

public:
    CAlgorithmDFS(std::unique_ptr<CGraph> graph, int start);
    void execute() override;
    void DFS(std::vector<bool> &visited, int v);
    void presentResult() override;
};

#endif
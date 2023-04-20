#ifndef CALGORITHMSP_HPP
#define CALGORITHMSP_HPP

#include "IAlgorithm.hpp"
#include "CGraph.hpp"
#include <vector>
#include <memory>
#include <bits/stdc++.h>

class CAlgorithmSP : public IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;
    std::vector<double> m_result;
    int m_start;

    int minDistance(const std::vector<double> &distances, const std::vector<bool> &visited);

public:
    CAlgorithmSP(std::unique_ptr<CGraph> graph, int start);

    void execute() override;
    void presentResult() override;
};

#endif
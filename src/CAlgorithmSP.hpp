#ifndef CALGORITHMSP_HPP
#define CALGORITHMSP_HPP

#include "CGraph.hpp"
#include <vector>
#include <memory>

struct resultSP
{
    int distance;
    std::vector<int> path;
}

class CAlgorithmSP
{
private:
    std::unique_ptr<CGraph> m_graph;
    resultSP m_result;
    int m_start;
    int m_end;

public:
    CAlgorithmSP(std::unique_ptr<CGraph> graph, int start, int end);
    void execute() override;
    void presentResult() override;
};

#endif
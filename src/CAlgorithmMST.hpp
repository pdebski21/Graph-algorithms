#ifndef CALGORITHMMST_HPP
#define CALGORITHMMST_HPP

#include "IAlgorithm.hpp"
#include "CEdge.hpp"
#include "CGraph.hpp"
#include <vector>
#include <memory>
#include <algorithm>

struct DisjointSet
{
    std::vector<int> parent, rank;

    DisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};

class CAlgorithmMST : public IAlgorithm
{
private:
    std::unique_ptr<CGraph> m_graph;
    DisjointSet m_disjointSet;
    std::vector<CEdge> m_result;

    int find(int v);
    void makeUnion(int v, int u);

public:
    CAlgorithmMST(std::unique_ptr<CGraph> graph);
    void execute() override;
    void presentResult() override;
};

#endif
#include "CAlgorithmMST.hpp"

DisjointSet::DisjointSet(int n)
{
    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet::find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void DisjointSet::unite(int x, int y)
{
    int x_root = find(x);
    int y_root = find(y);

    if (x_root == y_root)
    {
        return;
    }

    if (rank[x_root] < rank[y_root])
    {
        parent[x_root] = y_root;
    }
    else if (rank[x_root] > rank[y_root])
    {
        parent[y_root] = x_root;
    }
    else
    {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}

CAlgorithmMST::CAlgorithmMST(std::unique_ptr<CGraph> graph) : m_graph(std::move(graph)), m_disjointSet(m_graph->getVerticesCount())
{
}

void CAlgorithmMST::execute()
{
    auto edges = m_graph->getRepresentation()->getAllEdges();

    std::sort(edges.begin(), edges.end(), [](auto &right, auto &left)
              { return right.getWeight() < left.getWeight(); });
    for (auto &edge : edges)
    {
        int u = m_disjointSet.find(edge.getBeg());
        int v = m_disjointSet.find(edge.getEnd());

        if (u != v)
        {
            m_result.push_back(edge);
            m_disjointSet.unite(u, v);
        }
    }

    presentResult();
}

void CAlgorithmMST::presentResult()
{
    double minCost = 0;
    std::cout << "result {" << std::endl;
    for (auto &edge : m_result)
    {
        std::cout << "(" << edge.getBeg() << ", " << edge.getEnd() << ", " << edge.getWeight() << ")" << std::endl;
        minCost += edge.getWeight();
    }
    std::cout << "MST cost: " << minCost << std::endl;
    std::cout << "}" << std::endl;
}
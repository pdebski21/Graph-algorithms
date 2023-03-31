#include "CGraphFileLoader.hpp"

std::unique_ptr<CGraph> CGraphFileLoader::makeGraph()
{
    int edgesCount, verticesCount, beg, end;
    double weight;
    std::vector<CEdge> edges(verticesCount);
    std::ifstream graphFile(m_path);

    try
    {
        graphFile >> edgesCount;
        graphFile >> verticesCount;
        for (int i = 0; i < verticesCount; ++i)
        {
            graphFile >> beg;
            graphFile >> end;
            graphFile >> weight;
            edges[i].setBeg(beg);
            edges[i].setEnd(end);
            edges[i].setWeight(weight);
        }
    }
    catch (std::exception const &e)
    {
        std::cout << "Loading graph from file failed" << e.what() << std::endl;
    }

    return std::make_unique<CGraph>(edgesCount, verticesCount, edges, m_type);
}
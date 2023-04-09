#include "CGraphFileLoader.hpp"

CGraphFileLoader::CGraphFileLoader(std::string path, representationType type) : m_path(path), m_type(type)
{
}

std::unique_ptr<CGraph> CGraphFileLoader::makeGraph()
{
    int edgesCount, verticesCount, beg, end;
    double weight;
    std::vector<CEdge> edges;
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
            auto edge = CEdge(beg, end, weight);
            edges.push_back(edge);
        }
    }
    catch (std::exception const &e)
    {
        std::cout << "Loading graph from file failed" << e.what() << std::endl;
    }

    return std::make_unique<CGraph>(edgesCount, verticesCount, edges, m_type);
}
#include "CCore.hpp"

CCore::CCore()
{
}

std::shared_ptr<CCore> CCore::GetInstance()
{
    if (m_core == nullptr)
    {
        m_core = std::make_shared<CCore>();
    }
    return m_core;
}

std::unique_ptr<IAlgorithm> CCore::ScheduleAlgorithms(params &cmdParams)
{
    std::unique_ptr<IGraphLoader> graphLoader;
    std::unique_ptr<IAlgorithm> algorithm;
    representationType type = cmdParams.m_representation == "AL" ? representationType::adjacencyList : representationType::adjacencyMatrix;
    if (cmdParams.m_filePath)
    {
        graphLoader = std::make_unique<CGraphFileLoader>(cmdParams.m_filePath.value(), type);
    }
    else
    {
        graphLoader = std::make_unique<CGraphGenerator>(cmdParams.m_verticesCount.value(), cmdParams.m_density.value(), type);
    }
    auto graph = graphLoader->makeGraph();

    if (cmdParams.m_algorithm == "SP")
    {
        algorithm = std::make_unique<CAlgorithmSP>(std::move(graph), cmdParams.m_startVertex.value());
    }
    else if (cmdParams.m_algorithm == "BFS")
    {
        algorithm = std::make_unique<CAlgorithmBFS>(std::move(graph), cmdParams.m_startVertex.value());
    }
    else if (cmdParams.m_algorithm == "DFS")
    {
        algorithm = std::make_unique<CAlgorithmDFS>(std::move(graph), cmdParams.m_startVertex.value());
    }
    else if (cmdParams.m_algorithm == "MST")
    {
        algorithm = std::make_unique<CAlgorithmMST>(std::move(graph));
    }

    algorithm->execute();

    return algorithm;
}

std::shared_ptr<CCore> CCore::m_core = nullptr;

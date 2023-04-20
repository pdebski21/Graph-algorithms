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

std::unique_ptr<IAlgorithm> CCore::ScheduleAlgorithms()
{
    //std::unique_ptr<IGraphLoader> graphLoader = std::make_unique<CGraphGenerator>(8, 0.4, representationType::adjacencyList);
    std::unique_ptr<IGraphLoader> graphLoader = std::make_unique<CGraphFileLoader>("./data/graph1.txt", representationType::adjacencyList);
    auto graph = graphLoader->makeGraph();

    for (int i = 0; i < graph->getVerticesCount(); ++i)
    {
        for (auto &el : graph->getRepresentation()->getAdjacentVertices(i))
        {
            std::cout << i << ", " << el.first << "," << el.second << std::endl;
        }
    }

    //std::unique_ptr<IAlgorithm> algorithm = std::make_unique<CAlgorithmSP>(std::move(graph), 1);
    std::unique_ptr<IAlgorithm> algorithm = std::make_unique<CAlgorithmMST>(std::move(graph));

    algorithm->execute();

    return algorithm;
}

std::shared_ptr<CCore> CCore::m_core = nullptr;

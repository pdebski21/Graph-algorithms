#include "CAlgorithmSP.hpp"

CAlgorithmSP::CAlgorithmSP(std::unique_ptr<CGraph> graph, int start, int end) m_graph(std::move(graph)), m_start(start), m_end(end)
{
}

void CAlgorithmSP::execute()
{
}

void CAlgorithmSP::presentResult()
{
}
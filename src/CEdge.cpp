#include "CEdge.hpp"

int CEdge::getBeg()
{
    return m_beg;
}
int CEdge::getEnd()
{
    return m_end;
}
double CEdge::getWeight()
{
    return m_weight;
}
void CEdge::setBeg(int beg)
{
    m_beg = beg;
}
void CEdge::setEnd(int end)
{
    m_end = end;
}
void CEdge::setWeight(double weight)
{
    m_weight = weight;
}

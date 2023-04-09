#ifndef EDGE_HPP
#define EDGE_HPP

class CEdge
{
private:
    int m_beg;
    int m_end;
    double m_weight;

public:
    CEdge();
    CEdge(int beg, int end, double weight);

    int getBeg();
    int getEnd();
    double getWeight();
    void setBeg(int beg);
    void setEnd(int end);
    void setWeight(double weight);
};

#endif
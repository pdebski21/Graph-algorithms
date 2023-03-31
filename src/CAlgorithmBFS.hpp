#ifndef CALGORITHMBFS_HPP
#define CALGORITHMBFS_HPP

#include "IAlgorithm.hpp"
#include "CVertex.hpp"
#include <vector>

class CAlgorithmDFS : public IAlgorithm
{
private:
    int m_start;
    std::vector<CVertex> result;

public:
    void execute() override;
}

#endif
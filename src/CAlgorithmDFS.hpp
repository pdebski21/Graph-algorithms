#ifndef CALGORITHMDFS_HPP
#define CALGORITHMDFS_HPP

#include "IAlgorithm.hpp"
#include "CVertex.hpp"
#include <memory>
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
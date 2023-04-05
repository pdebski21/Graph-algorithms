#ifndef CCORE_HPP
#define CCORE_HPP

#include "CGraphGenerator.hpp"
#include "CAlgorithmBFS.hpp"
#include "CGraphFileLoader.hpp"
#include <memory>
#include <iostream>
class CCore
{
protected:
    static std::shared_ptr<CCore> m_core;

public:
    CCore();
    CCore(CCore &other) = delete;
    void operator=(const CCore &) = delete;

    static std::shared_ptr<CCore> GetInstance();
    std::unique_ptr<IAlgorithm> ScheduleAlgorithms();
};

#endif
#include "CCore.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    auto core = CCore::GetInstance();
    core->ScheduleAlgorithms();
    return 0;
}
#include "CCore.hpp"
#include "CCmdParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    auto cmdParams = CCmdParser::parse(argc, argv);
    auto core = CCore::GetInstance();
    core->ScheduleAlgorithms(cmdParams);
    return 0;
}
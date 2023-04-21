#ifndef CCMDPARSER_HPP
#define CCMDPARSER_HPP

#include <iostream>
#include <fstream>
#include <string_view>
#include <cstring>
#include <cstdlib>
#include <optional>
#include <filesystem>
#include <getopt.h>

namespace fs = std::filesystem;

struct params
{
    std::string_view m_algorithm;
    std::string_view m_representation;
    std::optional<int> m_startVertex;
    std::optional<std::string> m_filePath;
    std::optional<double> m_density;
    std::optional<int> m_verticesCount;

    params(std::string_view algorithm, std::string_view representation, std::optional<int> startVetex, std::optional<std::string> filePath,
           std::optional<double> density, std::optional<int> verticesCount);
};

class CCmdParser
{
private:
    static void usage();

public:
    static params parse(int argc, char **argv);
};

#endif

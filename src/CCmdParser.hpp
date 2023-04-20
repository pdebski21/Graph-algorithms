#ifndef CCMDPARSER_HPP
#define CCMDPARSER_HPP

#include <iostream>
#include <fstream>
#include <string_view>
#include <cstring>
#include <cstdlib>
#include <optional>
#include <getopt.h>

class CCmdParser
{
public:
    static void usage();
    static void parse(int argc, char **argv);
};

#endif

#ifndef CCMDPARSER_HPP
#define CCMDPARSER_HPP

/*
* cmd structure: ./bin/main <generate-graph> <vertices-count> <density> <algorithm-name> <algorithm-params> (generated graph)
* cmd structure: ./bin/main <load-graph> <algorithm-name> <filepath> <algorithm-name> <algorithm-params> (load graph from file)
*
*/
class CCmdParser
{
public:
    static void Parse(int argc, char **argv)
    {
    }
};

#ifndef
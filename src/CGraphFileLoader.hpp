#ifndef CGRAPHFILELOADER_HPP
#define CGRAPHFILELOADER_HPP

#include "IGraphLoader.hpp"
#include "CGraph.hpp"
#include "CEdge.hpp"
#include <string>
#include <fstream>
#include <iostream>

/* 
* Input file format 
* first line: edges count, vertices count, starting vertex, ending vertex  
* next lines: edges with begin vertex, end vertex, weight
*/
class CGraphFileLoader : public IGraphLoader
{
private:
    std::string m_path;
    representationType m_type;

public:
    std::unique_ptr<CGraph> makeGraph() override;
};

#endif
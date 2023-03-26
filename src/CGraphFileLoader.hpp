#ifndef CGRAPHFILELOADER_HPP
#define CGRAPHFILELOADER_HPP

#include "IGraphLoader.hpp"

/* 
* Input file format 
* first line: edges count, vertices count, starting vertex, ending vertex  
* next lines: edges with begin vertex, end vertex, weight
*/
class CGraphFileLoader : public IGraphLoader
{
};

#endif
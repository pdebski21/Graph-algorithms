
#ifndef CCOLOREDVERTEX_HPP
#define CCOLOREDVERTEX_HPP

#include "CVertex.hpp"
#include <optional>

enum color
{
    white = 0,
    gray = 1,
    black = 2,
};

class CColoredVertex : public CVertex
{
private:
    std::optional<color> m_color;

public:
    CColoredVertex(int id, std::optional<color> color);
};

#endif

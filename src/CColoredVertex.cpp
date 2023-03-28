#include "CColoredVertex.hpp"

CColoredVertex::CColoredVertex(int id, std::optional<color> color) : CVertex(id), m_color(color)
{
}
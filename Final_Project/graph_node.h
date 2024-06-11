#pragma once

#include <vector>

#include "edge.h"

struct Edge;

struct GraphNode
{
    std::string name;
    std::vector<Edge *> neighbors;
};
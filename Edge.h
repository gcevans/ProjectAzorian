#pragma once

#include <memory>

#include "Vertex.h"

using std::shared_ptr;

template <typename V, typename W>
class Edge{
public:
    Edge(V *end1, V *end2, const W &weight);
    void print();
    W weight() { return weight_; } ;

private:
    W weight_;
    V *ends_[2];
};

#include "Edge.hpp"
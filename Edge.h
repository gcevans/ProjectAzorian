#pragma once

#include <memory>

#include "Vertex.h"

using std::shared_ptr;

template <typename V, typename W>
class Edge{
public:
    Edge(shared_ptr<V> end1, shared_ptr<V> end2, const W &weight);
    void print();
    W weight() { return weight_; } ;

private:
    W weight_;
    shared_ptr<V> ends_[2];
};

#include "Edge.hpp"
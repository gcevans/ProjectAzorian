#pragma once

#include <memory>

#include "Vertex.h"

using std::pair;
using std::shared_ptr;

template <typename V, typename W>
class Edge{
public:
    Edge(shared_ptr<V> end1, shared_ptr<V> end2, const W &weight);
    void print();
    W weight() { return weight_; } ;

    const pair<shared_ptr<V>, shared_ptr<V>> &ends() const { return ends_;}; 

private:
    W weight_;
    pair<shared_ptr<V>, shared_ptr<V>> ends_;
};

#include "Edge.hpp"
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

    W weight() const;
    const pair<shared_ptr<V>, shared_ptr<V>> &ends() const; 

private:
    W weight_;
    pair<shared_ptr<V>, shared_ptr<V>> ends_;
};

template<typename V,typename W>
std::ostream & operator<<(std::ostream &os, const Edge<V,W> &e);

#include "Edge.hpp"
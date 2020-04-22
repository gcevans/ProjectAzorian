#pragma once

#include <list>
#include <memory>
#include <unordered_map>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

using std::list;
using std::shared_ptr;
using std::unordered_map;
using std::vector;

template<typename V, typename E>
class Graph {
public:
    Graph(vector<shared_ptr<V>> v, vector<E> e) : vertices_(v), edges_(e) { };
    Graph() { };

    //Vertex Functions
    void insert(shared_ptr<V> &v);
    void erase(shared_ptr<V> &v);
    const list<shared_ptr<V>> &incident(shared_ptr<V> &v);
    const list<const shared_ptr<const V>> &incident(shared_ptr<V> &v) const;
    int degree(shared_ptr<V> &v) const;
    bool adjcent(shared_ptr<V> &v1, shared_ptr<V> &v2) const;

    //Edge Funtions
    void insert(shared_ptr<E> &e);
    void erase(shared_ptr<E> &e);

    //Helper Function
    void print();

private:
    unordered_map<shared_ptr<V>, list<shared_ptr<V>>> vertices_;
    list<E> edges_;
};

#include "Graph.hpp"
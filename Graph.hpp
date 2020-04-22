#pragma once

#include <algorithm>

#include "Graph.h"


//Vertex Functions
template<typename V, typename E>
void Graph<V,E>::insert(shared_ptr<V> &v) {
    vertices_[v] = list<shared_ptr<E>>();
}

template<typename V, typename E>
void Graph<V,E>::erase(shared_ptr<V> &v) {

    auto adj_list = vertices_[v];

    while(!adj_list.empty() ) {
        erase(adj_list.front() );
    }

    vertices_.erase(v);
}

template<typename V, typename E>
const list<shared_ptr<E>> &Graph<V,E>::incident(shared_ptr<V> &v) {
    return vertices_[v];
}

template<typename V, typename E>
const list<const shared_ptr<const E>> &Graph<V,E>::incident(shared_ptr<V> &v) const {
    return vertices_[v];
}


template<typename V, typename E>
int Graph<V,E>::degree(shared_ptr<V> &v) const {
    return vertices_[v].size();
}

template<typename V, typename E>
unsigned int Graph<V,E>::numVertices() const {
    return vertices_.size();
}


//Edge Functions
template<typename V, typename E>
void Graph<V,E>::insert(shared_ptr<E> &e) {
    edges_.push_back(e);
}

template<typename V, typename E>
void Graph<V,E>::erase(shared_ptr<E> &e) {
    //find edge
    auto edgeIt = std::find(edges_.begin(), edges_.end(), e);
    
    if(edgeIt != edges_.end()) {
    // remove the edges from both vertext adj lists
        auto end_adj = vertices_[(*edgeIt)->ends().first];
        end_adj.erase(std::find(end_adj.begin(),end_adj.end(), e));
        
        end_adj = vertices_[(*edgeIt)->ends().second];
        end_adj.erase(std::find(end_adj.begin(),end_adj.end(), e));
    //remove edge
        edges_.erase(edgeIt);
    }
}

template<typename V, typename E>
unsigned int Graph<V,E>::numEdges() const {
    return edges_.size();
}

#pragma once

#include <algorithm>

#include "Graph.h"

template<typename V, typename E>
Graph<V,E>::Graph(vector<shared_ptr<V>> vertices, vector<shared_ptr<E>> edeges){
    for(auto vertex : vertices) {
        insert(vertex);
    }

    for(auto edge : edeges) {
        insert(edge);
    }
}


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

//TODO resolve shared code between const and non-const versions of incident
template<typename V, typename E>
const list<shared_ptr<E>> &Graph<V,E>::incident(shared_ptr<V> &v) {
    auto v_it = vertices_.find(v);

    if(v_it != vertices_.end()) {
        return v_it->second;
    } else {
        return empty_;
    }
}

template<typename V, typename E>
const list<const shared_ptr<const E>> &Graph<V,E>::incident(shared_ptr<V> &v) const {
    auto v_it = vertices_.find(v);

    if(v_it != vertices_.end()) {
        return v_it->second;
    } else {
        return empty_;
    }
}

template<typename V, typename E>
int Graph<V,E>::degree(shared_ptr<V> &v) const {
    auto v_it = vertices_.find(v);

    if(v_it != vertices_.end()) {
        return v_it->second.size();
    } else {
        return 0;
    }
}

template<typename V, typename E>
unsigned int Graph<V,E>::numVertices() const {
    return vertices_.size();
}


// TODO Reduce Code Sharing in getListVertices versions
template<typename V, typename E>
std::list<shared_ptr<V>> Graph<V,E>::getListVertices() const {
    std::list<shared_ptr<V>> vertices;

    for(auto v : vertices_) {
        vertices.push_back(v.first);
    }

    return vertices;
}

template<typename V, typename E>
std::list<shared_ptr<V>> Graph<V,E>::getListVertices() {
    std::list<shared_ptr<V>> vertices;

    for(auto v : vertices_) {
        vertices.push_back(v.first);
    }

    return vertices;
}

template<typename V, typename E>
std::list<shared_ptr<V>> Graph<V,E>::getListAdj(shared_ptr<V> &v) const {
    std::list<shared_ptr<V>> vertices;

    for(auto edge : vertices_[v]) {
        if(edge->ends().first == v ) {
            vertices.push_back(edge->ends().second);
        } else {
            vertices.push_back(edge->ends().first);
        }
    }
    return vertices;
}

template<typename V, typename E>
std::list<shared_ptr<V>> Graph<V,E>::getListAdj(shared_ptr<V> &v)  {
    std::list<shared_ptr<V>> vertices;

    for(auto edge : vertices_[v]) {
        if(edge->ends().first == v ) {
            vertices.push_back(edge->ends().second);
        } else {
            vertices.push_back(edge->ends().first);
        }
    }
    return vertices;
}

//Edge Functions
template<typename V, typename E>
void Graph<V,E>::insert(shared_ptr<E> &e) {
    auto v1_it = vertices_.find(e->ends().first);
    auto v2_it = vertices_.find(e->ends().second);

    if(v1_it == vertices_.end() || v2_it == vertices_.end() ) {
        return;
    } else {
        v1_it->second.push_back(e);
        v2_it->second.push_back(e);
        edges_.push_back(e);
    }
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

template<typename V, typename E>
list<shared_ptr<const E>> Graph<V,E>::getListEdges() const {
    return edges_;
}

template<typename V, typename E>
list<shared_ptr<E>> Graph<V,E>::getListEdges() {
    return edges_;
}

//Helper Function
template<typename V, typename E>
bool Graph<V,E>::adjcent(shared_ptr<V> &v1, shared_ptr<V> &v2) const {
    auto v1_it = vertices_.find(v1);
    auto v2_it = vertices_.find(v2);

    if(v1_it == vertices_.end() || v2_it == vertices_.end()) {
        return false;
    }

    if( v1_it->second.size() > v2_it->second.size() ) {
        for(auto v2_e : v2_it->second ) {
            if( v2_e->ends().first == v1 || v2_e->ends().second == v1) {
                return true;
            }
        }
    } else {
        for(auto v1_e : v1_it->second ) {
            if( v1_e->ends().first == v2 || v1_e->ends().second == v2) {
                return true;
            }
        }
    }

    return false;
}

template<typename V, typename E>
void Graph<V,E>::print() {
    std::cout << "V = { ";
    for(auto v : vertices_) {
        std::cout << *(v.first) << " "; 
    }
    std::cout << "}" << std::endl;

    std::cout << "E = {" << std::endl;
    for(auto e : edges_) {
        std::cout << *e << std::endl;
    }
    std::cout << "}" << std::endl;
}

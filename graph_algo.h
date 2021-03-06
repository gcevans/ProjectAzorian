#pragma once

#include<unordered_map>

#include "Graph.h"

using std::unordered_map;

enum edge_label { UNEXPLORED_EDGE = 0, DISCOVERY_EDGE, CROSS_EDGE};
enum vertex_label { UNEXPLORED_VERT = 0, EXPLORED_VERT};

// BFS on a Graph G returning mapping of edges to DISCOVERY or CROSS
template<typename V, typename E>
unordered_map<shared_ptr<E>,edge_label> BFS( Graph<V,E> &G);

// BFS on Graph G from vertex start updating labeled_edges and labeled_vertices
template<typename V, typename E>
void BFS( Graph<V,E> &G,
            shared_ptr<V> &start,
            unordered_map<shared_ptr<V>,vertex_label> &labeled_vertices,
            unordered_map<shared_ptr<E>,edge_label> &labeled_edges
        );

template<typename V, typename E>
unordered_map<shared_ptr<V>,int> DijkstraAlgorithm( Graph<V,E> &G, shared_ptr<V> start);

template<typename V, typename E>
Graph<V,E> PrimsAlgorithm(Graph<V,E> &G, shared_ptr<V> start);

#include "graph_algo.hpp"

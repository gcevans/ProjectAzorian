#pragma once

#include<unordered_map>

#include "Graph.h"

using std::unordered_map;

enum edge_label { UNEXPLORED_EDGE = 0, DISCOVERY_EDGE, CROSS_EDGE};
enum vertex_label { UNEXPLORED_VERT = 0, EXPLORED_VERT};

// BFS on a Graph G returning mapping of edges to DISCOVERY or CROSS
template<typename V, typename E>
unordered_map<shared_ptr<const E>,edge_label> BFS( const Graph<V,E> &G);

// BFS on Graph G from vertex start updating labeled_edges and labeled_vertices
template<typename V, typename E>
void BFS( const Graph<V,E> &G,
            shared_ptr< const V> &start,
            unordered_map<shared_ptr<const V>,vertex_label> &labeled_vertices,
            unordered_map<shared_ptr<const E>,edge_label> &labeled_edges
        );

#include "graph_algo.hpp"
#pragma once

#include <iostream>

#include "graph_algo.h"

template<typename V, typename E>
unordered_map<shared_ptr<const E>,edge_label> BFS( const Graph<V,E> &G) {
    unordered_map<shared_ptr<const E>,edge_label> labeled_edges;
    unordered_map<shared_ptr<const V>,vertex_label> labeled_vertices;

    for(auto v : G.getListVertices() ) {
        if(labeled_vertices[v] == UNEXPLORED_VERT) {
            BFS(G, v, labeled_vertices, labeled_edges );
        }
    }

    return labeled_edges;
}

template<typename V, typename E>
void BFS( const Graph<V,E> &G,
            shared_ptr< const V> &start,
            unordered_map<shared_ptr<const V>,vertex_label> &labeled_vertices,
            unordered_map<shared_ptr<const E>,edge_label> &labeled_edges
        ) {
    std::cout << "BFS from " << *start << std::endl;

    // BFS(G, v):
    //     Queue q
    //     setLabel(v, VISITED)
    //     q.enqueue(v)

    //     while !q.empty():
    //         v = q.dequeue()
    //         foreach (Vertex w : G.adjacent(v)):
    //             if getLabel(w) == UNEXPLORED:
    //                 setLabel(v, w, DISCOVERY)
    //                 setLabel(w, VISITED)
    //                 q.enqueue(w)
    //             elseif getLabel(v, w) == UNEXPLORED:
    //                 setLabel(v, w, CROSS)
}

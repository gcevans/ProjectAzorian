#pragma once

#include <iostream>
#include <queue>
#include <stack>

#include "graph_algo.h"

using std::priority_queue;

template<typename V, typename E>
unordered_map<shared_ptr<E>,edge_label> BFS( Graph<V,E> &G) {
    unordered_map<shared_ptr<E>,edge_label> labeled_edges;
    unordered_map<shared_ptr<V>,vertex_label> labeled_vertices;

    for( auto v : G.getListVertices() ) {
        if( labeled_vertices[v] == UNEXPLORED_VERT ) {
            BFS(G, v, labeled_vertices, labeled_edges );
        }
    }

    return labeled_edges;
}

template<typename V, typename E>
void BFS( Graph<V,E> &G,
            shared_ptr<V> &start,
            unordered_map<shared_ptr<V>,vertex_label> &labeled_vertices,
            unordered_map<shared_ptr<E>,edge_label> &labeled_edges
        ) {
    std::cout << "BFS from " << *start << std::endl;
        //initialize worklist
        std::stack<std::pair<shared_ptr<V>,shared_ptr<E>>> worklist;
        std::pair<shared_ptr<V>,shared_ptr<E>> initstate = make_pair(start,shared_ptr<E>(nullptr));
        worklist.push( initstate );

        //while worklist not empty
        while( !worklist.empty() ) {
            shared_ptr<V> v = worklist.top().first;
            shared_ptr<E> v_path = worklist.top().second;
            worklist.pop();

            // Visit vertex updating path
            if( labeled_vertices[v] == EXPLORED_VERT) {
                if( labeled_edges[v_path] == UNEXPLORED_EDGE ) {
                    labeled_edges[v_path] = CROSS_EDGE;
                }
            } else {
                std::cout << "Processing " << *v << std::endl;
                labeled_vertices[v] = EXPLORED_VERT;
                // Initial Vertex has a non-path skip
                if( v_path ) {
                    labeled_edges[v_path] = DISCOVERY_EDGE;
                } 

                // add neighbors to work list        
                for( auto incident : G.incident(v) ) {
                    shared_ptr<V> w;

                    if( incident->ends().first == v ) {
                        w = incident->ends().second;
                    } else {
                        w = incident->ends().first;
                    }
                    worklist.push(make_pair(w,incident));     
                }
            }
        }
    std::cout << "BFS from " << *start << " finshed" << std::endl;
}


template<typename V, typename E>
unordered_map<shared_ptr<V>,int> DijkstraAlgorithm( Graph<V,E> &G, shared_ptr<V> start) {
    unordered_map<shared_ptr<V>,int> distances;
    unordered_map<shared_ptr<V>,shared_ptr<E>> pred;

    auto comp = [&](shared_ptr<V> l, shared_ptr<V> r){ return distances[l] > distances[r]; };
    priority_queue<shared_ptr<V>, vector<shared_ptr<V>>, decltype(comp)> pq( comp );

    for(auto v : G.getListVertices()) {
        if( v == start) {
            distances[start] = 0;
        } else {
        distances[v] = INT32_MAX;
        }
        pred[v] = shared_ptr<E>(nullptr);
        pq.push(v);
    }

    while(pq.size() > 0) {
        shared_ptr<V> u = pq.top();
        pq.pop();

        for( auto incident : G.incident(u) ) {
            shared_ptr<V> v;

            if( incident->ends().first == u ) {
                v = incident->ends().second;
            } else {
                v = incident->ends().first;
            }

            if( ( incident->weight() + distances[u] ) < distances[v] ) {
                distances[v] = incident->weight() + distances[u];
                pq.push(v); // ideally don't push but update v in pq.
                pred[v] = incident;
            }
        }
    }
    return distances;
}


template<typename V, typename E>
Graph<V,E> PrimsAlgorithm(Graph<V,E> &G, shared_ptr<V> start) {

}

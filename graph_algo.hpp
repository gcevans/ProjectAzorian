#pragma once

#include <iostream>
#include <queue>
#include <stack>

#include "graph_algo.h"

using std::priority_queue;
using std::cout;
using std::endl;

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

        if(distances[u] != INT32_MAX) {
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
    }
    return distances;
}


// PrimMST(G, s):
// Input: G, Graph;
// s, vertex in G, starting vertex
// Output: T, a minimum spanning tree (MST) of G
template<typename V, typename E>
Graph<V,E> PrimsAlgorithm(Graph<V,E> &G, shared_ptr<V> start) {
    Graph<V,E> T;

    // foreach (Vertex v : G):
    //     d[v] = +inf
    //     p[v] = NULL
    // d[s] = 0
    // PriorityQueue Q // min distance, defined by d[v]
    // Q.buildHeap(G.vertices())
    // Graph T // "labeled set"
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

    unordered_map<shared_ptr<V>,bool> processed;

    // repeat n times:
    while (G.numVertices() != T.numVertices()) {
    //     Vertex m = Q.removeMin()
        shared_ptr<V> m = pq.top();
        pq.pop();
        if(processed.find(m) == processed.end() ) {
    //     T.add(m)
            T.insert(m);
            processed[m] = true;
            if(pred[m] != nullptr) {
                T.insert(pred[m]);
            }
            cout << "Processing " << *m << endl;
    //     foreach (Vertex v : neighbors of m not in T):
            for( auto incident : G.incident(m) ) {
                shared_ptr<V> v;

                if( incident->ends().first == m ) {
                    v = incident->ends().second;
                } else {
                    v = incident->ends().first;
                }

                cout << "Checking " << *v << "with weight " << incident->weight() << endl;
                if(processed.find(v) == processed.end() ) {
        //         if cost(v, m) < d[v]:
                    if(incident->weight() < distances[v]) {
            //             d[v] = cost(v, m)
                        distances[v] = incident->weight();
            //             p[v] = m
                        pred[v] = incident;
                        cout << "inserting " << *v << "into pq with weight " << distances[v] << endl;
                        pq.push(v);
                        cout << "PQ top = " << *(pq.top()) << " with cost " << distances[pq.top()] << endl;
                    }
                }
            }
        }
    }

    // return T
    return T;
}

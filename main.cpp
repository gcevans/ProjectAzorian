#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

std::vector<Edge<Vertex<string>, int>> makeEdges() {
    std::vector<Edge<Vertex<string>, int>>edges;
    shared_ptr<Vertex<string>> zero(new Vertex<string>("zero"));
    shared_ptr<Vertex<string>> one(new Vertex<string>("one"));
    shared_ptr<Vertex<string>> two(new Vertex<string>("two"));
    edges.push_back(Edge<Vertex<string>, int>(zero, one, 1));
    edges.push_back(Edge<Vertex<string>, int>(one, two, 1));
    edges.push_back(Edge<Vertex<string>, int>(two, zero, 2));

    return edges;
}

int main() {
    Graph<Vertex<string>,Edge<Vertex<string>, int>> G;
    
    // shared_ptr<Vertex<string>> zero(new Vertex<string>("zero"));
    // shared_ptr<Vertex<string>> one(new Vertex<string>("one"));
    // shared_ptr<Vertex<string>> two(new Vertex<string>("two"));
    // Vertex<string> one_number_two;

    auto edges = makeEdges();

    cout << "Edges" << endl;
    for( auto edge : edges) {
        edge.print();
        cout << endl;
    }
 
    // one_number_two = *one;
    
    // cout << *zero << endl;
    // cout << *one << endl;
    // cout << one_number_two << endl;

    // if( one_number_two == *zero) {
    //     cout << "The world is wrong" << endl;
    // }
    
    // if( one_number_two != *zero) {
    //     cout << "The world is ok" << endl;
    // }
    return 0;
}
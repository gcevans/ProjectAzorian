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

typedef shared_ptr<Vertex<string>> v_type;
typedef shared_ptr<Edge<Vertex<string>, int>> e_type;
typedef Graph<Vertex<string>,Edge<Vertex<string>, int>> g_type;



int main() {
    shared_ptr<Vertex<string>> zero(new Vertex<string>("zero"));
    shared_ptr<Vertex<string>> one(new Vertex<string>("one"));
    shared_ptr<Vertex<string>> two(new Vertex<string>("two"));
    shared_ptr<Edge<Vertex<string>, int>> one_two(new Edge<Vertex<string>, int>(one, two, 1));
    Vertex<string> one_number_two;

    vector<shared_ptr<Vertex<string>>> v = {zero, one, two};
    vector<shared_ptr<Edge<Vertex<string>, int>>> e = {one_two};


    Graph<Vertex<string>,Edge<Vertex<string>, int>> G(v,e);

    // cout << "Graph G has " << G.numVertices() << " Verticies" << endl;
    // cout << "Insert vertex zero" << endl;
    // G.insert(zero);
    // G.insert(one);
    // G.insert(two);
    // G.insert(one_two);
    cout << "Graph G has " << G.numVertices() << " Verticies" << endl;
    cout << "Graph G has " << G.numEdges() << " Edges" << endl;
    if(G.adjcent(one,two)) {
        cout << "One is adjcent to two and everything is fine." << endl;
    }
    if(!G.adjcent(zero,one)) {
        cout << "Zero is not adjacent to one and everything is fine." << endl;
    }


    one_number_two = *one;
    
    cout << *zero << endl;
    cout << *one << endl;
    cout << one_number_two << endl;

    if( one_number_two == *zero) {
        cout << "The world is wrong" << endl;
    }
    
    if( one_number_two != *zero) {
        cout << "The world is ok" << endl;
    }
    return 0;
}
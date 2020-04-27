#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Edge.h"
#include "Graph.h"
#include "graph_algo.h"
#include "Vertex.h"

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::shared_ptr;

typedef Vertex<string> v_type;
typedef shared_ptr<Vertex<string>> vp_type;
typedef Edge<Vertex<string>, int> e_type;
typedef shared_ptr<Edge<Vertex<string>, int>> ep_type;
typedef Graph<v_type, e_type> g_type;

vector<vp_type> make_vertices(const vector<string> &names) {
    vector<vp_type> vertices;
    for(string name : names) {
        vertices.push_back(vp_type(new v_type(name) ) );
    }
    return vertices;
}

vector<ep_type> make_edges(const vector<vp_type> &v, const vector<pair<int,int>> &connections) {
    vector<ep_type> edges;    
    for(auto edge : connections) {
        edges.push_back(ep_type(new e_type(v[edge.first],v[edge.second],1)));
    }
    return edges;
}

int main() {

    vector<string> names = {"A","B","C","D","E","F","G","H"};
    vector<pair<int,int>> connections;
    connections.push_back(make_pair(0,1));
    connections.push_back(make_pair(0,2));
    connections.push_back(make_pair(0,3));
    connections.push_back(make_pair(1,2));
    connections.push_back(make_pair(1,4));
    connections.push_back(make_pair(2,3));
    connections.push_back(make_pair(2,4));
    connections.push_back(make_pair(2,5));
    connections.push_back(make_pair(3,5));
    connections.push_back(make_pair(3,7));
    connections.push_back(make_pair(4,6));
    connections.push_back(make_pair(5,6));
    connections.push_back(make_pair(6,7));

    vector<vp_type> vertices = make_vertices(names);
    vector<ep_type> edges = make_edges(vertices, connections);

    g_type G(vertices, edges);

    cout << "G has " << G.numVertices() << " vertices" << endl;
    cout << "G has " << G.numEdges() << " edges" << endl;

    G.print();

    cout << "BFS G" << endl;
    BFS(G);
    cout << "BFS G Done" << endl;

    cout << "Vertices Adj to " << *vertices[0] << endl;
    for(auto v : G.getListAdj(vertices[0])) {
        cout << *v << endl;
    }

    return 0;
}
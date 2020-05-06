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

vector<ep_type> make_edges(const vector<vp_type> &v, const vector<pair<int,int>> &c,
    const vector<int> &weights) {

    vector<ep_type> edges;
    for(size_t i = 0; i < c.size(); ++i) {
        edges.push_back( ep_type( new e_type( v[c[i].first], v[c[i].second], weights[i]) ) );
    }
    return edges;
}

g_type makeGraph(vector<string> &names, vector<pair<int,int>> &connections,
            vector<vp_type> &v, vector<ep_type> &e, const vector<int> &weights) {
    v =  make_vertices(names);
    e = make_edges(v, connections, weights);

    return g_type(v, e);
}

g_type makeGraphOne(vector<vp_type> &v, vector<ep_type> &e) {
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
    vector<int> weights = {1,2,3,4,5,6,1,2,3,4,5,6,1};

    return makeGraph(names, connections, v, e, weights);
}

g_type makeGraphTwo(vector<vp_type> &v, vector<ep_type> &e) {
    vector<string> names = {"A","B","C","D","E","F"};
    vector<pair<int,int>> connections;
    vector<int>w;
    connections.push_back(make_pair(0,1));
    w.push_back(2);
    connections.push_back(make_pair(0,3));
    w.push_back(17);
    connections.push_back(make_pair(0,5));
    w.push_back(16);
    connections.push_back(make_pair(1,2));
    w.push_back(15);
    connections.push_back(make_pair(1,3));
    w.push_back(5);
    connections.push_back(make_pair(2,3));
    w.push_back(13);
    connections.push_back(make_pair(2,4));
    w.push_back(11);
    connections.push_back(make_pair(3,4));
    w.push_back(8);
    connections.push_back(make_pair(3,5));
    w.push_back(9);
    connections.push_back(make_pair(4,5));
    w.push_back(12);

    return makeGraph(names, connections, v, e, w);
}

int main() {
    vector<vp_type> vertices_G;
    vector<ep_type> edges_G;
    g_type G = makeGraphOne(vertices_G, edges_G);

    vector<vp_type> vertices_G2;
    vector<ep_type> edges_G2;
    g_type G2 = makeGraphTwo(vertices_G2, edges_G2);


    cout << "G has " << G.numVertices() << " vertices" << endl;
    cout << "G has " << G.numEdges() << " edges" << endl;
    G.print();
    cout << "--------------------" << endl;

    cout << "BFS G" << endl;
    auto labeled_edges = BFS(G);
    cout << "BFS G Done" << endl;
    cout << "--------------------" << endl;

    for(auto e : labeled_edges ) {
        if(e.second == DISCOVERY_EDGE) {
            cout << "Discovery Edge " << *(e.first) << endl;
        } else if (e.second == CROSS_EDGE) {
            cout << "Cross Edge " << *(e.first) << endl;
        } else {
            cout << "WTF Happened with " << *(e.first) << endl;
        }
    }
    cout << "--------------------" << endl;

    cout << "DijkstraAlgorithm on G starting at " << *vertices_G[0] << endl; 

    auto distances = DijkstraAlgorithm(G,vertices_G[0]);

    for(auto vert : distances) {
        cout << *(vert.first) << " : " << (vert.second) << endl;
    }
    cout << "--------------------" << endl;

    cout << "Run Prim's Algoirth on G2 starting at " << *vertices_G2[0] << endl;
    g_type MST_G2 = PrimsAlgorithm(G2, vertices_G2[0]);

    return 0;
}
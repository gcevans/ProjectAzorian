#include <iostream>
#include <string>

#include "Vertex.h"
#include "Edge.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    Vertex<string> zero("zero");
    Vertex<string> one("one");
    Vertex<string> one_number_two;
    Edge<Vertex<string>, int> zero_one_edge(&zero, &one, 1);

    cout << "Edge Zero One" << endl;
    zero_one_edge.print();
    cout << endl;

    one_number_two = one;
    
    cout << zero << endl;
    cout << one << endl;
    cout << one_number_two << endl;

    if( one_number_two == zero) {
        cout << "The world is wrong" << endl;
    }
    
    if( one_number_two != zero) {
        cout << "The world is ok" << endl;
    }

    return 0;
}
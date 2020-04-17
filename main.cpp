#include <iostream>
#include <string>

#include "Vertex.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    Vertex<string> zero("zero");
    Vertex<string> one("one");
    Vertex<string> one_number_two;

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
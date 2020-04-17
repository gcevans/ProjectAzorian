#pragma once
#include<ostream>

template<typename D>
class Vertex{
private:
    D data_;

public:
    Vertex(const D& data = D()) : data_(data) {}

    D getData() const;
    bool operator==(const Vertex &rhs) const;
};

template<typename D>
std::ostream & operator<<(std::ostream &os, const Vertex<D> &v);

template<typename D>
bool operator!=(const Vertex<D> &lhs, const Vertex<D> &rhs);

#include "Vertex.hpp"
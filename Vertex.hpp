#include"Vertex.h"

template<typename D>
D Vertex<D>::getData() const {
    return data_;
}

template<typename D>
bool Vertex<D>::operator==(const Vertex &rhs) const {
    return (data_ == rhs.data_);
}

template<typename D>
std::ostream & operator<<(std::ostream &os, const Vertex<D> &v){
    os << "< " << v.getData() << " >";

    return os;
}

template<typename D>
bool operator!=(const Vertex<D> &lhs, const Vertex<D> &rhs) {
    return !(lhs == rhs);
}

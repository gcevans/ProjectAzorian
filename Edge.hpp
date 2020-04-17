#include <iostream>

template <typename V, typename W>
Edge<V,W>::Edge(V *end0, V *end1, const W &weight) {
    weight_ = weight;
    ends_[0] = end0;
    ends_[1] = end1;
}

template <typename V, typename W>
void Edge<V,W>::print() {
    std::cout << *ends_[0] << " - " << weight_ << " - " << *ends_[1];
}


#include <iostream>

template <typename V, typename W>
Edge<V,W>::Edge(shared_ptr<V> end0, shared_ptr<V> end1, const W &weight) {
    weight_ = weight;
    ends_.first = end0;
    ends_.second = end1;
}

template <typename V, typename W>
void Edge<V,W>::print() {
    std::cout << *ends_.first << " - " << weight_ << " - " << *ends_.second;
}


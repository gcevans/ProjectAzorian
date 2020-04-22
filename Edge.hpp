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

template <typename V, typename W>
W Edge<V,W>::weight() const {
    return weight_;
}

template <typename V, typename W>
const pair<shared_ptr<V>, shared_ptr<V>> &Edge<V,W>::ends() const {
    return ends_;
}

template<typename V,typename W>
std::ostream & operator<<(std::ostream &os, const Edge<V,W> &e) {
    os << *(e.ends().first);
    os << " - " << e.weight() << " - " ;
    os << *(e.ends().second);

    return os;
}

#include "adjacency_weight_list.h"


const double adjacency_weight_list::DEFAULT_EXISTANCE_CONNECTION_VALUE = 1.0;
const double adjacency_weight_list::DEFAULT_NON_EXISTANCE_CONNECTION_VALUE = 0.0;


adjacency_weight_list::adjacency_weight_list(const adjacency_weight_list & another_matrix) {
    m_adjacency = another_matrix.m_adjacency;
}


adjacency_weight_list::adjacency_weight_list(adjacency_weight_list && another_matrix) {
    m_adjacency = std::move(another_matrix.m_adjacency);
}


adjacency_weight_list::adjacency_weight_list(const size_t node_amount) : m_adjacency(node_amount) { }


adjacency_weight_list::~adjacency_weight_list(void) { }


void adjacency_weight_list::set_connection(const size_t node_index1, const size_t node_index2) {
    m_adjacency[node_index1].insert( { node_index2, DEFAULT_EXISTANCE_CONNECTION_VALUE } );
}


void adjacency_weight_list::erase_connection(const size_t node_index1, const size_t node_index2) {
    m_adjacency[node_index1].erase(node_index2);
}


bool adjacency_weight_list::has_connection(const size_t node_index1, const size_t node_index2) const {
    const std::unordered_map<size_t, double> & node_neighbors = m_adjacency[node_index1];

    if (node_neighbors.find(node_index2) != node_neighbors.end()) {
        return true;
    }

    return false;
}


void adjacency_weight_list::get_neighbors(const size_t node_index, std::vector<size_t> & node_neighbors) const {
    node_neighbors.clear();
    node_neighbors.reserve(m_adjacency[node_index].size());

    for (auto index_neighbor : m_adjacency[node_index]) {
        node_neighbors.push_back(index_neighbor.first);
    }
}


void adjacency_weight_list::set_connection_weight(const size_t node_index1, const size_t node_index2, const double weight) {
    std::unordered_map<size_t, double> & node_neighbors = m_adjacency[node_index1];

    if (weight > 0) {
        node_neighbors[node_index2] = weight;
    }
    else {
        node_neighbors.erase(node_index2);
    }
}


double adjacency_weight_list::get_connection_weight(const size_t node_index1, const size_t node_index2) const {
    const std::unordered_map<size_t, double> & node_neighbors = m_adjacency[node_index1];
    const std::unordered_map<size_t, double>::const_iterator connection_iterator = node_neighbors.find(node_index2);

    if (connection_iterator != node_neighbors.end()) {
        return connection_iterator->second;
    }

    return DEFAULT_NON_EXISTANCE_CONNECTION_VALUE;
}
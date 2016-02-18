#ifndef _ADJACENCY_H_
#define _ADJACENCY_H_

#include <vector>

/***********************************************************************************************
*
* @brief   Abstract class of the adjacency collection that provides interface to control collection.
*
***********************************************************************************************/
class adjacency_collection {
public:
    /***********************************************************************************************
    *
    * @brief   Establishes one-way connection from the first node to the second in adjacency collection.
    *
    * @param[in]  node_index1: index of node in the collection that should be connected with another.
    * @param[in]  node_index2: index of another node in the collection that should be connected with
    *              the node defined by the first argument 'node_index1'.
    *
    ***********************************************************************************************/
    virtual void set_connection(const size_t node_index1, const size_t node_index2) = 0;

    /***********************************************************************************************
    *
    * @brief   Removes one-way connection from the first node to the second in adjacency collection.
    *
    * @param[in]  node_index1: index of node in the collection that should be disconnected from another.
    * @param[in]  node_index2: index of another node in the collection that should be diconnected from
    *              the node defined by the first argument 'node_index1'.
    *
    ***********************************************************************************************/
    virtual void erase_connection(const size_t node_index1, const size_t node_index2) = 0;

    /***********************************************************************************************
    *
    * @brief   Checks existance of connection between specified nodes.
    *
    * @param[in]  node_index1: index of node in the collection.
    * @param[in]  node_index2: index of another node in the collection.
    *
    * @return  'true' - connection between the nodes exists, 'false' - connection does not exist.
    *
    ***********************************************************************************************/
    virtual bool has_connection(const size_t node_index1, const size_t node_index2) const = 0;

    /***********************************************************************************************
    *
    * @brief   Returns vector of indexes of neighbors of specified node in line with adjacency collection.
    *
    * @param[in]  node_index: index of node in the collection.
    * @param[out] node_neighbors: vector of indexes of neighbors of specified node.
    *
    ***********************************************************************************************/
    virtual void get_neighbors(const size_t node_index, std::vector<size_t> & node_neighbors) const = 0;
};



/***********************************************************************************************
*
* @brief   Abstract class of the adjacency collection that provides interface to control collection.
*
***********************************************************************************************/
class adjacency_weight_collection : public adjacency_collection {
public:
    /***********************************************************************************************
    *
    * @brief   Set weight of connection between nodes where zero value means lack of connection and
    *          non-zero means connection with specified weight.
    *
    * @param[in]  node_index1: index of node in the collection whose connection weight should be updated 
    *              with another node.
    * @param[in]  node_index2: index of another node in the collection.
    * @param[in]  weight: new value of weight of connection between the nodes.
    *
    ***********************************************************************************************/
    virtual void set_connection_weight(const size_t node_index1, const size_t node_index2, const double weight) = 0;

    /***********************************************************************************************
    *
    * @brief   Returns weight of one-way connection between specified nodes.
    *
    * @param[in]  node_index1: index of node in the collection whose connection weight should be 
    *              updated with another node.
    * @param[in]  node_index2: index of another node in the collection that is connected to the 
    *              first node.
    *
    * @return  Weight of one-way connection between specified nodes.
    *
    ***********************************************************************************************/
    virtual double get_connection_weight(const size_t node_index1, const size_t node_index2) const = 0;
};

#endif
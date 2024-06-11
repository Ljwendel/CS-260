#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <climits>

#include "graph_node.h"
#include "edge.h"

using namespace std;

class Graph
{
public:
    Graph() {}

    // add node
    // takes a single parameter "new_node" (pointer to node object)
    void add_node(GraphNode *new_node)
    {
        nodes.push_back(new_node); // adds element new_node to the 'nodes' vector
    }

    // add edge
    // takes a single parameter "new_edge" (pointer to edge object)
    void add_edge(Edge *new_edge)
    {
        // access source member of the new_edge object
        // add new_edge pointer to the neighbors vector of source
        new_edge->source->neighbors.push_back(new_edge);
    }

    // shortest path (Dijkstra's algorithm)
    // returns a vector of 'pair' objects where each pair consists of a GraphNode and an int
    // dijkstra() takes one argument: a pointer to the starting GraphNode
    vector<pair<GraphNode *, int>> dijkstra(GraphNode *start)
    {
        // create a hash table (distances) that maps each GraphNode to an int
        // store the shortest known distance to each node from start node
        unordered_map<GraphNode *, int> distances;

        // initializes 'distances' for each node
        for (GraphNode *node : nodes)
        {
            // distances to each node is infinity (INT_MAX)
            distances[node] = INT_MAX;
        }
        // start distance should be zero (distance to itself)
        distances[start] = 0;

        // lambda function 'compare' to compare pairs (left vs right)
        auto compare = [](pair<int, GraphNode *> left, pair<int, GraphNode *> right)
        { return left.first > right.first; };  // if 1st ele of left pair > 1st ele of right pair - return true
        // priority queue (min-heap) to store pairs (GraphNode & int)
        // ordered using 'compare'
        priority_queue<pair<int, GraphNode *>, vector<pair<int, GraphNode *>>, decltype(compare)> pq(compare);
        // push start node on top of priority queue (PQ) because distance is zero
        pq.push({0, start});

        // loop until PQ is empty
        while (!pq.empty())
        {
            // extract top node with smallest distance from PQ
            auto [current_distance, current_node] = pq.top(); // structured binding unpacks pair returned by 'pq.top()'
            // pop off PQ
            pq.pop();

            // if current distance > known/recorded distance:
            if (current_distance > distances[current_node])
                // skip this node
                continue;

            // iterate through each neighbor (edge connected) of current_node
            for (Edge *edge : current_node->neighbors)
            {
                GraphNode *neighbor = edge->destination;
                // calculate distance to neighboring node for each edge
                int distance = current_distance + edge->weight;

                // if new distance < known/recorded distance
                if (distance < distances[neighbor])
                {
                    // update distance
                    distances[neighbor] = distance;
                    // push new distance and node onto PQ
                    pq.push({distance, neighbor});
                }
            }
        }

        // declares a vector 'result' to store pair of (GraphNode and int)
        // int represents shortest distance from start node to GraphNode pointer
        vector<pair<GraphNode *, int>> result;
        // iterate over distances hash table
        for (auto &[node, distance] : distances) // unpack each pair from distances into 'node' and 'distance'
        {
            // push a new pair to the end of the result vector
            result.push_back({node, distance});
        }
        return result;
    }

    // minimum spanning tree (Prim's algorithm)
    // returns a vector of pointers to Edge objects
    vector<Edge *> prim()
    {
        // check if the graph has nodes
        if (nodes.empty())
            // if true, return empty vector
            return {};
        // inMST is a hash table to track if nodes are to be included in MST
        unordered_map<GraphNode *, bool> inMST; // track if included, True/False
        // vector to store edges that are part of the MST
        vector<Edge *> mst;

        // lambda function 'compare' to prioritize edges with smaller distances
        auto compare = [](pair<int, Edge *> left, pair<int, Edge *> right)
        { return left.first > right.first; };
        // PQ to store pairs (pointers to edges and edge weights) ordered with compare function
        priority_queue<pair<int, Edge *>, vector<pair<int, Edge *>>, decltype(compare)> pq(compare);

        // helper function
        // lambda function to add all edges associated with the node to PQ, if not in MST
        auto add_edges = [&pq, &inMST](GraphNode *node)
        {
            // node included in MST = true
            inMST[node] = true;
            // for each Edge pointer in the neighbors vector of node
            for (Edge *edge : node->neighbors)
            {
                // if destination node of the edge is not in MST
                if (!inMST[edge->destination])
                {
                    // then add edge pair into PQ
                    pq.push({edge->weight, edge});
                }
            }
        };

        // Start with the first node
        // add edges to PQ
        add_edges(nodes[0]);

        // loop until PQ is empty and MST contains 'n-1' edges
        while (!pq.empty() && mst.size() < nodes.size() - 1)
        {
            // extracts top element of PQ (weight and pointer to Edge)
            auto [weight, edge] = pq.top(); // structured binding
            pq.pop(); // removes element

            // if destination node is already in MST (true in the inMST map)
            if (inMST[edge->destination])
                // skip current iteration
                continue;

            // edge is added to the MST
            mst.push_back(edge);
            // mark destination node as included in MST
            // add all its edges (not yet in MST) to the PQ
            add_edges(edge->destination);
        }

        return mst;
    }

    // function to print current nodes in the graph
    void print_nodes()
    {
        cout << "\nCurrent nodes in the graph:" << endl;
        // iterate over elements in nodes vector
        for (GraphNode *node : nodes)
        {
            // access 'name' member of 'GraphNode' pointed to by 'node' and print
            cout << node->name << endl;
        }
    }

private:
    // vector to store pointers to GraphNode objects
    vector<GraphNode *> nodes;
};

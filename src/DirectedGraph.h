#ifndef STACK_DIRECTEDGRAPH_H
#define STACK_DIRECTEDGRAPH_H

#include <map>
#include <set>
#include <vector>
#include "SingleLinkedList.h"
#include "LinkedStack.h"

using namespace std;

struct Edge {
    int src;
    int dest;
};

class DirectedGraph {
private:
    // A node is represented with a map entry
    // The key of the map entry is the node value
    // The value of the map entry is the "neighbours" of this node.
    // Here a node B is considered a "neighbour" of a node A when there is a edge that goes from A to B
    map<int, SingleLinkedList<int> *> nodes;


    void topologySort(int val, LinkedStack<int> &, set<int> &);

    bool inSet(set<int> & theSet, int val) {
        set<int>::iterator i;
        for (i = theSet.begin(); i != theSet.end(); ++i) {
            if (*i == val) {
                return true;
            }
        }
        return false;
    }

public:
    explicit DirectedGraph(Edge *edges, int size);

    void printGraph();

    virtual ~DirectedGraph();

    vector<int> *topologySort();

    vector<int> sort;
};

#endif //STACK_DIRECTEDGRAPH_H

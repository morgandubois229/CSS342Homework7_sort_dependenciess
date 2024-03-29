#include "DirectedGraph.h"
#include <iostream>
#include <algorithm>

DirectedGraph::DirectedGraph(Edge *edges, int size) {
    for (int i = 0; i < size; i++) {
        int src = edges[i].src, dest = edges[i].dest;
        if (nodes.count(src) == 0) {
            nodes[src] = new SingleLinkedList<int>();
        }
        nodes[src]->add(dest);
        if (nodes.count(dest) == 0) {
            nodes[dest] = new SingleLinkedList<int>();
        }
    }
}

DirectedGraph::~DirectedGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        delete (*it).second;
    }
}

void DirectedGraph::printGraph() {
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        printf("node(%d) has edges: ", (*it).first);
        for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
            printf("%d ", (*itl));
        }
        printf("\n");
    }
}

vector<int> *DirectedGraph::topologySort() {
	// homework
	// the return here is a placeholder. replace with your own code

	LinkedStack<int> theStack;

	set<int> theSet;

    map<int, SingleLinkedList<int> *>::iterator it;

	for (it = this->nodes.begin(); it != this->nodes.end(); ++it) {
	    if (!inSet(theSet, it->first)) {
	        topologySort(it->first, theStack, theSet);
	    }
	}

	while(!theStack.isEmpty()) {
	    this->sort.push_back(theStack.peek());
	    theStack.pop();
	}

    bool doFlip = false;


    for(int i = 0; i < this->nodes.size(); i++) {
        vector<int> aVector = this->nodes[i]->toVector();
        for (int k = 0; k < aVector.size(); k++) {
            if (this->sort[0] == aVector[k]) {
                doFlip = true;

            }
        }
    }

    if (doFlip) {
        std::reverse(this->sort.begin(), this->sort.end());
    }



	return new vector<int>;
}

void DirectedGraph::topologySort(int val, LinkedStack<int> & theStack, set<int> & theSet) {

    theSet.insert(val);

    map<int, SingleLinkedList<int> *>::iterator i;
    for (i = this->nodes.begin(); i != this->nodes.end(); ++i)
        if (!inSet(theSet, i->first)) {
            topologySort(i->first, theStack, theSet);
        }

    theStack.push(val);
}

#ifndef GRAPH_H
#define GRAPH_H

#include "Project4b.h"
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Graph {
protected:
    map<string, Username*> usernames;

public:
    Graph();
    virtual ~Graph();

    void addEdge(const string &user2, const string &user1);
    virtual void BFS(const string &startV);
};

#endif // GRAPH_H

#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {}

Graph::~Graph() {
    for (auto &entry : usernames) {
        delete entry.second;
    }
}

void Graph::addEdge(const string &user2, const string &user1) {
    if (usernames.find(user1) == usernames.end()) {
        usernames[user1] = new Username(user1);
    }
    if (usernames.find(user2) == usernames.end()) {
        usernames[user2] = new Username(user2);
    }
    usernames[user1]->addFollowing(usernames[user2]);
    usernames[user2]->addFollower(usernames[user1]);

}

void Graph::BFS(const string &startV) {
}




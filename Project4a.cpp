#include "Project4a.h"
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

CentralityGraph::CentralityGraph() : rootAccount(nullptr) {}

void CentralityGraph::calcCentrality() {
    rootAccount = nullptr;

    for (const auto &entry : usernames) {
        Username* username = entry.second;
        int centrality = username->followers.size();

        if (!rootAccount || centrality > rootAccount->followers.size() ||
            (centrality == rootAccount->followers.size() && username->name < rootAccount->name)) {
            rootAccount = username;
        }
    }
}

string CentralityGraph::getUserRoot() const {
    return rootAccount ? rootAccount->name : "";
}

void CentralityGraph::BFS(const string &startV) {
    queue<pair<Username*, int>> frontierQueue;
    visitedDistances.clear();

    frontierQueue.push({usernames[startV], 0});
    visitedDistances.push_back({startV, 0});

    while (!frontierQueue.empty()) {
        auto [current, depth] = frontierQueue.front();
        frontierQueue.pop();

        if (depth >= 2) continue;

        vector<Username*> sortedFollowers = current->getSortedFollowers();
        for (Username* neighbor : sortedFollowers) {
            visitedDistances.push_back({neighbor->name, depth + 1});
            frontierQueue.push({neighbor, depth + 1});
        }
    }
}

void CentralityGraph::printResults(const string &userRoot) const {
    cout << "The root user is " << userRoot << ", with in-degree centrality of " << rootAccount->followers.size() << ".\n";
    cout << "There are " << usernames.size() << " users in the social network.\n";

    cout << userRoot << " (0)" << endl;

    vector<string> depthOneUsers;
    for (Username* user : usernames.at(userRoot)->getSortedFollowers()) {
        depthOneUsers.push_back(user->name);
    }
    sort(depthOneUsers.begin(), depthOneUsers.end());

    for (const string &depthOneUser : depthOneUsers) {
        cout << depthOneUser << " (1)" << endl;

        vector<string> depthTwoUsers;
        for (Username* user : usernames.at(depthOneUser)->getSortedFollowers()) {
            depthTwoUsers.push_back(user->name);
        }
        sort(depthTwoUsers.begin(), depthTwoUsers.end());

        for (const string &depthTwoUser : depthTwoUsers) {
            cout << depthTwoUser << " (2)" << endl;
        }
    }
}

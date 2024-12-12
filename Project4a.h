#ifndef PROJECT4A_H
#define PROJECT4A_H

#include "Graph.h"
#include <string>

using namespace std;

class CentralityGraph : public Graph {
private:
    Username* rootAccount;
    vector<pair<string, int>> visitedDistances;


public:
    CentralityGraph();

    void calcCentrality();
    string getUserRoot() const;
    void BFS(const string &startV) override;
    void printResults(const string &userRoot) const;
};

#endif // PROJECT4A_H

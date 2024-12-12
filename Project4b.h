#ifndef Project4b_h
#define Project4b_h

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Username {
public:
    string name;
    vector<Username*> followers;
    vector<Username*> following;

    Username();
    Username(const string &name);

    void addFollower(Username *follower);
    void addFollowing(Username *followed);

    static bool compareName(Username* name1, Username* name2);
    const vector<Username*>& getSortedFollowers();
};

#endif //Project4b_h
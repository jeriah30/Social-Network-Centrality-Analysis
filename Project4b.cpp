#include "Project4b.h"

using namespace std;

Username::Username() : name("") {}

Username::Username(const string &name) : name(name) {}

void Username::addFollower(Username *follower) {
    followers.push_back(follower);
}

void Username::addFollowing(Username *followed) {
    following.push_back(followed);
}

bool Username::compareName(Username* name1, Username* name2) {
    return name1->name < name2->name;
}

const vector<Username*>& Username::getSortedFollowers() {
    sort(followers.begin(), followers.end(), Username::compareName);
    return followers;
}
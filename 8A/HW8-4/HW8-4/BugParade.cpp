#include <vector>
#include "BugParade.h"

void BugParade::add(Bug* bug){
    bugs.push_back(bug);
}

vector<int> BugParade::moveAll(int distance){
    vector<int> result;
    for (int i = 0; i < bugs.size(); i++) {
        bugs.at(i)->move(distance);
        result.push_back(bugs.at(i)->getPosition());
    }
    return result;
}

#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(unordered_map<int, Employee*>& map, int id, int& sum) {
    sum += map[id]->importance;
    for(auto x: map[id]->subordinates) 
        dfs(map, x, sum);
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> map;
    for(auto x : employees)
        map[x->id] = x;
    int sum = 0;
    dfs(map, id, sum);
    return sum;
}
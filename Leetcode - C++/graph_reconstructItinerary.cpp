#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, multiset<string>> targets;
vector<string> route; 

vector<string> findItinerary(vector<vector<string>>& tickets) {
    for(auto ticket : tickets)
    	targets[ticket[0]].insert(ticket[1]);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

void visit(string airport) {
	while(targets[airport].size()) {
		string next = *targets[airport].begin();
		targets[airport].erase(targets[airport].begin());
		visit(next);
	}
	route.push_back(airport);
}

int main() {
	vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	vector<string> res = findItinerary(tickets);
	for(string s : res) {
		cout << s << " ";
	}
	cout << endl;
}
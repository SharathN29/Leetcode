// https://leetcode.com/problems/employee-free-time/

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        map<int, int> mp;
        
        for (const auto& v:schedule)
            for (const auto& itv:v)
                mp[itv.start] = max(mp[itv.start], itv.end);   
        
        vector<Interval> res;
        
        for (auto it = mp.begin(), nit=next(it); it != prev(mp.end()); ++it, ++nit)
            if (it->second >= nit->first) nit->second = max(it->second, nit->second);
            else res.push_back(Interval(it->second, nit->first));
        return res;
    }
};

// class Solution {
// public:
//     vector<Interval> employeeFreeTime(vector<vector<Interval>>& a) {
//         vector<Interval> res;
//         map<int, int> timeline;
//         for (int i = 0; i < a.size(); i++) {
//             for (int j = 0; j < a[i].size(); j++) {
//                 timeline[a[i][j].start]++;
//                 timeline[a[i][j].end]--;
//             }
//         }
//         int workers = 0;
//         for (pair<int, int> p : timeline) {
//             workers += p.second;
//             if (!workers) res.push_back(Interval(p.first, 0));
//             if (workers && !res.empty() && !res.back().end) res.back().end = p.first;
//         }
//         if (!res.empty()) res.pop_back();
//         return res;
//     }
// };


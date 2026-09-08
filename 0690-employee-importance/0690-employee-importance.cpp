/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*> mp) {
        int totalImp = mp[id]->importance;
        for (auto& subId : mp[id]->subordinates) {
            totalImp += dfs(subId, mp);
        }
        return totalImp;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto& employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id, mp);
    }
};
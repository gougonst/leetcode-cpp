#include "course_schedule_II.h"
#include <unordered_set>
#include <queue>

// No repeat prerequisite
// Couse may require multiple prerequisites
// The values in prerequisites are within [0, numCouses)

// There should not has any cycle in the tree
vector<int> Solution::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
    vector<bool> valid(numCourses, false);
    for (auto& prerequisite: prerequisites) {
        graph[prerequisite[0]].insert(prerequisite[1]);
    }

    for (int course = 0; course < numCourses; course++) {
        // DFS, if meet self, fail
        vector<bool> visited(numCourses, false);
        if (_dfs(graph, valid, visited, course)) {
            return {};
        }
    }

    queue<int> q;
    for (int course = 0; course < numCourses; course++) {
        if (graph[course].size() == 0) {
            q.push(course);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int course = q.front();
        ans.push_back(course);
        q.pop();
        for (int pre = 0; pre < numCourses; pre++) {
            if (graph[pre].find(course) != graph[pre].end()) {
                graph[pre].erase(course);
                if (graph[pre].size() == 0)
                    q.push(pre);
            }
        }
    }
    return ans;
}

bool Solution::_dfs(vector<unordered_set<int>>& graph, vector<bool>& valid, vector<bool> &visited, int cur) {
    visited[cur] = true;
    for (auto& prerequisite: graph[cur]) {
        if (visited[prerequisite]) {
            return false;
        }
        if (valid[prerequisite]) {
            return true;
        }
        if (_dfs(graph, valid, visited, prerequisite)) {
            return valid[prerequisite] = true;
        }
        else {
            return false;
        }
    }
    return false;
}

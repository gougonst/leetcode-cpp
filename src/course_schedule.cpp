#include "course_schedule.h"

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ancients[numCourses];
    vector<int> indegree(numCourses, 0);
    vector<int> ans;

    for (vector<int>& relation: prerequisites) {
        int child = relation[0];
        int parent = relation[1];
        ancients[child].push_back(parent);
        indegree[parent]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int child = q.front();
        q.pop();
        ans.push_back(child);

        for (int& parent: ancients[child]) {
            if (--indegree[parent] == 0) {
                q.push(parent);
            }
        }
    }
    return ans.size() == numCourses;
}

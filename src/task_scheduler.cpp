#include "task_scheduler.h"
#include <queue>

// Greedy, from higher frequency to lower frequency

// Heap
int Solution::leastInterval1(vector<char>& tasks, int n) {
    vector<int> taskFreq(26, 0);
    for (auto& task: tasks)
        taskFreq[task - 'A']++;

    priority_queue<int> pqFreq;
    for (auto& freq: taskFreq) {
        if (freq > 0)
            pqFreq.push(freq);
    }

    int interval = 0;
    while (!pqFreq.empty()) {
        int taskCount = 0;
        vector<int> nextCycle;
        for (int i = 0; i <= n && !pqFreq.empty(); i++) {
            if (pqFreq.top() > 1)
                nextCycle.push_back(pqFreq.top() - 1);
            pqFreq.pop();
            taskCount++;
        }
        for (auto& nextFreq: nextCycle)
            pqFreq.push(nextFreq);
        interval += (pqFreq.empty()) ? taskCount : n + 1;
    }
    return interval;
}

int Solution::leastInterval2(vector<char>& tasks, int n) {
    vector<int> taskFreq(26, 0);
    for (auto& task: tasks)
        taskFreq[task - 'A']++;

    sort(taskFreq.begin(), taskFreq.end());
    int maxFreq = taskFreq[25] - 1;
    int idleSlots = maxFreq * n;
    for (int i = 24; i >= 0 && taskFreq[i] > 0; i--) {
        // Choose the minimum value since maxFreq is the maximum frequency - 1;
        // there might be other tasks with the same maximum frequency as well.
        idleSlots -= min(maxFreq, taskFreq[i]);
    }
    return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
}

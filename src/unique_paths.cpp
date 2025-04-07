#include "unique_paths.h"
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> prevRow(n, 1);
    for (int r = 1; r < m; r++) {
        int prevCol = 1;
        for (int c = 1; c < n; c++) {
            prevRow[c] = prevRow[c] + prevCol;
            prevCol = prevRow[c];
        }
    }
    return prevRow[n - 1];
}

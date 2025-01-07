#include "first_bad_version.h"

int Solution::firstBadVersion(int n) {
    int l = 0;
    int r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

void Solution::setBadVersion(int version) {
    _badVersion = version;
}

bool Solution::isBadVersion(int version) {
    return version >= _badVersion;
}

#include <vector>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    TimeMap();
    void set(string key, string value, int timestamp);
    string get(string key, int timestamp);
private:
    unordered_map<string, vector<pair<int, string>>> _map;
};

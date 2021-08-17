#include <vector>
using namespace std;


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0, now_height = 0;
        for (auto &val : gain){
            now_height += val;
            max_height = (now_height > max_height? now_height: max_height);
        }
        return max_height;
    }
};
#include <vector>
#include <unordered_map>
using namespace std;

class mySolution1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
            n += getSum(nums, goal, i, nums.size());
        return n;
    }

    int getSum(vector<int>& nums, int goal, int begin, const int size){
        if(begin >= size || goal < 0)
            return 0;
        int n1 = 0, n2 = 0;
        if (nums[begin] == goal)
            n2 += 1;
        n1 += getSum(nums, goal - nums[begin], begin + 1, size);
        return n1 + n2;
    }
};

/*
    
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};


#include <vector>
#include <unordered_map>
using namespace std;

/*
    能运行，但是效率太低，实现思想便利数组，将后面的所有数看为一个数，本质仍为双循环。
*/
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
    难题为解决num为0时的效率问题。

    随着数组的便利。在数组[i-j]中, sum[j] - sum[i]的值若为goal，则[i-j]中的和为goal
    随着sum值不断增加，则cnt中的key不断增加(sum-goal)，若哈希表中sum-goal的值存在，则对应的值则为[i-j]
    中和为goal的个数。
*/
class Solution_1 {
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


/*
    滑动窗口思想
*/
class Solution_2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;
        int ret = 0;
        while (right < n) {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1];
                left1++;
            }
            sum2 += nums[right];
            while (left2 <= right && sum2 >= goal) {
                sum2 -= nums[left2];
                left2++;
            }
            ret += left2 - left1;
            right++;
        }
        return ret;
    }
};
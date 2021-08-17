#include <vector>
#include <math.h>
#include <algorithm>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;


namespace my1{ 
/*
    效率太低
*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto m = max_element(nums.begin(), nums.end());
        int cache = -1;
        double divisor = 1;
        for (; divisor <= *m; divisor++){
            int sum = 0;
            for (auto val : nums)
                sum += ceil((double)val / divisor);
            if (sum <= threshold){
                if(cache != -1){
                    if (threshold - sum >= cache || threshold - sum == 0)
                        return divisor - 1;
                }
                else
                    cache = threshold - sum;
            }
        }
        return divisor - 1;
    }
};

}




namespace stander{

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int total = 0;
            for (int num: nums) {
                total += (num - 1) / mid + 1;
            }
            if (total <= threshold) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

}
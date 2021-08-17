 from typing import List
 
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_height, now_height = 0, 0
        for val in gain:
            now_height += val
            max_height = max(max_height, now_height)
        return max_height
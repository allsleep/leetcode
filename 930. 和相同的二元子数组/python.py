class Solution:
    class table:
        def __init__(self) -> None:
            self._table = {}

        def get(self, key):
            try:
                return self._table[key]
            except Exception as e:
                return 0
             
        def hash(self, key):
            if key not in self._table:
                self._table.update({key: 1})
            else:
                self._table[key] += 1


    def numSubarraysWithSum(self, nums, goal) -> int:
        t = self.table()
        sum, res = 0, 0
        for val in nums:
            t.hash(sum)
            sum += val
            res += t.get(sum - goal)
        return res  
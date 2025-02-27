class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        max_reachable = 0

        for i in range(n):
            if i > max_reachable:
                return False

            max_reachable = max(max_reachable, i + nums[i])

            if max_reachable >= n-1:
                return True
        
        return True

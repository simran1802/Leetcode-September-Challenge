class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ans=0
        for i in range(32)[::-1]:
            ans <<= 1
            pre = {num >> i for num in nums}
            ans += any(ans^1 ^ p in pre for p in pre)
        return ans

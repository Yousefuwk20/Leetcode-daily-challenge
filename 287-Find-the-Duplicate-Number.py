class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dub = set()
        for num in nums:
            if num in dub:
                return num
            dub.add(num)
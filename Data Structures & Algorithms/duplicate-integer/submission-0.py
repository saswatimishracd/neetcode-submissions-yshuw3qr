class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # we define set
        seen = set()
        #we check if it's present in set
        for num in nums:
            if num in seen:
                return True
            seen.add(num)   
    
        return False

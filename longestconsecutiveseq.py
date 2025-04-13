class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        num_set = set(nums)  
        max_length = 0
        
        for num in num_set:
           
            if num - 1 not in num_set:
                current_num = num
                streak = 1
                

                while current_num + 1 in num_set:
                    current_num += 1
                    streak += 1
                
                max_length = max(max_length, streak)
        
        return max_length

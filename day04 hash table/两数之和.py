'''
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.
'''
def twosum(self, nums, target):
    hashmap = {}
    for i in range(len(nums)):
        hashmap[nums[i]] = i
    for i in range(len(nums)):
        complement = target - nums[i]
        if complement in hashmap and hashmap[complement] != i:
            return (hashmap[complement], i)
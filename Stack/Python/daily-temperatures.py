# Given an array of integers temperatures represents the daily temperatures, return an array answer
# such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
# If there is no future day for which this is possible, keep answer[i] == 0 instead.

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        result = [0]*n
        stack = deque() #a double ended queue that we are going to use as a stack
        
        i = 0
        while i<n:
            if not stack or temperatures[i] <= temperatures[stack[-1]]:
                stack.append(i) 
                i+=1
                continue
            
            t = stack.pop()
            result[t] = i-t
        
        return result
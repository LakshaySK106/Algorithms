class Solution:
    def trap(self, heights: List[int]) -> int:
        stack = []  # a decreasing stack
        total = 0
        for i, v in enumerate(heights):
            while stack and heights[stack[-1]] < v:
                popped_idx = stack.pop()
                if not stack:
                    break
                height = min(heights[stack[-1]], v) - heights[popped_idx]
                length = i - stack[-1] - 1
                total += height * length
            stack.append(i)
        return total
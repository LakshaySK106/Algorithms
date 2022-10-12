# You are given an integer array nums with no duplicates. A maximum binary tree can be
# built recursively from nums using the following algorithm:
#
# Create a root node whose value is the maximum value in nums.
# Recursively build the left subtree on the subarray prefix to the left of the maximum value.
# Recursively build the right subtree on the subarray suffix to the right of the maximum value.
# Return the maximum binary tree built from nums.

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        stack = []
        
        for num in nums:
            new_node = TreeNode(num)
            
            right_child = None
            while stack and stack[-1].val < num:
                node = stack.pop()
                node.right = right_child
                right_child = node
            
            new_node.left = right_child
            stack.append(new_node)
        
        root = None
        while stack:
            node = stack.pop()
            node.right = root
            root = node
        
        return root
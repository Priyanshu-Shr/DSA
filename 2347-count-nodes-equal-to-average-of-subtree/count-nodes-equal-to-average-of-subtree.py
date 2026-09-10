# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root: TreeNode):
        if(root == None):
            return (0,0)
        
        left = self.solve(root.left)
        right = self.solve(root.right)
        
        avg = (left[0] + right[0] + root.val)//(left[1] + right[1] + 1)

        if(avg == root.val):
            self.ans += 1
        return(left[0] + right[0] + root.val,left[1] + right[1] + 1)

    def averageOfSubtree(self, root: TreeNode) -> int:
        self.ans = 0
        self.solve(root)
        return self.ans
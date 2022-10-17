#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//this is inorder traversal which run O(N) and !! Sc is O(1)

/**
 * @1st case:- left node -->null 
 *          print (root) move (right)
 * @2nd case : before moving to left whichever is the right most guy on the left sub tree
 *              have connections to root 
 * 
 *          1
 *      2           3
 *  4       5
 *              6
 * 
 * dry run 
 * 1 have left node then we have to make thread right most guy to 1
 * 6--->1
 * root->left
 * then move left 
 * then node have left who is the last guy in left subtree will make thred to root 
 * like 4--->2
 * root-->left
 * 
 * left have null --case 1 4 will print root have now 2 
 * and  print root
 * 
 * Now where we go  --- go left we find a thread then we
 * need to diconnect the thread 
 * and move right 
 * 
 * 
 * 
 */ 
vector<int> getInorder(TreeNode* root)
{
    vector<int>inorder;
    TreeNode *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode *prev=cur->left;
            while(prev->right && prev->right!=cur)
            {
                prev=prev->right;
            }
            //exterme left subtree pe aa gye 

            if(prev->right==NULL)
            {
                //making thread 
                prev->right=cur;
                cur=cur->left;
            }
            else{
                //braking thread  printing current and moving right 
                prev->right=NULL;
                inorder.push_back(cur->val);
                cur=cur->right;
            }
        }
    }
}
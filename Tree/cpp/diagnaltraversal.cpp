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



vector<int> diagonal(TreeNode *root)
{
   // your code here
   queue<TreeNode* >q;
   q.push(root);
   vector<int>ans;
   while(!q.empty())
   {
       int size=q.size();
      
       for(int i=0; i<size; i++)
       {
           auto it =q.front();
           q.pop();
           
           while(it!=NULL)
           {
               if(it->left) q.push(it->left);
               ans.push_back(it->val);
               it=it->right;
           }
           
       }
   }
   return ans;
}
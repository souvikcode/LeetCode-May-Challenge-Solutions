/*
Problem Link: 
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

The main concept of the Problem is:
   First find the level of both the nodes x, y given in question and then check two conditions:
i> Level of x is equal to level of y
2> Parent of x not equal to parent of y
  If both this conditions evaluate to true then x is a cousin of y else not a cousin.
  The approach is two define a struct data type which will contain the level and parent of x and y after traversals from root node to the leaf.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    struct node
    {
     TreeNode *parent;
     int level;
    };
    
    void solve(TreeNode* root, int data, int level, node &res)
    {
        if(!root)
            return;
        if (root->left && root->left->val == data || root->right && root->right->val == data)
        {
            res.level = level;
            res.parent = root;
            return;
        }
        solve(root->left, data, level+1, res);
        solve(root->right, data, level+1, res);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        node x1, x2;
        solve(root, x, 0, x1);
        solve(root, y, 0, x2);
        return x1.level==x2.level && x1.parent!=x2.parent;
    }
};

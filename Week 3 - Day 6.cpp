/*
Use Inorder traversal to traverse through the whole Binary tree and store the nodes in a vector.
Since its a inoder traversal, as a result, the vector that we obtain is in sorted order;
Return the (k-1)th element from the vector.
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
    vector<int> v;
    void inorder(TreeNode* node)
    {
      if(node == NULL)
        return;
      inorder(node->left);
      v.push_back(node->val);
      inorder(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return v[k-1];
    }
};

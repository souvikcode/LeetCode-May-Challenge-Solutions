/*
Preorder traversal is given, we can find the inoder traversal from the preorder traversal by sorting the preorer traversal,
Then using the buildTree function, we can create BST.
build function is taken from: https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

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
    
  set<TreeNode*> s; 
  stack<TreeNode*> st; 
  
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder,int n) 
    {   
     TreeNode* root = NULL; 
    for (int pre = 0, in = 0; pre < n;)  
    { 
        TreeNode* node = NULL; 
        do
        { 
            node = new TreeNode(preorder[pre]); 
            if (root == NULL) 
            { 
                root = node; 
            } 
            if (st.size() > 0)  
            { 
                if (s.find(st.top()) != s.end()) 
                { 
                    s.erase(st.top()); 
                    st.top()->right = node; 
                    st.pop(); 
                } 
                else
                { 
                    st.top()->left = node; 
                } 
            } 
            st.push(node); 
        } while (preorder[pre++] != inorder[in] && pre < n); 
  
        node = NULL; 
        while (st.size() > 0 && in < n &&  st.top()->val == inorder[in])  
        { 
            node = st.top(); 
            st.pop(); 
            in++; 
        } 
  
        if (node != NULL)  
        { 
            s.insert(node); 
            st.push(node); 
        } 
      }  
  
      return root; 
    }
  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for(int i=0; i<preorder.size(); i++)
          inorder.push_back(preorder[i]);
        sort(inorder.begin(), inorder.end());
        TreeNode *root = buildTree(preorder, inorder, preorder.size());
        return root;
    }
};

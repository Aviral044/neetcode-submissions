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
    int height;
    int maxDepth(TreeNode* root) {
        height=1;
        if(!root){
            return 0;
        }
        height=dfs(root,0);
        return height;
    }
    int dfs(auto& root,int height)
    {
        if(root==nullptr)
        {
            return height;
        }
        height=height+1;
        return max(dfs(root->left,height),dfs(root->right,height));
    }
};

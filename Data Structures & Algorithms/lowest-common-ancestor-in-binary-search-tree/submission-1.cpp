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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=dfs(root,p,q);
        return res;
    }
    TreeNode* dfs(auto& node,auto& p,auto& q)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        if (p->val < node->val && q->val < node->val) {
            return dfs(node->left, p, q);      // both on the left
        }
        if (p->val > node->val && q->val > node->val) {
            return dfs(node->right, p, q);     // both on the right
        }
        return node; 
    }
};

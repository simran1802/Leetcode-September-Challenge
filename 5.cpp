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
    void dfs(TreeNode *root,vector<int> &v){
            if(root->left)
                dfs(root->left,v);
            v.push_back(root->val);
            if(root->right)
                dfs(root->right,v);
        }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> s1,s2,res;
        if(root1)
            dfs(root1,s1);
        if(root2)
            dfs(root2,s2);
        int pos1=0,pos2=0;
        while(pos1<s1.size() && pos2<s2.size()){
            if(s1[pos1] < s2[pos2])
                res.push_back(s1[pos1++]);
            else
                res.push_back(s2[pos2++]);
            
        }
        while(pos1<s1.size())
            res.push_back(s1[pos1++]);
        while(pos2<s2.size())
            res.push_back(s2[pos2++]);
        return res;
    }
};

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
    unordered_map<int, int>mp;
int preIdx = 0;
public:
TreeNode*build (vector<int>& preorder, int left, int right){

if(left > right){
    return NULL;
}

int rootValue = preorder[preIdx++];
TreeNode * root = new TreeNode(rootValue);

int rootIdx = mp[rootValue];

root->left = build(preorder, left, rootIdx-1);
root->right = build(preorder, rootIdx+1, right);

return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
       }

        return build(preorder, 0, inorder.size()-1);
    }
};

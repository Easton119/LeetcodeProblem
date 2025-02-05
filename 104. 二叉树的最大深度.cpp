#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int ans=0;
    void Search(TreeNode* root,int depth){
        if(root->left==nullptr&&root->right==nullptr){
            ans=max(ans,depth);
            return;
        }
        if(root->left!=nullptr)Search(root->left,depth+1);
        if(root->right!=nullptr)Search(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        Search(root,1);
        return ans;
    }
};
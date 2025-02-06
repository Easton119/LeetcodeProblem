#include<iostream>

using namespace std;

//翻转二叉树
//递归法：把左右子树的节点进行swap即可
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution{
public:
    void invert(TreeNode* root){
        if(root==nullptr)return;
        invert(root->left);
        invert(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    TreeNode* invertTree(TreeNode* root){
        invert(root);
        return root;
    }

};
int main(){

}
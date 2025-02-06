#include<iostream>
using namespace std;
/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。
培养递归思维，虽然往下分叉点越来越多，但是模式不变。
检查：
    左节点的左子树 与 右节点的右子树
    左节点的右子树 与 右节点的左子树
不过在每次处理的步骤要比之前的题多一点。
*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    bool check(TreeNode* l,TreeNode* r){
        if(l==nullptr&&r==nullptr){
            return true;
        }else if(l!=nullptr&&r!=nullptr){
            if(l->val!=r->val){
                return false;
            }
        }else{
            return false;
        }
        bool a,b;
        //左节点的左子树 与 右节点的右子树
        a = check(l->left,r->right);
        if(a==false)return false;
        //左节点的右子树 与 右节点的左子树
        b = check(l->right,r->left);
        if(b==false)return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};
int main(){

}
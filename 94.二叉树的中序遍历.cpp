#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
//1、递归法
class Solution {
public:
    vector<int> ans;
    void Search(TreeNode* root){
        if(root==nullptr)return;
        if(root->left!=nullptr){
            Search(root->left);
        }
        ans.push_back(root->val);
        if(root->right!=nullptr){
            Search(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Search(root);
        return ans;
    }
};
//2、进阶：迭代法
class Solution2 {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       stack<TreeNode*> Sta;
       Sta.push(root);
       TreeNode* cur = root;//实际上只是浅拷贝
       while(!Sta.empty()||cur!=nullptr){
           if(cur!=nullptr){
            Sta.push(cur);
            cur = cur->left;//左
           }else{
            cur = Sta.top();
            Sta.pop();
            ans.push_back(cur->val);//中
            cur=cur->right;//右
           }
       }
       return ans;
    }
};
int main(){

}
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 
 * 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
 * 你可以按任意顺序返回答案。
 * 
 * 1.暴力法：两重for循环
 * 2.先sort排序，后双指针
 * 3.用哈希法，即map<int,int>，
 *     考虑可能有重复值,所以用multimap<int,int> 存放<数值，下标>?
 * 但是根据题意来说每种输入只会对应一个答案,所以用map没问题，不用multimap
 */
// @lc code=start
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> vec;
        vector<int> vec = nums;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        
       
        int begin = 0,end=len-1;
        while(begin<=end){
            if(nums[begin]+nums[end]==target){
                break;
            }
            while(nums[begin]+nums[end]<target && begin<=end){
                begin++;
            }
            while(nums[begin]+nums[end]>target && begin<=end){
                end--;
            }
        }
       
        if(begin>=end){
            return {};
        }
        cout<<"test"<<endl;
        int f1=-1,f2=-1;
        for(int i=0;i<len;i++){
            if(vec[i]==nums[begin]&&f1==-1){
                f1 = i;
            }
            else if(vec[i]==nums[end]&&f2==-1){
                f2 = i;
            }
        }
        return {f1,f2};
    }
    vector<int> twoSum2(vector<int>& nums, int target) {
        // map<int,int> mp;
        multimap<int,int> mp2;
        //即使有重复的值，也不需要使用multimap
        //根据题意，只有一种答案，那么出现相同键的时候，把原来的覆盖掉没有关系的
        for(int i=0;i<nums.size();i++){
            // if(mp.count(target-nums[i])>0){
            //     //即存在对应的另一个值
            //     return {i,mp[target-nums[i]]};
            // }
            if(mp2.count(target-nums[i])>0){
                return {i,mp2.find(target-nums[i])->second};
            }
            mp2.insert({nums[i],i});
        }
        return {};
    }
};

int main(){
    Solution* sol = new Solution();

    vector<int> vec={3,3};

    sol->twoSum(vec,6);
}
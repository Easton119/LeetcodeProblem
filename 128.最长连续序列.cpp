#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
/*
Q:
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

方法1：使用sort可以AC,不过时间复杂度为O(nlogn)

方法2：使用正宗的哈希表解法
    unordered_set (无序集合,去重,基于链式哈希表)
    哈希表的增删查O(1)在时间复杂度上很有优势！！！！！
    官方解法的剪枝确实很好
    两层循环，实际上时间复杂度是O(2n)->O(n)！！！！！

    不过O(2n)在数据量不够的情况下确实会表现得比O(nlogn)稍差
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int it = 1;
        int len = 1;
        int max_len = 1;
        if(nums.size()==0){
            return 0;
        }
        while(it<nums.size()){
            if(nums[it]==nums[it-1]+1){
                len++;
                max_len = max(max_len,len);
            }else if(nums[it]!=nums[it-1]){
                len=1;
            }
            it++;
        }
        return max_len;
    }
    int longestConsecutive2(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        unordered_set<int> set;
        for(int num:nums){
            set.insert(num);
        }
        int len = 1;
        int current =0;
        int max_len = 1;
        for(int num:set){
            if(set.count(num-1)==0){
                //如果当前值是某段序列的最小值,开始计数
                len=1;
                current=num;
                while(set.count(current+1)){
                    len++;
                    current++;
                    max_len = max(max_len,len);
                }
            }
        }
        
        return max_len;
    }
};
int main(){
    vector<int> vec{0,3,7,2,5,8,4,6,0,1};
    Solution* sol = new Solution;
    int ans = sol->longestConsecutive(vec);
    cout<<ans<<endl;
}
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include <typeinfo>
using namespace std;

/*
Q:给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

/*
方法1：令特征值为按字符大小升序排列后得到的字符串，例如ate,eat,tea的特征值为aet，
存入一个多重映射表中multimap<string,string>，以特征值为key,以原本值为value
然后遍历映射表，每个key取出其value集合

这道题对于语言知识上的应用 大于 思维上的难度
注意点：
1、遍历多重映射表的每个key所对应的value集合：
    使用 equal_range 获取当前键的所有值的范围 auto range = mp.equal_range(key)
    for(auto it4=range.first;it4!=range.second;it4++){
        其中 it4->second 为value值
    }
2、cstring提供memset 将所有元素设置为 0:memset(s,0,sizeof(s));
3、strcpy(s,tmp.c_str()); c_str()将string类型转换为const char*类型,strcpy进行复制
    然后s进行排序时注意排序的范围，sort(s,s+tmp.length());
*/

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto it = strs.begin();
        multimap<string,string> mp;
        vector<vector<string>> ans;
        while(it!=strs.end()){
            string tmp = *it;
            char s[105]="a";
            memset(s,0,sizeof(s));
            strcpy(s,tmp.c_str());//c_str()转换为const char*类型,strcpy复制

            sort(s,s+tmp.length());
            string tmp2 = s;
            mp.insert({tmp2,*it});
            it++;
        }
        auto it2= mp.begin();
        while(it2!=mp.end()){
            string key = it2->first;
            vector<string> tmpvec;
            // cout<<"key:"<<key<<endl;
             // 使用 equal_range 获取当前键的所有值的范围
            auto range = mp.equal_range(key);
            for(auto it4=range.first;it4!=range.second;it4++){
                // cout<<it4->second<<" ";
                tmpvec.push_back(it4->second);
            }
            // cout<<endl;
            ans.push_back(tmpvec);
            it2 = range.second;
        }
        return ans;
    }
};

int main(){

    vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> vec2 = Solution::groupAnagrams(vec);

}
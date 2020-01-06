# 题目链接
[leetcode 49](https://leetcode-cn.com/problems/group-anagrams/)

# 原文
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。  
示例:  
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],  
输出:
[  
  ["ate","eat","tea"],  
  ["nat","tan"],  
  ["bat"]  
]  
说明：  
所有输入均为小写字母。
不考虑答案输出的顺序。

# 思路
- ### **哈希表-迭代器**
  寻找字母异位词，特点时字母相同但排序不同，所以首先考虑将不同排序的字符组合重新排序，则所有排列不同的字符串排序后全都相同了。最开始不知道有多少个不同的异位词种类，所以直接给result不好解决，使用哈希表来记录，一旦检测到新的异位词种类，为对应的排序组合创建新的向量，并开始将成员放进去，所有的循环结束后将创建了足够的种类，且每个种类已经聚齐了对应的成员（在判断时，先将成员提取出来，再进行排序，为了不影响原始真正的成员你，排序以后的结果作为map的第一个元素）；最后将所有的map成员放进最后的result向量，首先创建遍历map的迭代器it（或者直接使用auto），格式见代码，将格式后加上::iterator，一定记得最后是or结尾不是er结尾，然后使用for循环遍历，中间it无法使用<只能使用!=，然后使用指针+.second进行访问，而不是直接使用.second，格式为(*it).second。48 70      
  (第二段代码使用auto来访问）68 76
- ### **哈希表-字符转向量**
  同样是使用哈希表，不同的是找到所有异位词的共同点不相同，上一种方法使用排序，使所有异位词打回原形，统一以后再分别归类，但如果不允许使用自带的sort函数，则开始考虑找寻别的异位词的相同点，发现既然异位词的字母完全相同，则对于26的字符的每个的数量也会一一对应的，于是设计向量代表26个字符的数量，对于每一个字符串计数其中每个字符的数量，则异位词再次被打回原形，将得到的向量作为哈希表的关键字，后面放入所有的成员，最后依然使用迭代器放入最后的数组，使用it直接用->访问成员变量。58 14    

# 代码
- C++ 哈希表-迭代器
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> hash_map;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            if(hash_map.find(str)==hash_map.end()){
                vector<string> temp;
                hash_map[str] = temp;
            }
            hash_map[str].push_back(strs[i]);
        }
        map<string,vector<string>>::iterator it;
        for(it=hash_map.begin();it!=hash_map.end();it++){
            result.push_back((*it).second);
        }
        return result;
    }
};
```
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> hash_map;
        for(int i=0;i<strs.size();i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            // if(hash_map.find(str)==hash_map.end()){
            //     vector<string> temp;
            //     hash_map[str] = temp;
            // }
            hash_map[str].push_back(strs[i]);
        }
        //map<string,vector<string>>::iterator it;
        // for(auto it=hash_map.begin();it!=hash_map.end();it++){
        //     result.push_back(it->second);
        // }
        for(auto& it:hash_map){
            result.push_back(it.second);
        }
        return result;
    }
};
```
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<int> vec(26,0);
        vector<vector<string>> result;
        map<vector<int>,vector<string>> hash;
        for(int i=0;i<strs.size();i++){
            change_to_vec(strs[i],vec);
            hash[vec].push_back(strs[i]);
        }
        for(auto it=hash.begin();it!=hash.end();it++){
            result.push_back(it->second);
        }
        return result;
    }
private:
    void change_to_vec(string& str,vector<int>& vec){
        for(int i=0;i<26;i++)  vec[i] = 0;
        for(int i=0;i<str.length();i++){
            vec[str[i]-'a']++;
        }
    }
};
```
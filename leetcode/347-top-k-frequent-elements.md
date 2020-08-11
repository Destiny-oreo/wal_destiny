# 题目链接
[leetcode 347](https://leetcode-cn.com/problems/top-k-frequent-elements/)

# 原文
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。   
示例 1:   
输入: nums = [1,1,1,2,2,3], k = 2   
输出: [1,2]   
示例 2:  
输入: nums = [1], k = 1  
输出: [1]  
提示：  
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。  
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。  
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。  
你可以按任意顺序返回答案。  
  
# 思路
- ### **哈希表-最小堆**
  首先需要统计每个数字出现的次数，使用的是哈希表，然后对哈希表中的次数找到前k个，使用最小堆，其中次数以及对应的数字都需要用到，所以最小堆的元素使用pair<int,int>来记录，对于哈希表的遍历使用auto& it:hash，访问第一二个元素使用it.second等，然后放入到最小堆里，最后将最小堆的所有元素放入result向量里，可使用`reverse(result.begin(),result.end());`。46 36

# 代码
- C++ 哈希表-最小堆
```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto& it:hash){
            if(pq.size()<k){
                pq.push(make_pair(it.second,it.first));
            }
            else{
                if(it.second>pq.top().first){
                    pq.pop();
                    pq.push(make_pair(it.second,it.first));
                }
            }
        }
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
```

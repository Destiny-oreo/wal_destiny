# 题目链接
[leetcode 56](https://leetcode-cn.com/problems/merge-intervals/)

# 原文
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

# 思路
- ### **数组排序**
  最简单的解法，一个一个遍历原始区间时先进行排序，确保前面一个放入result的区间的起始位不大于当前位的起始点；接着开始遍历区间集合，首先先放入第一个区间，后面区间再开始判断，由于已经进行了排序，所以对于后面一个区间，一共2个可能性，1是起始点≤前面区间的结束点，此时区间重叠（重叠时也包含了完全覆盖、完美衔接、部分重叠三种，后面两种情况需要进行更新），所以再次进行判断，如果结束点大于前面区间的结束点，说明是后面两种情况，更新前面区间的结束点即可（使用result.back()[1]访问前面一个区间的结束点），2是起始点＞前面区间的结束点，此时直接把新的区间添加进结果数组即可。39 5
- ### **数组排序**
  仅仅在循环时判断的是否为空取出来，少了一个if的过程便节省了很多时间，说明这个思路已经是很好的了，花时间的基本全在排序上，使用库函数sort是最快地快速排序，时间上从32ms优化到20毫秒已经从39%进步到91%，剩下需要优化的是空间复杂度。91 5

# 代码
- C++ 数组排序
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(result.size()==0){
                result.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0]<=result.back()[1]){
                if(intervals[i][1]>result.back()[1])
                    result.back()[1] = intervals[i][1];
            }
            else    result.push_back(intervals[i]);
        }
        return result;
    }
};
```
- C++ 数组排序
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty())   return result;
        sort(intervals.begin(),intervals.end());
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=result.back()[1]){
                if(intervals[i][1]>result.back()[1])
                    result.back()[1] = intervals[i][1];
            }
            else    result.push_back(intervals[i]);
        }
        return result;
    }
};
```
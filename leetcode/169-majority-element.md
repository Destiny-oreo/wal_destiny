# 题目链接
[leetcode 169](https://leetcode-cn.com/problems/majority-element/)

# 原文
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。  
你可以假设数组是非空的，并且给定的数组总是存在多数元素。  
示例 1:  
输入: [3,2,3]  
输出: 3  
示例 2:  
输入: [2,2,1,1,1,2,2]  
输出: 2  

# 思路
- ### **摩尔投票法**
  核心是对拼消耗法，由于题目中目标元素在数组中出现次数大于一半，所以可以使用类似诸葛争霸的游戏，即使一对一的消耗最后剩下的也一定是多数元素，所以每遇到一个元素，判断和前面一个元素是否相同，相同继续++，否则--，但计数等于0时，重新将新的值符合目标值，这样的结果如果全部的目标数在前面，则后面所有数合起来也无法打败多数元素，如果前面没有多数元素，说明其他元素在相互抵消，更容易找到多数元素。100 100
- ### **哈希表**
  使用哈希表记录每一个元素出现的次数，当次数超过一半时直接break返回即可，是比较容易想到的方法。34 100

# 代码
- C++ 摩尔投票法
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0],count = 1;
        for(int i=1;i<nums.size();i++){
            if(result == nums[i]){
                count++;
            }
            else{
                count--;
                if(count==0){
                    result = nums[i];
                    count = 1;
                }
            }
        }
        return result;
    }
};
```
- C++ 哈希表
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> maps;
        int n = nums.size();
        int result = nums[0];
        for(int i=0;i<n;i++){
            maps[nums[i]]++;
            if(maps[nums[i]]>n/2){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
```

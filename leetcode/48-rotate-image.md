# 题目链接
[leetcode 48](https://leetcode-cn.com/problems/rotate-image/)

# 原文
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：  
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。  
示例 1:  
给定 matrix =   
[  
  [1,2,3],  
  [4,5,6],  
  [7,8,9]  
],    
原地旋转输入矩阵，使其变为:  
[  
  [7,4,1],  
  [8,5,2],  
  [9,6,3]  
]  
示例 2:  
给定 matrix =  
[  
  [ 5, 1, 9,11],  
  [ 2, 4, 8,10],  
  [13, 3, 6, 7],  
  [15,14,12,16]  
],   

原地旋转输入矩阵，使其变为:  
[  
  [15,13, 2, 5],  
  [14, 3, 4, 1],  
  [12, 6, 8, 9],  
  [16, 7,10,11]  
]  

# 思路
- ### **找规律**
  总体需要将一个数组顺时针旋转，没有这样一个函数，所以分解为每个对应位置的四个像素点进行旋转，四个点相当于三次相互交换，所以首先需要完成一个两两交换像素点的函数，参数必须为引用即可以直接改变原向量的值；接着进行寻找规律，首先最外一圈对应点进行旋转，然后向内缩一圈继续同样的操作，所以为两层循环，对于第一行，交换列数-1即可，因为最后一列已经和第一列交换过，赋值行列时变为n-1，外层循环0-row（因为每次交换为最外面一圈，所以相当于行数首尾都在减少，此时i++同时row--），内层循环为j=i，同样col也要每次进行--才能平衡；每次循环，交换四个点，寻找四个点的对应关系即可，第一个点为(i,j)，一次找到其余三个点的坐标（用i和j表示），其中需要用到行数和列数时需要用n而不是row和col，因为后者一直在改变。94 87

# 代码
- C++ 找规律
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0)    return;
        int n=matrix.size()-1;
        int row = n,col = n;
        for(int i=0;i<row;i++){
            for(int j=i;j<col;j++){
                int x1=i,y1=j;
                int x2=j,y2=n-i;
                int x3=n-i,y3=n-j;
                int x4=n-j,y4=i;
                swap(matrix,x1,y1,x2,y2);
                swap(matrix,x1,y1,x4,y4);
                swap(matrix,x4,y4,x3,y3);
            }
            row--;
            col--;
        }
    }
private:
    void swap(vector<vector<int>>& matrix,int x1,int y1,int x2,int y2){
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
    }
};
```
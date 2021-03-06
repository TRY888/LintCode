﻿/*
 * title：中等-510.最大矩形
 * desc:给你一个二维矩阵，权值为False和True，找到一个最大的矩形，使得里面的值全部为True，输出它的面积
 * e.g.:给你一个矩阵如下
 *      [
 *       [1, 1, 0, 0, 1],
 *       [0, 1, 0, 0, 1],
 *       [0, 0, 1, 1, 1],
 *       [0, 0, 1, 1, 1],
 *       [0, 0, 0, 0, 1]
 *      ]
 *      输出6
 */

class Solution {
public:
    /*
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maxHistogramBar(vector<int> &v)
    {
        int size = v.size();
        int max=0, temp=0, w;
        stack<int> s;
        for(int i=0; i<=size; i++)
        {
            int maxh = (i==size)?0:v[i];
            while(!s.empty() && v[s.top()] > maxh)
            {
                int h = v[s.top()];
                s.pop();
                if(s.empty())
                    w = i;
                else
                    w = i-1-s.top();
                temp = h * w;
                if(temp > max)
                    max = temp;
            }
            s.push(i);
        }
        return max;
    }
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        int max = 0, temp = 0;
        vector<int> v;
        v.resize(col);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                v[j] = (matrix[i][j]==0)?0:v[j]+1;
            }
            temp = maxHistogramBar(v);
            if(temp > max)
                max = temp;
        }
        return max;
    }
};
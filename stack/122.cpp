/*
 * title：中等-122.直方图最大矩形覆盖
 * desc:Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *      Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *      The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * e.g.:给出 height = [2,1,5,6,2,3]，返回 10
 */

class Solution {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
     
    int findmin(vector<int> &height,int x,int y){
        if(x==y)
            return x;
        int minh=x;
        for(int i=x+1;i<=y;i++)
        {
            if(height[minh]>height[i])
            minh=i;
        }
        return minh;
    }
    //2 1 5 6 2 3
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int maxh=0;
        stack<int> st; //存放递增高度序列的下标
        for(int i=0;i<=height.size();i++) //用i遍历全部数组
        {
            int nowh= (i == height.size()) ? 0 : height[i]; //若下标为height.size()时，其高度置为0
            while( !st.empty() && nowh <= height[st.top()] )
            //若当前的高度小于或等于栈顶的高度时
            {
                int h=height[st.top()]; //矩阵的高度为栈顶元素的高度
                ///////这个很重要////
                st.pop();               //将栈顶元素弹出
                //要先将栈顶元素弹出，因为若左边界元素是栈底元素长度要取数组全长
                //而不是当前长度到栈顶的长度
                int w;
    
                if(st.empty())      //若此时栈空
                    w=i;            //取全部长度，而不应该取
                else                //否则宽度为i-1-st.top();
                    w=i-1-st.top();
    
                maxh=max(maxh,w*h);     //记录下最大面积
            }//执行完这个循环后栈为空，或栈顶元素的高度小于i的高度
            st.push(i);              //将i再压入栈中
        }
        return maxh;
    }
};
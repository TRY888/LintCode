class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: the median of numbers
     */

    //两个堆，一个最大堆储存前一半数，一个最小堆储存后一半数，
    //插入次数是奇数时将值插入最大堆，是偶数时插入最小堆，
    //同时保证最大堆的最大值小于最小堆的最小值
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> res;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        for(int i=0; i<nums.size(); i++)
        {
            if(!(i&1)) // 插入次数为偶数
            {
                min_heap.push(nums[i]);
                int min = min_heap.top();
                min_heap.pop();
                max_heap.push(min);
            }
            else // 插入次数为奇数
            {
                max_heap.push(nums[i]);
                int max = max_heap.top();
                max_heap.pop();
                min_heap.push(max);
            }
            res.push_back(max_heap.top());
        }
        return res;

    }
};

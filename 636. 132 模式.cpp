class Solution {
public:
    /*
     * @param nums: a list of n integers
     * @return: true if there is a 132 pattern or false
     */

    //利用栈来实现（思路清晰的方法）
    bool find132pattern(vector<int> &nums) {
        // write your code here
        int third = INT_MIN;
        stack<int> s;
        for(int i=nums.size()-1; i>=0; --i)
        {
            if(nums[i] < third) return true;
            else
            {
                while(!s.empty() && nums[i] > s.top())
                {
                    third = s.top();
                    s.pop();
                }
                s.push(nums[i]);
            }

        }
        return false;
    }
    //一般的方法
/*
    bool find132pattern(vector<int> &nums) {
        // write your code here
        if(nums.size()<=2) return false;
        int i,j,k,n;
        i = j = k = 0;
        n = nums.size();
        while(i<n)
        {
            while(i<n-1 && nums[i] >= nums[i+1]) i++;
            j = i + 1;
            while(j<n-1 && nums[j] <= nums[j+1]) j++;
            k = j + 1;
            while(k<n)
            {
                if(nums[k] > nums[i] && nums[k] < nums[j])
                    return true;
                k++;
            }
            i = j + 1;
        }
        return false;
    }
*/
};

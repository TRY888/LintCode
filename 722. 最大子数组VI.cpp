class Solution {
public:
    /*
     * @param : the array
     * @return: the max xor sum of the subarray in a given array
     */
     
    // 本方法时间复杂度o(n^2),有时候会提交成功
    int maxXorSubarray(vector<int> &nums) {
        // write code here
        vector<int> temp;
        int max = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<temp.size(); j++)
            {
                int t = nums[i]^temp[j];
                temp[j] = t;
                if(t>max)
                    max = t;
            }
            temp.push_back(nums[i]);
            if(nums[i]>max)
                max = nums[i];
        }
        return max;
    }
};
class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    int maximumGap(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        int max = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            int j = i + 1;
            int temp = nums[j]-nums[i];
            if(temp>max)
                max = temp;
        }
        return max;
    }
};

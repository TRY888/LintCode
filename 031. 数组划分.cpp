class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    void swap(vector<int> &nums, int pos1, int pos2)
    {
        int temp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = temp;
    }

    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.size()==0)
            return 0;
        int start=0, end=nums.size()-1;
        while(start<end)
        {
            if(nums[start]>=k)
            {
                swap(nums, start, end);
                end--;
            }
            if(nums[start]<k)
            {
                start++;
            }
        }
        int i=0;
        while(i<nums.size() && nums[i]<k)
            i++;
        return i;
    }
};

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The majority number
     */
    int majorityNumber(vector<int> &nums, int k) {
        // write your code here
        multiset<int> mset;
        for(int i=0; i<nums.size(); i++)
            mset.insert(nums[i]);
        multiset<int>::iterator iter;
        int maxcnt = 0;
        int maxval = 0;
        for(iter=mset.begin(); iter!=mset.end(); iter++)
        {
            int cnt = mset.count(*iter);
            if(cnt>maxcnt)
            {
                maxcnt = cnt;
                maxval = *iter;
            }
        }
        return maxval;
    }
};

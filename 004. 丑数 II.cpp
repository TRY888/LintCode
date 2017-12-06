class Solution {
public:
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int nums[3] = {2,3,5};
        int index_nums[3] = {0,0,0};
        vector<int> res(n, 0);
        res[0] = 1;
        int cnt=1;
        while(cnt<n)
        {
            long min = 0x80000000;
            int index = -1;
            for(int i=0; i<3; i++)
            {
                int temp = res[index_nums[i]] * nums[i];
                if(temp<min)
                {
                    min = temp;
                    index = i;
                }
            }
            if(index!=-1)
            {
                ++index_nums[index];
                if(min>res[cnt-1])
                {
                    res[cnt] = min;
                    ++cnt;
                }
            }
        }
        return res[n-1];
    }
};

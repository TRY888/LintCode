class Solution {
public:
    /*
     * @param nums: A list of non negative integers
     * @return: A string
     */
    struct compare{
        bool operator()(int a, int b)
        {
            string aa = to_string(a);
            string bb = to_string(b);
            return aa+bb>bb+aa?true:false;
        }
    };
    string largestNumber(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end(), compare());
        string res;
        for(int i=0; i<nums.size(); i++)
            res.append(to_string(nums[i]));
        int r = atoi(res.data());
        if(r == 0)
            return string("0");
        return res;
    }
};

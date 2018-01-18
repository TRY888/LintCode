class Solution {
public:

    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        multiset<int> set_1(nums1.begin(), nums1.end());
        multiset<int> set_2(nums2.begin(), nums2.end());
        vector<int> res(nums1.size()>nums2.size()?nums2.size():nums1.size());
        vector<int>::iterator iter_first, iter_last;
        iter_first = res.begin();
        iter_last = set_intersection(set_1.begin(), set_1.end(),
                                     set_2.begin(), set_2.end(), res.begin());
        res.resize(iter_last - iter_first);
        return res;
    }
};

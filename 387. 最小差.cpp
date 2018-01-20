class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: Their smallest difference.
     */
    int binarySearch(vector<int> &v, int target)
    {
        int min = 0x7fffffff;
        int start=0, end=v.size()-1;
        if(target>=v[end])
            return target-v[end];
        if(target<=v[start])
            return v[start]-target;
        while(start<=end)
        {
            int mid = (start+end)/2;
            int temp = abs(target - v[mid]);
            if(temp<min)
                min = temp;
            if(target>v[mid])
                start = mid+1;
            else if(target<v[mid])
                end = mid-1;
            else
                return 0;
        }
        return min;
    }

    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(B.begin(), B.end());
        int min = 0x7fffffff;
        for(int i=0; i<A.size(); i++)
        {
            int temp = binarySearch(B, A[i]);
            if(temp<min)
                min = temp;
        }
        return min;
    }
};

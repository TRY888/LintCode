class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        int min = 0x7fffffff;
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        for(int i=0; i<size; i++)
        {
            int j=i+1, k=size-1;
            while(j<k)
            {
                int sum = numbers[i] + numbers[j] + numbers[k];
                if(abs(min-target) > abs(sum-target))
                    min = sum;
                if(sum<=target)
                    j++;
                else
                    k--;
            }
        }
        return min;
    }
};

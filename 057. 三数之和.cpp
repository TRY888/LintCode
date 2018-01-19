class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        vector<vector<int> > res;
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        for(int i=0; i<size; i++)
        {
            int j=i+1, k=size-1;
            while(j<k)
            {
                int sum = numbers[i] + numbers[j] + numbers[k];
                vector<int> temp;
                temp.resize(0);
                if(sum == 0)
                {
                    temp.push_back(numbers[i]);
                    temp.push_back(numbers[j]);
                    temp.push_back(numbers[k]);
                    bool ok = true;
                    for(int index=0; index<res.size(); index++)
                    {
                        if(temp == res[index])
                        {
                            ok = false;
                            break;
                        }
                    }
                    if(ok)
                    {
                        res.push_back(temp);
                    }
                }
                if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};

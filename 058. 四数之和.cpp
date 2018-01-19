class Solution {
public:
    /*
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> numbers, int target) {
        // write your code here
        vector<vector<int>> res;
        sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        for(int i=0; i<size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                int k=j+1, h=size-1;
                while(k<h)
                {
                    int sum = numbers[i] + numbers[j] + numbers[k] + numbers[h];
                    vector<int> temp;
                    temp.resize(0);
                    if(sum == target)
                    {
                        temp.push_back(numbers[i]);
                        temp.push_back(numbers[j]);
                        temp.push_back(numbers[k]);
                        temp.push_back(numbers[h]);
                        bool ok = true;
                        for(int index=0; index<res.size(); index++)
                        {
                            if(res[index] == temp)
                            {
                                ok = false;
                                break;
                            }
                        }
                        if(ok)
                            res.push_back(temp);
                    }
                    if(sum <= target)
                        k++;
                    else
                        h--;
                }
            }
        }
        return res;
    }
};

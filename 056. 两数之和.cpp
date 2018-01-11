class Solution {
public:
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        // write your code here
        vector<int> res;
        map<int, int> data;
        for(int i=0; i<numbers.size(); i++)
            data.insert(map<int, int>::value_type(numbers[i], i));
        for(int i=0; i<numbers.size(); i++)
        {
            if(data.find(target - numbers[i])!=data.end())
            {
                if(i != data[target-numbers[i]])
                {
                    res.push_back(i);
                    res.push_back(data[target-numbers[i]]);
                    break;
                }
            }
        }
        if(res.size() == 2)
        {
            if(res[0] > res[1])
            {
                int temp = res[0];
                res[0] = res[1];
                res[1] = temp;
            }
        }
        return res;
    }
};

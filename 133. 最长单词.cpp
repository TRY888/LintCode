class Solution {
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> res;
        if(dictionary.size() == 0)
            return res;
        string comp_str = dictionary[0];
        res.push_back(comp_str);
        for(int i=1; i<dictionary.size(); i++)
        {
            if(dictionary[i].size() > comp_str.size())
            {
                comp_str = dictionary[i];
                res.resize(0);
                res.push_back(comp_str);
            }
            else if(dictionary[i].size() == comp_str.size())
            {
                res.push_back(dictionary[i]);
            }
        }
        return res;
    }
};

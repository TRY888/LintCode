/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        for(int i=0; i<nuts.size(); i++)
        {
            for(int j=i; j<bolts.size(); j++)
            {
                if(compare.cmp(nuts[i], bolts[j]) == 0)
                {
                    string temp = bolts[i];
                    bolts[i] = bolts[j];
                    bolts[j] = temp;
                }
            }
        }
    }
};

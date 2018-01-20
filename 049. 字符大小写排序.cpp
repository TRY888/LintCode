class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void swap(string &str, int pos1, int pos2)
    {
        char temp = str[pos1];
        str[pos1] = str[pos2];
        str[pos2] = temp;
    }

    void sortLetters(string &chars) {
        // write your code here
        int start=0, end=chars.size()-1, size=end+1;
        while(start<end)
        {
            if(chars[start]>='A' && chars[start]<='Z')
            {
                swap(chars, start, end);
                end--;
            }
            if(chars[start]>='a' && chars[start]<='z')
            {
                start++;
            }
        }
    }
};

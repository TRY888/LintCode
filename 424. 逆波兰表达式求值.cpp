class Solution {
public:
    /*
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */

    int strToNum(string str)
    {
        int len = str.size();
        double result = 0;
        if(str[0] == '-')
        {
            for(int i=len-1; i>=1; --i)
                result += (str[i]-48)* pow(10, len-i-1);
            result = -result;
        }
        else
        {
            for(int i=len-1; i>=0; --i)
                result += (str[i]-48)* pow(10, len-i-1);
        }
        return static_cast<int>(result);
    }
    int evalRPN(vector<string> &tokens) {
        // write your code here
        stack<int> s;
        int len = tokens.size();
        int result = 0;
        for(int i=0; i< len; i++)
        {
            if(tokens[i] == "+")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                result = val2 + val1;
                s.push(result);
                continue;
            }
            if(tokens[i] == "-")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                result = val2 - val1;
                s.push(result);
                continue;
            }
            if(tokens[i] == "*")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                result = val2 * val1;
                s.push(result);
                continue;
            }
            if(tokens[i] == "/")
            {
                int val1 = s.top();
                s.pop();
                int val2 = s.top();
                s.pop();
                result = val2 / val1;
                s.push(result);
                continue;
            }
            s.push(strToNum(tokens[i]));
        }
        int r = s.top();
        s.pop();
        return r;
    }
};

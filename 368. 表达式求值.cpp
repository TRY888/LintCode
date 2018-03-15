class Solution {
public:
    /*
     * @param expression: a list of strings
     * @return: an integer
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        stack<string> s;
        vector<string> v;
        for(int i=0; i<expression.size(); i++)
        {
            if(expression[i] == "(")
                s.push(expression[i]);
            else if(expression[i] == ")")
            {
                while(!s.empty())
                {
                    if(s.top() == "(")
                    {
                        s.pop();
                        break;
                    }
                    else
                    {
                        v.push_back(s.top());
                        s.pop();
                    }
                }
            }
            else if(expression[i] == "+" || expression[i] == "-")
            {
                while(!s.empty() && (s.top() == "*" || s.top() == "/" || s.top() == "+" || s.top() == "-"))
                {
                    v.push_back(s.top());
                    s.pop();
                }
                s.push(expression[i]);
            }
            else if(expression[i] == "*" || expression[i] == "/")
            {
                while(!s.empty() && (s.top() == "*" || s.top() == "/"))
                {
                    v.push_back(s.top());
                    s.pop();
                }
                s.push(expression[i]);
            }
            else
            {
                v.push_back(expression[i]);
            }
        }
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
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
    int calculateRPN(vector<string> rpn)
    {
        stack<int> s;
        int val1, val2, result;
        for(int i=0; i<rpn.size(); i++)
        {
            if(rpn[i] == "+")
            {
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();
                result = val1 + val2;
                s.push(result);
            }
            else if(rpn[i] == "-")
            {
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();
                result = val1 - val2;
                s.push(result);
            }
            else if(rpn[i] == "*")
            {
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();
                result = val1 * val2;
                s.push(result);
            }
            else if(rpn[i] == "/")
            {
                val2 = s.top();
                s.pop();
                val1 = s.top();
                s.pop();
                result = val1 / val2;
                s.push(result);
            }
            else
            {
                s.push(strToNum(rpn[i]));
            }
        }
        if(s.empty())
            return 0;
        result = s.top();
        s.pop();
        return result;
    }
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        return calculateRPN(convertToRPN(expression));
    }
};

/*
 * title：容易-423.有效的括号序列
 * desc:给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'， 判定是否是有效的括号序列。
 * e.g.:括号必须依照 "()" 顺序表示， "()[]{}" 是有效的括号，但 "([)]"则是无效的括号。
 */

class Solution {
public:
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */

    bool isValidParentheses(string &s) {
        // write your code here
        stack<char> sta;
        bool flag = false;
        for(int i=0; i<s.size(); i++)
        {
            switch(s.at(i))
            {
                case '(': sta.push('(');break;
                case '{': sta.push('{');break;
                case '[': sta.push('[');break;
                case ')': 
                        while(!sta.empty())
                        {
                            char val = sta.top();
                            sta.pop();
                            if(val == '[' || val == '{')
                                return false;
                            if(val == '(')
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(flag == false)
                            return false;
                        flag = false;
                        break;
                case '}': 
                        while(!sta.empty())
                        {
                            char val = sta.top();
                            sta.pop();
                            if(val == '(' || val == '[')
                                return false;
                            if(val == '{')
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(flag == false)
                            return false;
                        flag = false;
                        break;
                case ']': 
                        while(!sta.empty())
                        {
                            char val = sta.top();
                            sta.pop();
                            if(val == '(' || val == '{')
                                return false;
                            if(val == '[')
                            {
                                flag = true;
                                break;
                            }
                        }
                        if(flag == false)
                            return false;
                        flag = false;
                        break;
                default:break;
            }
        }
        if(sta.empty() == true)
            return true;
    }

};




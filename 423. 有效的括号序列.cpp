// class Solution {
// public:
//     /*
//      * @param s: A string
//      * @return: whether the string is a valid parentheses
//      */

//     bool isValidParentheses(string &s) {
//         // write your code here
//         stack<char> sta;
//         bool flag = false;
//         for(int i=0; i<s.size(); i++)
//         {
//             switch(s.at(i))
//             {
//                 case '(': sta.push('(');break;
//                 case '{': sta.push('{');break;
//                 case '[': sta.push('[');break;
//                 case ')':
//                         while(!sta.empty())
//                         {
//                             char val = sta.top();
//                             sta.pop();
//                             if(val == '[' || val == '{')
//                                 return false;
//                             if(val == '(')
//                             {
//                                 flag = true;
//                                 break;
//                             }
//                         }
//                         if(flag == false)
//                             return false;
//                         flag = false;
//                         break;
//                 case '}':
//                         while(!sta.empty())
//                         {
//                             char val = sta.top();
//                             sta.pop();
//                             if(val == '(' || val == '[')
//                                 return false;
//                             if(val == '{')
//                             {
//                                 flag = true;
//                                 break;
//                             }
//                         }
//                         if(flag == false)
//                             return false;
//                         flag = false;
//                         break;
//                 case ']':
//                         while(!sta.empty())
//                         {
//                             char val = sta.top();
//                             sta.pop();
//                             if(val == '(' || val == '{')
//                                 return false;
//                             if(val == '[')
//                             {
//                                 flag = true;
//                                 break;
//                             }
//                         }
//                         if(flag == false)
//                             return false;
//                         flag = false;
//                         break;
//                 default:break;
//             }
//         }
//         if(sta.empty() == true)
//             return true;
//     }

// };

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
            char temp = s[i];
            switch(temp)
            {
                case '(': sta.push(temp); break;
                case '[': sta.push(temp); break;
                case '{': sta.push(temp); break;
                case ')':
                {
                    while(sta.size()>0)
                    {
                        char temp = sta.top();
                        sta.pop();
                        if(temp=='[' || temp=='{')
                            return false;
                        if(temp == '(')
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag==false)
                        return false;
                    flag = false;
                    break;
                }
                case ']':
                {
                    while(sta.size()>0)
                    {
                        char temp = sta.top();
                        sta.pop();
                        if(temp=='(' || temp=='{')
                            return false;
                        if(temp == '[')
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag==false)
                        return false;
                    flag = false;
                    break;
                }
                case '}':
                {
                    while(sta.size()>0)
                    {
                        char temp = sta.top();
                        sta.pop();
                        if(temp=='(' || temp=='[')
                            return false;
                        if(temp == '{')
                        {
                            flag = true;
                            break;
                        }
                    }
                    if(flag==false)
                        return false;
                    flag = false;
                    break;
                }
                default: break;
            }
        }
        if(sta.empty() == true)
            return true;
        else
            return false;
    }

};

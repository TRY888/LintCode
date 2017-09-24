/*
 * title：中等-370.将表达式转换为逆波兰表达式
 * desc:给定一个表达式字符串数组，返回该表达式的逆波兰表达式（即去掉括号）。
 * e.g.:对于 [3 - 4 + 5]的表达式（该表达式可表示为["3", "-", "4", "+", "5"]），返回 [3 4 - 5 +]（该表达式可表示为 ["3", "4", "-", "5", "+"]）。
 */

class Solution {
public:
	stack<string> s;
	vector<string> v;
    /*
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
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
};
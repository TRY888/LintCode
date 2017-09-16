/*
 * title：中等-424.逆波兰表达式求值
 * desc:求逆波兰表达式的值。
 *      在逆波兰表达法中，其有效的运算符号包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰计数表达。
 * e.g.:["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

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
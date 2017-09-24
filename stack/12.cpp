/*
 * title：中等-12.带最小值操作的栈 
 * desc:实现一个带有取最小值min方法的栈，min方法将返回当前栈中的最小值。
 *      你实现的栈将支持push，pop 和 min 操作，所有操作要求都在O(1)时间内完成。
 *      如果堆栈中没有数字则不能进行min方法的调用
 * e.g.:如下操作：push(1)，pop()，push(2)，push(3)，min()， push(1)，min() 返回 1，2，1
 */

class MinStack {
public:
     
    /*
    * @param a: An integer
    */
    MinStack() {
        // do intialization if necessary
    }
/* 一般的方法（效率低）
    stack<int> s1,s2,s3;
    void push(int number) {
        // write your code here
        s1.push(number);
        if(s3.empty()) s3.push(number);
       	else
       	{
	    	if(number<=s3.top()) s3.push(number);
	    	else
			{
				do
				{
					s2.push(s3.top());
					s3.pop();	
				}while(!s3.empty() && number>s3.top());
				s3.push(number);
				while(!s2.empty())
				{
					s3.push(s2.top());
					s2.pop();
				}	
	    	}
        }
    }
    int pop() {
        // write your code here
        int val = s1.top();
        s1.pop();
    	while(!s3.empty())
    	{
	    	if(val == s3.top())
    		{
		    	s3.pop();
		    	break;
		    }
		    else
			{
    			s2.push(s3.top());
    			s3.pop();
    		}
	    }
	    while(!s2.empty())
	    {
    		s3.push(s2.top());
    		s2.pop();
    	}
    	return val;
    }
    int min() {
        // write your code here
        return s3.top();
    }
*/
    stack<int> s1,s2;
    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        s1.push(number);
        if(s2.size()<=0 || s2.top() >= number)
			s2.push(number);
  		else
  			s2.push(s2.top());
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int pop() {
        // write your code here
        if(s1.size()>0 && s2.size()>0)
        {
        	int val = s1.top();
        	s1.pop();
        	s2.pop();
			return val;
        }
        return 0;
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int min() {
        // write your code here
        if(s1.size()>0 && s2.size()>0)
      		return s2.top();
  		return 0;
    }    
    
};
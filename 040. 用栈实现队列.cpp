class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */

    //第一种方法：
/*
    void push(int element) {
        // write your code here
        stack1.push(element);
    }
*/
    /*
     * @return: An integer
     */
/*
    int pop() {
        // write your code here
        while(!stack1.empty())
        {
            if(stack1.size() == 1)
            {
                break;
            }
            stack2.push(stack1.top());
            stack1.pop();
        }
        int val = stack1.top();
        stack1.pop();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return val;
    }
*/

    /*
     * @return: An integer
     */
/*
    int top() {
        // write your code here
        while(!stack1.empty())
        {
            if(stack1.size() == 1)
            {
                break;
            }
            stack2.push(stack1.top());
            stack1.pop();
        }
        int val = stack1.top();
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return val;
    }
*/
    //第二种方法（最好）
/*
    void push(int element) {
        stack1.push(element);
    }
    int pop() {
        if(!stack2.empty())
        {
            int val = stack2.top();
            stack2.pop();
            return val;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int val = stack2.top();
            stack2.pop();
            return val;
        }

    }
    int top() {
        if(!stack2.empty())
        {
            int val = stack2.top();
            return val;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int val = stack2.top();
            return val;
        }
    }
*/
    //第三种方法
    void push(int element){
        if(!stack1.empty())
        {
            stack1.push(element);
        }
        else
        {
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack1.push(element);
        }
    }
    int pop(){
        if(!stack2.empty())
        {
            int val = stack2.top();
            stack2.pop();
            return val;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int val = stack2.top();
            stack2.pop();
            return val;
        }
    }
    int top(){
        if(!stack2.empty())
        {
            int val = stack2.top();
            return val;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int val = stack2.top();
            return val;
        }
    }

};

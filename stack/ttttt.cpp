#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>

using namespace std; 

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){} 
};

bool isPointerExist(ListNode *head, ListNode *pointer)
{
	ListNode *p = head;
	if(p == NULL)
		return false;
	else
	{
		while(p!=NULL)
		{
			if(p == pointer)
				return true;
			p = p->next;
		}
		return false;
	}
}

/*
ListNode *detectCycle(ListNode *head) {
    ListNode *p, *s, *temp;
	p = head;
	s = temp = NULL;
	while(p!=NULL)
	{
		if(isPointerExist(s, p) == true)
		{
			p->next= NULL;
			cout << "the same" << endl; 
			return p;
		}
		else
		{
			temp = p->next;
			p->next = s;
			s = p;
			p = temp;
		}
	}
	cout << "no the same" << endl; 
	return NULL; 
}
*/

ListNode *detectCycle(ListNode *head) 
{
	ListNode *fast = head, *slow = head;
	while(fast!=NULL && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(fast && fast == slow)
	{
		fast = head;
		while(fast!=slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		cout << "the same" << endl;
		return fast;
	}
	return NULL;
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
int evalRPN(vector<string> &tokens) {
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


class Solution1 {
public:
    /*
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int max=0,result;
        int size = 0;
        int i,j,k;
        for(i=0; i< height.size(); i++)
        {
        	for(j=i-1; j>=0; j--)
        	{
	        	if(height[j]<height[i])
	        	{
	        		j = j + 1;
	        		break;
	        	}	
	        }
	        if(j<0) j = 0;
	        for(k=i+1; k<height.size(); k++)
	        {
        		if(height[k]<height[i])
        		{
		        	k = k - 1;
		        	break;
		        }
        	}
        	if(k>=height.size()) k = height.size()-1;
        	
	        result = height[i]*(k-j+1);
	        if(result>max)
	        	max = result;
        }
        return max;
    }
};

  //2 1 5 6 2 3
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int maxh=0;
        stack<int> st; //存放递增高度序列的下标
        for(int i=0;i<=height.size();i++) //用i遍历全部数组
        {
            int nowh= (i == height.size()) ? 0 : height[i]; //若下标为height.size()时，其高度置为0
            while( !st.empty() && nowh <= height[st.top()] )
            //若当前的高度小于或等于栈顶的高度时
            {
                int h=height[st.top()]; //矩阵的高度为栈顶元素的高度
                ///////这个很重要////
                st.pop();               //将栈顶元素弹出
                //要先将栈顶元素弹出，因为若左边界元素是栈底元素长度要取数组全长
                //而不是当前长度到栈顶的长度
                int w;
    
                if(st.empty())      //若此时栈空
                    w=i;            //取全部长度，而不应该取
                else                //否则宽度为i-1-st.top();
                    w=i-1-st.top();
    
                maxh=max(maxh,w*h);     //记录下最大面积
            }//执行完这个循环后栈为空，或栈顶元素的高度小于i的高度
            st.push(i);              //将i再压入栈中
        }
        return maxh;
    }


int maxsum(vector<int> value)
{
	int max=0, s=0;
	for(int i=0; i<value.size(); i++)
	{
		s = s + value[i];
		if(s > max)
			max = s;
		else if(s<=0)
			s = 0;		
	}
	return max;
} 

int maxVectorSum(vector<vector<int> > v)
{
	int row, col, max=0, temp=0;
	row = v.size();
	col = v[0].size();
	for(int i=0; i<row; i++)
	{
		vector<int> a;
		a.resize(col);
		for(int j=i; j<row; j++)
		{
			for(int k=0; k<col; k++)
			{
				a[k]+= v[j][k];
			}
			temp = maxsum(a);
			if(temp>max)
				max = temp;
		}
	}
	
	return max;
}

int maxHistogramBar(vector<int> &v)
    {
        int size = v.size();
        int max=0, temp=0, w;
        stack<int> s;
        for(int i=0; i<=size; i++)
        {
            int maxh = (i==size)?0:v[i];
            while(!s.empty() && v[s.top()] > maxh)
            {
                int h = v[s.top()];
                s.pop();
                if(s.empty())
                    w = i;
                else
                    w = i-1-s.top();
                temp = h * w;
                if(temp > max)
                    max = temp;
            }
            s.push(i);
        }
        return max;
    }
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // write your code here
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        int max = 0, temp = 0;
        vector<int> v;
        v.resize(col);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                v[j] = (matrix[i][j]==0)?0:v[j]+1;
            }

            temp = maxHistogramBar(v);
            if(temp > max)
                max = temp;
        }
        return max;
    }

#define len 10

typedef int TDataType;

typedef struct tnode
{
	TDataType data;
	tnode *lchild;
	tnode *rchild;
}BiNode,BiTree;

void postOrder(BiTree *t)
{
	BiNode *temp = t;
	stack<BiNode *> s1;
	stack<int> s2;
	while(temp!=NULL)
	{
		s1.push(temp);
		s2.push(1);
		temp = temp->lchild;
		if(temp == NULL)
		{
			while(!s1.empty())
			{
				int val = s2.top();
				s2.pop();
				temp = s1.top();
				if(val == 1)
				{
					BiNode *tt = temp->rchild;
					if(tt == NULL)
					{
						cout << temp->data << " ";
						s1.pop();
					}
					else
					{
						s2.push(2);
						temp = tt;
						break;
					}		
				}
				else
				{
					cout << temp->data << " ";
					s1.pop();
				}
			}
		}
	}
}


void postOrder1(BiTree *t)
{
	if(t == NULL)
		return;
	else
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		cout << t->data << " ";
	}
}














int main(int argc, char *argv[])
{
	//BiNode *t = new BiNode[len];
	BiNode *t[len];
	for(int i=0; i<len; i++)
	{
		t[i] = new BiNode();
	}
	for(int i=1; i<len; i++)
	{
		t[i]->data = i;
	}
	for(int i=1; i<len; i++)
	{
		if(2*i>len)
			t[i]->lchild = NULL;
		else
			t[i]->lchild = t[2*i];
		if(2*i+1>len)
			t[i]->rchild = NULL;
		else
			t[i]->rchild = t[2*i+1];
	}
	//postOrder1(t[1]);
	postOrder(t[1]);
	
	return 0;
}


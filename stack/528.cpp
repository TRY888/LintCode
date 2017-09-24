/*
 * title：中等-528.摊平嵌套的列表 
 * desc:给你一个嵌套的列表，实现一个迭代器将其摊平。
 *      一个列表的每个元素可能是整数或者一个列表。
 *      You don't need to implement the remove method.
 * e.g.:给出列表 [[1,1],2,[1,1]]，经过迭代器之后返回 [1,1,2,1,1]。
 *      给出列表 [1,[4,[6]]]，经过迭代器之后返回 [1,4,6]。
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    stack<NestedInteger> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for(int i=nestedList.size()-1; i>=0; i--)
        	s.push(nestedList[i]);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
		int val = s.top().getInteger();
		s.pop();
		return val;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        while(!s.empty())
        {
            NestedInter n = s.top();
            if(n.isInteger())
                return true;
            else
            {
                s.pop();
    	       	for(int i=n.getList().size()-1; i>=0; --i)
    	       	{
    	       		s.push(n.getList().at(i));
    	       	}
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
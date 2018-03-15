class Solution {
public:
    /*
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
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
    string multiString(string ori, int num)
    {
        string s = "";
        for(int i=0; i<num; ++i)
            s.append(ori);
        return s;
    }

    string expressionExpand(string &s) {
        // write your code here
        stack<string> temp;
        string str_temp;
        string str_num;
        for(int i=0; i<s.size(); ++i)
        {
            if((s[i] >='a' && s[i] <='z') || (s[i]>='A' && s[i]<='Z'))
            {
                str_temp.append(1, s[i]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                if(!str_temp.empty())
                {
                    temp.push(str_temp);
                    str_temp = "";
                }
                const char c = s[i];
                str_num.append(1, s[i]);
            }
            else if(s[i] == '[')
            {
                temp.push(str_num);
                str_num = "";
                temp.push("[");
            }
            else
            {
                while(temp.top()!="[")
                {
                    string aaa = temp.top();
                    str_temp = aaa.append(str_temp);
                    temp.pop();
                }
                temp.pop();
                int num = strToNum(temp.top());
                temp.pop();
                temp.push(multiString(str_temp, num));
                str_temp = "";
            }
        }
        if(!str_temp.empty())
            temp.push(str_temp);
        string str1,str2;

        while(!temp.empty())
        {
            str2 = temp.top();
            str2.append(str1);
            str1 = str2;
            temp.pop();
        }
        return str1;
    }
};

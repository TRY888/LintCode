class Solution {
public:
    stack<string> s;
    /*
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        string str1="/", str2;
        for(int i=1; i<path.size(); i++)
        {
            if(path[i] == '/')
            {
                if(str1 == "/" && str2.size()>0)
                {
                    s.push(str1.append(str2));
                    str1 = "/";
                    str2 = "";
                }
                else if(str1 == "/..")
                {
                    if(str2.size() == 0)
                    {
                        if(!s.empty())
                            s.pop();
                    }
                    else
                    {
                        s.push(str1.append(str2));
                    }
                    str1 = "/";
                    str2 = "";
                }
                else if(str1 == "/.")
                {
                    if(str2.size() != 0)
                    {
                        s.push(str1.append(str2));
                    }
                    str1 = "/";
                    str2 = "";
                }
            }
            else if(path[i] == '.')
            {
                str1.append(1, path[i]);
            }
            else
            {
                str2.append(1, path[i]);
            }
        }
        str1 = str1.append(str2);
        if(str1 == "/." || str1 == "/..")
        {
            s.push("/");
        }
        else if(str1 != "/")
        {
            s.push(str1);
        }
        string s1,s2;
        if(s.empty())
        {
            s1 = "/";
        }
        else
        {
            while(!s.empty())
            {
                s2 = s.top();
                s2.append(s1);
                s1 = s2;
                s.pop();
            }
        }
        return s1;
    }
};

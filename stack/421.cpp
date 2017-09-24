/*
 * title：中等-421.简化路径
 * desc:给定一个文档(Unix-style)的完全路径，请进行路径简化。
 * e.g.:"/home/", => "/home"
 *      "/a/./b/../../c/", => "/c"
 *     你是否考虑了 路径 = "/../" 的情况？
 *     在这种情况下，你需返回"/"。
 *     此外，路径中也可能包含双斜杠'/'，如 "/home//foo/"。
 *     在这种情况下，可忽略多余的斜杠，返回 "/home/foo"。
 */

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
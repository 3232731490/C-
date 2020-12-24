#include<iostream>
#include<string>
using namespace std;

/*
案例描述：
输入两个字符串，验证其中一个串是否为另一个串的子串。

若第一个串 s1​是第二个串 s2的子串，则输出"(s1) is substring of (s2)"；

否则，若第二个串s2是第一个串s1的子串，输出"(s2) is substring of (s1)"；

否则，输出"No substring"。


样例：abc
      dddncabca

      abc is substring of dddncabca
*/

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 >= len2)
    {
        int count = 0;
        bool s;
        for (int i = 0; i < len1; i++)
        {
            s = false;
            int j = 0;
            if (str1[i] == str2[j])
            {
                int temp = i;
                for (j = 0; j < len2; j++, temp++)
                {
                    count++;
                    if (str2[j] != str1[temp])
                    {
                        s = false;
                        break;
                    }
                    else s = true;
                }
                if (count == len2)
                {
                    break;
                }
            }
        }
        if (s)
        {
            cout << str2 << " is substring of " << str1 << endl;
        }
        else
        {
            cout << "No substring" << endl;
        }
    }
    else
    {
        int count = 0;
        bool s;
        for (int i = 0; i < len2; i++)
        {
            s = false;
            int j = 0;
            if (str2[i] == str1[j])
            {
                int temp = i;
                for (j = 0; j < len1; j++, temp++)
                {
                    count++;
                    if (str1[j] != str2[temp])
                    {
                        s = false;
                        break;
                    }
                    else s = true;
                }
                if (count == len1)
                {
                    break;
                }
            }
        }
        if (s)
        {
            cout << str1 << " is substring of " << str2 << endl;
        }
        else
        {
            cout << "No substring" << endl;
        }
      
    }
    return 0;
}
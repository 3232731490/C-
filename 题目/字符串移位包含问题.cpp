
/*
案例描述：

对于一个字符串来说，定义一次循环移位操作为：将字符串的第一个字符移动到末尾形成新的字符串。

给定两个字符串 s1和 s2​，要求判定其中一个字符串是否是另一字符串通过若干次循环移位后的新字符串的子串。
例如CDAA是由AABCD两次移位后产生的新串BCDAA的子串
而ABCD与ACBD则不能通过多次移位来得到其中一个字符串是新串的子串。

输入格式：
一行，包含两个字符串，中间由单个空格隔开。字符串只包含字母和数字，长度不超过 3030。

输出格式：
如果一个字符串是另一字符串通过若干次循环移位产生的新串的子串，则输出"true"，否则输出"false"。
*/

#include<iostream>
#include<string>
using namespace std;
bool p(const string& str1, const string& str2)
{
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
            return true;
        }
        else
        {
            return false;
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
            return true;
        }
        else
        {
            return false;
        }

    }
}
int main()
{
    string str1, str2;
    cout << "请输入两个字符串：" << endl;
    cin >> str1 >> str2;
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 >= len2)
    {
        bool s = false;
        for (int i = 0; i < len1; i++)
        {
            if (p(str1, str2))
            {
                s = true;
                cout << "true" << endl;
                break;
            }
            for (int j = 0; j < len1 - 1; j++)
            {
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
        }
        if (!s)
        {
            cout << "false" << endl;
        }
    }
    else
    {
        bool s = false;
        for (int i = 0; i < len2; i++)
        {
            if (p(str1, str2))
            {
                s = true;
                cout << "true" << endl;
                break;
            }
            for (int j = 0; j < len2 - 1; j++)
            {
                char temp = str2[j];
                str2[j] = str2[j + 1];
                str2[j + 1] = temp;
            }
        }
        if (!s)
        {
            cout << "false" << endl;
        }
    }
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int comparestr(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    int lenmin = min(len1, len2);
    int i;
    for (i = 0; i < lenmin; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] -= 32;
        }
        if (str2[i] >= 'a' && str2[i] <= 'z')
        {
            str2[i] -= 32;
        }
        if (str1[i] - str2[i] != 0)
        {
            return str1[i] - str2[i];
        }
    }
    if (len1 - lenmin > 0)
    {
        return 1;
    }
    else if (len2 - lenmin > 0)
    {
        return -1;
    }
    else return 0;
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int num = comparestr(str1, str2);
    if (num > 0)
    {
        cout << ">" << endl;
    }
    else if (num < 0)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << "=" << endl;
    }

    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
案例描述：

判断两个由大小写字母和空格组成的字符串在忽略大小写，且忽略空格后是否相等。

两行，每行包含一个字符串；字符串长度不超过 100。

若两个字符串相等，输出"YES"，否则输出"NO"。
*/

int comparestr(char*str1, char* str2 ,int len)
{

    for (int i = 0,j=0; i < len&&j<len; i++,j++)
    {
        while (str1[i] == 32)
        {
            i++;
        }
        while (str2[j] == 32)
        {
            j++;
        }
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] -= 32;
        }
        if (str2[j] >= 'a' && str2[j] <= 'z')
        {
            str2[j] -= 32;
        }
   


        if (str1[i] != str2[j])
        {
            return -1;
        }
        else continue;
    }
    return 1;
}
int main()
{
    char str1[100],str2[100];
    //输入空格符要使用getline
    cout << "请输入第一个字符串" << endl;
    cin.getline(str1,100);
    cout << "请输入第二个字符串" << endl;
    cin.getline(str2,100);
    int i = 0, j = 0;
    while (str1[i] != '/0'&&str1[i]!=0)
    {
        i++;
    }
    while (str2[j] != '/0' && str2[j] != 0)
    {
        j++;
    }
    int len = max(i, j);
    int num = comparestr(str1, str2,len);
    if (num == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
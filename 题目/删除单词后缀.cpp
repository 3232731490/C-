/*
题目描述：

给定一个单词，如果该单词以er、ly或者ing后缀结尾， 则删除该后缀（题目保证删除后缀后的单词长度不为 0）
否则不进行任何操作。

*/

#include<iostream>
#include<string>
using namespace std;
int myDelete(char* s,int len)
{
    if (s[len - 1] == 'r'&& s[len - 2] == 'e' )
    {
            if(len>2)
               return 1;
            else return 0;
 
    }
    else if ( s[len - 1] == 'y' && s[len - 2] == 'l')
    {
        if (len > 2)
            return 1;
        else return 0;

    }
    else if (s[len - 1] == 'g' && s[len - 2] == 'n' && s[len - 3] == 'i')
    {
        if (len > 3)
            return 2;
        else return 0;
    }
    else return 0;
}
int main()
{
    cout << "请输入一个单词：" << endl;
    char s[32];
    cin >> s;
    int i=0;
    while (s[i] != '/0' && s[i] !=0)
    {
        i++;
    }
   int num= myDelete(s,i);
   if (num == 1)
   {
       for (int j = 0; j < i - 2; j++)
       {
           cout << s[j];
       }
       cout << endl;
    }
   else if (num == 2)
   {
       for (int j = 0; j < i - 3; j++)
       {
           cout << s[j];
       }
       cout << endl;
   }
   else
   {
       for (int j = 0; j < i; j++)
       {
           cout << s[j];
       }
       cout << endl;
   }
    return 0;
}
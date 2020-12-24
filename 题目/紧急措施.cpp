/*
案例描述：
近日，一些热门网站遭受黑客入侵，这些网站的账号、密码及 email 的数据惨遭泄露。
你在这些网站上注册若干账号（使用的用户名不一定相同），但是注册时使用了相同的 email。
你此时拿到了那份泄露的数据，希望尽快将自己的密码更改。策略如下：
根据 email 找到你的用户名和密码，然后更改密码。
更改的规则为：小写和大写交换，非字母字符保持不变。


输入格式：
第一行为你的 email 地址，长度不超过 50 个字符且只包含字母、数字和 '@' 符号。

第二行为账号数 N，N(0 < N < 10000)。

接下来 N 行，每行表示一个账号，格式为：

用户名 密码 email

它们之间用单个空格分开。用户名、密码、email 均不含空格，且长度不超过 50 个字符。


输出格式：
有若干行，每行为你的一个账号，包括：你的账号，修改后的密码（之间用单个空格分隔）。

如果没有你的账号，则输出"empty"。

*/


/*
输入样式：
abc@pku.edu.cn
5
helloKitty iLoveCats abc@pku.edu.cn
2012 maya2012 cplusplus@exam.com
KittyCat 5iKitty abc@pku.edu.cn
program password teacher@exam.com
whoAmi Feb.29$ abc@pku.edu.cn

输出样式：
helloKitty IlOVEcATS
KittyCat 5IkITTY
whoAmi fEB.29$
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class my
{
public:
    string userID;
    string userKey;
    string userEmail;
};
void swap(string& str)
{
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
int main()
{
    string email;
    cin >> email;
    int n;
    cin >> n;
    vector<my> myZ;
    for (int i = 0; i < n; i++)
    {
        my my1;
        cin >> my1.userID >> my1.userKey >>my1. userEmail;
        myZ.push_back(my1);
    }
    bool isEmpty = true;
    for (vector<my>::iterator it = myZ.begin(); it != myZ.end(); it++)
    {
        if (it->userEmail == email)
        {
            isEmpty = false;
            swap(it->userKey);
            cout << it->userID << " " << it->userKey << endl;
        }
    }
    if (isEmpty)
    {
        cout << "empty" << endl;
    }
    return 0;
}
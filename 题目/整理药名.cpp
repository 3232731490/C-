#include<vector>
#include<iostream>
#include<string>
using namespace std;

/*
案例描述：

医生在书写药品名的时候经常不注意大小写，格式比较混乱。
现要求你写一个程序将医生书写混乱的药品名整理成统一规范的格式，
即药品名的第一个字符如果是字母要大写，其他字母小写。如将"ASPIRIN"、"aspirin"整理成"Aspirin"。


第一行一个数字 n，表示有 n 个药品名要整理，n 不超过 100。

接下来 n 行，每行一个单词，长度不超过 20，表示医生手书的药品名。药品名由字母、数字和-组成。
*/

/*
样例输入：
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6
*/
int main()
{
    vector<string> v;
    int n;
    cout << "请输入有几个药名需要整理： " << endl;
    cin >> n;
    cout << "请依次输入药名：" << endl;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        int len = (*it).size();
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                if ((*it)[i] >= 'a' && (*it)[i] <= 'z')
                {
                    (*it)[i] -= 32;
                }
            }
            else
            {
                if ((*it)[i] >= 'A' && (*it)[i] <= 'Z')
                {
                    (*it)[i] += 32;
                }
            }
        }
    }
    cout << "药名整理完成如下： " << endl;
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}
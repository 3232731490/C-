#include<iostream>
#include<string>
using namespace std;
int main()
{
    /*
    小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。

    在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。

    经过研究，小英发现了如下加密规律（括号中是一个 "原文 -> 密文" 的例子）

    原文中所有的字符都在字母表中被循环
    右移了三个位置（ abz -> dec ）
    逆序存储（abcd -> dcba ）
    大小写反转（abXY -> ABxy）
   
   */
    cout << "请输入密文： " << endl;
    string key;
    cin >> key;
    int len = key.size();
    for (int i = 0; i < len; i++)
    {
        if (key[i] <= 'Z' && key[i] >= 'A')
        {
            key[i] += 32;
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 32;
        }
    }
    for (int i = 0; i < len; i++)
    {
        char temp = key[i];
        key[i] = key[len - i - 1];
        key[len - i - 1] = temp;
        if (i+1 >= (len / 2) )
        {
            break;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (key[i] - 'a' > 2)
        {
            key[i] -= 3;
        }
        else if (key[i] <= 'Z' && key[i] >= 'A' && key[i] - 'A' > 2)
        {
            key[i] -= 3;
        }
        else
        {
            if (key[i] <= 'Z' && key[i] >= 'A')
            {
                key[i] = 'Z' - (2 - key[i] + 'A');
            }
            else if (key[i] >= 'a' && key[i] <= 'z')
            {
                key[i] = 'z' - (2 - key[i] + 'a');
            }
        }
    }
    cout << "原文为： " << endl;
    cout << key << endl;
    return 0;
}
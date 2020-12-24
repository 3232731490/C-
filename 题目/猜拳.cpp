#include <iostream>
#include<vector>
using namespace std;
int main()
{
    /*
    案例描述：

    石头剪刀布是常见的猜拳游戏。石头胜剪刀，剪刀胜布，布胜石头。如果两个人出拳一样，则不分胜负。
    一天，小 A 和小 B 正好在玩石头剪刀布。已知他们的出拳都是有周期性规律的，
    比如：“石头-布-石头-剪刀-石头-布-石头-剪刀……”，就是以“石头-布-石头-剪刀”为周期不断循环的。
    请问，小 A 和小 B 比了 N 轮之后，谁赢的轮数多？
    */
    
    int N, NA, NB;
    cout << "0---石头、2--剪刀、5--布" << endl;
    cout << "请输入猜拳轮数、A 出拳的周期长度、B出拳的周期长度" << endl;
    int numA = 0, numB = 0;
    cin >> N >> NA >> NB;
    vector<int> vA;
    vector<int> vB;
    cout << "请输入A 的一个出拳周期: " << endl;
    for (int i = 0; i < NA; i++)
    {
        int n;
        cin >> n;
        vA.push_back(n);
    }
    cout << "请输入B 的一个出拳周期: " << endl;
    for (int i = 0; i < NB; i++)
    {
        int n;
        cin >> n;
        vB.push_back(n);
    }
    vector<int>::iterator itA = vA.begin();
    vector<int>::iterator itB = vB.begin();
    for (int i = 0; i < N; i++)
    {
        if (*itA == 0)
        {
            if (*itB == 2)
            {
                numA++;
            }
            else if (*itB == 5)
            {
                numB++;
            }
        }
        else if (*itA == 2)
        {
            if (*itB == 5)
            {
                numA++;
            }
            else if (*itB == 0)
            {
                numB++;
            }
        }
        else if (*itA == 5)
        {
            if (*itB == 0)
            {
                numA++;
            }
            else if (*itB == 2)
            {
                numB++;
            }
        }
        itA++;
        itB++;
        if (itA == vA.end())
        {
            itA = vA.begin();
        }
        if (itB == vB.end())
        {
            itB = vB.begin();
        }
    }
    if (numA > numB)
    {
        cout << "获胜者为 A" << endl;
    }
    else if (numA < numB)
    {
        cout << "获胜者为 B" << endl;
    }
    else
    {
        cout << "draw 平局" << endl;
    }
    return 0;
}
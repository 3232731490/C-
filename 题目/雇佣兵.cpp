#include<iostream>
using namespace std;

/*
案例描述：

雇佣兵的体力最大值为 MM，初始体力值为 00、战斗力为 NN、拥有 XX 个能量元素。

当雇佣兵的体力值恰好为 MM 时，才可以参加一个为期 MM 天的战斗期，战斗期结束体力值将为 00。在同一个战斗期内，雇佣兵每连续战斗 nn 天，战斗力就会上升 11 点，nn 为当前战斗期开始时的战斗力。

一个战斗期结束后，雇佣兵需要用若干个能量元素使其体力恢复到最大值 MM，从而参加下一个战斗期。每个能量元素恢复的体力值不超过当前的战斗力。每个能量元素只能使用一次。

请问：雇佣兵的战斗力最大可以到达多少。

说明：只在战斗期结束后可以使用能量元素，可以使用多个能量元素。
*/

class Person
{
public:
    int m_p;
    int m_f;
    int m_e;
};

int main()
{
    int M, N, X, n;
    cin >> M >> N >> X;
    Person p;
    p.m_p = 0;
    p.m_f = N;
    p.m_e = X;
   
    while (p.m_e != 0)
    {
        n = N;
        while (p.m_p < M)
        {
            if (p.m_e > 0)
            {
                p.m_p +=n;
                p.m_e--;
            }
            else break;
        }
        if (p.m_p < M)
        {
            break;
        }
        else
        {
            p.m_p = M;
            for (int i = 0; i < M; i++)
            {
                if ((i+1) % n== 0)
                {
                    N++;
                }
                p.m_p--;
            }
        }
    }
    cout << N;
    return 0;
}
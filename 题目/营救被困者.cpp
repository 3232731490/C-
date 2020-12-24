#include<iostream>
#include<cmath>
using namespace std;

/*
题目描述：


救生船从大本营出发，营救若干屋顶上的人回到大本营，屋顶数目以及每个屋顶的坐标和人数都将由输入决定，求出所有人都到达大本营并登陆所用的时间。

在直角坐标系的原点是大本营，救生船每次从大本营出发，救了人之后将人送回大本营。坐标系中的点代表屋顶，每个屋顶由其位置坐标和其上的人数表示。

救生船每次从大本营出发，以速度 50 米/分钟驶向下一个屋顶。达到一个屋顶后，救下其上的所有人，每人上船 1 分钟。然后船原路返回，回到大本营，每人下船 0.5 分钟。假设原点与任意一个屋顶的连线不穿过其它屋顶。
*/

class Point
{
public:
    double m_x;
    double m_y;
    double m_r;
    double m_d;
};

int main()
{
    Point p[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].m_x >> p[i].m_y >> p[i].m_r;
        p[i].m_d = sqrt(p[i].m_x * p[i].m_x + p[i].m_y * p[i].m_y);
    }
    double time = 0, t;
    for (int i = 0; i < n; i++)
    {
        time += p[i].m_d / 50 * 2 + 3 * p[i].m_r / 2;
    }
    int T = time;
    if (time - T == 0)
        cout << time;
    else
        cout << ++T;

    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

/*
��Ŀ������


�������Ӵ�Ӫ������Ӫ�������ݶ��ϵ��˻ص���Ӫ���ݶ���Ŀ�Լ�ÿ���ݶ�����������������������������������˶������Ӫ����½���õ�ʱ�䡣

��ֱ������ϵ��ԭ���Ǵ�Ӫ��������ÿ�δӴ�Ӫ������������֮�����ͻش�Ӫ������ϵ�еĵ�����ݶ���ÿ���ݶ�����λ����������ϵ�������ʾ��

������ÿ�δӴ�Ӫ���������ٶ� 50 ��/����ʻ����һ���ݶ����ﵽһ���ݶ��󣬾������ϵ������ˣ�ÿ���ϴ� 1 ���ӡ�Ȼ��ԭ·���أ��ص���Ӫ��ÿ���´� 0.5 ���ӡ�����ԭ��������һ���ݶ������߲����������ݶ���
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
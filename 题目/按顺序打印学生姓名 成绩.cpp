#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

/*
����������

С������˰���ĳ�ſγ̵ĳɼ���
���㰴�ɼ��Ӹߵ��ͶԳɼ����������
�������ͬ�����������ֵ���С����ǰ��
*/
using namespace std;
class Student
{
public:
    string m_name;
    string m_score;
};
class mycompare
{
public:
    bool operator ()( Student &p1, Student &p2)
    {
        if (p1.m_score == p2.m_score)
        {
            return p1.m_name<p2.m_name;
        }
        else return p1.m_score > p2.m_score;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<Student> v;
    for (int i = 0; i < n; i++)
    {
        Student p;
        cin >> p.m_name >> p.m_score;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), mycompare());
    for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->m_name << " " << it->m_score << endl;
    }
    return 0;
}
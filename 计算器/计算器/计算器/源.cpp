#include<iostream>
using namespace std;
#define PI 3.1415926
struct mydata {
	double U[6];
	double t[6];
	double q[6];
	double r[6];
	double avg_q;
	double n;
	double e;
};
int main() {

	double r, p1, p2, n, t, g, U, l, b, p3,d;
	mydata oil[4];
	d = 0.005;
	g = 9.794;
	p1 = 981.0;
	p2 = 1.293;
	p3 = 101330.0;
	b = 0.00822;
	n = 0.0000183;
	l = 0.0015;
	double q0 = 1.602e-19;
	double res_p;  //����� �ٷ����
	double sum_q=0;
	while (1)
	{
		cout << "1������"<<endl;
		cout << "2���˳�"<<endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "������4�������͵�6�β����ĵ�ѹ������ʱ��" << endl;
				for (int i = 0; i < 4; i++)
				{
					sum_q = 0;
					cout << "�������" << (i + 1) << "���͵ε����β���ֵ��" << endl;
					for (int j = 0; j < 6; j++)
					{
						cout << "��" << (j + 1) << "�Σ�" << endl;
						cin >> oil[i].U[j] >> oil[i].t[j];
					
						double rtemp = sqrt((9 * n * (l / oil[i].t[j])) / (2 * (p1 - p2) * g));
						oil[i].r[j] = rtemp;
						double temp1 = 18 * PI / sqrt(2 * g * (p1 - p2));
						double temp2 = d / oil[i].U[j];
						double temp3 = n * l / (oil[i].t[j] * (1 + b / (p3 * oil[i].r[j])));
						oil[i].q[j] = temp1 * temp2 * temp3 * sqrt(temp3);
						sum_q += oil[i].q[j];
						oil[i].avg_q = sum_q / 6;
						oil[i].n = oil[i].avg_q / q0;
						int N = round(oil[i].n);
						oil[i].e = oil[i].avg_q / N;
					}
				}
				cout << "��������" << endl;
				double e_sum=0;
				for (int i = 0; i < 4; i++)
				{
					cout << "��" << (i + 1) << "���͵Σ�" << endl;
					for(int j = 0; j < 6; j++)
					{
						cout << " \t������ " << oil[i].q[j]  << " �뾶�� " << oil[i].r[j] << endl;;
					}
					cout  << "\t����ƽ��ֵ�� "<<oil[i].avg_q << " ������� " << oil[i].n << " Ԫ��ɣ� " << oil[i].e;
					e_sum += oil[i].e;
					cout << endl;
				}
				cout << "\tƽ��Ԫ��ɣ�" << e_sum / 4 << endl;
				break;
			}
			case 2:
				return 0;
		}
	}
	system("pause");
	return 0;
}
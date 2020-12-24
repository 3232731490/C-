#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[30][30];
	int max, max1 = a[0][0];
	cout << "请输入二维数组的行数，列数；" << endl;
	int h, l, k, m, p, t = 1,i=0;
	cin >> h >> l;
	cout << "请按行输入二维数组元素：" << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			cin >> a[i][j];
		}
	}
	for ( i = 0; i < h; i++)
	{
		max = a[i][0];
		for (int j = 0; j < l; j++)
		{
			k = j;
			m = i;
			if (a[i][j] > max)
			{
				k = j;
				max = a[i][j];
			}
		}
				for (int w = 0; w < h; w++)
				{
					if (a[w][k] < a[i][k])
					{
						t = 0; break;
					}
				}
			
			if (t) {
				cout << "此二维数组有鞍点：" <<a[i][k]<<"在第"<< m << "行" << k << "列" << endl;
			}
	}
	if (!t)cout << "此二维数组没有鞍点..." << endl;
	return 0;
}

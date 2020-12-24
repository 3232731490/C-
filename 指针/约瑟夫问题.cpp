#include <stdio.h>
#define N 11
void main()
{
	int a[N] = { 0 }, i = 0, out_n = 0, call_n = 0, * p;
	p = a;
	while (1) //循环计数
	{
		if (*p == 0) //判断是否存活，已经淘汰的人*p==1;
		{
			if (out_n == (N - 1))break;//当最后只存活一人就退出循环
			call_n++;  //计数
			call_n %= 3;   //当计数到3就变为0重新开始计数
			if (call_n == 0) { *p = 1; out_n++; }   //记录被淘汰的人的数据为1，并给淘汰总人数·加1操作
		}
		p++;    //循环转向下一人
		if (p == a + N)
			p = a;
	}
	printf("最后剩余者的编号是：%d\n", p + 1 - a);
}

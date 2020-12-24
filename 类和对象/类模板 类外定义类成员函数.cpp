#include <iostream>
using namespace std;
template<class t>
class Compare
{
public:
	Compare(t a, t b) :x(a), y(b) {};
	t max();
	t min();
private:
	t x, y;
};
template<class t>
t Compare <t>::max()
{
	return (x> y) ? x :y;
}
template<class t>
t Compare <t>::min()
{
	return (x > y) ? y : x;
}
int main()
{
	Compare<int>cmpl(3, 7);
	cout<<"最大值：  "<<cmpl.max()<<endl;
	cout << "最小值：  " << cmpl.min()<<endl;
	cout << endl;
	Compare<float>cmpl2(45.78 , 93.6);
	cout << "最大值：  " << cmpl2.max() << endl;
	cout << "最小值：  " << cmpl2.min()<<endl; cout << endl;
	Compare<char>cmpl3('a', 'A');
	cout << "最大值：  " << cmpl3.max()<<endl;
	cout << "最小值：  " << cmpl3.min()<<endl; cout << endl;
	system("pause");
	return 0;
}


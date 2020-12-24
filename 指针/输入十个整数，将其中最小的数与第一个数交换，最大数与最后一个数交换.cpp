#include<iostream>
#include<string>
using namespace std;
void input(int * arr)
{
	cout << "please enter ten intengers:" << endl;
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
}
void swap(int* arr)
{
	int* min, * max;
	min = &arr[0];
	max = &arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (arr[i] < *min)
			min = &arr[i];
		if (arr[i] > * max)
			max = &arr[i];
}
	int temp1 = arr[0];
	arr[0] = *min;
	*min = temp1;
	int temp2 = arr[9];
	arr[9] = *max;
	*max = temp2;
}
void output(int * arr)
{
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
}
int main()
{
	int arr[10];
	input(arr);
	swap(arr);
	output(arr);
		system("pause");
		return 0;
	
}


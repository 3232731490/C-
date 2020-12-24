#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b > c&& a + c > b&& b + c > a)
    {
        int max = (a > b) ? a : b;
        int min = (a > b) ? b : a;
        a = max; b = min;
        if (c > max)
        {
            if (a * a + b * b == c * c)
            {
                cout << c * c << endl;
            }
            else
            {
                cout << a * a + c * c << endl;
            }
        }
        else if (c > min&& c < max)
        {
            if (c * c + b * b == a * a)
            {
                cout << a * a << endl;
            }
            else
            {
                cout << a * a + c * c << endl;
            }
        }
        else
        {
            if (c * c + b * b == a * a)
            {
                cout << a * a << endl;
            }
            else
            {
                cout << a * a + b * b << endl;
            }
        }
    }
    else
    {
        return 0;
    }
    return 0;
}
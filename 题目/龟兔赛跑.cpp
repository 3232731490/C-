
//借鉴了网上的，然后自己编写
#include<iostream>
using namespace std;
int main()
{
    int T, t = 0;
    cin >> T;
    int s = 0, S = 0;
    while (++t <= T)
    {
        s += 3;
        S += 9;
        if (t % 10 == 0)
        {
            if (s < S)
                for (int i = 0; i < 30; i++)
                {
                    if (++t <= T)
                    {
                        s += 3;
                       
                    }
                    else break;
                }
        }
    }
    if (s < S)
    {
        cout << "^_^ " << S;
    }
    else if (S == s)
    {
        cout << "-_- " << s;
    }
    else {
        cout << "@_@ " << s;
    }
    return 0;
}


//网上的一个答案
//#include<iostream>
//using namespace std;
//int main()
//{
//    int t = 0, trab = 0, T, dtur = 0, drab = 0;
//    bool rest = false;
//    cin >> T;
//    while (t != T)
//    {
//        dtur += 3;
//        if (!rest)
//        {
//            trab++;
//            drab += 9;
//        }
//        t++;
//        if (trab % 10 == 0 && rest == false)
//        {
//            if (drab > dtur)
//            {
//                rest = true;
//                trab += 30;
//            }
//        }
//        if (t == trab)
//            rest = false;
//    }
//    if (drab > dtur)
//        cout << "^_^" << ' ' << drab;
//    else if (drab < dtur)
//        cout << "@_@" << ' ' << dtur;
//    else
//        cout << "-_-" << ' ' << dtur;
//    return 0;
//}
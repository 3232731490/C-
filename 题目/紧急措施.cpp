/*
����������
���գ�һЩ������վ���ܺڿ����֣���Щ��վ���˺š����뼰 email �����ݲ���й¶��
������Щ��վ��ע�������˺ţ�ʹ�õ��û�����һ����ͬ��������ע��ʱʹ������ͬ�� email��
���ʱ�õ����Ƿ�й¶�����ݣ�ϣ�����콫�Լ���������ġ��������£�
���� email �ҵ�����û��������룬Ȼ��������롣
���ĵĹ���Ϊ��Сд�ʹ�д����������ĸ�ַ����ֲ��䡣


�����ʽ��
��һ��Ϊ��� email ��ַ�����Ȳ����� 50 ���ַ���ֻ������ĸ�����ֺ� '@' ���š�

�ڶ���Ϊ�˺��� N��N(0 < N < 10000)��

������ N �У�ÿ�б�ʾһ���˺ţ���ʽΪ��

�û��� ���� email

����֮���õ����ո�ֿ����û��������롢email �������ո��ҳ��Ȳ����� 50 ���ַ���


�����ʽ��
�������У�ÿ��Ϊ���һ���˺ţ�����������˺ţ��޸ĺ�����루֮���õ����ո�ָ�����

���û������˺ţ������"empty"��

*/


/*
������ʽ��
abc@pku.edu.cn
5
helloKitty iLoveCats abc@pku.edu.cn
2012 maya2012 cplusplus@exam.com
KittyCat 5iKitty abc@pku.edu.cn
program password teacher@exam.com
whoAmi Feb.29$ abc@pku.edu.cn

�����ʽ��
helloKitty IlOVEcATS
KittyCat 5IkITTY
whoAmi fEB.29$
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class my
{
public:
    string userID;
    string userKey;
    string userEmail;
};
void swap(string& str)
{
    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
int main()
{
    string email;
    cin >> email;
    int n;
    cin >> n;
    vector<my> myZ;
    for (int i = 0; i < n; i++)
    {
        my my1;
        cin >> my1.userID >> my1.userKey >>my1. userEmail;
        myZ.push_back(my1);
    }
    bool isEmpty = true;
    for (vector<my>::iterator it = myZ.begin(); it != myZ.end(); it++)
    {
        if (it->userEmail == email)
        {
            isEmpty = false;
            swap(it->userKey);
            cout << it->userID << " " << it->userKey << endl;
        }
    }
    if (isEmpty)
    {
        cout << "empty" << endl;
    }
    return 0;
}
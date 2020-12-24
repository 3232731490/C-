#include<iostream>
#include<string>
using namespace std;

//string的构造函数
void test01()
{
	string s1;// 默认构造
	const char* str = "hello world";
	string s2(str);  //使用字符串初始化

	string s3(s2);//拷贝构造

	string s4(5, 'a');//用5个 a 进行初始化

}

//string 的赋值操作
void test02()
{
	string str1;
	str1 = "hello world";  //方法一 等号直接赋值

	string str2;
	str2 = str1;  //方法二

	string str3;
	str3 = 'a';  //方法三  赋值单个字符

	string str4;
	str4.assign("hello C++"); // 方法四 利用string的成员函数赋值

	string str5;
	str4.assign("hello C++",5); //方法五  将字符串前5个字符赋值给str5;

	string str6;
	str6.assign(str5);  //方法六 

	string str7;
	str7.assign(10, 'w');//方法七  赋值10个w给str7
}

//string字符串拼接
void test03()
{
	string str1 = "我";
	str1 += "爱玩游戏";//方法一 重载运算符

	str1 += ':'; //方法二 拼接一个字符

	string str2 = "LOL";
	str1 += str2;  //方法三 拼接一个字符串

	string str3="I";
	str3.append("LOVE");//方法四 利用string 的成员方法拼接

	str3.append("GAME ", 4);// 方法五 将字符串前4个字符拼接

	str3.append(str2); //方法五 追加一个字符串

	str3.append(str2, 0, 3);//方法六 从str2第0个开始拼接3个字符
	cout << str3;
}


//string 的查找和替换
void test04()
{
	//1、查找

	string str1 = "abcdefg";
	//find  从左往右查找
	int pos= str1.find("de"); //返回字符串出现的位置 ，找到返回第一个字符位置，没有找到返回-1
	//rfind  从右往左查找
	pos = str1.rfind("de");  //返回字符串出现的位置 ，找到返回第一个字符位置，没有找到返回-1

	//2、替换
	string str2="abcdefg";
	str2.replace(1, 3, "1111"); //从一号位置开始后的三个字符被替换成 1111  ；str2="a1111efg"

}


//string 字符串比较
void test05()
{
	string str1 = "hello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)  //compare 函数主要作用是比较两个字符串是否相等 
	{
		cout << "str1==str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
	else
	{
		cout << "str1<str2" << endl;
	}
}

//string 中单个字符读取
void test06()
{
	string str1 = "hello";

	//1、通过[]访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;

	//2、通过at方法访问单个字符
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str1[0] = 'x';
	str1.at(0) = 'h';
}

//string 插入和删除
void test07()
{
	string str1 = "hello";

	//1、插入
	str1.insert(1, "111");//从一号位插入"111"字符串  str1="h111ello";

	//2、删除
	str1.erase(1, 3);//从一号位起删除3个字符
}

//从字符串中获取子串
void test08()
{
	string str = "abcdefg";
	string substr = str.substr(1, 3);//从一号位开始截取3个字符给substr


	//应用
	string email = "nilu@qq.com";
	int pos=email.find("@");
	string username = email.substr(0, pos);//从邮箱中截取用户名
}
int main()
{
	//string 的构造函数
	test01();

	//string 的赋值操作
	test02();

	//string 字符串拼接
	test03();

	//string 的查找和替换
	test04();

	//string 字符串比较
	test05();

	//string 中单个字符读写
	test06();

	//string 插入和删除
	test07();

	//从字符串中获取子串
	test08();
	return 0;
}
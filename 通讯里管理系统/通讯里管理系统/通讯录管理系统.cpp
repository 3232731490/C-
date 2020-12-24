#include<iostream>
#include<string>
using namespace std;

//************************************菜单界面************************************

void showMeau()
{
	cout << "*************************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "*************************" << endl;
}

//***************************联系人结构体*****************************

struct person
{
	string name;     //姓名
	int m_sex;       //性别：1、男，2、女
	int m_Age;       //年龄
	string m_phone;  //电话
	string m_addr;   //住址
};

//*******************************通讯录结构体***********************************

struct addressbooks
{
	person personArray [1000];
	int m_size;      //记录通讯录中有几个人
};

//*****************************************添加通讯录**************************************

void addperson(addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_size == 1000)
	{
		cout << "通讯录已满..." << endl;
		return;
	}
	else
	{
		//姓名

		string name;    
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;
		cout << "请输入性别：" << endl;
		cout << "1、男  2、女" << endl;
		
		//性别

		int sex = 0;  
		while (true)  
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误请重新输入..." << endl;
		}
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		
		//联系电话

		cout << "请输入电话：" << endl;
		string num;
		cin >> num;
		abs->personArray[abs->m_size].m_phone = num;
		
		//住址

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_size].m_addr = address;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功..." << endl;

		system("pause");
		system("cls");    //清屏操作
	}
}

//*******************************************8显示联系人**************************************

void showperson(addressbooks* abs)
{
	//判断通讯录中人数是否为0，如果为0，提示为空
	if (abs->m_size == 0)
		cout << "当前通讯录为空..." << endl;
	else {
		for (int i = 0; i < abs->m_size; i++)
			cout << "姓名：" << abs->personArray[i].name << '\t'
			     << "性别：" << (abs->personArray[i].m_sex==1?"男":"女") << '\t'
			     << "年龄：" << abs->personArray[i].m_Age << '\t'
			     << "电话：" << abs->personArray[i].m_phone << '\t'
			     << "住址：" << abs->personArray[i].m_addr << endl;
		system("pause");
		system("cls");
	}
}

//检测联系人是否存在，如果存在，返回该联系人在数组中的位置，不存在返回-1

int isExist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;     //找到了 返回它的下标标号
	}
	return -1;  //未找到，返回-1
}


//***********************************删除联系人*************************************

void deleteperson(addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//查询联系人中是否有此人...
    int ret = isExist(abs, name);
	
	if (ret == -1)
		cout << "查无此人" << endl;
	else
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];   //使需要删除的联系人后的联系人都向前移一位
		}
		abs->m_size--;    //更新通讯录人数...
	}
	system("pause");
	system("cls");
}

//查找联系人

void findperson(addressbooks* abs )
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);   //判断联系人是否存在通讯录中
	if (ret == -1)
		cout << "查无此人" << endl;
	else
	{
		cout << "姓名：" << abs->personArray[ret].name << '\t'
			<< "性别：" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << '\t'
			<< "年龄：" << abs->personArray[ret].m_Age << '\t'
			<< "电话：" << abs->personArray[ret].m_phone << '\t'
			<< "住址：" << abs->personArray[ret].m_addr << endl;
	}
	system("pause");
	system("cls");
}

//********************************修改联系人*****************************************

void modifyperson(addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret =isExist(abs, name);//判断通讯录中是否有此人
	if (ret == -1)
		cout << "查无此人" << endl;
	
	else
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].name = name;
		
		cout << "请输入性别：" << endl;
		int sex;
		cin >> sex;
		while(true)
		{
			cout << "1、男   2、女" << endl;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			else cout << "输入有误，请重新输入" << endl;
		}
		
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		
		cout << "请输入联系电话：" << endl;
		string num;
		cin >> num;
		abs->personArray[ret].m_phone;
		
		cout << "请输入家庭住址：" << endl;
		string add;
		cin >> add;
		abs->personArray[ret].m_addr = add;
	}
	system("pause");
		system("cls");
}

//***************************清空联系人*****************************

void cleanperson(addressbooks* abs)
{
	cout << "您是否真的要清空...." << endl;
	cout << "1、  确认    2、   取消" << endl;
	int i;
	cin >> i;
	if (i == 1)
	{
		abs->m_size = 0;    //将通讯录成员数量置为0
		cout << "通讯录已清空..." << endl;
	}
	else if(i==2)
	{
		cout << "已取消清空操作..." << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	addressbooks abs;
	abs.m_size = 0;
	while (true) 
	{//菜单调用
		showMeau();
		int select = 0;//创建一个用户选择输入的变量
		cin >> select;
		switch (select)
		{
		case 1: //添加联系人
			addperson(&abs);
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
    	deleteperson(&abs);
		break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空联系人
			cleanperson( & abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		}
}
	system("pause");
	return 0;
}
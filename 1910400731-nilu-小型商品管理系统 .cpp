#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class User
{
public:
	User(string admin, string key)
	{
		m_adminNum = admin;
		m_key = key;
	}
	User() {}
	static void Set0_UserNum()
	{
		usersNum = 0;
	}
	static void add_userNum()   //设置使用者人数+1
	{
		usersNum++;
	}
	static void sub_userNum()   //设置使用者人数-1
	{
		usersNum--;
	}
	static int get_userNum()   //获取使用者总人数
	{
		return usersNum;
	}
	void set_admin_key(string admin, string key)
	{
		m_adminNum = admin;
		m_key = key;
	}
	string get_admin()
	{
		return m_adminNum;
	}
	string get_key()
	{
		return m_key;
	}
private:
	string m_adminNum;  //账号
	string m_key;   //密码
	static int usersNum;  //使用者总人数
};
int User::usersNum = 0;

class Goods
{
public:
	Goods(int num, string name, double price, double discount)
	{
		m_num = num;
		m_name = name;
		m_price = price;
		m_discount = discount;
	}
	Goods() {}
	void set_num(int num)
	{
		m_num = num;
	}
	void set_name(string name)
	{
		m_name = name;
	}
	void set_price(double price)
	{
		m_price = price;
	}
	void set_discount(double discount)
	{
		m_discount = discount;
	}
	int get_num()
	{
		return m_num;
	}
	string get_name()
	{
		return m_name;
	}
	double get_price()
	{
		return m_price;
	}
	double get_discount()
	{
		return m_discount;
	}
	static void add_goodsSum()  //增加商品总数
	{
		m_goodsSum++;
	}
	static void sub_goodsSum()  //减少商品总数
	{
		m_goodsSum--;
	}
	static int get_goodsSum()  //获取商品总数
	{
		return m_goodsSum;
	}
	static void Set0_GoodsNum()   //使商品数清零
	{
		m_goodsSum = 0;
	}
private:
	int m_num;  //序号
	string m_name;  //名称
	double m_price;  //价格
	double m_discount; //折扣
	static int m_goodsSum;  //商品总数
};
int Goods::m_goodsSum = 0;

void showCommonMenu()
{
	cout << endl << endl << endl;
	cout << "					小型商品管理系统(普通用户版)" << endl;
	cout << endl << endl << endl;
	cout << "					1. 查询商品价格信息" << endl;
	cout << "					2. 商品价格排行浏览" << endl;
	cout << "					3. 返回上一级" << endl;
	cout << "					0. 退出系统" << endl;
}
void showAdminMenu()
{
	cout << endl << endl << endl;
	cout << "					小型商品管理系统(管理员版)" << endl;
	cout << endl << endl << endl;
	cout << "					1. 查询商品价格信息" << endl;
	cout << "					2. 商品价格排行浏览" << endl;
	cout << "					3. 增加商品价格信息" << endl;
	cout << "					4. 修改商品价格信息" << endl;
	cout << "					5. 删除商品价格信息" << endl;
	cout << "					6. 用户管理" << endl;
	cout << "					7. 返回上一级" << endl;
	cout << "					8. 清空商品价格信息" << endl;
	cout << "					0. 退出系统" << endl;
}
void showSettingUser()
{
	cout << endl << endl << endl;
	cout << "					1. 创建用户信息" << endl;
	cout << "					2. 增加用户信息" << endl;
	cout << "					3. 删除用户信息" << endl;
	cout << "					4. 修改用户信息" << endl;
	cout << "					5. 浏览用户信息" << endl;
	cout << "					6. 返回上一级" << endl;
	cout << "					7. 清空用户信息" << endl;
	cout << "					0. 退出系统" << endl;
}
void biggersort(Goods* G,int sum)
{
	for (int i = 0; i < sum; i++)
	{
		for (int j = i + 1; j < sum; j++)
		{
			if (G[i].get_price() > G[j].get_price())
			{
				Goods temp = G[i];
				G[i] = G[j];
				G[j] = temp;
			}
		}
	}
}
void smallersort(Goods* G,int sum)
{
	for (int i = 0; i < sum; i++)
	{
		for (int j = i + 1; j < sum; j++)
		{
			if (G[i].get_price() < G[j].get_price())
			{
				Goods temp = G[i];
				G[i] = G[j];
				G[j] = temp;
			}
		}
	}
}
int main()
{
	while (1)
	{
	LL:
		cout << "					小型商品管理系统" << endl << endl << endl;
		cout << "					1. 用户登录" << endl;
		cout << "					2. 商品信息管理" << endl;
		cout << "					3. 权限管理" << endl;
		cout << "					0. 退出系统" << endl;
		int choice;
		cin >> choice;
		ifstream ifs;
		ofstream ofs;
		switch (choice)
		{
		case 0:
		{
			cout << "欢迎下次使用!" << endl;
			exit(1);
		}
		case 1:
		{
		NL:
			cout << "[1]普通用户    [2]管理员" << endl;
			int n;
			cin >> n;
			if (1 == n)
			{
				ifs.open("commonUser.txt");
				//文件夹不存在
				if (!ifs)
				{
					ofs.open("commonUser.txt");
					cout << "普通用户文件不存在,请创建!" << endl;
					system("pause");
					system("cls");
					string admin, key;
				ADDcommon:
					cout << "请输入账号:" << endl;
					cin >> admin;
					cout << "请输入密码:" << endl;
					cin >> key;
					ofs << admin << " " << key << endl;
					User::add_userNum();  //使使用者人数+1
					system("cls");
					ofs.close();
					cout << "创建成功!" << endl;
					cout << "返回登陆界面..." << endl;
					system("pause");
					system("cls");
					goto LL;
				}
				//文件存在
				else
				{
					string admin, ifsadmin, key, ifskey;
					if (User::get_userNum() == 0)
					{
						while (!ifs.eof())
						{
							ifs >> ifsadmin >> ifskey;
							User::add_userNum();
						}
						if (User::get_userNum() == 1)
						{
							system("cls");
							cout << "普通用户文件夹为空,请先注册..." << endl;
							system("pause");
							ifs.close();
							ofs.open("commonUser.txt");
							string admin, key;
							cout << "请输入账号:" << endl;
							cin >> admin;
							cout << "请输入密码:" << endl;
							cin >> key;
							ofs << admin << " " << key << endl;
							User::add_userNum();  //使使用者人数+1
							system("cls");
							cout << "注册成功,返回登录页面..." << endl;
							system("pause");
							system("cls");
							goto NL;
						}
					}
					cout << "已有用户,请登录..." << endl;
					int flag = 0, errorCount = 0;
				Error:
					ifs.close();
					ifs.open("commonUser.txt");
					cout << "您还有" << 3 - errorCount << "次输入机会" << endl;
					if (errorCount == 3)
					{
						cout << "输入账号密码次数过多,已自动退出系统" << endl;
						exit(0);
					}
					cout << "请输入账号:" << endl;
					cin >> admin;
					cout << "请输入密码:" << endl;
					cin >> key;
					while (!ifs.eof())
					{
						ifs >> ifsadmin >> ifskey;
						if (ifsadmin == admin && ifskey == key)
						{
							flag = 1;
							system("cls");
							cout << "登录成功!" << endl;
							ofs.close();
							ifs.close();
							break;
						}
					}
					if (flag)
					{
					NN:
						showCommonMenu();  //展示菜单
						int select;
						cin >> select;
						switch (select)
						{
						case 0:
						{
							system("cls");
							cout << "欢迎下次使用..." << endl;
							exit(1);
						}
						case 1:  //查询商品价格信息
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "未找到商品信息文件夹" << endl;
								cout << "请创建商品信息文件" << endl;
								ofs.open("Goods.txt");
								string name;  //名称
								double price;  //价格
								double discount;  //折扣
							NLL:
								cout << "请输入商品名称" << endl;
								cin >> name;
								cout << "请输入商品价格" << endl;
								cin >> price;
								cout << "请输入商品折扣" << endl;
								cin >> discount;
								ofs << Goods::get_goodsSum()+1 << " " << name << " " << price << " " << discount << endl;
								Goods::add_goodsSum();
								system("cls");
								cout << "创建成功!" << endl;
							ErrorL:
								cout << "请问您是否要继续添加?(Y/N)" << endl;
								char c;
								cin >> c;
								if (c == 'Y' || c == 'y')
								{
									system("cls");
									goto NLL;
								}
								else if (c == 'N' || c == 'n')
								{
									system("cls");
									ofs.close();
									Goods::Set0_GoodsNum();
									cout << "创建完毕!" << endl;
									goto NN;
								}
								else
								{
									system("cls");
									cout << "您的输入有误,请重新输入..." << endl;
									goto ErrorL;
								}
							}
							else  //存在文件
							{
								string ifsname;  //名称
								int ifsnum;  //编号
								double ifsprice, ifsdiscount;  //价格和折扣
								int flag1 = 0;
								if (Goods::get_goodsSum() == 0)
								{
									flag1 = 1;
									while (!ifs.eof())
									{
										ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
										Goods::add_goodsSum();
									}
									if (Goods::get_goodsSum() == 1)
									{
										system("cls");
										cout << "文件信息为空! 请联系管理员添加" << endl;
										system("pause");
										goto NN;
										system("cls");
									}
								}
								int sum = 0;
								if (flag1)
									sum = Goods::get_goodsSum() - 1;
								else
									sum = Goods::get_goodsSum();
								Goods* G = new Goods[sum];
								ifs.close();
								ifs.open("Goods.txt");  //打开文件
								int i = 0;
								for (int i = 0; i < sum; i++)
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									G[i].set_discount(ifsdiscount);
									G[i].set_name(ifsname);
									G[i].set_num(ifsnum);
									G[i].set_price(ifsprice);
								}
								ifs.close();  //关闭文件

								cout << "请输入您查询商品的方式 :" << endl;
							NLRenew:
								cout << "[1] 序号 |  [2] 名称" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)   //通过序号查询
								{
									system("cls");
									int num;
									int flag = 0;
								NLLL:
									cout << "请输入商品序号:" << endl;
									cin >> num;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_num() == num)
										{
											flag = 1;
											cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "查找失败 , 无该商品信息!" << endl;
									NLLLL:
										cout << "请问您是否要继续查找?(Y/N)" << endl;
										char c;
										cin >> c;
										if (c == 'Y' || c == 'y')
										{
											system("cls");
											goto NLLL;
										}
										else if (c == 'N' || c == 'n')
										{
											ofs.open("Goods.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
											}
											ofs.close();
											Goods::Set0_GoodsNum();
											cout << " 谢谢使用" << endl;
											system("pause");
											system("cls");
											goto NN;
										}
										else
										{
											cout << "您的输入有误,请重新输入..." << endl;
											goto NLLLL;
										}
									}
									else
									{
										ofs.open("Goods.txt");
										for (int i = 0; i < sum; i++)
										{
											ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
										}
										ofs.close();
										Goods::Set0_GoodsNum();
										system("cls");
										cout << "查找成功,已返回..." << endl;
										goto NN;
									}
								}
								else if (2 == choice)   //通过名称查询
								{
									system("cls");
									string name;
									int flag = 0;
								LLLN:
									cout << "请输入商品名称:" << endl;
									cin >> name;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_name() == name)
										{
											flag = 1;
											cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "查找失败 , 无该商品信息!" << endl;
									NLLLLL:
										cout << "请问您是否要继续查找?(Y/N)" << endl;
										char c;
										cin >> c;
										if (c == 'Y' || c == 'y')
										{
											system("cls");
											goto LLLN;
										}
										else if (c == 'N' || c == 'n')
										{
											ofs.open("Goods.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
											}
											ofs.close();
											Goods::Set0_GoodsNum();
											cout << " 谢谢使用" << endl;
											system("pause");
											system("cls");
											goto NN;
										}
										else
										{
											cout << "您的输入有误,请重新输入..." << endl;
											goto NLLLLL;
										}
									}
									else
									{
										ofs.open("Goods.txt");
										for (int i = 0; i < sum; i++)
										{
											ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
										}
										ofs.close();
										Goods::Set0_GoodsNum();
										system("cls");
										cout << "查找成功,已返回..." << endl;
										goto NN;
									}
								}
								else
								{
									system("cls");
									cout << "您的输入有误,请重新输入..." << endl;
									goto NLRenew;
								}
							}
						}
						case 2:  //商品价格排行浏览
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "未找到商品价格信息文件! 请先创建..." << endl;
								system("pause");
								goto NN;
								system("cls");
							}
							string ifsname;  //名称
							int ifsnum;  //编号
							double ifsprice, ifsdiscount;  //价格和折扣
							int flag1 = 0;
							if (Goods::get_goodsSum() == 0)
							{
								flag1 = 1;
								while (!ifs.eof())
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									Goods::add_goodsSum();

								}
								if (Goods::get_goodsSum() == 1)
								{
									system("cls");
									cout << "文件信息为空! 请联系管理员添加" << endl;
									system("pause");
									goto NN;
									system("cls");
								}
							}
							int sum = 0;
							if (flag1)
								sum = Goods::get_goodsSum() - 1;
							else
								sum = Goods::get_goodsSum();
							Goods* G = new Goods[sum];

							ifs.close();
							ifs.open("Goods.txt");  //打开文件
							int i = 0;
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_discount(ifsdiscount);
								G[i].set_name(ifsname);
								G[i].set_num(ifsnum);
								G[i].set_price(ifsprice);
							}
							ifs.close();  //关闭文件
							Goods::Set0_GoodsNum();
						A:
							cout << "您想要看价格有小到大(1) 还是由大到小(0) 进行排序?" << endl;
							int choice;
							cin >> choice;
							if (1 == choice)
							{
								if (sum > 1)
									biggersort(G,sum);  //升序排
							}
							else if (0 == choice)
							{
								if (sum > 1)
									smallersort(G,sum);  //降序排
							}
							else
							{
								cout << "您的输入有误, 请重新输入..." << endl;
								goto A;
							}
							//打印输出
							for (int i = 0; i < sum; i++)
							{
								cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
							}
							delete[] G;
							system("pause");
							system("cls");
							goto NN;
						}
						case 3:  //返回上一级
						{
							system("cls");
							goto LL;
						}
						default:
						{
							system("cls");
							cout << "您的输入有误,请重新输入..." << endl;
							system("pause");
							goto NN;
						}
						}
					}
					else
					{
						errorCount++;
						system("cls");
						cout << "账号或密码错误";
						cout << "请重新输入..." << endl;
						goto Error;
					}
				}
			}
			else if (2 == n)
			{
				ifs.open("adminUser.txt");
				if (!ifs)
				{
					cout << "管理员用户文件不存在,请创建!" << endl;
					ofs.open("adminUser.txt");
					string admin, key;
				ADDadmin:
					cout << "请输入账号:" << endl;
					cin >> admin;
					cout << "请输入密码:" << endl;
					cin >> key;
					ofs << admin << " " << key << endl;
					User::add_userNum();  //使使用者人数+1
					system("cls");
					cout << "创建成功!" << endl;
					cout << "返回登录界面..." << endl;
					system("pause");
					system("cls");
					ofs.close();
					goto LL;
				}
				else   //文件存在
				{
					string ifsadmin, ifskey, admin, key;
					if (User::get_userNum() == 0)
					{
						while (!ifs.eof())
						{
							ifs >> ifsadmin >> ifskey;
							User::add_userNum();
						}
						if (User::get_userNum() == 1)
						{
							system("cls");
							cout << "管理员文件夹为空,请先注册..." << endl;
							system("pause");
							ifs.close();
							ofs.open("adminUser.txt");
							string admin, key;
							cout << "请输入账号:" << endl;
							cin >> admin;
							cout << "请输入密码:" << endl;
							cin >> key;
							ofs << admin << " " << key << endl;
							User::add_userNum();  //使使用者人数+1
							system("cls");
							cout << "注册成功,返回登录页面..." << endl;
							system("pause");
							system("cls");
							goto NL;
						}
					}
					cout << "已有用户,请登录..." << endl;
					int flag = 0, errorCount = 0;
				Error2:
					ifs.close();
					ifs.open("adminUser.txt");
					cout << "您还有" << 3 - errorCount << "次输入机会" << endl;
					if (errorCount == 3)
					{
						cout << "输入账号密码次数过多,已自动退出系统" << endl;
						exit(0);
					}
					cout << "请输入账号:" << endl;
					cin >> admin;
					cout << "请输入密码:" << endl;
					cin >> key;
					while (!ifs.eof())
					{
						ifs >> ifsadmin >> ifskey;
						if (ifsadmin == admin && ifskey == key)
						{
							flag = 1;
							system("cls");
							cout << "登录成功!" << endl;
							//							ofs.close();
							ifs.close();
							break;
						}
					}
					if (flag)
					{
					HH:
						showAdminMenu();
						int choice;
						cin >> choice;
						switch (choice)
						{
						case 0:   //退出系统
						{
							system("cls");
							cout << "欢迎下次使用..." << endl;
							system("pause");
							exit(1);
						}
						case 1:   //查询商品价格信息
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "未找到商品信息文件夹" << endl;
								cout << "请创建商品信息文件" << endl;
								ofs.open("Goods.txt");
								string name;  //名称
								double price;  //价格
								double discount;  //折扣
							NLL2:
								cout << "请输入商品名称" << endl;
								cin >> name;
								cout << "请输入商品价格" << endl;
								cin >> price;
								cout << "请输入商品折扣" << endl;
								cin >> discount;
								ofs << Goods::get_goodsSum()+1 << " " << name << " " << price << " " << discount << endl;
								Goods::add_goodsSum();
								system("cls");
								cout << "创建成功!" << endl;
							ErrorN:
								cout << "请问您是否要继续添加?(Y/N)" << endl;
								char c;
								cin >> c;
								if (c == 'Y' || c == 'y')
								{
									system("cls");
									goto NLL2;
								}
								else if (c == 'N' || c == 'n')
								{
									system("cls");
									ofs.close();
									Goods::Set0_GoodsNum();
									cout << "创建完毕!" << endl;
									goto HH;
								}
								else
								{
									system("cls");
									cout << "您的输入有误,请重新输入..." << endl;
									goto ErrorN;
								}
							}
							else  //存在文件
							{
								string ifsname;  //名称
								int ifsnum;  //编号
								double ifsprice, ifsdiscount;  //价格和折扣
								int flag1 = 0;
								if (Goods::get_goodsSum() == 0)
								{
									flag1 = 1;
									while (!ifs.eof())
									{
										ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
										Goods::add_goodsSum();
									}
									if (Goods::get_goodsSum() == 1)
									{
										system("cls");
										cout << "文件信息为空,请添加商品价格信息!" << endl;
										system("pause");
										goto HH;
									}
								}
								int sum;
								if (flag1)
									sum = Goods::get_goodsSum() - 1;
								else
									sum = Goods::get_goodsSum();
								Goods* G = new Goods[sum];
								ifs.close();
								ifs.open("Goods.txt");  //打开文件
								int i = 0;
								for (int i = 0; i < sum; i++)
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									G[i].set_discount(ifsdiscount);
									G[i].set_name(ifsname);
									G[i].set_num(ifsnum);
									G[i].set_price(ifsprice);
								}
								ifs.close();  //关闭文件
								cout << "请输入您查询商品的方式 :" << endl;
							NLRenew2:
								cout << "[1] 序号 |  [2] 名称" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)   //通过序号查询
								{
									system("cls");
									int num;
									int flag = 0;
								E:
									cout << "请问您是否继续查找?(Y/N)" << endl;
									char q;
									cin >> q;
									if ('Y' == q || 'y' == q)
									{
									NLLL2:
										cout << "请输入商品序号:" << endl;
										cin >> num;
										for (int i = 0; i < sum; i++)
										{
											if (G[i].get_num() == num)
											{
												flag = 1;
												cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
												system("pause");
												system("cls");
												break;
											}
										}
										if (!flag)
										{
											cout << "查找失败 , 无该商品信息!" << endl;
										NLLLL2:
											cout << "请问您是否要继续查找?(Y/N)" << endl;
											char c;
											cin >> c;
											if (c == 'Y' || c == 'y')
											{
												system("cls");
												goto NLLL2;
											}
											else if (c == 'N' || c == 'n')
											{
												ofs.open("Goods.txt");
												for (int i = 0; i < sum; i++)
												{
													ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
												}
												ofs.close();
												Goods::Set0_GoodsNum();
												cout << " 谢谢使用" << endl;
												system("pause");
												system("cls");
												goto HH;
											}
											else
											{
												system("cls");
												cout << "您的输入有误,请重新输入..." << endl;
												system("pause");
												goto NLLLL2;
											}
										}
										else
										{
											ofs.open("Goods.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
											}
											ofs.close();
											Goods::Set0_GoodsNum();
											system("cls");
											goto HH;
										}
									}
									else if ('N' == q || 'n' == q)
									{
										system("cls");
										goto HH;
									}
									else
									{
										system("cls");
										goto E;
									}
								}
								else if (2 == choice)   //通过名称查询
								{
									system("cls");
									string name;
									int flag = 0;
								LLLN2:
									cout << "请输入商品名称:" << endl;
									cin >> name;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_name() == name)
										{
											flag = 1;
											cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "查找失败 , 无该商品信息!" << endl;
									NLLLLL2:
										cout << "请问您是否要继续查找?(Y/N)" << endl;
										char c;
										cin >> c;
										if (c == 'Y' || c == 'y')
										{
											system("cls");
											goto LLLN2;
										}
										else if (c == 'N' || c == 'n')
										{
											ofs.open("Goods.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
											}
											ofs.close();
											Goods::Set0_GoodsNum();
											delete[]G;
											cout << " 谢谢使用" << endl;
											system("pause");
											system("cls");
											goto HH;
										}
										else
										{
											cout << "您的输入有误,请重新输入..." << endl;
											goto NLLLLL2;
										}
									}
									else
									{
										ofs.open("Goods.txt");
										for (int i = 0; i < sum; i++)
										{
											ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
										}
										ofs.close();
										Goods::Set0_GoodsNum();
										delete[]G;
										system("cls");
										goto HH;
									}
								}
								else
								{
									system("cls");
									cout << "您的输入有误,请重新输入..." << endl;
									goto NLRenew2;
								}
							}
						}
						case 2:   //商品价格排行浏览
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "未找到商品价格信息文件! 请先创建..." << endl;
								system("pause");
								goto HH;
								system("cls");
							}
							string ifsname;  //名称
							int ifsnum;  //编号
							double ifsprice, ifsdiscount;  //价格和折扣
							int flag1 = 0;
							if (Goods::get_goodsSum() == 0)
							{
								flag1 = 1;
								while (!ifs.eof())
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									Goods::add_goodsSum();
								}
								if (Goods::get_goodsSum() == 1)
								{
									cout << "商品价格信息文件为空,请添加..." << endl;
									system("pause");
									system("cls");
									goto HH;
								}
							}
							int sum;
							if (flag1)
								sum = Goods::get_goodsSum() - 1;
							else
								sum = Goods::get_goodsSum();
							Goods* G = new Goods[sum];
							ifs.close();
							ifs.open("Goods.txt");  //打开文件
							int i = 0;
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_discount(ifsdiscount);
								G[i].set_name(ifsname);
								G[i].set_num(ifsnum);
								G[i].set_price(ifsprice);
							}
							ifs.close();  //关闭文件
							Goods::Set0_GoodsNum();
						B:
							cout << "您想要看价格有小到大(1) 还是由大到小(0) 进行排序?" << endl;
							int choice;
							cin >> choice;
							if (1 == choice)
							{
								if (sum > 1)
									biggersort(G,sum);  //升序排
							}
							else if (0 == choice)
							{
								if (sum > 1)
									smallersort(G,sum);  //降序排
							}
							else
							{
								cout << "您的输入有误, 请重新输入..." << endl;
								goto B;
							}
							//打印输出
							for (int i = 0; i < sum; i++)
							{
								cout << "商品编号: " << G[i].get_num() << "\t商品名称: " << G[i].get_name() << "\t商品价格: " << G[i].get_price() << "\t商品折扣: " << G[i].get_discount() << endl;
							}
							system("pause");
							system("cls");
							goto HH;
						}
						case 3:   //增加商品价格信息
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "未找到商品价格信息文件! 请先创建..." << endl;
								system("pause");
								system("cls");
								goto HH;
							}
							string ifsname;  //名称
							int ifsnum;  //编号
							double ifsprice, ifsdiscount;  //价格和折扣
							int flag1 = 0;
							if (Goods::get_goodsSum() == 0)
							{
								flag1 = 1;
								while (!ifs.eof())
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									Goods::add_goodsSum();
								}
							}
							ifs.close();
							ofs.open("Goods.txt", ios::app);
						C:
							cout << "请输入商品名称" << endl;
							cin >> ifsname;
							cout << "请输入商品价格" << endl;
							cin >> ifsprice;
							cout << "请输入商品折扣" << endl;
							cin >> ifsdiscount;
							ofs << Goods::get_goodsSum() << " " << ifsname << " " << ifsprice << " " << ifsdiscount << endl;
							Goods::add_goodsSum();
							cout << "添加成功!" << endl;
							cout << "请问您是否还要继续添加?(Y/N)" << endl;
							char c;
						D:
							cin >> c;
							if (c == 'Y' || c == 'y')
							{
								system("cls");
								goto C;
							}
							else if (c == 'N' || c == 'n')
							{
								system("cls");
								ofs.close();
								cout << "添加完毕!" << endl;
								Goods::Set0_GoodsNum();
								//delete[] G;
								goto HH;
							}
							else
							{
								system("cls");
								cout << "您的输入有误,请重新输入..." << endl;
								goto D;
							}
						}
						case 4:   //修改商品价格信息
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "商品价格信息文件不存在,请先创建!" << endl;
								system("pause");
								system("cls");
								goto HH;
							}
							string ifsname;
							int ifsnum;
							int flag1 = 0;
							double ifsprice, ifsdiscount;
							if (Goods::get_goodsSum() == 0)
							{
								flag1 = 1;
								while (!ifs.eof())
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									Goods::add_goodsSum();
								}
								if (Goods::get_goodsSum() == 1)
								{
									cout << "商品信息文件夹为空,请先添加信息..." << endl;
									system("pause");
									system("cls");
									goto HH;
								}
							}
							int sum;
							if (flag1)
								sum = Goods::get_goodsSum() - 1;
							else
								sum = Goods::get_goodsSum();
							Goods* G = new Goods[sum];
							ifs.close();
							ifs.open("Goods.txt");
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_num(ifsnum);
								G[i].set_name(ifsname);
								G[i].set_price(ifsprice);
								G[i].set_discount(ifsdiscount);
							}
							ifs.close();
						G:	cout << "请输入您要修改的商品编号:" << endl;
							int num, flag = 0;
							cin >> num;
							for (int i = 0; i < sum; i++)
							{
								if (G[i].get_num() == num)
								{
									cout << "已找到该商品,请问您确认要修改它吗?(Y/N)" << endl;
									char w;
								F:
									cin >> w;
									if ('Y' == w || 'y' == w)
									{
										flag = 1;
										cout << "请您重新输入该商品的信息:" << endl;
										cout << "请输入商品名称:" << endl;
										cin >> ifsname;
										cout << "请输入商品价格:" << endl;
										cin >> ifsprice;
										cout << "请输入商品折扣:" << endl;
										cin >> ifsdiscount;
										G[i].set_name(ifsname);
										G[i].set_price(ifsprice);
										G[i].set_discount(ifsdiscount);
										break;
									}
									else if ('N' == w || 'n' == w)
									{
										system("cls");
										goto HH;
									}
									else
									{
										system("cls");
										cout << "您的输入有误,请重新输入..." << endl;
										goto F;
									}
								}
							}
							Goods::Set0_GoodsNum();
							if (flag)
							{
								ofs.open("Goods.txt");
								for (int i = 0; i < sum; i++)
								{
									ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
								}
								cout << "商品信息修改完成!" << endl;
								ofs.close();
								system("pause");
								system("cls");
								goto HH;
							}
							else
							{
								system("cls");
								cout << "未找到该商品信息..." << endl;
								cout << "请问您是否要重新输入?(Y/N)" << endl;
								char q;
							H:
								cin >> q;
								if ('Y' == q || 'y' == q)
								{
									system("cls");
									goto G;
								}
								else if ('N' == q || 'n' == q)
								{
									goto HH;
								}
								else
								{
									cout << "您的输入有误,请重新输入..." << endl;
									goto H;
								}
							}
						}
						case 5:  //删除商品价格信息
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "商品价格信息文件不存在,请先创建!" << endl;
								system("pause");
								system("cls");
								goto HH;
							}
							string ifsname;
							int ifsnum;
							int flag1 = 0;
							double ifsprice, ifsdiscount;
							if (Goods::get_goodsSum() == 0)
							{
								flag1 = 1;
								while (!ifs.eof())
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									Goods::add_goodsSum();
								}
								if (Goods::get_goodsSum() == 1)
								{
									cout << "商品信息文件夹为空,请先添加信息..." << endl;
									system("pause");
									system("cls");
									goto HH;
								}
							}
							int sum;
							if (flag)
								sum = Goods::get_goodsSum() - 1;
							else
								sum = Goods::get_goodsSum();
							Goods* G = new Goods[sum];
							ifs.close();
							ifs.open("Goods.txt");
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_discount(ifsdiscount);
								G[i].set_name(ifsname);
								G[i].set_num(ifsnum);
								G[i].set_price(ifsprice);
							}
							ifs.close();  //关闭文件
						G2:	cout << "请输入您要删除的商品名称:" << endl;
							int flag = 0;
							string name;
							cin >> name;
							for (int i = 0; i < sum; i++)
							{
								if (G[i].get_name() == name)
								{
								F2:	cout << "已找到该商品,请问您确认要删除它吗?(Y/N)" << endl;
									char w,q;
									cin >> w;
									if ('Y' == w || 'y' == w)
									{
									GG:	cout << "请您再次确认您是否要删除该商品...(Y/N)" << endl;
										cin >> q;
										if ('Y' == q || 'y' == q)
										{
											flag = 1;
											for (int j = i + 1; j < sum; j++)
											{
												G[j].set_num(G[j].get_num() - 1);
												G[j - 1] = G[j];
											}
											sum--;
											break;
										}
										else if ('N' == q || 'n' == q)
										{
											system("cls");
											cout << "已取消删除该商品，即将返回..." << endl;
											system("pause");
											goto HH;
										}
										else
										{
											system("cls");
											cout << "您的输入有误，请重新输入..." << endl;
											system("pause");
											goto GG;
										}
									}
									else if ('N' == w || 'n' == w)
									{
										system("cls");
										goto HH;
									}
									else
									{
										system("cls");
										cout << "您的输入有误,请重新输入..." << endl;
										goto F2;
									}
								}
							}
							if (flag)
							{
								ofs.open("Goods.txt");
								for (int i = 0; i < sum; i++)
								{
									ofs << G[i].get_num() << " " << G[i].get_name() << " " << G[i].get_price() << " " << G[i].get_discount() << endl;
								}
								cout << "商品信息删除完成!" << endl;
								ofs.close();
								Goods::Set0_GoodsNum();
								system("pause");
								system("cls");
								goto HH;
							}
							else
							{
								system("cls");
								cout << "未找到该商品信息..." << endl;
							H2:
								cout << "请问您是否要重新输入?(Y/N)" << endl;
								char q;
								cin >> q;
								if ('Y' == q || 'y' == q)
								{
									system("cls");
									goto G2;
								}
								else if ('N' == q || 'n' == q)
								{
									system("cls");
									Goods::Set0_GoodsNum();
									goto HH;
								}
								else
								{
									system("cls");
									cout << "您的输入有误,请重新输入..." << endl;
									system("pause");
									goto H2;
								}
							}
						}
						case 6:   //用户设置
						{
						NLH:
							system("cls");
							showSettingUser();
							int select;
							cin >> select;
							switch (select)
							{
							case 1:  //创建用户信息
							{
								cout << "请问您要创建管理员还是普通用户的信息?" << endl;
								cout << "[1]  普通用户  |  [2]  管理员" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										string admin, key;
									ADDcommon2:
										cout << "请输入账号:" << endl;
										cin >> admin;
										cout << "请输入密码:" << endl;
										cin >> key;
										ofs.open("commonUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //使使用者人数+1
										ofs.close();
										cout << "创建成功!" << endl;
										system("pause");
										goto NLH;
									}
									else
									{
										ifs.close();
										cout << "普通用户信息文件已存在,请勿重复创建!" << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										string admin, key;
										cout << "请输入账号:" << endl;
										cin >> admin;
										cout << "请输入密码:" << endl;
										cin >> key;
										ofs.open("adminUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //使使用者人数+1
										ofs.close();
										cout << "创建成功!" << endl;
										system("pause");
										goto NLH;
									}
									else
									{
										ifs.close();
										cout << "管理员信息文件已存在,请勿重复创建!" << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
								}
								break;
							}
							case 2:  //增加用户信息
							{
								system("cls");
								cout << "请问您要增加管理员还是普通用户的信息?" << endl;
								cout << "[1]  普通用户  |  [2]  管理员" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "普通用户信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										ifs.close();
										string admin, key;
									ADDcommon4:
										int sum = 0;
										ifs.open("commonUser.txt");
										while (!ifs.eof())
										{
											ifs >> admin >> key;
											sum++;
										}
										sum--;
										ifs.close();
										ifs.open("commonUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> admin >> key;
											U[i].set_admin_key(admin, key);
										}
										ifs.close();
										cout << "请输入新增账号:" << endl;
										cin >> admin;
										cout << "请输入新增密码:" << endl;
										cin >> key;
										for (int i = 0; i < sum; i++)
										{
											if (admin == U[i].get_admin())
											{
												cout << "该账号信息已存在!" << endl;
												cout << "请重新添加!" << endl;
												system("pause");
												system("cls");
												goto ADDcommon4;
											}
										}
										delete[] U;
										ofs.open("commonUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //使使用者人数+1
										cout << "增加成功!" << endl;
										cout << "请问您还要继续添加用户吗? (Y/N)" << endl;
										char choice;
									commonRenew4:
										cin >> choice;
										if (choice == 'Y' || choice == 'y')
										{
											system("cls");
											goto ADDcommon4;
										}
										else if (choice == 'N' || choice == 'n')
										{
											system("cls");
											ofs.close();
											cout << "增加完毕!" << endl;
											goto NLH;
										}
										else
										{
											system("cls");
											cout << "输入有误,请重新输入..." << endl;
											goto commonRenew4;
										}
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										cout << "管理员信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										ifs.close();
										string admin, key;
									ADDcommon5:
										int sum = 0;
										ifs.open("adminUser.txt");
										while (!ifs.eof())
										{
											ifs >> admin >> key;
											sum++;
										}
										sum--;
										ifs.close();
										ifs.open("adminUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> admin >> key;
											U[i].set_admin_key(admin, key);
										}
										ifs.close();
										cout << "请输入新增账号:" << endl;
										cin >> admin;
										cout << "请输入新增密码:" << endl;
										cin >> key;
										for (int i = 0; i < sum; i++)
										{
											if (admin == U[i].get_admin())
											{
												cout << "该账号信息已存在!" << endl;
												cout << "请重新添加!" << endl;
												system("pause");
												system("cls");
												goto ADDcommon5;
											}
										}
										delete[] U;
										ofs.open("adminUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //使使用者人数+1
										cout << "增加成功!" << endl;
										cout << "请问您还要继续添加用户吗? (Y/N)" << endl;
										char choice;
									commonRenew5:
										cin >> choice;
										if (choice == 'Y' || choice == 'y')
										{
											system("cls");
											goto ADDcommon5;
										}
										else if (choice == 'N' || choice == 'n')
										{
											system("cls");
											ofs.close();
											cout << "增加完毕!" << endl;
											goto NLH;
										}
										else
										{
											system("cls");
											cout << "输入有误,请重新输入..." << endl;
											goto commonRenew5;
										}
									}
								}
								break;
							}
							case 3:   //删除用户信息
							{
								system("cls");
								cout << "请问您要删除管理员还是普通用户的信息?" << endl;
								cout << "[1]  普通用户  |  [2]  管理员" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "普通用户信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										sum--;
										User* U = new User[sum];
										ifs.close();
										ifs.open("commonUser.txt");
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
										}
										ifs.close();
										cout << "请输入您要删除的普通用户的账号" << endl;
									K:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
											I:cout << "找到该用户,请问您是否要将其删除...(Y/N)" << endl;
												char q,l;
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
												II:	cout << "请您再次确认是否要将该用户删除...(Y/N)" << endl;
													cin >> l;
													if ('Y' == l || 'y' == l)
													{
														flag = 1;
														for (int j = i + 1; j < sum; j++)
														{
															U[j - 1] = U[j];
														}
														sum--;
														break;
													}
													else if ('N' == l || 'n' == l)
													{
														system("cls");
														cout << "已取消删除该用户..." << endl;
														system("pause");
														goto NLH;
													}
													else
													{
														system("cls");
														cout << "您的输入有误，请重新输入..." << endl;
														system("pause");
														goto II;
													}
												}
												else if ('N' == q || 'n' == q)
												{
													system("pause");
													system("cls");
													goto NLH;
												}
												else
												{
													system("cls");
													cout << "您的输入出错,请重新输入..." << endl;
													goto I;
												}
											}
										}
										if (flag)
										{
											ofs.open("commonUser.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
											}
											ofs.close();
											if (User::get_userNum() != 0)
												User::sub_userNum();
											cout << "该用户已被删除!" << endl;
											system("pause");
											system("cls");
											goto NLH;
										}
										else
										{
											cout << "删除失败,未找到该用户!" << endl;
											cout << "是否需要重新输入用户账号:(Y/N)" << endl;
											char r;
										J:
											cin >> r;
											if ('Y' == r || 'y' == r)
											{
												system("cls");
												goto K;
											}
											else if ('N' == r || 'n' == r)
											{
												system("pause");
												system("cls");
												goto NLH;
											}
											else
											{
												system("cls");
												cout << "您的输入出错,请重新输入..." << endl;
												goto J;
											}
										}
										delete[] U;
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										cout << "管理员信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										sum--;
										ifs.close();
										ifs.open("adminUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
										}
										ifs.close();
										cout << "请输入您要删除的管理员的账号" << endl;
									M:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
											L:  cout << "找到该管理员,请问您是否要将其删除...(Y/N)" << endl;
												char q,l;
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
											LLp:		cout << "请再次确认您是否要删除该管理员...(Y/N)" << endl;
													cin >> l;
													if ('Y' == l || 'y' == l)
													{
														flag = 1;
														for (int j = i + 1; j < sum; j++)
														{
															U[j - 1] = U[j];
														}
														sum--;
														break;
													}
													else if ('N' == l || 'n' == l)
													{
														system("cls");
														cout << "已取消删除..." << endl;
														system("pause");
														goto NLH;
													}
													else
													{
														system("cls");
														cout << "您的输入有误，请重新输入..." << endl;
														system("pause");
														goto LLp;
													}
												}
												else if ('N' == q || 'n' == q)
												{
													system("pause");
													system("cls");
													goto NLH;
												}
												else
												{
													system("cls");
													cout << "您的输入出错,请重新输入..." << endl;
													goto L;
												}
											}
										}
										if (flag)
										{
											ofs.open("adminUser.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
											}
											system("pause");
											system("cls");
											ofs.close();
											cout << "该管理员已被删除!" << endl;
											goto NLH;
										}
										else
										{
											cout << "删除失败,未找到该管理员!" << endl;
											cout << "是否需要重新输入用户账号:(Y/N)" << endl;
											char r;
										N:
											cin >> r;
											if ('Y' == r || 'y' == r)
											{
												system("cls");
												goto M;
											}
											else if ('N' == r || 'n' == r)
											{
												system("pause");
												system("cls");
												goto NLH;
											}
											else
											{
												system("cls");
												cout << "您的输入出错,请重新输入..." << endl;
												goto N;
											}
										}
										delete[] U;
									}
								}
								break;
							}
							case 4:   //修改用户信息
							{
								system("cls");
								cout << "请问您要修改管理员还是普通用户的信息?" << endl;
								cout << "[1]  普通用户  |  [2]  管理员" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "普通用户信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										sum--;
										ifs.close();
										ifs.open("commonUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
										}
										ifs.close();
										cout << "请输入您要修改的普通用户的账号" << endl;
									P:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
												cout << "找到该用户,请问您是否要将其修改...(Y/N)" << endl;
												char q;
											O:
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
													flag = 1;
													cout << "请重新输入该用户的账号密码:" << endl;
													cout << "请输入该用户的账号:" << endl;
													cin >> ifsadmin;
													cout << "请输入该用户的密码:" << endl;
													cin >> ifskey;
													U[i].set_admin_key(ifsadmin, ifskey);
													break;
												}
												else if ('N' == q || 'n' == q)
												{
													system("pause");
													system("cls");
													goto NLH;
													break;
												}
												else
												{
													system("cls");
													cout << "您的输入出错,请重新输入..." << endl;
													goto O;
													break;
												}
											}
										}
										if (flag)
										{
											ofs.open("commonUser.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
											}
											ofs.close();
											system("pause");
											system("cls");
											cout << "该用户已修改!" << endl;
											goto NLH;
										}
										else
										{
											cout << "修改失败,未找到该用户!" << endl;
											cout << "是否需要重新输入用户账号:(Y/N)" << endl;
											char r;
										Q:
											cin >> r;
											if ('Y' == r || 'y' == r)
											{
												system("cls");
												goto P;
											}
											else if ('N' == r || 'n' == r)
											{
												system("pause");
												system("cls");
												goto NLH;
											}
											else
											{
												system("cls");
												cout << "您的输入出错,请重新输入..." << endl;
												goto Q;
											}
										}
										delete[] U;
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										cout << "管理员信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										sum--;
										ifs.close();
										ifs.open("adminUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
										}
										ifs.close();
										cout << "请输入您要修改的管理员的账号" << endl;
									S:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
												cout << "找到该管理员,请问您是否要将其修改...(Y/N)" << endl;
												char q;
											R:
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
													flag = 1;
													cout << "请重新输入该管理员的账号密码:" << endl;
													cout << "请输入该管理员的账号:" << endl;
													cin >> ifsadmin;
													cout << "请输入该管理员的密码:" << endl;
													cin >> ifskey;
													U[i].set_admin_key(ifsadmin, ifskey);
												}
												else if ('N' == q || 'n' == q)
												{
													system("pause");
													system("cls");
													goto NLH;
												}
												else
												{
													system("cls");
													cout << "您的输入出错,请重新输入..." << endl;
													goto R;
												}
											}
										}
										if (flag)
										{
											ofs.open("adminUser.txt");
											for (int i = 0; i < sum; i++)
											{
												ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
											}
											ofs.close();
											cout << "该管理员已被修改!" << endl;
											system("pause");
											system("cls");
											goto NLH;
										}
										else
										{
											cout << "修改失败,未找到该管理员!" << endl;
											cout << "是否需要重新输入用户账号:(Y/N)" << endl;
											char r;
										T:
											cin >> r;
											if ('Y' == r || 'y' == r)
											{
												system("cls");
												goto S;
											}
											else if ('N' == r || 'n' == r)
											{
												system("pause");
												system("cls");
												goto NLH;
											}
											else
											{
												system("cls");
												cout << "您的输入出错,请重新输入..." << endl;
												goto T;
											}
										}
										delete[] U;
									}
									break;
								}
							case 5:   //浏览用户信息
							{
								system("cls");
								cout << "请问您要浏览管理员还是普通用户的信息?" << endl;
								cout << "[1]  普通用户  |  [2]  管理员" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "普通用户信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										if (sum == 1)
										{
											system("cls");
											cout << "普通用户信息文件为空,请先添加..." << endl;
											system("pause");
											goto NLH;
										}
										sum--;
										ifs.close();
										ifs.open("commonUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
											cout << "用户账号: " << ifsadmin << "用户密码: " << ifskey << endl;
										}
										ifs.close();
										ofs.open("commonUser.txt");
										for (int i = 0; i < sum; i++)
										{
											ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
										}
										ofs.close();
										delete[] U;
										system("pause");
										system("cls");
										goto NLH;
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										cout << "管理员信息文件不存在,请先创建..." << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
									else
									{
										string ifsadmin, ifskey;
										int sum = 0;
										while (!ifs.eof())
										{
											sum++;
											ifs >> ifsadmin >> ifskey;
										}
										sum--;
										ifs.close();
										ifs.open("adminUser.txt");
										User* U = new User[sum];
										for (int i = 0; i < sum; i++)
										{
											ifs >> ifsadmin >> ifskey;
											U[i].set_admin_key(ifsadmin, ifskey);
											cout << "管理员账号: " << ifsadmin << "\t密码: " << ifskey << endl;
										}
										ifs.close();
										ofs.open("adminUser.txt");
										for (int i = 0; i < sum; i++)
										{
											ofs << U[i].get_admin() << " " << U[i].get_key() << endl;
										}
										ofs.close();
										system("pause");
										system("cls");
										goto NLH;
										delete[] U;
									}
								}
								break;
							}
							case 6:  //返回上一级
							{
								system("cls");
								goto HH;
								break;
							}
							case 7:
							{
								system("cls");
								cout << "您想清空[1]普通用户 | [2]管理员 的信息?(Y/N)" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
								X:
									cout << "请您确认是否要清空普通用户信息?(Y/N)" << endl;
									char i, j;
									cin >> i;
									cout << "请您最后一次确认...(Y/N)" << endl;
									cin >> j;
									if (('Y' == i || 'y' == i) && ('y' == j || 'Y' == j))
									{
										ofs.open("commonUser.txt");
										ofs.close();
										system("cls");
										User::Set0_UserNum();
										cout << "普通用户信息已清空..." << endl;
										system("pause");
										goto NLH;
									}
									else if (('N' == i || 'n' == i) || ('N' == j || 'n' == j))
									{
										system("cls");
										goto NLH;
									}
									else
									{
										cout << "您的输入有误,请重新输入..." << endl;
										system("pause");
										system("cls");
										goto X;
									}
								}
								else if (2 == choice)
								{
								Z:
									cout << "请您确认是否要清空管理员信息?(Y/N)" << endl;
									char i, j;
									cin >> i;
									cout << "请您最后一次确认...(Y/N)" << endl;
									cin >> j;
									if (('Y' == i || 'y' == i) && ('y' == j || 'Y' == j))
									{
										ofs.open("adminUser.txt");
										ofs.close();
										system("cls");
										cout << "管理员信息已清空..." << endl;
										system("pause");
										goto NLH;
									}
									else if (('N' == i || 'n' == i) || ('N' == j || 'n' == j))
									{
										system("cls");
										goto NLH;
									}
									else
									{
										cout << "您的输入有误,请重新输入..." << endl;
										system("pause");
										system("cls");
										goto Z;
									}
								}
							}
							case 0:   //退出系统
							{
								system("cls");
								cout << "欢迎下次使用本系统..." << endl;
								exit(1);
								break;
							}
							default:
							{
								system("cls");
								cout << "您的输入有误,请重新输入..." << endl;
								system("pause");
								goto NLH;
							}
							}
							}
						case 7:  //返回上一级
						{
							system("cls");
							goto LL;
						}
						case 8:  //清空商品信息
						{
						Y:
							cout << "您确认您要清空商品信息吗?(Y/N)" << endl;
							char choice, select;
							cin >> choice;
							cout << "请您再次确认是否清空?(Y/N)" << endl;
							cin >> select;
							if ((choice == 'Y' || choice == 'y') && (select == 'Y' || select == 'y'))
							{
								ofs.open("Goods.txt");
								ofs.close();
								system("cls");
								Goods::Set0_GoodsNum();
								system("cls");
								cout << "商品信息已清空..." << endl;
								system("pause");
								system("cls");
								goto HH;
							}
							else if (('N' == choice || 'n' == choice) || ('N' == select || 'n' == select))
							{
								system("cls");
								goto HH;
							}
							else
							{
								system("cls");
								cout << "您的输入有误,请重新输入..." << endl;
								goto Y;
							}
						}
						default:
						{
							system("cls");
							cout << "您的输入有误,请重新输入..." << endl;
							system("pause");
							goto HH;
						}
						}
						}
					}
					else
					{
						errorCount++;
						system("cls");
						cout << "账号或密码错误,请重新登录..." << endl;
						system("pause");
						goto Error2;
					}
				}
			}
			else
			{
				system("cls");
				cout << "输入有误,请重新输入..." << endl;
				goto NL;
			}
		}
		case 2:
		{
			system("cls");
			cout << "请先登录..." << endl;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "请先登录..." << endl;
			system("pause");
			break;
		}
		default:
		{
			system("cls");
			cout << "您的输入有误,请重新输入..." << endl;
			system("pause");
		}
		}
		system("cls");
	}
	system("pause");
	return 0;
}

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
	static void add_userNum()   //����ʹ��������+1
	{
		usersNum++;
	}
	static void sub_userNum()   //����ʹ��������-1
	{
		usersNum--;
	}
	static int get_userNum()   //��ȡʹ����������
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
	string m_adminNum;  //�˺�
	string m_key;   //����
	static int usersNum;  //ʹ����������
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
	static void add_goodsSum()  //������Ʒ����
	{
		m_goodsSum++;
	}
	static void sub_goodsSum()  //������Ʒ����
	{
		m_goodsSum--;
	}
	static int get_goodsSum()  //��ȡ��Ʒ����
	{
		return m_goodsSum;
	}
	static void Set0_GoodsNum()   //ʹ��Ʒ������
	{
		m_goodsSum = 0;
	}
private:
	int m_num;  //���
	string m_name;  //����
	double m_price;  //�۸�
	double m_discount; //�ۿ�
	static int m_goodsSum;  //��Ʒ����
};
int Goods::m_goodsSum = 0;

void showCommonMenu()
{
	cout << endl << endl << endl;
	cout << "					С����Ʒ����ϵͳ(��ͨ�û���)" << endl;
	cout << endl << endl << endl;
	cout << "					1. ��ѯ��Ʒ�۸���Ϣ" << endl;
	cout << "					2. ��Ʒ�۸��������" << endl;
	cout << "					3. ������һ��" << endl;
	cout << "					0. �˳�ϵͳ" << endl;
}
void showAdminMenu()
{
	cout << endl << endl << endl;
	cout << "					С����Ʒ����ϵͳ(����Ա��)" << endl;
	cout << endl << endl << endl;
	cout << "					1. ��ѯ��Ʒ�۸���Ϣ" << endl;
	cout << "					2. ��Ʒ�۸��������" << endl;
	cout << "					3. ������Ʒ�۸���Ϣ" << endl;
	cout << "					4. �޸���Ʒ�۸���Ϣ" << endl;
	cout << "					5. ɾ����Ʒ�۸���Ϣ" << endl;
	cout << "					6. �û�����" << endl;
	cout << "					7. ������һ��" << endl;
	cout << "					8. �����Ʒ�۸���Ϣ" << endl;
	cout << "					0. �˳�ϵͳ" << endl;
}
void showSettingUser()
{
	cout << endl << endl << endl;
	cout << "					1. �����û���Ϣ" << endl;
	cout << "					2. �����û���Ϣ" << endl;
	cout << "					3. ɾ���û���Ϣ" << endl;
	cout << "					4. �޸��û���Ϣ" << endl;
	cout << "					5. ����û���Ϣ" << endl;
	cout << "					6. ������һ��" << endl;
	cout << "					7. ����û���Ϣ" << endl;
	cout << "					0. �˳�ϵͳ" << endl;
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
		cout << "					С����Ʒ����ϵͳ" << endl << endl << endl;
		cout << "					1. �û���¼" << endl;
		cout << "					2. ��Ʒ��Ϣ����" << endl;
		cout << "					3. Ȩ�޹���" << endl;
		cout << "					0. �˳�ϵͳ" << endl;
		int choice;
		cin >> choice;
		ifstream ifs;
		ofstream ofs;
		switch (choice)
		{
		case 0:
		{
			cout << "��ӭ�´�ʹ��!" << endl;
			exit(1);
		}
		case 1:
		{
		NL:
			cout << "[1]��ͨ�û�    [2]����Ա" << endl;
			int n;
			cin >> n;
			if (1 == n)
			{
				ifs.open("commonUser.txt");
				//�ļ��в�����
				if (!ifs)
				{
					ofs.open("commonUser.txt");
					cout << "��ͨ�û��ļ�������,�봴��!" << endl;
					system("pause");
					system("cls");
					string admin, key;
				ADDcommon:
					cout << "�������˺�:" << endl;
					cin >> admin;
					cout << "����������:" << endl;
					cin >> key;
					ofs << admin << " " << key << endl;
					User::add_userNum();  //ʹʹ��������+1
					system("cls");
					ofs.close();
					cout << "�����ɹ�!" << endl;
					cout << "���ص�½����..." << endl;
					system("pause");
					system("cls");
					goto LL;
				}
				//�ļ�����
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
							cout << "��ͨ�û��ļ���Ϊ��,����ע��..." << endl;
							system("pause");
							ifs.close();
							ofs.open("commonUser.txt");
							string admin, key;
							cout << "�������˺�:" << endl;
							cin >> admin;
							cout << "����������:" << endl;
							cin >> key;
							ofs << admin << " " << key << endl;
							User::add_userNum();  //ʹʹ��������+1
							system("cls");
							cout << "ע��ɹ�,���ص�¼ҳ��..." << endl;
							system("pause");
							system("cls");
							goto NL;
						}
					}
					cout << "�����û�,���¼..." << endl;
					int flag = 0, errorCount = 0;
				Error:
					ifs.close();
					ifs.open("commonUser.txt");
					cout << "������" << 3 - errorCount << "���������" << endl;
					if (errorCount == 3)
					{
						cout << "�����˺������������,���Զ��˳�ϵͳ" << endl;
						exit(0);
					}
					cout << "�������˺�:" << endl;
					cin >> admin;
					cout << "����������:" << endl;
					cin >> key;
					while (!ifs.eof())
					{
						ifs >> ifsadmin >> ifskey;
						if (ifsadmin == admin && ifskey == key)
						{
							flag = 1;
							system("cls");
							cout << "��¼�ɹ�!" << endl;
							ofs.close();
							ifs.close();
							break;
						}
					}
					if (flag)
					{
					NN:
						showCommonMenu();  //չʾ�˵�
						int select;
						cin >> select;
						switch (select)
						{
						case 0:
						{
							system("cls");
							cout << "��ӭ�´�ʹ��..." << endl;
							exit(1);
						}
						case 1:  //��ѯ��Ʒ�۸���Ϣ
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "δ�ҵ���Ʒ��Ϣ�ļ���" << endl;
								cout << "�봴����Ʒ��Ϣ�ļ�" << endl;
								ofs.open("Goods.txt");
								string name;  //����
								double price;  //�۸�
								double discount;  //�ۿ�
							NLL:
								cout << "��������Ʒ����" << endl;
								cin >> name;
								cout << "��������Ʒ�۸�" << endl;
								cin >> price;
								cout << "��������Ʒ�ۿ�" << endl;
								cin >> discount;
								ofs << Goods::get_goodsSum()+1 << " " << name << " " << price << " " << discount << endl;
								Goods::add_goodsSum();
								system("cls");
								cout << "�����ɹ�!" << endl;
							ErrorL:
								cout << "�������Ƿ�Ҫ�������?(Y/N)" << endl;
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
									cout << "�������!" << endl;
									goto NN;
								}
								else
								{
									system("cls");
									cout << "������������,����������..." << endl;
									goto ErrorL;
								}
							}
							else  //�����ļ�
							{
								string ifsname;  //����
								int ifsnum;  //���
								double ifsprice, ifsdiscount;  //�۸���ۿ�
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
										cout << "�ļ���ϢΪ��! ����ϵ����Ա���" << endl;
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
								ifs.open("Goods.txt");  //���ļ�
								int i = 0;
								for (int i = 0; i < sum; i++)
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									G[i].set_discount(ifsdiscount);
									G[i].set_name(ifsname);
									G[i].set_num(ifsnum);
									G[i].set_price(ifsprice);
								}
								ifs.close();  //�ر��ļ�

								cout << "����������ѯ��Ʒ�ķ�ʽ :" << endl;
							NLRenew:
								cout << "[1] ��� |  [2] ����" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)   //ͨ����Ų�ѯ
								{
									system("cls");
									int num;
									int flag = 0;
								NLLL:
									cout << "��������Ʒ���:" << endl;
									cin >> num;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_num() == num)
										{
											flag = 1;
											cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "����ʧ�� , �޸���Ʒ��Ϣ!" << endl;
									NLLLL:
										cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
											cout << " ллʹ��" << endl;
											system("pause");
											system("cls");
											goto NN;
										}
										else
										{
											cout << "������������,����������..." << endl;
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
										cout << "���ҳɹ�,�ѷ���..." << endl;
										goto NN;
									}
								}
								else if (2 == choice)   //ͨ�����Ʋ�ѯ
								{
									system("cls");
									string name;
									int flag = 0;
								LLLN:
									cout << "��������Ʒ����:" << endl;
									cin >> name;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_name() == name)
										{
											flag = 1;
											cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "����ʧ�� , �޸���Ʒ��Ϣ!" << endl;
									NLLLLL:
										cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
											cout << " ллʹ��" << endl;
											system("pause");
											system("cls");
											goto NN;
										}
										else
										{
											cout << "������������,����������..." << endl;
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
										cout << "���ҳɹ�,�ѷ���..." << endl;
										goto NN;
									}
								}
								else
								{
									system("cls");
									cout << "������������,����������..." << endl;
									goto NLRenew;
								}
							}
						}
						case 2:  //��Ʒ�۸��������
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "δ�ҵ���Ʒ�۸���Ϣ�ļ�! ���ȴ���..." << endl;
								system("pause");
								goto NN;
								system("cls");
							}
							string ifsname;  //����
							int ifsnum;  //���
							double ifsprice, ifsdiscount;  //�۸���ۿ�
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
									cout << "�ļ���ϢΪ��! ����ϵ����Ա���" << endl;
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
							ifs.open("Goods.txt");  //���ļ�
							int i = 0;
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_discount(ifsdiscount);
								G[i].set_name(ifsname);
								G[i].set_num(ifsnum);
								G[i].set_price(ifsprice);
							}
							ifs.close();  //�ر��ļ�
							Goods::Set0_GoodsNum();
						A:
							cout << "����Ҫ���۸���С����(1) �����ɴ�С(0) ��������?" << endl;
							int choice;
							cin >> choice;
							if (1 == choice)
							{
								if (sum > 1)
									biggersort(G,sum);  //������
							}
							else if (0 == choice)
							{
								if (sum > 1)
									smallersort(G,sum);  //������
							}
							else
							{
								cout << "������������, ����������..." << endl;
								goto A;
							}
							//��ӡ���
							for (int i = 0; i < sum; i++)
							{
								cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
							}
							delete[] G;
							system("pause");
							system("cls");
							goto NN;
						}
						case 3:  //������һ��
						{
							system("cls");
							goto LL;
						}
						default:
						{
							system("cls");
							cout << "������������,����������..." << endl;
							system("pause");
							goto NN;
						}
						}
					}
					else
					{
						errorCount++;
						system("cls");
						cout << "�˺Ż��������";
						cout << "����������..." << endl;
						goto Error;
					}
				}
			}
			else if (2 == n)
			{
				ifs.open("adminUser.txt");
				if (!ifs)
				{
					cout << "����Ա�û��ļ�������,�봴��!" << endl;
					ofs.open("adminUser.txt");
					string admin, key;
				ADDadmin:
					cout << "�������˺�:" << endl;
					cin >> admin;
					cout << "����������:" << endl;
					cin >> key;
					ofs << admin << " " << key << endl;
					User::add_userNum();  //ʹʹ��������+1
					system("cls");
					cout << "�����ɹ�!" << endl;
					cout << "���ص�¼����..." << endl;
					system("pause");
					system("cls");
					ofs.close();
					goto LL;
				}
				else   //�ļ�����
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
							cout << "����Ա�ļ���Ϊ��,����ע��..." << endl;
							system("pause");
							ifs.close();
							ofs.open("adminUser.txt");
							string admin, key;
							cout << "�������˺�:" << endl;
							cin >> admin;
							cout << "����������:" << endl;
							cin >> key;
							ofs << admin << " " << key << endl;
							User::add_userNum();  //ʹʹ��������+1
							system("cls");
							cout << "ע��ɹ�,���ص�¼ҳ��..." << endl;
							system("pause");
							system("cls");
							goto NL;
						}
					}
					cout << "�����û�,���¼..." << endl;
					int flag = 0, errorCount = 0;
				Error2:
					ifs.close();
					ifs.open("adminUser.txt");
					cout << "������" << 3 - errorCount << "���������" << endl;
					if (errorCount == 3)
					{
						cout << "�����˺������������,���Զ��˳�ϵͳ" << endl;
						exit(0);
					}
					cout << "�������˺�:" << endl;
					cin >> admin;
					cout << "����������:" << endl;
					cin >> key;
					while (!ifs.eof())
					{
						ifs >> ifsadmin >> ifskey;
						if (ifsadmin == admin && ifskey == key)
						{
							flag = 1;
							system("cls");
							cout << "��¼�ɹ�!" << endl;
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
						case 0:   //�˳�ϵͳ
						{
							system("cls");
							cout << "��ӭ�´�ʹ��..." << endl;
							system("pause");
							exit(1);
						}
						case 1:   //��ѯ��Ʒ�۸���Ϣ
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "δ�ҵ���Ʒ��Ϣ�ļ���" << endl;
								cout << "�봴����Ʒ��Ϣ�ļ�" << endl;
								ofs.open("Goods.txt");
								string name;  //����
								double price;  //�۸�
								double discount;  //�ۿ�
							NLL2:
								cout << "��������Ʒ����" << endl;
								cin >> name;
								cout << "��������Ʒ�۸�" << endl;
								cin >> price;
								cout << "��������Ʒ�ۿ�" << endl;
								cin >> discount;
								ofs << Goods::get_goodsSum()+1 << " " << name << " " << price << " " << discount << endl;
								Goods::add_goodsSum();
								system("cls");
								cout << "�����ɹ�!" << endl;
							ErrorN:
								cout << "�������Ƿ�Ҫ�������?(Y/N)" << endl;
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
									cout << "�������!" << endl;
									goto HH;
								}
								else
								{
									system("cls");
									cout << "������������,����������..." << endl;
									goto ErrorN;
								}
							}
							else  //�����ļ�
							{
								string ifsname;  //����
								int ifsnum;  //���
								double ifsprice, ifsdiscount;  //�۸���ۿ�
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
										cout << "�ļ���ϢΪ��,�������Ʒ�۸���Ϣ!" << endl;
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
								ifs.open("Goods.txt");  //���ļ�
								int i = 0;
								for (int i = 0; i < sum; i++)
								{
									ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
									G[i].set_discount(ifsdiscount);
									G[i].set_name(ifsname);
									G[i].set_num(ifsnum);
									G[i].set_price(ifsprice);
								}
								ifs.close();  //�ر��ļ�
								cout << "����������ѯ��Ʒ�ķ�ʽ :" << endl;
							NLRenew2:
								cout << "[1] ��� |  [2] ����" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)   //ͨ����Ų�ѯ
								{
									system("cls");
									int num;
									int flag = 0;
								E:
									cout << "�������Ƿ��������?(Y/N)" << endl;
									char q;
									cin >> q;
									if ('Y' == q || 'y' == q)
									{
									NLLL2:
										cout << "��������Ʒ���:" << endl;
										cin >> num;
										for (int i = 0; i < sum; i++)
										{
											if (G[i].get_num() == num)
											{
												flag = 1;
												cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
												system("pause");
												system("cls");
												break;
											}
										}
										if (!flag)
										{
											cout << "����ʧ�� , �޸���Ʒ��Ϣ!" << endl;
										NLLLL2:
											cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
												cout << " ллʹ��" << endl;
												system("pause");
												system("cls");
												goto HH;
											}
											else
											{
												system("cls");
												cout << "������������,����������..." << endl;
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
								else if (2 == choice)   //ͨ�����Ʋ�ѯ
								{
									system("cls");
									string name;
									int flag = 0;
								LLLN2:
									cout << "��������Ʒ����:" << endl;
									cin >> name;
									for (int i = 0; i < sum; i++)
									{

										if (G[i].get_name() == name)
										{
											flag = 1;
											cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
											system("pause");
											system("cls");
											break;
										}
									}
									if (!flag)
									{
										cout << "����ʧ�� , �޸���Ʒ��Ϣ!" << endl;
									NLLLLL2:
										cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
											cout << " ллʹ��" << endl;
											system("pause");
											system("cls");
											goto HH;
										}
										else
										{
											cout << "������������,����������..." << endl;
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
									cout << "������������,����������..." << endl;
									goto NLRenew2;
								}
							}
						}
						case 2:   //��Ʒ�۸��������
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "δ�ҵ���Ʒ�۸���Ϣ�ļ�! ���ȴ���..." << endl;
								system("pause");
								goto HH;
								system("cls");
							}
							string ifsname;  //����
							int ifsnum;  //���
							double ifsprice, ifsdiscount;  //�۸���ۿ�
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
									cout << "��Ʒ�۸���Ϣ�ļ�Ϊ��,�����..." << endl;
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
							ifs.open("Goods.txt");  //���ļ�
							int i = 0;
							for (int i = 0; i < sum; i++)
							{
								ifs >> ifsnum >> ifsname >> ifsprice >> ifsdiscount;
								G[i].set_discount(ifsdiscount);
								G[i].set_name(ifsname);
								G[i].set_num(ifsnum);
								G[i].set_price(ifsprice);
							}
							ifs.close();  //�ر��ļ�
							Goods::Set0_GoodsNum();
						B:
							cout << "����Ҫ���۸���С����(1) �����ɴ�С(0) ��������?" << endl;
							int choice;
							cin >> choice;
							if (1 == choice)
							{
								if (sum > 1)
									biggersort(G,sum);  //������
							}
							else if (0 == choice)
							{
								if (sum > 1)
									smallersort(G,sum);  //������
							}
							else
							{
								cout << "������������, ����������..." << endl;
								goto B;
							}
							//��ӡ���
							for (int i = 0; i < sum; i++)
							{
								cout << "��Ʒ���: " << G[i].get_num() << "\t��Ʒ����: " << G[i].get_name() << "\t��Ʒ�۸�: " << G[i].get_price() << "\t��Ʒ�ۿ�: " << G[i].get_discount() << endl;
							}
							system("pause");
							system("cls");
							goto HH;
						}
						case 3:   //������Ʒ�۸���Ϣ
						{
							ifs.close();
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "δ�ҵ���Ʒ�۸���Ϣ�ļ�! ���ȴ���..." << endl;
								system("pause");
								system("cls");
								goto HH;
							}
							string ifsname;  //����
							int ifsnum;  //���
							double ifsprice, ifsdiscount;  //�۸���ۿ�
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
							cout << "��������Ʒ����" << endl;
							cin >> ifsname;
							cout << "��������Ʒ�۸�" << endl;
							cin >> ifsprice;
							cout << "��������Ʒ�ۿ�" << endl;
							cin >> ifsdiscount;
							ofs << Goods::get_goodsSum() << " " << ifsname << " " << ifsprice << " " << ifsdiscount << endl;
							Goods::add_goodsSum();
							cout << "��ӳɹ�!" << endl;
							cout << "�������Ƿ�Ҫ�������?(Y/N)" << endl;
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
								cout << "������!" << endl;
								Goods::Set0_GoodsNum();
								//delete[] G;
								goto HH;
							}
							else
							{
								system("cls");
								cout << "������������,����������..." << endl;
								goto D;
							}
						}
						case 4:   //�޸���Ʒ�۸���Ϣ
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "��Ʒ�۸���Ϣ�ļ�������,���ȴ���!" << endl;
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
									cout << "��Ʒ��Ϣ�ļ���Ϊ��,���������Ϣ..." << endl;
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
						G:	cout << "��������Ҫ�޸ĵ���Ʒ���:" << endl;
							int num, flag = 0;
							cin >> num;
							for (int i = 0; i < sum; i++)
							{
								if (G[i].get_num() == num)
								{
									cout << "���ҵ�����Ʒ,������ȷ��Ҫ�޸�����?(Y/N)" << endl;
									char w;
								F:
									cin >> w;
									if ('Y' == w || 'y' == w)
									{
										flag = 1;
										cout << "���������������Ʒ����Ϣ:" << endl;
										cout << "��������Ʒ����:" << endl;
										cin >> ifsname;
										cout << "��������Ʒ�۸�:" << endl;
										cin >> ifsprice;
										cout << "��������Ʒ�ۿ�:" << endl;
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
										cout << "������������,����������..." << endl;
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
								cout << "��Ʒ��Ϣ�޸����!" << endl;
								ofs.close();
								system("pause");
								system("cls");
								goto HH;
							}
							else
							{
								system("cls");
								cout << "δ�ҵ�����Ʒ��Ϣ..." << endl;
								cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
									cout << "������������,����������..." << endl;
									goto H;
								}
							}
						}
						case 5:  //ɾ����Ʒ�۸���Ϣ
						{
							ifs.open("Goods.txt");
							if (!ifs)
							{
								cout << "��Ʒ�۸���Ϣ�ļ�������,���ȴ���!" << endl;
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
									cout << "��Ʒ��Ϣ�ļ���Ϊ��,���������Ϣ..." << endl;
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
							ifs.close();  //�ر��ļ�
						G2:	cout << "��������Ҫɾ������Ʒ����:" << endl;
							int flag = 0;
							string name;
							cin >> name;
							for (int i = 0; i < sum; i++)
							{
								if (G[i].get_name() == name)
								{
								F2:	cout << "���ҵ�����Ʒ,������ȷ��Ҫɾ������?(Y/N)" << endl;
									char w,q;
									cin >> w;
									if ('Y' == w || 'y' == w)
									{
									GG:	cout << "�����ٴ�ȷ�����Ƿ�Ҫɾ������Ʒ...(Y/N)" << endl;
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
											cout << "��ȡ��ɾ������Ʒ����������..." << endl;
											system("pause");
											goto HH;
										}
										else
										{
											system("cls");
											cout << "����������������������..." << endl;
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
										cout << "������������,����������..." << endl;
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
								cout << "��Ʒ��Ϣɾ�����!" << endl;
								ofs.close();
								Goods::Set0_GoodsNum();
								system("pause");
								system("cls");
								goto HH;
							}
							else
							{
								system("cls");
								cout << "δ�ҵ�����Ʒ��Ϣ..." << endl;
							H2:
								cout << "�������Ƿ�Ҫ��������?(Y/N)" << endl;
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
									cout << "������������,����������..." << endl;
									system("pause");
									goto H2;
								}
							}
						}
						case 6:   //�û�����
						{
						NLH:
							system("cls");
							showSettingUser();
							int select;
							cin >> select;
							switch (select)
							{
							case 1:  //�����û���Ϣ
							{
								cout << "������Ҫ��������Ա������ͨ�û�����Ϣ?" << endl;
								cout << "[1]  ��ͨ�û�  |  [2]  ����Ա" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										string admin, key;
									ADDcommon2:
										cout << "�������˺�:" << endl;
										cin >> admin;
										cout << "����������:" << endl;
										cin >> key;
										ofs.open("commonUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //ʹʹ��������+1
										ofs.close();
										cout << "�����ɹ�!" << endl;
										system("pause");
										goto NLH;
									}
									else
									{
										ifs.close();
										cout << "��ͨ�û���Ϣ�ļ��Ѵ���,�����ظ�����!" << endl;
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
										cout << "�������˺�:" << endl;
										cin >> admin;
										cout << "����������:" << endl;
										cin >> key;
										ofs.open("adminUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //ʹʹ��������+1
										ofs.close();
										cout << "�����ɹ�!" << endl;
										system("pause");
										goto NLH;
									}
									else
									{
										ifs.close();
										cout << "����Ա��Ϣ�ļ��Ѵ���,�����ظ�����!" << endl;
										system("pause");
										system("cls");
										goto NLH;
									}
								}
								break;
							}
							case 2:  //�����û���Ϣ
							{
								system("cls");
								cout << "������Ҫ���ӹ���Ա������ͨ�û�����Ϣ?" << endl;
								cout << "[1]  ��ͨ�û�  |  [2]  ����Ա" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "��ͨ�û���Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "�����������˺�:" << endl;
										cin >> admin;
										cout << "��������������:" << endl;
										cin >> key;
										for (int i = 0; i < sum; i++)
										{
											if (admin == U[i].get_admin())
											{
												cout << "���˺���Ϣ�Ѵ���!" << endl;
												cout << "���������!" << endl;
												system("pause");
												system("cls");
												goto ADDcommon4;
											}
										}
										delete[] U;
										ofs.open("commonUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //ʹʹ��������+1
										cout << "���ӳɹ�!" << endl;
										cout << "��������Ҫ��������û���? (Y/N)" << endl;
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
											cout << "�������!" << endl;
											goto NLH;
										}
										else
										{
											system("cls");
											cout << "��������,����������..." << endl;
											goto commonRenew4;
										}
									}
								}
								else if (2 == choice)
								{
									ifs.open("adminUser.txt");
									if (!ifs)
									{
										cout << "����Ա��Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "�����������˺�:" << endl;
										cin >> admin;
										cout << "��������������:" << endl;
										cin >> key;
										for (int i = 0; i < sum; i++)
										{
											if (admin == U[i].get_admin())
											{
												cout << "���˺���Ϣ�Ѵ���!" << endl;
												cout << "���������!" << endl;
												system("pause");
												system("cls");
												goto ADDcommon5;
											}
										}
										delete[] U;
										ofs.open("adminUser.txt", ios::app);
										ofs << admin << " " << key << endl;
										User::add_userNum();  //ʹʹ��������+1
										cout << "���ӳɹ�!" << endl;
										cout << "��������Ҫ��������û���? (Y/N)" << endl;
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
											cout << "�������!" << endl;
											goto NLH;
										}
										else
										{
											system("cls");
											cout << "��������,����������..." << endl;
											goto commonRenew5;
										}
									}
								}
								break;
							}
							case 3:   //ɾ���û���Ϣ
							{
								system("cls");
								cout << "������Ҫɾ������Ա������ͨ�û�����Ϣ?" << endl;
								cout << "[1]  ��ͨ�û�  |  [2]  ����Ա" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "��ͨ�û���Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "��������Ҫɾ������ͨ�û����˺�" << endl;
									K:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
											I:cout << "�ҵ����û�,�������Ƿ�Ҫ����ɾ��...(Y/N)" << endl;
												char q,l;
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
												II:	cout << "�����ٴ�ȷ���Ƿ�Ҫ�����û�ɾ��...(Y/N)" << endl;
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
														cout << "��ȡ��ɾ�����û�..." << endl;
														system("pause");
														goto NLH;
													}
													else
													{
														system("cls");
														cout << "����������������������..." << endl;
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
													cout << "�����������,����������..." << endl;
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
											cout << "���û��ѱ�ɾ��!" << endl;
											system("pause");
											system("cls");
											goto NLH;
										}
										else
										{
											cout << "ɾ��ʧ��,δ�ҵ����û�!" << endl;
											cout << "�Ƿ���Ҫ���������û��˺�:(Y/N)" << endl;
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
												cout << "�����������,����������..." << endl;
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
										cout << "����Ա��Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "��������Ҫɾ���Ĺ���Ա���˺�" << endl;
									M:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
											L:  cout << "�ҵ��ù���Ա,�������Ƿ�Ҫ����ɾ��...(Y/N)" << endl;
												char q,l;
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
											LLp:		cout << "���ٴ�ȷ�����Ƿ�Ҫɾ���ù���Ա...(Y/N)" << endl;
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
														cout << "��ȡ��ɾ��..." << endl;
														system("pause");
														goto NLH;
													}
													else
													{
														system("cls");
														cout << "����������������������..." << endl;
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
													cout << "�����������,����������..." << endl;
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
											cout << "�ù���Ա�ѱ�ɾ��!" << endl;
											goto NLH;
										}
										else
										{
											cout << "ɾ��ʧ��,δ�ҵ��ù���Ա!" << endl;
											cout << "�Ƿ���Ҫ���������û��˺�:(Y/N)" << endl;
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
												cout << "�����������,����������..." << endl;
												goto N;
											}
										}
										delete[] U;
									}
								}
								break;
							}
							case 4:   //�޸��û���Ϣ
							{
								system("cls");
								cout << "������Ҫ�޸Ĺ���Ա������ͨ�û�����Ϣ?" << endl;
								cout << "[1]  ��ͨ�û�  |  [2]  ����Ա" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "��ͨ�û���Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "��������Ҫ�޸ĵ���ͨ�û����˺�" << endl;
									P:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
												cout << "�ҵ����û�,�������Ƿ�Ҫ�����޸�...(Y/N)" << endl;
												char q;
											O:
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
													flag = 1;
													cout << "������������û����˺�����:" << endl;
													cout << "��������û����˺�:" << endl;
													cin >> ifsadmin;
													cout << "��������û�������:" << endl;
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
													cout << "�����������,����������..." << endl;
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
											cout << "���û����޸�!" << endl;
											goto NLH;
										}
										else
										{
											cout << "�޸�ʧ��,δ�ҵ����û�!" << endl;
											cout << "�Ƿ���Ҫ���������û��˺�:(Y/N)" << endl;
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
												cout << "�����������,����������..." << endl;
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
										cout << "����Ա��Ϣ�ļ�������,���ȴ���..." << endl;
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
										cout << "��������Ҫ�޸ĵĹ���Ա���˺�" << endl;
									S:
										string admin;
										int flag = 0;
										cin >> admin;
										for (int i = 0; i < sum; i++)
										{
											if (U[i].get_admin() == admin)
											{
												cout << "�ҵ��ù���Ա,�������Ƿ�Ҫ�����޸�...(Y/N)" << endl;
												char q;
											R:
												cin >> q;
												if ('Y' == q || 'y' == q)
												{
													flag = 1;
													cout << "����������ù���Ա���˺�����:" << endl;
													cout << "������ù���Ա���˺�:" << endl;
													cin >> ifsadmin;
													cout << "������ù���Ա������:" << endl;
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
													cout << "�����������,����������..." << endl;
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
											cout << "�ù���Ա�ѱ��޸�!" << endl;
											system("pause");
											system("cls");
											goto NLH;
										}
										else
										{
											cout << "�޸�ʧ��,δ�ҵ��ù���Ա!" << endl;
											cout << "�Ƿ���Ҫ���������û��˺�:(Y/N)" << endl;
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
												cout << "�����������,����������..." << endl;
												goto T;
											}
										}
										delete[] U;
									}
									break;
								}
							case 5:   //����û���Ϣ
							{
								system("cls");
								cout << "������Ҫ�������Ա������ͨ�û�����Ϣ?" << endl;
								cout << "[1]  ��ͨ�û�  |  [2]  ����Ա" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
									ifs.open("commonUser.txt");
									if (!ifs)
									{
										cout << "��ͨ�û���Ϣ�ļ�������,���ȴ���..." << endl;
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
											cout << "��ͨ�û���Ϣ�ļ�Ϊ��,�������..." << endl;
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
											cout << "�û��˺�: " << ifsadmin << "�û�����: " << ifskey << endl;
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
										cout << "����Ա��Ϣ�ļ�������,���ȴ���..." << endl;
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
											cout << "����Ա�˺�: " << ifsadmin << "\t����: " << ifskey << endl;
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
							case 6:  //������һ��
							{
								system("cls");
								goto HH;
								break;
							}
							case 7:
							{
								system("cls");
								cout << "�������[1]��ͨ�û� | [2]����Ա ����Ϣ?(Y/N)" << endl;
								int choice;
								cin >> choice;
								if (1 == choice)
								{
								X:
									cout << "����ȷ���Ƿ�Ҫ�����ͨ�û���Ϣ?(Y/N)" << endl;
									char i, j;
									cin >> i;
									cout << "�������һ��ȷ��...(Y/N)" << endl;
									cin >> j;
									if (('Y' == i || 'y' == i) && ('y' == j || 'Y' == j))
									{
										ofs.open("commonUser.txt");
										ofs.close();
										system("cls");
										User::Set0_UserNum();
										cout << "��ͨ�û���Ϣ�����..." << endl;
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
										cout << "������������,����������..." << endl;
										system("pause");
										system("cls");
										goto X;
									}
								}
								else if (2 == choice)
								{
								Z:
									cout << "����ȷ���Ƿ�Ҫ��չ���Ա��Ϣ?(Y/N)" << endl;
									char i, j;
									cin >> i;
									cout << "�������һ��ȷ��...(Y/N)" << endl;
									cin >> j;
									if (('Y' == i || 'y' == i) && ('y' == j || 'Y' == j))
									{
										ofs.open("adminUser.txt");
										ofs.close();
										system("cls");
										cout << "����Ա��Ϣ�����..." << endl;
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
										cout << "������������,����������..." << endl;
										system("pause");
										system("cls");
										goto Z;
									}
								}
							}
							case 0:   //�˳�ϵͳ
							{
								system("cls");
								cout << "��ӭ�´�ʹ�ñ�ϵͳ..." << endl;
								exit(1);
								break;
							}
							default:
							{
								system("cls");
								cout << "������������,����������..." << endl;
								system("pause");
								goto NLH;
							}
							}
							}
						case 7:  //������һ��
						{
							system("cls");
							goto LL;
						}
						case 8:  //�����Ʒ��Ϣ
						{
						Y:
							cout << "��ȷ����Ҫ�����Ʒ��Ϣ��?(Y/N)" << endl;
							char choice, select;
							cin >> choice;
							cout << "�����ٴ�ȷ���Ƿ����?(Y/N)" << endl;
							cin >> select;
							if ((choice == 'Y' || choice == 'y') && (select == 'Y' || select == 'y'))
							{
								ofs.open("Goods.txt");
								ofs.close();
								system("cls");
								Goods::Set0_GoodsNum();
								system("cls");
								cout << "��Ʒ��Ϣ�����..." << endl;
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
								cout << "������������,����������..." << endl;
								goto Y;
							}
						}
						default:
						{
							system("cls");
							cout << "������������,����������..." << endl;
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
						cout << "�˺Ż��������,�����µ�¼..." << endl;
						system("pause");
						goto Error2;
					}
				}
			}
			else
			{
				system("cls");
				cout << "��������,����������..." << endl;
				goto NL;
			}
		}
		case 2:
		{
			system("cls");
			cout << "���ȵ�¼..." << endl;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "���ȵ�¼..." << endl;
			system("pause");
			break;
		}
		default:
		{
			system("cls");
			cout << "������������,����������..." << endl;
			system("pause");
		}
		}
		system("cls");
	}
	system("pause");
	return 0;
}

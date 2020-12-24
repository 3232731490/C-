#include<string>
#include<iostream>
namespace nl1  //人事部门
{
	class Student
	{
	public:
		void set_student(int num,char name[50],int age,char addr[50])
		{
			m_num = num;
			strcpy_s(m_name , name);
			m_age = age;
			strcpy_s(m_addr, addr);
		}
		int get_num()
		{
			return m_num;
		}
		char* get_name()
		{
			return m_name;
		}
		int get_age()
		{
			return m_age;
		}
		char* get_addr()
		{
			return m_addr;
		}
	private:

		int m_num;//学号
		char m_name[50];//姓名
		int m_age;//年龄
		char m_addr[50];//地址
	};


}
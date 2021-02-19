#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void ShowMenu();							//显示菜单
void Clean();								//清屏
int Check(struct Addressbook * abs, string name);								//检测是否存在搜索的人
void Add(struct Addressbook * abs);			//添加联系人
void Display(struct Addressbook * abs);		//显示联系人
void Delete(struct Addressbook * abs);		//删除联系人
void Find(struct Addressbook * abs);		//查找联系人
void Rewrite(struct Addressbook * abs);		//修改联系人
void Empty(struct Addressbook * abs);		//清空联系人

struct Person
{
	string m_name;		//姓名
	int m_Sex;			//性别，1-代表男生，2-代表女生
	int m_Age;			//年龄
	string m_Phone;		//电话号码
	string m_Address;	//家庭住址
};

struct Addressbook
{
	struct Person personArray[MAX];		//通讯录中的联系人数组
	int m_Size;							//通讯录保存的人数
};

int main()
{
	Addressbook abs;		//创建一个通讯录的结构体变量
	abs.m_Size = 0;			//初始化通讯录中的人数为0

	int slect = 0;

	while (1)
	{
		ShowMenu();
		cin >> slect;
		switch (slect)
		{
		case 1:		//添加联系人
			Add(&abs);
			Clean();
			break;
		case 2:		//显示联系人
			Display(&abs);
			Clean();
			break;
		case 3:		//删除联系人
			Delete(&abs);
			Clean();
			break;
		case 4:		//查找联系人
			Find(&abs);
			Clean();
			break;
		case 5:		//修改联系人
			Rewrite(&abs);
			Clean();
			break;
		case 6:		//清空联系人
			Empty(&abs);
			Clean();
			break;
		case 0:		//退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "您输入的选择有误，请重新输入！" << endl;
			Clean();
			break;
		}
	}


}

void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}

void Clean()
{
	system("pause");
	system("cls");
}

int Check(struct Addressbook * abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
			return i;	//找到后返回所在数组的下标
	}
	return -1;			//查无此人时范围值为 -1
}

void Add(struct Addressbook * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	else
	{

		cout << "请输入添加人的姓名:" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		
		cout << "请输入添加人的性别:" << endl;
		int sex = 0;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "您的输入有误，请重新输入！" << endl;
			}
		}
		

		cout << "请输入添加人的年龄:" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;


		cout << "请输入添加人的电话号码:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		

		cout << "请输入添加人的家庭住址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;


		cout << "信息已录入完毕！" <<endl;
		abs->m_Size++;
	}

}

void Display(struct Addressbook * abs)
{
	int i = 0;
	if (abs->m_Size ==0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for ( i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name 
				<< "\t性别: " << ( abs->personArray[i].m_Sex == 1 ? "男" : "女" )
				<< "\t年龄: " << abs->personArray[i].m_Age 
				<< "\t电话: " << abs->personArray[i].m_Phone 
				<< "\t家庭住址: " << abs->personArray[i].m_Address << endl;
		}
	}
	
}

void Delete(struct Addressbook * abs)
{
	cout << "请输入要删除的人的姓名： " << endl;
	string name;
	cin >> name;
	if (Check(abs, name) == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		for (int i = Check(abs, name); i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size -= 1;
		cout << "删除完毕！" << endl;
	}
}

void Find(struct Addressbook * abs)
{
	cout << "请输入要查找的人的姓名： " << endl;
	string name;
	cin >> name;
	if (Check(abs, name) == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "姓名： " << abs->personArray[Check(abs, name)].m_name
			<< "\t性别： " << (abs->personArray[Check(abs, name)].m_Sex == 1 ? "男" : "女")
			<< "\t年龄： " << abs->personArray[Check(abs, name)].m_Age
			<< "\t电话号码:" << abs->personArray[Check(abs, name)].m_Phone
			<< "\t家庭住址： " << abs->personArray[Check(abs, name)].m_Address << endl;
	}
}

void Rewrite(struct Addressbook * abs)
{
	cout << "请输入要修改的人的姓名： " << endl;
	string cname;
	cin >> cname;
	int ret = Check(abs, cname);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "请输入要修改的姓名:" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;


		cout << "请输入要修改的性别:" << endl;
		int sex = 0;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "您的输入有误，请重新输入！" << endl;
			}
		}


		cout << "请输入要修改的年龄:" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;


		cout << "请输入要修改的电话号码:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;


		cout << "请输入要修改的家庭住址:" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;


		cout << "信息已修改完毕！" << endl;

	}
}

void Empty(struct Addressbook * abs)
{
	cout << "您确认要清空通讯录吗？" << endl;
	cout << "YES     NO" << endl;
	string	choice;
	cin >> choice;
	if ("YES" == choice)
	{
		abs->m_Size = 0;
		cout << "联系人已清空！" << endl;
	}
	else
	{
		return;
	}
	
}
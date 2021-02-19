#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

void ShowMenu();							//��ʾ�˵�
void Clean();								//����
int Check(struct Addressbook * abs, string name);								//����Ƿ������������
void Add(struct Addressbook * abs);			//�����ϵ��
void Display(struct Addressbook * abs);		//��ʾ��ϵ��
void Delete(struct Addressbook * abs);		//ɾ����ϵ��
void Find(struct Addressbook * abs);		//������ϵ��
void Rewrite(struct Addressbook * abs);		//�޸���ϵ��
void Empty(struct Addressbook * abs);		//�����ϵ��

struct Person
{
	string m_name;		//����
	int m_Sex;			//�Ա�1-����������2-����Ů��
	int m_Age;			//����
	string m_Phone;		//�绰����
	string m_Address;	//��ͥסַ
};

struct Addressbook
{
	struct Person personArray[MAX];		//ͨѶ¼�е���ϵ������
	int m_Size;							//ͨѶ¼���������
};

int main()
{
	Addressbook abs;		//����һ��ͨѶ¼�Ľṹ�����
	abs.m_Size = 0;			//��ʼ��ͨѶ¼�е�����Ϊ0

	int slect = 0;

	while (1)
	{
		ShowMenu();
		cin >> slect;
		switch (slect)
		{
		case 1:		//�����ϵ��
			Add(&abs);
			Clean();
			break;
		case 2:		//��ʾ��ϵ��
			Display(&abs);
			Clean();
			break;
		case 3:		//ɾ����ϵ��
			Delete(&abs);
			Clean();
			break;
		case 4:		//������ϵ��
			Find(&abs);
			Clean();
			break;
		case 5:		//�޸���ϵ��
			Rewrite(&abs);
			Clean();
			break;
		case 6:		//�����ϵ��
			Empty(&abs);
			Clean();
			break;
		case 0:		//�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������ѡ���������������룡" << endl;
			Clean();
			break;
		}
	}


}

void ShowMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
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
			return i;	//�ҵ��󷵻�����������±�
	}
	return -1;			//���޴���ʱ��ΧֵΪ -1
}

void Add(struct Addressbook * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	else
	{

		cout << "����������˵�����:" << endl;
		string name;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		
		cout << "����������˵��Ա�:" << endl;
		int sex = 0;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
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
				cout << "���������������������룡" << endl;
			}
		}
		

		cout << "����������˵�����:" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;


		cout << "����������˵ĵ绰����:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		

		cout << "����������˵ļ�ͥסַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;


		cout << "��Ϣ��¼����ϣ�" <<endl;
		abs->m_Size++;
	}

}

void Display(struct Addressbook * abs)
{
	int i = 0;
	if (abs->m_Size ==0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for ( i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_name 
				<< "\t�Ա�: " << ( abs->personArray[i].m_Sex == 1 ? "��" : "Ů" )
				<< "\t����: " << abs->personArray[i].m_Age 
				<< "\t�绰: " << abs->personArray[i].m_Phone 
				<< "\t��ͥסַ: " << abs->personArray[i].m_Address << endl;
		}
	}
	
}

void Delete(struct Addressbook * abs)
{
	cout << "������Ҫɾ�����˵������� " << endl;
	string name;
	cin >> name;
	if (Check(abs, name) == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		for (int i = Check(abs, name); i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size -= 1;
		cout << "ɾ����ϣ�" << endl;
	}
}

void Find(struct Addressbook * abs)
{
	cout << "������Ҫ���ҵ��˵������� " << endl;
	string name;
	cin >> name;
	if (Check(abs, name) == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������ " << abs->personArray[Check(abs, name)].m_name
			<< "\t�Ա� " << (abs->personArray[Check(abs, name)].m_Sex == 1 ? "��" : "Ů")
			<< "\t���䣺 " << abs->personArray[Check(abs, name)].m_Age
			<< "\t�绰����:" << abs->personArray[Check(abs, name)].m_Phone
			<< "\t��ͥסַ�� " << abs->personArray[Check(abs, name)].m_Address << endl;
	}
}

void Rewrite(struct Addressbook * abs)
{
	cout << "������Ҫ�޸ĵ��˵������� " << endl;
	string cname;
	cin >> cname;
	int ret = Check(abs, cname);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�����:" << endl;
		string name;
		cin >> name;
		abs->personArray[ret].m_name = name;


		cout << "������Ҫ�޸ĵ��Ա�:" << endl;
		int sex = 0;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
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
				cout << "���������������������룡" << endl;
			}
		}


		cout << "������Ҫ�޸ĵ�����:" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;


		cout << "������Ҫ�޸ĵĵ绰����:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;


		cout << "������Ҫ�޸ĵļ�ͥסַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;


		cout << "��Ϣ���޸���ϣ�" << endl;

	}
}

void Empty(struct Addressbook * abs)
{
	cout << "��ȷ��Ҫ���ͨѶ¼��" << endl;
	cout << "YES     NO" << endl;
	string	choice;
	cin >> choice;
	if ("YES" == choice)
	{
		abs->m_Size = 0;
		cout << "��ϵ������գ�" << endl;
	}
	else
	{
		return;
	}
	
}
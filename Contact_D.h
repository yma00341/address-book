#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <Windows.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 15
#define MAX_ADDR 30
#define DEFAULT_SZ 3		//ͨѶ¼Ĭ�ϴ�С

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE
};


typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


typedef struct Contact
{
	//��̬���ٿռ�
	struct PeoInfo *data;
	int capacity;	//���data���ٵĿռ�������������size���бȽ��Ƿ����
	int size;
}Contact;

//��ʼ������
void InitContact(Contact * ps);
//����ͨѶ¼
void DestroyContact(Contact *ps);
//�������
void CheckCapacity(Contact* ps);
//�����ϵ��
void AddContact(Contact * ps);
//ɾ����ϵ��
void DelContact(Contact * ps);
//������ϵ��
void SearchContact(const Contact * ps);
//�޸���ϵ��
void ModifyContact(Contact * ps);
//չʾ��ϵ����Ϣ
void ShowContact(const Contact * ps);
//������Ϣ���ļ���
void SaveContact(Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼��
void LoadContact(Contact* ps);
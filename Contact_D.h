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
#define DEFAULT_SZ 3		//通讯录默认大小

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
	//动态开辟空间
	struct PeoInfo *data;
	int capacity;	//存放data开辟的空间容量，用来和size进行比较是否溢出
	int size;
}Contact;

//初始化函数
void InitContact(Contact * ps);
//销毁通讯录
void DestroyContact(Contact *ps);
//检测容量
void CheckCapacity(Contact* ps);
//添加联系人
void AddContact(Contact * ps);
//删除联系人
void DelContact(Contact * ps);
//查找联系人
void SearchContact(const Contact * ps);
//修改联系人
void ModifyContact(Contact * ps);
//展示联系人信息
void ShowContact(const Contact * ps);
//保存信息到文件中
void SaveContact(Contact* ps);
//加载文件中的信息到通讯录中
void LoadContact(Contact* ps);
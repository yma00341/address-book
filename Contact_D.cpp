#include "Contact_D.h"

//初始化通讯录
void InitContact(Contact * ps)
{
	//动态开辟空间
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	//判断是否开辟成功
	if (ps->data == NULL)
	{
		return;
	}
	//容量设置为默认
	ps->capacity = DEFAULT_SZ;
	//通讯录清空
	ps->size = 0;
	//把文件中以及存放的通讯录信息加载到通讯录中
	LoadContact(ps);

}
//查找联系人函数 - 返回元素所在数组的下标,否则返回-1
static int FindByName(const Contact *ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//检测容量
void CheckCapacity(Contact* ps)
{
	if ((ps->size+1) == ps->capacity)
	{
		//增容
		PeoInfo *ptr = (PeoInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
		}
	}
}
//销毁通讯录
void DestroyContact(Contact *ps)
{
	free(ps->data);
	ps->data = NULL;
}



//添加联系人
void AddContact(Contact * ps)
{
	//检测当前通讯录的容量是否已满
	//满了增加空间
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入住址:>");
	scanf("%s", ps->data[ps->size].addr);
	//添加之后指向数组的下一个元素
	ps->size ++;
	printf("添加成功!\n");
}

//删除指定联系人
void DelContact(Contact * ps)
{
	int i = 0;
	char name[MAX_NAME];
	printf("请输入要删除的联系人姓名:>");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	i = FindByName(ps, name);
	//2.删除
	if (i == ps->size)
		printf("要删除的人不存在!\n");
	else
	{
		int j = 0;
		for (j = i; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功!\n");
	}
}

//查找联系人并打印出来
void SearchContact(const Contact *ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("要查找的人不存在!\n");
	else
	{
		printf("%-20s\t%-5s\t%-4s\t%-15s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
		printf("%-20s\t%-5s\t%-4d\t%-15s\t%-30s\n",
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].age,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

//修改联系人
void ModifyContact(Contact *ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("请输入要修改的联系人姓名:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("要修改人的信息不存在!");
	else
	{
		printf("请输入要修改的名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入要修改的性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入要修改的年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入要修改的电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入要修改的住址:>");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功!\n");
	}
}

//展示所有联系人信息
void ShowContact(const Contact *ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("通讯录为空!\n");
	}
	else
	{
		printf("%-6s\t%-5s\t%-4s\t%-15s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			//-为左对齐
			printf("%-6s\t%-5s\t%-4d\t%-15s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//保存信息到文件中
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//写通讯录的数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//一次写入一个
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	printf("保存成功\n");
	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
}

//加载文件信息
void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	
	fclose(pfRead);
	pfRead = NULL;

}
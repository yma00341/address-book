/*
功能：
1.最开吃存放3个人的信息
2.动态增长
姓名、电话、性别、年龄、住址
2.增加联系人
3.删除指定名字联系人
4.查找联系人
5.修改联系人
6.打印好友信息
*/
#include "Contact_D.h"

void menu()
{
	printf("********************************************\n");
	printf("****** 1.add                2.del    *******\n");
	printf("****** 3.search             4.modify *******\n");
	printf("****** 5.show               6.save   *******\n");
	printf("******            0.exit             *******\n");
	printf("********************************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;//里面包含data指针，size,capacity
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case DEL:
				DelContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case SEARCH:
				SearchContact(&con);
				Sleep(2000);
				system("cls");
				break;
			case MODIFY:
				ModifyContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case SHOW:
				ShowContact(&con);
				Sleep(3000);
				system("cls");
				break;
			case SAVE:
				SaveContact(&con);
				Sleep(1000);
				system("cls");
				break;
			case EXIT:
				//先默认保存
				SaveContact(&con);
				//销毁通讯录释放内存
				DestroyContact(&con);
				printf("退出通讯录!\n");
				break;
			default:
				printf("选择错误，请重新选择!\n");
				break;
		}
	} while (input);

	return 0;
}


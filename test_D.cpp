/*
���ܣ�
1.��Դ��3���˵���Ϣ
2.��̬����
�������绰���Ա����䡢סַ
2.������ϵ��
3.ɾ��ָ��������ϵ��
4.������ϵ��
5.�޸���ϵ��
6.��ӡ������Ϣ
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
	//����ͨѶ¼
	Contact con;//�������dataָ�룬size,capacity
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
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
				//��Ĭ�ϱ���
				SaveContact(&con);
				//����ͨѶ¼�ͷ��ڴ�
				DestroyContact(&con);
				printf("�˳�ͨѶ¼!\n");
				break;
			default:
				printf("ѡ�����������ѡ��!\n");
				break;
		}
	} while (input);

	return 0;
}


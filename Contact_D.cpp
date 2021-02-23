#include "Contact_D.h"

//��ʼ��ͨѶ¼
void InitContact(Contact * ps)
{
	//��̬���ٿռ�
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	//�ж��Ƿ񿪱ٳɹ�
	if (ps->data == NULL)
	{
		return;
	}
	//��������ΪĬ��
	ps->capacity = DEFAULT_SZ;
	//ͨѶ¼���
	ps->size = 0;
	//���ļ����Լ���ŵ�ͨѶ¼��Ϣ���ص�ͨѶ¼��
	LoadContact(ps);

}
//������ϵ�˺��� - ����Ԫ������������±�,���򷵻�-1
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
//�������
void CheckCapacity(Contact* ps)
{
	if ((ps->size+1) == ps->capacity)
	{
		//����
		PeoInfo *ptr = (PeoInfo*)realloc(ps->data, (ps->capacity + 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
		}
	}
}
//����ͨѶ¼
void DestroyContact(Contact *ps)
{
	free(ps->data);
	ps->data = NULL;
}



//�����ϵ��
void AddContact(Contact * ps)
{
	//��⵱ǰͨѶ¼�������Ƿ�����
	//�������ӿռ�
	CheckCapacity(ps);
	//��������
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("����������:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("������סַ:>");
	scanf("%s", ps->data[ps->size].addr);
	//���֮��ָ���������һ��Ԫ��
	ps->size ++;
	printf("��ӳɹ�!\n");
}

//ɾ��ָ����ϵ��
void DelContact(Contact * ps)
{
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	i = FindByName(ps, name);
	//2.ɾ��
	if (i == ps->size)
		printf("Ҫɾ�����˲�����!\n");
	else
	{
		int j = 0;
		for (j = i; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�!\n");
	}
}

//������ϵ�˲���ӡ����
void SearchContact(const Contact *ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("Ҫ���ҵ��˲�����!\n");
	else
	{
		printf("%-20s\t%-5s\t%-4s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-20s\t%-5s\t%-4d\t%-15s\t%-30s\n",
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].age,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

//�޸���ϵ��
void ModifyContact(Contact *ps)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("Ҫ�޸��˵���Ϣ������!");
	else
	{
		printf("������Ҫ�޸ĵ�����:>");
		scanf("%s", ps->data[pos].name);
		printf("������Ҫ�޸ĵ��Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������Ҫ�޸ĵ�����:>");
		scanf("%d", &(ps->data[pos].age));
		printf("������Ҫ�޸ĵĵ绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("������Ҫ�޸ĵ�סַ:>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸ĳɹ�!\n");
	}
}

//չʾ������ϵ����Ϣ
void ShowContact(const Contact *ps)
{
	int i = 0;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
	}
	else
	{
		printf("%-6s\t%-5s\t%-4s\t%-15s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");
		for (i = 0; i < ps->size; i++)
		{
			//-Ϊ�����
			printf("%-6s\t%-5s\t%-4d\t%-15s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//������Ϣ���ļ���
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		//һ��д��һ��
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}
	printf("����ɹ�\n");
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
}

//�����ļ���Ϣ
void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ�
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}
	
	fclose(pfRead);
	pfRead = NULL;

}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>

				�ļ��Ĵ�

int main()
{
	fopen("test.txt", "r");	//	���·��
	fopen("F:\\Vs\\10.28\\test.txt", "r");//  ����·��
	fopen("../test.txt", "r");	//	��ǰ·������һ��·�� - ..
	fopen("./test.txt", "r");	//  ��ǰ·��			 - .
	fopen("../../test.txt", "r");	// ��һ��·������һ��·�� - ../..

	FILE* pf = fopen("test.txt", "w");
	  �ɹ��򿪺󣬷���һ�� FILE* ��ָ�룬ʧ���򷵻ؿ�ָ��NULL

	if (pf == NULL)
	{
		printf("%s ", strerror(errno));
		return 0;
	}

	fclose(pf);
		�ر��ļ�������pfָ�����ݲ��䣬��Ҫ������Ϊ��ָ��
	pf = NULL;

	return 0;
}

int main()
{
	FILE* pfw = fopen("test.txt", "w");
	 pf w - write
	if (pfw == NULL)
	{
		printf("%s ", strerror(errno));
		return 0;
	}
	else
	{
		fputc('B', pfw);
		fputc('A', pfw);
		fputc('B', pfw);
		fputc('Y', pfw);
	}
	fclose(pfw);
	pfw = NULL;
	return 0;
}

int main()
{
	FILE* pfr = fopen("test.txt", "r");
	 pf r - read
	if (pfr == NULL)
	{
		printf("%s ", strerror(errno));
		return 0;
	}
	else
	{
		printf("%c", fgetc(pfr));
		printf("%c", fgetc(pfr));
		printf("%c", fgetc(pfr));
		printf("%c", fgetc(pfr));
	}
	fclose(pfr);
	pfr = NULL;
	return 0;
}

	�Ӽ������룬�������Ļ - ����&��Ļ�ⲿ�豸
	���� - ��׼�����豸 - stdin
	��Ļ - ��׼����豸 - stdout
	����Ĭ�ϴ򿪵�2����

int main()
{
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	return 0;
}
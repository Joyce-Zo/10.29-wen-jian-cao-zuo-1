
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>

				文件的打开

int main()
{
	fopen("test.txt", "r");	//	相对路径
	fopen("F:\\Vs\\10.28\\test.txt", "r");//  绝对路径
	fopen("../test.txt", "r");	//	当前路径的上一级路径 - ..
	fopen("./test.txt", "r");	//  当前路径			 - .
	fopen("../../test.txt", "r");	// 上一级路径的上一级路径 - ../..

	FILE* pf = fopen("test.txt", "w");
	  成功打开后，返回一个 FILE* 的指针，失败则返回空指针NULL

	if (pf == NULL)
	{
		printf("%s ", strerror(errno));
		return 0;
	}

	fclose(pf);
		关闭文件，不过pf指针内容不变，需要下面置为空指针
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

	从键盘输入，输出到屏幕 - 键盘&屏幕外部设备
	键盘 - 标准输入设备 - stdin
	屏幕 - 标准输出设备 - stdout
	程序默认打开的2个流

int main()
{
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	return 0;
}
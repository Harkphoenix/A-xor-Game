
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100000
char words[MAX_SIZE] = {0};    //存储处理后的密文
char CipherText[MAX_SIZE] = {0}; //存储每一次的明文
int  temp[MAX_SIZE] = {0};       //将密文全都化为数字存于此数组中
int countswords = 0;			//密文字符个数计数
char passwd[3] ={0};    //存储密钥的数组
void Running(int x, int y, int z)
{
	/*
	破解密码的主程序，将所有的可能输出到result文件，为最后的比对做准备
	*/
	int i;
	FILE *p = fopen("f:\\result.txt", "a+");
	memset(CipherText, 0, MAX_SIZE);
	for(i = 0; i < countswords; i += 3)
	{
		CipherText[i] = x ^ temp[i];
		CipherText[i + 1] = y ^ temp[i + 1];
		CipherText[i + 2] = z ^ temp[i + 2];
	}
	fputs(passwd, p);
	fputs("\n\n", p);
	fputs(CipherText, p);
	fputs("\n\n\n\n\n\n", p);
	fclose(p);
}


void BreakPasswd()
{
	/*
	暴力枚举所有的可能性
	*/
	for(int i = 97; i <= 122; i++)
	{
		for(int j = 97; j <= 122; j++)
		{
			for(int k = 97; k <= 122; k++)
			{
				passwd[0] = i;
				passwd[1] = j;
				passwd[2] = k;
				Running(i,j,k);
			}
		}
	}
}


void ReadChar()
{
	/*
	处理密文文件，去掉多余符号，读入到数组中，为破解工作做准备
	*/

	FILE *fp1 = fopen("f:\\in.txt", "r");
	FILE *fp2 = fopen("f:\\out.txt", "w");
	int wordcount = 0;
	char testchar;
	while((testchar = fgetc(fp1)) != EOF)
	{
		if(testchar == ',')
			words[wordcount++] = ' ';
		else
			words[wordcount++] = testchar;
	}
	fputs(words,fp2);
	fclose(fp1);
	fclose(fp2);
	freopen("f:\\out.txt", "r", stdin);
	countswords = 0;
	while(scanf("%d", &temp[countswords++]) != EOF)
	{
		continue;
	}
}


int main()
{
	printf("Running.....、\n");
	ReadChar();       //对密文文件进行预处理
	BreakPasswd();    //暴力破解密文
	printf("Finish....... \n");
	return 0;
}

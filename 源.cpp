
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100000
char words[MAX_SIZE] = {0};    //�洢����������
char CipherText[MAX_SIZE] = {0}; //�洢ÿһ�ε�����
int  temp[MAX_SIZE] = {0};       //������ȫ����Ϊ���ִ��ڴ�������
int countswords = 0;			//�����ַ���������
char passwd[3] ={0};    //�洢��Կ������
void Running(int x, int y, int z)
{
	/*
	�ƽ�����������򣬽����еĿ��������result�ļ���Ϊ���ıȶ���׼��
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
	����ö�����еĿ�����
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
	���������ļ���ȥ��������ţ����뵽�����У�Ϊ�ƽ⹤����׼��
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
	printf("Running.....��\n");
	ReadChar();       //�������ļ�����Ԥ����
	BreakPasswd();    //�����ƽ�����
	printf("Finish....... \n");
	return 0;
}

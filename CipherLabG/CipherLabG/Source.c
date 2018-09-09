#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define debug

int getcap(int array[], int max);
int increment(int array[], int max);
void output(int array[], int max);
FILE*fin, *fp;

int main()
{
	char ch = 0;
	int array[222];
	fin = fopen("congress.txt", "r");
	fp = fopen("CipherLab.txt", "w");
	if (fin == NULL)
	{
		printf("The file could not be opened");
		return(-1);
	}
	int i, n, z;
	n = 0;
	for (i = 0; i < 272; i++)
	{
		fscanf(fin, "%c", &ch);
		if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
		{
			z = i - n;
			array[z] = ch;
		}
		else
		{
			n++;
		}
	}
	getcap(array, 222);
	increment(array, 222);
	output(array, 222);
	fclose(fp);
	return(0);
}

int getcap(int array[], int max)
{
	int i;
	char ch;
	for (i = 0; i < max; i++)
	{
		ch = array[i];
		if (ch >= 97 && ch <= 122)
		{
			array[i] = (ch - 32);
		}
		else
		{
			array[i] = ch;
		}
	}
	return array;
}

int increment(int array[], int max)
{
	char ch;
	int i;
	for (i = 0; i < max; i++)
	{
		ch = array[i];
		if (ch >= 65 && ch <= 77)
		{
			ch += 13;
			array[i] = ch;
		}
		else
		{
			ch = ch + 13 - 26;
			array[i] = ch;
		}
	}
	return array;
}

void output(int array[], int max)
{
	int i;

	for (i = 0; i < max; i++)
	{
		if ((i % 5) != 4)
		{
			printf("%c", array[i]);
			fprintf(fp, "%c", array[i]);
		}
		if ((i % 5) == 4)
		{
			printf("%c ", array[i]);
			fprintf(fp, "%c ", array[i]);
		}
		if ((i % 50) == 49)
		{
			printf("\n", array[i]);
			fprintf(fp, "\n", array[i]);
		}
	}
}
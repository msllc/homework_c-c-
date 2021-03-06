#include "stdafx.h"
#include <locale>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void zadacha1()
{
	printf_s("Вводится число. Вывести число Фибоначчи с таким номером \n");
	int g, ht, hu, he, i;
	printf_s("Введите выбранное вами число: ");
	scanf_s("%d", &g);
	if (g == 1)
	{
		printf_s("Число Фибоначчи с номером 1 это : 1\n");
	}
	if (g == 2)
	{
		printf_s("Число Фибоначчи с номером 2 это : 1\n");
	}
	if (g > 2)
	{
		ht = 1;
		hu = 1;
		he = 0;
		for (i = 2; i < g; i++)
		{
			he = ht + hu;
			ht = hu;
			hu = he;
		}
		printf_s("Число Фибоначчи с номером %d это : %d\n", g, he);
	}

	system("pause");
}


void zadacha2()
{
	int p = 0, b = 1, c = 0, x;
	printf_s("Вводится число. Вывести наименьшее число Фибоначчи, большее введённого. \n");
	printf_s("Введите выбранное вами число: ");
	scanf_s("%d", &x);
	while (c < x)
	{
		c = p + b;
		p = b;
		b = c;
	}
	if (c == x)
	{
		printf("Наименьшим числом Фибоначчи, большим введенного является : %d\n", p + b);
	}
	if (c > x)
	{
		printf("Наименьшим числом Фибоначчи, большим введенного является : %d\n", c);
	}
	system("pause");
}

void zadacha3()
{
	printf("Вводится любое число. Вывести его наоборот. \n");
	int ch;
	int t;
	int r = 0;
	int u;

	printf_s("Введите ваше число :");
	scanf_s("%d", &ch);
	while (ch != 0)
	{
		t = ch % 10;
		r = r * 10 + t;
		ch = ch / 10;
	}
	printf_s("%d", r);
	system("pause");
}

void zadacha4()
{
	printf("Вводится число. Вывести разложение этого числа на простые множители\n");

	int n, i;

	printf("Введите число: ");
	scanf_s("%d", &n);

	printf("Простые множители числа %d : ", n);
	for (i = 1; i <= n; ++i)
	{
		if (n%i == 0)
		{
			printf("%d ", i);
		}
	}
	system("pause");

}

void zadacha5()
{
	char k;
	printf(" Вводятся числа через пробел на одной строке. Вывести все числа, заменяя каждое число на ближайшее большее число Фибоначчи \n");
	printf("Введите числа через пробел. Для завершения ввода нажмите enter: ");
	do
	{
		int n;
		scanf_s("%d", &n);
		scanf_s("%c", &k);
		int o = 2;
		int f = 0, a = 1, b = 1;
		if (n < 1) f = 1; else
		{
			while (o >= 2)
			{
				o++;
				f = a + b;
				a = b;
				b = f;
				if (f > n) {
					printf("%d ", f); o = 1;
				}
			}
		}

	} while (k != '\n');
	system("pause");
}


int main()
{
	setlocale(LC_ALL, "russian");
	int errors = 0;
	char f;
	do
	{
		printf("Menu\n\n");
		scanf_s("%c", &f);
		switch (f)
		{
		case '0':
			exit(0);
			break;
		case '1':
			zadacha1();
			break;
		case '2':
			zadacha2();
			break;
		case '3':
			zadacha3();
			break;
		case '4':
			zadacha4();
			break;
		case '5':
			zadacha5();
			break;
		default:
		{
			errors++;
			printf("\n");
		}
		}
	} while (true);
	return 0;
}
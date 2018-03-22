#include "stdafx.h"
#include <stdio.h> 
#include <iostream> 

int tries();



void zadacha1()
{
	printf_s("Вводится число. Вывести число Фибоначчи с таким номером \n");
	int g, fa, fb, fc, i;
	printf_s("Введите выбранное вами число: ");
	scanf_s("%d", &g);
	if (g == 1)
	{
		printf_s("Число фибоначчи с номером 1 это : 1\n");
	}
	if (g == 2)
	{
		printf_s("Число фибоначчи с номером 2 это : 1\n");
	}
	if (g > 2)
	{
		fa = 1;
		fb = 1;
		fc = 0;
		for (i = 2; i < g; i++)
		{
			fc = fa + fb;
			fa = fb;
			fb = fc;
		}
		printf_s("Число фибоначчи с номером %d это : %d\n", g, fc);
	}

}


void zadacha2()
{
	int a = 0, b = 1, c = 0, fe;
	printf_s("Вводится число.Вывести наименьшее число Фибоначчи, большее введённого. \n");
	printf_s("Введите выбранное вами число: ");
	scanf_s("%d", &fe);
	while (c < fe)
	{
		c = a + b;
		a = b;
		b = c;
	}
	if (c == fe)
	{
		printf("Наименьшим числом Фибоначчи, большим введенного является : %d\n", a + b);
	}
	if (c > fe)
	{
		printf("Наименьшим числом Фибоначчи, большим введенного является : %d\n", c);
	}

}
void zadacha3()
{
	printf("Вводится любое число.Вывести его задом наперёд. \n");
	int chiselko;
	int temp;
	int otvetik = 0;
	printf_s("Введите ваше число :");
	scanf_s("%d", &chiselko);
	while (chiselko != 0)
	{
		temp = chiselko % 10;
		otvetik = otvetik * 10 + temp;
		chiselko = chiselko / 10;
	}
	printf_s("%d", otvetik);
}
void zadacha4()
{
	printf("Вводится число.Вывести разложение этого числа на простые множители\n");
	int n, div = 2;
	printf_s("Введите число : ");
	scanf_s("%d", &n);
	while (n > 1)
	{
		while (n % div == 0)
		{
			printf_s("%d ", div);
			n = n / div;
		}
		div++;
	}
	if (n % div != 0)
		printf_s("Это совершенное число\n");

}

int tries()
{
	char n;
	int number = 0;
	printf("Введите номер задачи: ");
	scanf_s("%c", &n);
	bool is_continue = true;
	while (is_continue) {
		while (n != '\n')
		{
			if (n < '0' || n > '9')
			{
				printf("Попробуйте еще раз \n");
				for (char cha = '\0'; cha != '\n'; scanf_s("%c", &cha))
					;
				is_continue = true;

			}
			else
			{
				number = number * 10 + n - '0';
				is_continue = false;
			}
			scanf_s("%c", &n);
		}
	}
	return number;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int errors, go_out;
	char x;
	char n;
	errors = 0;
	go_out = 0;
	printf(" Меню: \n 1. Задача №1 Вводится число. Вывести число Фибоначчи с таким номером \n 2. Задача №2 Вводится число.Вывести наименьшее число Фибоначчи, большее введённого. \n 3. Задача №3 Вводится любое число. Вывести его задом наперёд. \n 4. Задача №4 Вводится число. Вывести разложение этого числа на простые множители");
	do
	{
		printf("Выберете один из пунктов меню:\n");
		x = tries();
		switch (x)
		{
		case 0: x = 0; break;
		case 1:
			zadacha1();
			break;
		case 2:
			zadacha2();
			break;
		case 3:
			zadacha3();
			break;
		case 4:
			zadacha4();
			break;

		default:
			errors++;
			if (errors <= 4)
			{
				printf("Вы израсходовали %d из 5 попыток \n", errors);
			}
			else {
				printf("Вы израсходовали все попытки \n");
				x = 0;
			}
			break;
		}

	} while (x);
	system("pause");
	return 0;


}


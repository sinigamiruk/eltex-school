/*
 *calculator with four simple operations
 *1. +
 *2. -
 *3. /
 *4. *
 *5. exit program
 *date: 27.06.18
 *working hours: 4h
 *work performed: Kononov Dmitriy
 *kononov-dn94@yandex.ru
 */

#include <stdlib.h>
#include <stdio.h> 
#include "sum.h" //подключение заголовочного файла функции сложения
#include "sub.h" //подключение заголовочного файла функции вычитания
#include "dv.h" //подключение заголовочного файла функции деления
#include "mul.h" //подключение заголовочного файла функции умножения
int main (){
	float a, b; //объявление переменных вводимых с клавиатуры
	int oper; //объявление переменной операции списка
	while (1){
		printf (" \n 1. +\n 2. -\n 3. /\n 4. *\n 5. exit\n"); //выводится список оперций, доступных в этом калькуляторе
		printf (" enter transaction number: \n"); //введите номер операции
		scanf ("%d", &oper); //считывается значения выбора меню
		if (oper == 5){ //если переменная oper = 5, то выходим из программы
			printf ("exit"); //завершает работу программы
			return 0; 
		}
		printf ( " enter the variables: \n"); //введите переменные
		scanf ("%f%f", &a,&b); //считывается значение двух переменных
		if (oper == 1){ //если переменная oper = 1, то выполняем сложение
			printf("%f", sum(a, b)); //выводит сумму а+b
		}
		else if (oper == 2){ //если переменная oper = 2, то выполняем вычитание
			printf("%f", sub(a, b)); //выводит разницу a-b
		}
		else if (oper == 3){ //если переменная oper = 3, то выполняем деление
			printf("%f", dv(a, b)); //выводит результат деления a/b
		}
		else if (oper == 4){ //если переменная oper = 4, то выполняем умножение
			printf("%f", mul(a, b)); //выводит результат умножения a*b
		}

	}	
}

// Ex15.cpp: определяет точку входа для консольного приложения.
//

/*Создать класс Angle для работы с углами на плоскости, задаваемыми величиной в
градусах и минутах. Обязательно должны быть реализованы: перевод в радианы,
приведение к диапазону 0-360, увеличение и уменьшение угла на заданную величину,
получение синуса, сравнение углов*/

// https://github.com/Qerny/Ex15

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//Класс для работы с углами
class Angle 
{
private:
	int degrees;
	int minutes;

public:
	//Инициализация
	void Init() 
	{
		degrees = 0;
		minutes = 0;
	}

	//Ввод значения угла с клавиатуры
	void Read()
	{		
		cout << "Degrees: ";
		cin >> degrees;

		cout << "Minutes: ";
		cin >> minutes;

		if (degrees < 0)
			minutes *= -1;
	}

	//Вывод значения угла на экран
	void Display()
	{		
		cout << "Degrees: " << degrees << endl;

		if (minutes < 0)
			cout << "Minutes: " << minutes*-1 << endl;
		else
			cout << "Minutes: " << minutes << endl;
	}

	//Преобразование в строку
	string ToString()
	{
		if (minutes < 0)
			return to_string(degrees) + " " + to_string(minutes*-1);
		else
			return to_string(degrees) + " " + to_string(minutes);
	}

	//Получение значения угла в радианы
	double ToRadian()
	{
		return degrees*M_PI/180 + minutes*M_PI/180/60;  //M_PI - стандартная константа Пи
	}

	//Приведение к виду 0-360 (минуты к 0-60)
	void ToNormalRange()
	{	
		int d = degrees * 60 + minutes; //перевод в неправильную дробь
		
		minutes = d % 60;
		degrees = (d/60) - d/60/360 * 360;

		d = (degrees*60) + minutes; //перевод в неправильную дробь угла -360 - 360

		if (d < 0)
		{
			d = d + 360 * 60;
			minutes = d % 60;
			degrees = (d / 60) - d / 60 / 360 * 360;
		}
	}

	//Получение синуса
	double GetSin()
	{
		return sin(ToRadian());
	}
	
	//Увеличение угла на deg градусов, min минут
	void Increase(int deg, int min)
	{	
		if (degrees < 0)
			min *= -1;

		int d = deg * 60 + min + degrees * 60 + minutes;

		degrees = d / 60;
		minutes = d - degrees*60;
	}

	//Уменьшение угла на deg градусов, min минут
	void Decrease(int deg, int min)
	{
		if (degrees < 0)
			min *= -1;

		int d = degrees * 60 + minutes - deg * 60 - min;

		degrees = d / 60;
		minutes = d - degrees * 60;
	}
	
	//Перегрузка оператора > для углов
	Angle operator+(Angle a1)
	{
		Angle a3;

		int d = this->degrees * 60 + this->minutes + a1.degrees * 60 + a1.minutes;

		a3.degrees = d / 60;
		a3.minutes = d - a3.degrees * 60;

		return a3;
	}

	//Перегрузка оператора - для углов
	Angle operator-(Angle a1)
	{
		Angle a3;

		int d = this->degrees * 60 + this->minutes - a1.degrees * 60 - a1.minutes;

		a3.degrees = d / 60;
		a3.minutes = d - a3.degrees * 60;

		return a3;
	}

	//Перегрузка оператора < для углов
	bool operator<(Angle a1)
	{
		return (this->degrees + this->minutes * 60) < (a1.degrees + a1.minutes * 60); //Переводим в вещественные числа и сравниваем
	}

	//Перегрузка оператора > для углов
	bool operator>(Angle a1)
	{
		return (this->degrees + this->minutes * 60) > (a1.degrees + a1.minutes * 60);
	}
	
	//Перегрузка оператора = для углов
	bool operator==(Angle a1)
	{
		return (this->degrees + this->minutes * 60) == (a1.degrees + a1.minutes * 60);
	}

};

int main()
{	

	Angle ang1;
	ang1.Init();
	Angle ang2;
	ang2.Init();
	Angle ang3;

	int a;

	do
	{
		cout << "***************" << endl;
		cout << "1: Read" << endl;
		cout << "2: Display" << endl;
		cout << "3: ToString" << endl;
		cout << "4: ToRadian" << endl;
		cout << "5: ToNormalRange" << endl;
		cout << "6: GetSin" << endl;
		cout << "7: Increase" << endl;
		cout << "8: Decrease" << endl;
		cout << "9: a+b" << endl;
		cout << "10: a-b" << endl;
		cout << "11: a?b" << endl;
		cout << "0: Exit" << endl;
		cout << "***************" << endl;

		cin >> a;

		switch (a)
		{
		case 1:
		{
			cout << "Angle1:" << endl;
			ang1.Read();
			cout << endl;

			cout << "Angle2:" << endl;
			ang2.Read();
			cout << endl;
		}
		break;
		case 2:
		{
			cout << "Angle1:" << endl;
			ang1.Display();
			cout << endl;

			cout << "Angle2:" << endl;
			ang2.Display();
			cout << endl;
		}
		break;
		case 3:
		{
			cout << "Angle1:" << endl;
			cout << ang1.ToString() << endl;

			cout << "Angle2:" << endl;
			cout << ang2.ToString() << endl;
		}
		break;
		case 4:
		{
			cout << "Angle1:" << endl;
			cout << ang1.ToRadian() << endl;
		}
		break;
		case 5:
		{
			cout << "Angle1:" << endl;
			ang1.ToNormalRange();
			ang1.Display();
			cout << endl;
		}
		break;
		case 6:
		{
			cout << "Angle1:" << endl;
			cout << ang1.GetSin() << endl;
		}
		break;
		case 7:
		{
			int deg, min;
			
			cout << "Input degrees: ";
			cin >> deg;
			cout << "Input minutes: ";
			cin >> min;

			cout << "Angle1:" << endl;
			ang1.Increase(deg, min);
			ang1.Display();
			cout << endl;
		}
		break;
		case 8:
		{
			int deg, min;

			cout << "Input degrees: ";
			cin >> deg;
			cout << "Input minutes: ";
			cin >> min;

			cout << "Angle1:" << endl;
			ang1.Decrease(deg, min);
			ang1.Display();
			cout << endl;
		}
		break;
		case 9:
		{
			cout << "Angle1 + Angle2:" << endl;
			ang3 = ang1 + ang2;
			ang3.Display();
		}
		break;
		case 10:
		{
			cout << "Angle1 - Angle2:" << endl;
			ang3 = ang1 - ang2;
			ang3.Display();
		}
		break;
		case 11:
		{
			if (ang1 < ang2)
				cout << "Angle1 < Angle2" << endl;
			
			if(ang1 > ang2)
				cout << "Angle1 > Angle2" << endl;

			if(ang1 == ang2)
				cout << "Angle1 = Angle2" << endl;
		}
		break;
		}
		
	} while (a!=0);

	return 0;
}


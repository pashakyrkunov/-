#pragma once
#include <iostream>
#include "opencv2\core.hpp"

/* Singleton класс*/
class NumColTransformation
{
private:

	NumColTransformation() = default;

public:

	/* Статичный метод, для создания единственного экземпляра класса */
	static NumColTransformation &getInstance()
	{
		static NumColTransformation inst;
		return inst;
	}

	/*
	 *	Перевод числа из десятичной системы счисления в шестнадцатиричную
	 *  @param число в десятичной системе счисления
	 *  @return число в шестнадцатиричной системе счисления
	 */ 
	std::string ToHex(int number) const;
	/*
	 *	Перевод числа из шестнадцатиричной системы счисления в десятичную
	 *  @param число в шестнадцатиричной системе счисления
	 *  @return массив из трёх элементов - значений цвета в палитре BGR 
	 */
	std::array<int, 3> ToDec(std::string number) const;
	/*
	 * Вспомогательная функция для перевода в шестнадцатиричную систему счисления
	*/
	int sw(char element) const;
};


#pragma once
#include <iostream>
#include "opencv2\core.hpp"

/* Singleton �����*/
class NumColTransformation
{
private:

	NumColTransformation() = default;

public:

	/* ��������� �����, ��� �������� ������������� ���������� ������ */
	static NumColTransformation &getInstance()
	{
		static NumColTransformation inst;
		return inst;
	}

	/*
	 *	������� ����� �� ���������� ������� ��������� � �����������������
	 *  @param ����� � ���������� ������� ���������
	 *  @return ����� � ����������������� ������� ���������
	 */ 
	std::string ToHex(int number) const;
	/*
	 *	������� ����� �� ����������������� ������� ��������� � ����������
	 *  @param ����� � ����������������� ������� ���������
	 *  @return ������ �� ��� ��������� - �������� ����� � ������� BGR 
	 */
	std::array<int, 3> ToDec(std::string number) const;
	/*
	 * ��������������� ������� ��� �������� � ����������������� ������� ���������
	*/
	int sw(char element) const;
};


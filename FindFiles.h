#pragma once
#include <vector>
#include <stdio.h>
#include "Immage.h"
/* ����������� ����� - ��������� ������ ������*/
class FindFiles
{
public:
	/* ���������� ����� ������ ������ � ����������*/
	virtual std::vector<Immage*> search(char *path) const = 0;
};


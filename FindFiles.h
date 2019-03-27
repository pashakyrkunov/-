#pragma once
#include <vector>
#include <stdio.h>
#include "Immage.h"
/* абстрактный класс - обобщение поиска файлов*/
class FindFiles
{
public:
	/* обобщённый метод поиска файлов в директории*/
	virtual std::vector<Immage*> search(char *path) const = 0;
};


#pragma once
#include "FindFiles.h"


class FindImmages :
	public FindFiles
{
public:
	/* поиск изображений в директории
	 * @param путь к директории
	 * @return вектор объектов, описывающих изображение
	 */
	std::vector<Immage*> search(char *path) const;
};


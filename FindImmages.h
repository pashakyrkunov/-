#pragma once
#include "FindFiles.h"


class FindImmages :
	public FindFiles
{
public:
	/* ����� ����������� � ����������
	 * @param ���� � ����������
	 * @return ������ ��������, ����������� �����������
	 */
	std::vector<Immage*> search(char *path) const;
};


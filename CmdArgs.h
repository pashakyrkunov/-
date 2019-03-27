#pragma once
#include <iostream>
#include <vector>

/* Singleton ����� */
class CmdArgs
{
private:
	
	CmdArgs() = default;

public:

	/* ��������� �����, ��� �������� ������������� ���������� ������ */
	static CmdArgs &getInstance() 
	{
		static CmdArgs inst;
		return inst;
	}

	/* ������ ���������� ��������� ������, ����� ���������� ������������ ����� �����
	 * @param1 ���-�� ���������� ��������� ������
	 * @param2 ��������� ��������� ������
	 * @param3 ������ �� ����������, � ������� �������� ���� � ����������
	 * @param3 ������ �� ����������, � ������� �������� �������� ����
	 * @return 1, ���� ��� ��������� ����� � 0,���� ���
	 */
	int argParser(int argc, char* argv[], std::string &path, std::string &color);

};




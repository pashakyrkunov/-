#pragma once
#include <map>
class HexImmage
{
private:
	std::map<std::string, int> hexColorCount;
	/*
	* �������� �����������
	*/
	std::string im_name;
	/*
	* ���� � �����������
	*/
	std::string im_path;
	/*
	* ������������ ���� � �����������
	*/
	std::string dominateColor;
	
public:
	HexImmage();
	//~HexImmage();
};


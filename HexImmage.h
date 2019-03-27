#pragma once
#include <map>
class HexImmage
{
private:
	std::map<std::string, int> hexColorCount;
	/*
	* Название изображения
	*/
	std::string im_name;
	/*
	* Путь к изображению
	*/
	std::string im_path;
	/*
	* Доминирующий цвет в изображении
	*/
	std::string dominateColor;
	
public:
	HexImmage();
	//~HexImmage();
};


#pragma once
#include <iostream>
#include <vector>

/* Singleton класс */
class CmdArgs
{
private:
	
	CmdArgs() = default;

public:

	/* Статичный метод, для создания единственного экземпляра класса */
	static CmdArgs &getInstance() 
	{
		static CmdArgs inst;
		return inst;
	}

	/* Парсер аргументов командной строки, также определяет корректность ввода цвета
	 * @param1 кол-во параметров командной строки
	 * @param2 параметры командной строки
	 * @param3 ссылка на переменную, в которой хранится путь к директории
	 * @param3 ссылка на переменную, в которой хранится введённый цвет
	 * @return 1, если все параметры верны и 0,если нет
	 */
	int argParser(int argc, char* argv[], std::string &path, std::string &color);

};




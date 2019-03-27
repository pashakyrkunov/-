#pragma once
#include "stdafx.h"

	/*
	 * Перечисление,содержащее основные цвета RGB
	 */
	enum COLORS { BLACK = 0, WHITE, GREY, RED, ORANGE, YELLOW, GREEN, AQUA, BLUE, PURPLE};
	/*  
	 * Класс, описывающий изображение
	 */
	class Immage
	{	
	private:
		/*
		 * Контейнер map, в котором ключ - это цвет, значение - кол-во пикселей данного цвета
		 */
		std::map <std::string, int> colorCount;
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
		/*
		 * Конструктор класса 
		 * @param1 название изображения
		 * @param2 путь к изображению
		 */
		Immage(std::string name, std::string path);
		/*
		 * Метод, определяющий цвет пикселя по его значениям в HSV
		 * @param1 Hue - тон
		 * @param2 Saturation - насыщенность
		 * @param3 Value - значение
		 * @return цвет пикселя,соответствующий цвету в перечислении COLORS
		 */
		int getPixelColorType(int H, int S, int V);
		/*
		 * Метод, увеличивающий значения colorCount в соответствии с кол-вом
		 * пикселей определённого цвета
		 * @param матрица, хранящая изображение в HSV
		 */
		void findColors(cv::Mat image_hsv);
		/*
		 * Метод, увеличивающий значения colorCount в соответствии с кол-вом
		 * пикселей определённого цвета(для случая, когда пользователь вводит
		 * цвет в виде шестнадцатиричного значения)
		 * @param матрица, хранящая изображение в BGR
		 *
		 */
		void BGRfindcolors(cv::Mat image_bgr);
		/*
		 * Метод, определяющий доминирующий цвет
		 */
		void findDominateColor();
		/*
		 * Возвращает название изображения
		 */
		std::string getName() { return im_name; }
		/*
		 * Возвращает путь к изображению
		 */
		std::string getPath() { return im_path; }
		/*
		 * Возвращает доминирующий цвет
		 */
		std::string getDominateColor() { return dominateColor; }
	};



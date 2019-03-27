#pragma once
#include "stdafx.h"

	/*
	 * ������������,���������� �������� ����� RGB
	 */
	enum COLORS { BLACK = 0, WHITE, GREY, RED, ORANGE, YELLOW, GREEN, AQUA, BLUE, PURPLE};
	/*  
	 * �����, ����������� �����������
	 */
	class Immage
	{	
	private:
		/*
		 * ��������� map, � ������� ���� - ��� ����, �������� - ���-�� �������� ������� �����
		 */
		std::map <std::string, int> colorCount;
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
		/*
		 * ����������� ������ 
		 * @param1 �������� �����������
		 * @param2 ���� � �����������
		 */
		Immage(std::string name, std::string path);
		/*
		 * �����, ������������ ���� ������� �� ��� ��������� � HSV
		 * @param1 Hue - ���
		 * @param2 Saturation - ������������
		 * @param3 Value - ��������
		 * @return ���� �������,��������������� ����� � ������������ COLORS
		 */
		int getPixelColorType(int H, int S, int V);
		/*
		 * �����, ������������� �������� colorCount � ������������ � ���-���
		 * �������� ������������ �����
		 * @param �������, �������� ����������� � HSV
		 */
		void findColors(cv::Mat image_hsv);
		/*
		 * �����, ������������� �������� colorCount � ������������ � ���-���
		 * �������� ������������ �����(��� ������, ����� ������������ ������
		 * ���� � ���� ������������������ ��������)
		 * @param �������, �������� ����������� � BGR
		 *
		 */
		void BGRfindcolors(cv::Mat image_bgr);
		/*
		 * �����, ������������ ������������ ����
		 */
		void findDominateColor();
		/*
		 * ���������� �������� �����������
		 */
		std::string getName() { return im_name; }
		/*
		 * ���������� ���� � �����������
		 */
		std::string getPath() { return im_path; }
		/*
		 * ���������� ������������ ����
		 */
		std::string getDominateColor() { return dominateColor; }
	};



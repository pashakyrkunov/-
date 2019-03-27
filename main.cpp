//Выполнил Кыркунов Павел 23536/4

#include "Immage.h"
#include "FindImmages.h"
#include "CmdArgs.h"
#include "NumColTransformation.h"
	int main(int argc, char* argv[])
	{
		std::string path;
		std::string color;
		CmdArgs s = CmdArgs::getInstance();
		int bflag = s.argParser(argc, argv, path, color);
		if (bflag == 0)
		{
			return -1;
		}
		char *pathptr = &path[0];
		cv::Mat image_hsv;
		cv::Mat image_bgr;
		bool flag = 0;
		std::vector<Immage*> files;
		FindImmages *list = new FindImmages();
		try 
		{
			files = list->search(pathptr);
		}
		catch (int i)
		{
			std::cout << "This directory does not exist" << std::endl;
			return i;
		}
		if (bflag == 1)
		{
			for (int i = 2; i < files.size(); i++)
			{
				image_bgr = cv::imread(files[i]->getPath());
				if (!image_bgr.data)
				{
					continue;
				}

				cv::cvtColor(image_bgr, image_hsv, cv::COLOR_BGR2HSV);
				files[i]->findColors(image_hsv);
				files[i]->findDominateColor();
				if (files[i]->getDominateColor() == color)
				{
					std::cout << files[i]->getPath() << std::endl;
					flag = 1;
				}
				delete files[i];
			}
		}
		else
		{
			for (int i = 2; i < files.size(); i++)
			{
				image_bgr = cv::imread(files[i]->getPath());
				if (!image_bgr.data)
				{
					continue;
				}

				files[i]->BGRfindcolors(image_bgr);
				files[i]->findDominateColor();
				if (files[i]->getDominateColor() == color)
				{
					std::cout << files[i]->getPath() << std::endl;
					flag = 1;
				}
				delete files[i];
			}
		}
		if (flag == 0)
		{
			std::cout << "Nothing found." << std::endl;
		}
		else
		{
			std::cout << "The search is over." << std::endl;
		}
		return 0;
	}
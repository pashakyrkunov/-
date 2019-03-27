#include "Immage.h"
#include "NumColTransformation.h"
	Immage::Immage(std::string name, std::string path)
	{
		colorCount = 
		{ { "black", 0 },
		{ "white", 0 },
		{ "grey", 0 },
		{ "red", 0 },
		{ "orange", 0 },
		{ "yellow", 0 },
		{ "green", 0 },
		{ "aqua", 0 },
		{ "blue", 0 },
		{ "purple", 0 } };

		im_name = name;
		im_path = path;

	}

	int Immage::getPixelColorType(int H, int S, int V) 
	{

		int color = BLACK;

		if (V < 75) color = BLACK;
		else if (V > 190 && S < 27) color = WHITE;
		else if (S < 53 && V < 185) color = GREY;
		else
		{
			if (H < 7) color = RED;
			else if (H < 25) color = ORANGE;
			else if (H < 34) color = YELLOW;
			else if (H < 73) color = GREEN;
			else if (H < 102) color = AQUA;
			else if (H < 140) color = BLUE;
			else if (H < 170) color = PURPLE;
			else color = RED;
		}
		return color;
	}


	void Immage::findColors(cv::Mat image_hsv) 
	{
		for (int i = 0; i < image_hsv.rows; i++) 
		{
			for (int j = 0; j < image_hsv.cols; j++) 
			{
				switch (getPixelColorType(image_hsv.at<cv::Vec3b>(i, j)[0], image_hsv.at<cv::Vec3b>(i, j)[1], image_hsv.at<cv::Vec3b>(i, j)[2]))
				{
				case BLACK:
					colorCount["black"]++;
					break;
				case WHITE:
					colorCount["white"]++;
					break;
				case GREY:
					colorCount["grey"]++;
					break;
				case RED:
					colorCount["red"]++;
					break;
				case ORANGE:
					colorCount["orange"]++;
					break;
				case YELLOW:
					colorCount["yellow"]++;
					break;
				case GREEN:
					colorCount["green"]++;
					break;
				case AQUA:
					colorCount["aqua"]++;
					break;
				case BLUE:
					colorCount["blue"]++;
					break;
				case PURPLE:
					colorCount["purple"]++;
					break;
				}
			}
		}
	}

	void Immage::BGRfindcolors(cv::Mat image_bgr)
	{
		NumColTransformation inst = NumColTransformation::getInstance();
		std::string color;

		for (int i = 0; i < image_bgr.rows; i++)
		{
			for (int j = 0; j < image_bgr.cols; j++)
			{
				color = "#" + inst.ToHex(image_bgr.at<cv::Vec3b>(i, j)[2]) 
					+ inst.ToHex(image_bgr.at<cv::Vec3b>(i, j)[1]) 
					+ inst.ToHex(image_bgr.at<cv::Vec3b>(i, j)[0]);
				if (colorCount.find(color) == colorCount.end())
				{
					colorCount.insert(std::make_pair(color,1));
				}
				else
				{
					colorCount[color]++;
				}
			}
		}
	}

	void Immage::findDominateColor()
	{
		int max = -1;
		std::string ind;

		for (auto it = colorCount.begin(); it != colorCount.end(); ++it)
		{
			if (it->second > max) {
				max = it->second;
				ind = it->first;
			}
		}
		dominateColor = ind;
	}


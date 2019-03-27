#include "CmdArgs.h"
#include "Immage.h"
#include "NumColTransformation.h"


int CmdArgs::argParser(int argc, char* argv[], std::string &path, std::string &color)
{
	std::vector<std::string> colors = { "black", "white", "grey", "red", "orange", "yellow", "green", "aqua", "blue", "purple" };
	if (argc < 3)
	{
		std::cout << "Enter two parameters : path and color" << std::endl;
		return 0;
	}
	
	if (argv[1][1] == ':' && (argv[1][2] == '/' || argv[1][2] == '\\'))
	{
		path = argv[1];
		color = argv[2];
	}
	else
	{
		color = argv[1];
		path = argv[2];
	}

	if (color[0] == '#' && color.size() == 7)
	{
		return 2;
	}

	std::transform(color.begin(), color.end(), color.begin(), tolower);
	
	bool flag = 0;
	for (int i = 0; i < colors.size(); i++)
	{
		if (colors[i] == color)
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		return 1;
	}
	else
	{
		std::cout << "Invalid color" << std::endl;
		return 0;
	}
}

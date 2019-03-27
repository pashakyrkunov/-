#include <array>
#include "NumColTransformation.h"

int NumColTransformation::sw(char element) const
{
	int k;
	switch (element)
	{
	case 'A': k = 10; break;
	case 'B': k = 11; break;
	case 'C': k = 12; break;
	case 'D': k = 13; break;
	case 'E': k = 14; break;
	case 'F': k = 15; break;
	case '1': k = 1; break;
	case '2': k = 2; break;
	case '3': k = 3; break;
	case '4': k = 4; break;
	case '5': k = 5; break;
	case '6': k = 6; break;
	case '7': k = 7; break;
	case '8': k = 8; break;
	case '9': k = 9; break;
	case '0': k = 0; break;
	}

	return k;
}

std::array<int, 3> NumColTransformation::ToDec(std::string number) const
{
	std::array<int,3> BGRvalues;
	BGRvalues[0] = sw(number[5])*16 + sw(number[6]);
	BGRvalues[1] = sw(number[3])*16 + sw(number[4]);
	BGRvalues[2] = sw(number[1])*16 + sw(number[2]);
	return BGRvalues;
}

std::string NumColTransformation::ToHex(int number) const
{
	std::string tmp("");
	do
	{
		int r = number % 16;
		if (r>9) 
		{ 
			r += (int)'A' - 10; 
		}
		else 
		{ 
			r += (int)'0'; 
		};
		tmp = (char)r + tmp;
		number /= 16;
	} while (number);
	if (tmp.size() == 1)
	{
		return tmp + "0";
	}
	return tmp;
}
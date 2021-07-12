#include "readFile.hpp"

std::string readFile(const char *filename)
{
	std::string output;
	std::string line;
	
	std::ifstream file{ filename };
	if(file.is_open())
	{
		while(getline(file, line))
		{
			output += line;
			output += '\n';
		}
		
		file.close();
	}
	
	return output;
}
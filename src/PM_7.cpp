#include <iostream>
#include <conio.h>
#include "HashTable.hpp"

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
		key = _getch();
	return key - 48;
}

bool is_exists(const std::string& name) 
{
	std::ifstream f(name.c_str());
	return f.good();
}

int main_menu()
{
	std::cout << "[1] Find" << std::endl;
	std::cout << "[2] Exit" << std::endl;

	while (true)
	{
		int key = get_key();
		if (key == 1 || key == 2)
			return key;
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "You must specify only 1 argument: path to .txt file" << std::endl
			<< "EXAMPLE: ./PM_7.exe C:\\Users\\PC\\Documents\\sample_text.txt " << std::endl;
		return -1;
	}

	const std::string path(argv[1]);
	if (!is_exists(path))
	{
		std::cout << "File " << path << " doesn't exist" << std::endl;
		return -2;
	}

	HashTable hash_table(path);

	while (true)
	{
		int key = main_menu();
		system("cls");

		if (key == 2)
			return 0;
		else if (key == 1)
		{
			std::cout << "Enter value to find: ";
			std::string input;
			getline(std::cin, input);
			if (hash_table.contains(input))
				std::cout << "CONTAINS" << std::endl;
			else
				std::cout << "NOT CONTAINS" << std::endl;
			std::cout << std::endl;
		}
	}
}

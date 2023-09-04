#include <iostream>
#include <ctime>

int main()
{
	std::string task;
	std::time_t begin;
	std::time_t end;

	do {

		std::cout << "Enter command: ";
		std::cin >> task;

		if (task == "begin") {

			begin = std::time(nullptr);
			

		}
		else if (task == "end") {

			end = std::time(nullptr);
			

		}


	} while (task != "exit");
	


	std::cout << begin << " " << end << std::endl;

	std::cout << difftime(end, begin);
}
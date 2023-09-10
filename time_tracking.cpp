#include <iostream>
#include <vector>
#include <ctime>

int main()
{
	std::string command;

	std::time_t begin = 0;
	std::time_t end = 0;
	
	std::vector<std::string> task_name(0);
	std::vector<int> result(0);

	do {
				
		std::string task;

		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "begin") {

			if (begin == 0) {

				std::cout << "Enter the name of the task: ";
				std::cin >> task;
				task_name.push_back(task);
				begin = std::time(nullptr);

			}
			else if (begin != 0) {

				end = std::time(nullptr);				
				result.push_back(difftime(end, begin));
				
				std::cout << "Enter the name of the task: ";
				std::cin >> task;
				task_name.push_back(task);
				begin = std::time(nullptr);

			}
		}
		else if (command == "end") {

			if (begin != 0) {

				end = std::time(nullptr);

				result.push_back(difftime(end, begin));
				begin = 0;

			}
		}
		else if (command == "status") {			

			if (result.size() == task_name.size()) {

				for (int i = 0; i < result.size(); ++i) {

					std::cout << "Task " << i + 1 << " " << task_name[i] << " " << result[i] << std::endl;

				}
			}
			else {

				result.push_back(-1);
				
				for (int i = 0; i < task_name.size(); ++i) {

					if (result[i] >= 0) {

						std::cout << "Task " << i + 1 << " " << task_name[i] << " " << result[i] << std::endl;

					}
					else {

						std::cout << "Task " << i + 1 << " " << task_name[i] << " " << " In progress" << std::endl;

					}
				}

				result.pop_back();

			}			
		}

	} while (command != "exit");
}
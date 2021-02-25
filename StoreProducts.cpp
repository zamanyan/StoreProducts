#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void SELL(std::vector<int>& products, int& concrete_product)
{
	if (products[concrete_product - 1] != 0) {
		products[concrete_product - 1]--;
	}
}

void ADD(std::vector<int>& products, int& concrete_product)
{
	products[concrete_product - 1]++;
}

void DUMP(const std::vector<int>& products, int& concrete_product)
{
	std::cout << " Total number of product " << concrete_product
		<< " is: " << products[concrete_product - 1] << std::endl;
}

void DUMPALL(const std::vector<int>& products)
{
	int total_number = 0;
	for (auto product : products) {
		total_number += product;
	}
	std::cout << " Total number of all products is: " << total_number << std::endl;
}

void extractCommand(const std::string& command,
	std::string& action, int& concrete_product)
{
	std::string s = "";
	for (int i = 0; i < command.size(); i++) {
		if (command[i] >= 'A' && command[i] <= 'Z') {
			action += command[i];
		}
		else if (command[i] >= '0' && command[i] <= '9') {
			s += command[i];
		}
	}
	std::stringstream convert(s);
	convert >> concrete_product;
}

void PrintProducts(const std::vector<int>& prodcuts)
{
	for (auto product : prodcuts) {
		std::cout << ' ' << product;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << " There are 4 commands: SELL, ADD, DUMP and DUMPALL\n"
		<< " SELL - sells a concrete product:\n"
		<< " ADD - adds a concrete product by one:\n"
		<< " DUMP - prints the quantity of concrete product:\n"
		<< " DUMPALL - print the the total number of all products:\n"
		<< " If you want to end the program, type END\n\n";

	int size;
	std::cout << " size: ";
	std::cin >> size;
	std::vector<int> products(size);

	std::string command;
	std::string action;
	int concrete_product;

	std::getline(std::cin, command);

	do {
		action = "";
		std::cout << " command: ";
		std::getline(std::cin, command);
		extractCommand(command, action, concrete_product);

		if (action == "SELL") {
			SELL(products, concrete_product);
		}
		else if (action == "ADD") {
			ADD(products, concrete_product);
		}
		else if (action == "DUMP") {
			DUMP(products, concrete_product);
		}
		else if (action == "DUMPALL") {
			DUMPALL(products);
			PrintProducts(products);
		}
		else {
			if (action != "END") {
				std::cout << " Wrong command!" << std::endl;
			}
		}
	} while (action != "END");

	return 0;
}
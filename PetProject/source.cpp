#include <iostream>
#include "RabinKarpOut.h"
#include "RabinKarp.h"
#include "RabinKarpProMaxUltra.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	std::string line = "";
	std::string search_line = "";

	std::cin >> search_line;
	std::cout << std::endl;
	//алгоритм аутсайдер
	RabinKarpOut FromFileOut(search_line);
	FromFileOut.Alg();

	//стандартный алгоритм
	RabinKarp FromFile(search_line);
	FromFile.Alg();

	//оптимизированный алгоритм
	RabinKarpProMaxUltra FromFileUltra(search_line);
	FromFileUltra.Alg();

	return EXIT_SUCCESS;
}
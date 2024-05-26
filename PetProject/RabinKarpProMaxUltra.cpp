#include "RabinKarpProMaxUltra.h"

int BASE = 31; //для BASE необходимо выбрать число в диапазоне 0..Q, умножение на 31 очень оптимально, потому что это побитовый сдвиг на 5 слево и вычитание этого числа из результата, так же это небольшое число и результат получается очень быстро
int Q = 2147483647; //для выбора Q есть рекомендации, желательно, чтобы Q было простым, для ускорения вычислений рекомендуют использовать числа Мерсена (2^32-1 или 2^64-1)

RabinKarpProMaxUltra::RabinKarpProMaxUltra()
{
}

RabinKarpProMaxUltra::RabinKarpProMaxUltra(std::string line, std::string search_line)
{
	str = line;
	sub_str = search_line;
}

RabinKarpProMaxUltra::RabinKarpProMaxUltra(std::string search_line)
{
	str = readTextFromFile();
	sub_str = search_line;
}

RabinKarpProMaxUltra::RabinKarpProMaxUltra(const RabinKarpProMaxUltra& copy)
{
	str = copy.str;
	sub_str = copy.sub_str;
}

RabinKarpProMaxUltra::~RabinKarpProMaxUltra()
{
	str = "";
	sub_str = "";
}

std::string RabinKarpProMaxUltra::readTextFromFile()
{
	std::ifstream file("text.txt");
	if (!file.is_open())
	{
		std::cout << "файл не открыт" << std::endl;
		return " ";
	}

	std::string str;
	std::string s;
	while (!file.eof()) {
		getline(file, s);
		str += s + '\n';
	}

	file.close();
	return str;
}

int RabinKarpProMaxUltra::gorner_scheme(std::string str, int start, int end)
{
	int res = (int)str[0];

	for (int i = start; i < end - 1; i++)
	{
		res = res * BASE + (int)str[i + 1];
	}
	return res;
}

//алгоритм хеширования, чтобы не сравнивать строки посимвольно 
int RabinKarpProMaxUltra::hash(std::string str, int start, int end)
{
	return gorner_scheme(str, start, end) % Q;
}

//функция для оптимизации, вычисление степени
int RabinKarpProMaxUltra::basePow(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		res = res * BASE;
	}
	return res;
}

//реализация алгоритма
void RabinKarpProMaxUltra::Alg()
{
	unsigned int start_time = clock();

	int start = 0;
	int m = sub_str.length();
	int end = start + m;

	int sub_hash = 0;
	sub_hash = hash(sub_str, start, end);

	int current_hash = 0;
	current_hash = hash(str, start, end);

	int mult = basePow(m - 1);

	int i = 0;
	bool exit = false;
	while (!exit)
	{
		if (sub_hash == current_hash)
		{
			std::cout << "Позиция: " << i << std::endl;
		}
		if ((i + m) >= str.length())
		{
			break;
		}
		current_hash = ((current_hash - (int)str[i] * basePow(m - 1)) * BASE + (int)str[i + m]) % Q;
		i = i + 1;
	}

	unsigned int end_time = clock();
	unsigned int total_time = end_time - start_time;
	std::cout << "Программа завершила свою работу за: " << total_time << " мс" << std::endl;
	std::cout << std::endl;
}
#include "RabinKarpOut.h"

int BASE2 = 617189991;
int Q2 = 2147473841;

RabinKarpOut::RabinKarpOut()
{
}

RabinKarpOut::RabinKarpOut(std::string line, std::string search_line)
{
	str = line;
	sub_str = search_line;
}

RabinKarpOut::RabinKarpOut(std::string search_line)
{
	str = readTextFromFile();
	sub_str = search_line;
}

RabinKarpOut::~RabinKarpOut()
{
	str = "";
	sub_str = "";
}

std::string RabinKarpOut::readTextFromFile()
{
	std::ifstream file("text.txt");
	if (!file.is_open())
	{
		std::cout << "���� �� ������" << std::endl;
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

int RabinKarpOut::gorner_scheme(std::string str, int start, int end)
{
	int res = (int)str[0];

	for (int i = start; i < end - 1; i++)
	{
		res = res * BASE2 + (int)str[i + 1];
	}
	return res;
}

//�������� �����������, ����� �� ���������� ������ ����������� 
int RabinKarpOut::hash(std::string str, int start, int end)
{
	return gorner_scheme(str, start, end) % Q2;
}

//������� ��� �����������, ���������� �������
int RabinKarpOut::basePow(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int res = 1;
	for (int i = 0; i < n; i++)
	{
		res = res * BASE2;
	}
	return res;
}

//���������� ���������
void RabinKarpOut::Alg()
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
			std::cout << "�������: " << i << std::endl;
		}
		if ((i + m) >= str.length())
		{
			break;
		}
		current_hash = ((current_hash - (int)str[i] * basePow(m - 1)) * BASE2 + (int)str[i + m]) % Q2;
		i = i + 1;
	}

	unsigned int end_time = clock();
	unsigned int total_time = end_time - start_time;
	std::cout << "��������� ��������� ���� ������ ��: " << total_time << " ��" << std::endl;
	std::cout << std::endl;
}
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class RabinKarpOut
{
public:
	std::string str;
	std::string sub_str;
	RabinKarpOut();
	RabinKarpOut(std::string line, std::string search_line);
	RabinKarpOut(std::string search_line);
	~RabinKarpOut();
	void Alg();

private:
	std::string readTextFromFile();
	int gorner_scheme(std::string str, int start, int end);
	int hash(std::string str, int start, int end);
	int basePow(int n);
};

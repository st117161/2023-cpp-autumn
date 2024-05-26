#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class RabinKarp
{
public:
	std::string str;
	std::string sub_str;
	RabinKarp();
	RabinKarp(std::string line, std::string search_line);
	RabinKarp(std::string search_line);
	~RabinKarp();
	void Alg();

private:
	std::string readTextFromFile();
	int gorner_scheme(std::string str, int start, int end);
	int hash(std::string str, int start, int end);
	int basePow(int n);
};
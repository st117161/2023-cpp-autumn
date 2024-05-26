#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class RabinKarpProMaxUltra
{
public:
	std::string str;
	std::string sub_str;
	RabinKarpProMaxUltra();
	RabinKarpProMaxUltra(std::string line, std::string search_line);
	RabinKarpProMaxUltra(std::string search_line);
	RabinKarpProMaxUltra(const RabinKarpProMaxUltra& copy);
	~RabinKarpProMaxUltra();
	void Alg();

private:
	std::string readTextFromFile();
	int gorner_scheme(std::string str, int start, int end);
	int hash(std::string str, int start, int end);
	int basePow(int n);
};
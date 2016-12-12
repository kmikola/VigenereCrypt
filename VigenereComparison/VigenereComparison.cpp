// VigenereComparison.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <ctime>
#include "VigenereEncryptorGeneral.hpp"
#include "VigenereEncryptorSequential.hpp"

using namespace Docler::Tools;

void vigenereGeneral(const std::string &str) {
	VigenereEncryptorGeneral enc = VigenereEncryptorGeneral("vtabla.dat", str, "PASSW");
	enc.encrypt();
}

void vigenereSequential(const std::string &str) {
	VigenereEncryptorSequential enc = VigenereEncryptorSequential("vtabla.dat", str, "PASSW");
	enc.encrypt();
}

void test(const std::string &str, const std::string &method_name, void(*fp)(const std::string &)) {
	for (int i = 0; i < 3; i++) {
		std::cout << method_name << " method running... ";
		std::clock_t start = std::clock();
		(*fp)(str);
		double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << duration << "s" << std::endl;
	}
}

std::string generateTestData() {
#ifdef _DEBUG
	int TEST_STRING_SIZE = 10000;
#else
	int TEST_STRING_SIZE = 1000000;
#endif
	std::cout << "Performance tests (" << TEST_STRING_SIZE << " test items):" << std::endl;
	std::cout << "Creating test string..." << std::endl;
	std::string str;
	str.reserve(TEST_STRING_SIZE);
	for (int i = 0; i < TEST_STRING_SIZE; i++) {
		str.append(1, rand() % ('Z'-'A') + 'A');
	}
	std::cout << "Test string created." << std::endl;
	return str;
}

int main()
{
	std::string str = generateTestData();
	VigenereEncryptorGeneral enc1 = VigenereEncryptorGeneral("vtabla.dat", str, "PASSW");
	std::string cript1 = enc1.encrypt();
	VigenereEncryptorSequential enc2 = VigenereEncryptorSequential("vtabla.dat", str, "PASSW");
	std::string cript2 = enc1.encrypt();
	if (cript1.compare(cript2) == 0) {
		std::cout << "Methods give same result. Algorithm tested." << std::endl;
	}
	else {
		std::cout << "!!! Algorithm error. Methods give different result. !!!" << std::endl;
	}
	test(str, "vigenereGeneral", &vigenereGeneral);
	test(str, "vigenereSequential", &vigenereSequential);
	std::cout << "" << std::endl;
	std::cout << "Press any key to exit." << std::endl;
	std::getchar();
}
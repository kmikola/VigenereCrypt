// UppercaseComparison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <ctime>

std::string toUppercase(const std::string &str) {
	std::string upperstr = std::string(str);
	std::transform(upperstr.begin(), upperstr.end(), upperstr.begin(), [](unsigned char c) { return std::toupper(c); });
	return upperstr;
}

std::string toUppercase2(const std::string &str) {
	std::string upperstr = std::string(str);
	std::transform(upperstr.begin(), upperstr.end(), upperstr.begin(), ::toupper);
	return upperstr;
}


std::string toUppercaseToUpper(const std::string &str) {
	std::string upperstr = std::string(str);
	for (int i = 0; upperstr[i] != 0; i++)
		upperstr[i] = std::toupper(str[i]);
	return upperstr;
}

std::string toUppercaseWithArrayOperator(const std::string &str) {
	std::string upperstr = std::string(str);
	for (int i = 0; upperstr[i] != 0; i++)
		if (upperstr[i] <= 122 && upperstr[i] >= 97)
			upperstr[i] -= 32;
	return upperstr;
}

std::string toUppercaseAutoVar(const std::string &str) {
	std::string upperstr = std::string(str);
	for (auto & c : upperstr) c = toupper(c);
	return upperstr;
}

std::string toUppercaseForeach(const std::string &str) {
	struct convert {
		void operator()(char& c) { c = toupper((unsigned char)c); }
	};
	std::string upperstr = std::string(str);
	for_each(upperstr.begin(), upperstr.end(), convert());
	return upperstr;
}

std::string toUppercaseIterator(const std::string &str) {
	std::string upperstr = std::string(str);
	for (std::string::iterator p = upperstr.begin(); upperstr.end() != p; ++p) {
		*p = toupper(*p);
	}
	return upperstr;
}

void test(const std::string &str, const std::string &method_name, std::string(*fp)(const std::string &)){
	for (int i = 0; i < 3; i++) {
		std::cout << method_name << " method running... ";
		std::clock_t start = std::clock();
		std::string uppercase = (*fp)(str);
		double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << duration << "s" << std::endl;
	}
}

std::string generateTestData() {
#ifdef _DEBUG
	int TEST_STRING_SIZE = 1000000;
#else
	int TEST_STRING_SIZE = 100000000;
#endif
	std::cout << "Performance tests (" << TEST_STRING_SIZE << " test items):" << std::endl;
	std::cout << "Creating test string..." << std::endl;
	std::string str;
	str.reserve(TEST_STRING_SIZE);
	for (int i = 0; i < TEST_STRING_SIZE; i++) {
		str.append(1, rand() % ('z' - 'a') + 'a');
	}
	std::cout << "Test string created." << std::endl;
	return str;
}

int main()
{
	std::string str = generateTestData();
	test(str, "toUppercase", &toUppercase);
	test(str, "toUppercase2", &toUppercase2);
	test(str, "toUppercaseAutoVar", &toUppercaseAutoVar);
	test(str, "toUppercaseForeach", &toUppercaseForeach);
	test(str, "toUppercaseIterator", &toUppercaseIterator);
	test(str, "toUppercaseToUpper", &toUppercaseToUpper);
	test(str, "toUppercaseWithArrayOperator", &toUppercaseWithArrayOperator);
	std::cout << "" << std::endl;
	std::cout << "Press any key to exit." << std::endl;
	std::getchar();
}


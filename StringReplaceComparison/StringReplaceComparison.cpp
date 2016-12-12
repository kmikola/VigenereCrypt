// StringReplaceComparison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <ctime>
#include "stdafx.h"

std::string eliminateSpecialChars(const std::string &str) {
	std::string eliminated = std::string();
	for (const unsigned char &c : str) {
		if (c == 0x82) {
			eliminated.append(1, 'e');
		}
		else if (c == 0xA0) {
			eliminated.append(1, 'a');
		}
		else if (c == 0xFB) {
			eliminated.append(1, 'u');
		}
		else if (c == 0x8B) {
			eliminated.append(1, 'o');
		}
		else if (c == 0xA3) {
			eliminated.append(1, 'u');
		}
		else if (c == 0xA2) {
			eliminated.append(1, 'o');
		}
		else if (c == 0x81) {
			eliminated.append(1, 'u');
		}
		else if (c == 0x94) {
			eliminated.append(1, 'o');
		}
		else if (c == 0xA1) {
			eliminated.append(1, 'i');
		}
		else if (c == 0x90) {
			eliminated.append(1, 'E');
		}
		else if (c == 0xB5) {
			eliminated.append(1, 'A');
		}
		else if (c == 0xEB) {
			eliminated.append(1, 'U');
		}
		else if (c == 0x8A) {
			eliminated.append(1, 'O');
		}
		else if (c == 0xE9) {
			eliminated.append(1, 'U');
		}
		else if (c == 0xE0) {
			eliminated.append(1, 'O');
		}
		else if (c == 0x9A) {
			eliminated.append(1, 'U');
		}
		else if (c == 0x99) {
			eliminated.append(1, 'O');
		}
		else if (c == 0xD6) {
			eliminated.append(1, 'I');
		}
		else if ((c>64 && c<91) || (c>96 && c<123)) {
			eliminated.append(1, c);
		}
	}
	return eliminated;
}

std::string eliminateSpecialCharsStdWay(const std::string &str) {
	std::string eliminated = std::string(str);
	std::replace(eliminated.begin(), eliminated.end(), (char)0x82, 'e');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xA0, 'a');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xFB, 'u');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x8B, 'o');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xA3, 'u');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xA2, 'o');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x81, 'u');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x94, 'o');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xA1, 'i');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x90, 'E');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xB5, 'A');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xEB, 'U');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x8A, 'O');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xE9, 'U');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xE0, 'O');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x9A, 'U');
	std::replace(eliminated.begin(), eliminated.end(), (char)0x99, 'O');
	std::replace(eliminated.begin(), eliminated.end(), (char)0xD6, 'I');
	return eliminated;
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
		str.append(1, rand() % 'a' + 'z');
	}
	std::cout << "Test string created." << std::endl;
	return str;
}

void test(const std::string &str, const std::string &method_name, std::string(*fp)(const std::string &)) {
	for (int i = 0; i < 3; i++) {
		std::cout << method_name << " method running... ";
		std::clock_t start = std::clock();
		std::string uppercase = (*fp)(str);
		double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << duration << "s" << std::endl;
	}
}

int main()
{
	std::string str = generateTestData();
	test(str, "eliminateSpecialChars", &eliminateSpecialChars);
	test(str, "eliminateSpecialCharsStdWay", &eliminateSpecialCharsStdWay);
	std::cout << "" << std::endl;
	std::cout << "Press any key to exit." << std::endl;
	std::getchar();
}


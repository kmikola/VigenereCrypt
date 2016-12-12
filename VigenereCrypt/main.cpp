#include "stdafx.h"
#include "StringTools.hpp"
#include "VigenerFactory.hpp"

#include <Windows.h>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace Docler::Tools;

static const int EXIT_WITHOUT_ERROR = 0;
static const int EXIT_MESSAGE_EMPTY = 1;
static const int EXIT_MESSAGE_TOO_LONG = 2;
static const int EXIT_KEY_EMPTY = 3;
static const int EXIT_KEY_TOO_LONG = 4;

static void printwelcome() {
	std::cout << "This is a program to encrypt your public message using Vigenere method." << std::endl;
	std::cout << "It can be less than 256 characters and empty text is not allowed." << std::endl;
	std::cout << "Alphabetical caracters are allowed (a-z, A-z). Numbers and special characters will be dropped." << std::endl;
	std::cout << "This program needs to be set \"Code Page 852\"." << std::endl;
}

static std::string getText(const std::string &nameOfvariable, unsigned int maxLength) {
	std::cout << "Type " << nameOfvariable << ":" << std::endl;
	std::string text;
	std::getline(std::cin, text);
	if (text.empty()) {
		std::cerr << "Text can not be empty." << std::endl;
		exit(EXIT_KEY_EMPTY);
	} else if (text.length() > maxLength) {
		std::cerr << "Text can not be larger than " << maxLength << " characters." << std::endl;
		exit(EXIT_KEY_TOO_LONG);
	}
	return text;
}

int main(){
	printwelcome();
	std::string message = getText("public message", 255);
	std::string withoutHunChars = StringTools::eliminateSpecialChars(message);
	std::string uppercase = StringTools::toUppercase(withoutHunChars);
	std::cout << "Your message is prepared to encrypt:" << std::endl;
	std::cout << uppercase << std::endl;
	std::string key = getText("key", 5);
	std::string keyUppercase = StringTools::toUppercase(key);
	VigenereEncryptor *encryptor = VigenerFactory::createInstance("vtabla.dat", uppercase, keyUppercase);
	std::cout << "Your key is prepared to encrypt:" << std::endl;
	std::cout << encryptor->getKeySentence() << std::endl;
	std::cout << "Your encripted message:" << std::endl;
	std::cout << encryptor->encrypt() << std::endl;
	delete encryptor;
	std::cout << "Press any key to exit." << std::endl;
	std::getchar();
	return EXIT_WITHOUT_ERROR;
}

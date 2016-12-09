// VigenereCrypt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "StringTools.hpp"
#include <Windows.h>
#include "Vigenere.hpp"

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

static std::string getMessage() {
	std::cout << "Write your public message:" << std::endl;
	std::string message;
	std::getline(std::cin, message);
	if (message.empty()) {
		std::cerr << "Message can not be empty." << std::endl;
		exit(EXIT_MESSAGE_EMPTY);
	}
	else if (message.length() > 255) {
		std::cerr << "Message can not be larger than 255 characters." << std::endl;
		exit(EXIT_MESSAGE_TOO_LONG);
	}
	return message;
}

static std::string getKey() {
	std::cout << "Type a key to encrypt:" << std::endl;
	std::string key;
	std::getline(std::cin, key);
	if (key.empty()) {
		std::cerr << "Key can not be empty." << std::endl;
		exit(EXIT_KEY_EMPTY);
	}
	else if (key.length() > 5) {
		std::cerr << "Key can not be larger than 5 characters." << std::endl;
		exit(EXIT_KEY_TOO_LONG);
	}
	return key;
}

int main()
{
	printwelcome();
	std::string message = getMessage();
	std::string withoutHunChars = StringTools::eliminateSpecialChars(message);
	std::string uppercase = StringTools::toUppercase(withoutHunChars);
	std::cout << "Your message is prepared to encrypt:" << std::endl;
	std::cout << uppercase << std::endl;
	std::string key = getKey();
	std::string keyUppercase = StringTools::toUppercase(key);
	Vigenere vigenere = Vigenere("vtabla.dat", uppercase, keyUppercase);
	std::cout << "Your key is prepared to encrypt:" << std::endl;
	std::cout << vigenere.getKeySentence() << std::endl;
	std::cout << "Your encripted message:" << std::endl;
	std::cout << vigenere.getEncryptedMessage() << std::endl;

	std::cout << "Press any key to exit." << std::endl;
	std::getchar();
	return EXIT_WITHOUT_ERROR;
}

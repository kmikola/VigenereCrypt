#include "stdafx.h"
#include "Vigenere.hpp"
#include <fstream>

//char* table;
//std::string message;
//std::string key;
//std::string keysentence;
//std::string encryptedMessage;

namespace Docler {
	namespace Tools {

		void Vigenere::encrypt() {
			std::string encripted = std::string();
			for (unsigned int i = 0; i < message.length(); i++) {
				char messageChar = message.at(i);
				char keyChar = keysentence.at(i);
				char codeChar = getCodeChar(messageChar, keyChar);
				encripted.append(1, codeChar);
			}
			this->encryptedMessage = encripted;
		}

		char Vigenere::getCodeChar(const char &messagechar, const char &keychar) {
			for (std::string row : table){
				if (messagechar == row.at(0)) {
					int pos = table.at(0).find(keychar, 0);
					char codechar = row.at(pos);
					return codechar;
				}
			}
			return '#';
		}

		void Vigenere::readFile(const std::string &filename) {
			std::ifstream f;
			f.open(filename);
			std::string s;
			while ( !f.eof() ){
				std::getline(f, s);
				table.push_back(s);
			}
			f.close();
		}

		Vigenere::Vigenere(const std::string &filename, const std::string &message, const std::string &key) {
			this->message = std::string(message);
			this->key = std::string(key);
			this->keysentence = std::string();
			this->encryptedMessage = std::string();
			for (unsigned int i = 0; i < message.length(); i++) {
				char keychar = key.at(i % (key.length()));
				this->keysentence.append(1, keychar);
			}
			readFile(filename);
			encrypt();
		}

		std::string Vigenere::getKeySentence() {
			return keysentence;
		}

		std::string Vigenere::getEncryptedMessage() {
			return encryptedMessage;
		}

	}
}
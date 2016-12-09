#pragma once

#include <string>
#include <vector>

namespace Docler {
	namespace Tools {
		class Vigenere {
		private:
			std::vector<std::string> table;
			int height;
			int width;
			std::string message;
			std::string key;
			std::string keysentence;
			std::string encryptedMessage;
			char getCodeChar(const char &messagechar, const char &keychar);
			void readFile(const std::string &filename);
			void encrypt();
		public:
			Vigenere(const std::string &filename, const std::string &message, const std::string &key);
			std::string getKeySentence();
			std::string getEncryptedMessage();
		};
	}
}
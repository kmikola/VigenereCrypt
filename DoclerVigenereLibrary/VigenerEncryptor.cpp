
#include "VigenereEncryptor.hpp"

#include <fstream>

namespace Docler {
	namespace Tools {

		VigenereEncryptor::VigenereEncryptor(const std::string &tableFile, const std::string &publicMessage, const std::string &key) : Encryptor(publicMessage, key) {
			keysentence = generateKeySentence(publicMessage.length(), key); 
			readFile(tableFile);
		}

		void VigenereEncryptor::readFile(const std::string &filename) {
			std::ifstream f;
			f.open(filename);
			std::string s;
			while (!f.eof()) {
				std::getline(f, s);
				table.push_back(s);
			}
			f.close();
		}

		std::string VigenereEncryptor::generateKeySentence(unsigned int messageLength, const std::string &key) {
			std::string keySentence;
			keySentence.reserve(messageLength);
			for (unsigned int i = 0; i < messageLength; i++) {
				char keychar = key.at(i % (key.length()));
				keysentence.append(1, keychar);
			}
			return keysentence;
		}

		std::string VigenereEncryptor::getKeySentence() {
			return keysentence;
		}

		void VigenereEncryptor::setKey(const std::string &key) {
			this->setKey(key);
			keysentence = generateKeySentence(publicMessage.length(), key);
		}

		void VigenereEncryptor::setPublicMessage(const std::string &publicMessage) {
			this->setPublicMessage(publicMessage);
			keysentence = generateKeySentence(publicMessage.length(), key);
		}
	}
}
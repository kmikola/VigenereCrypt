
#include "VigenereEncryptorSequential.hpp"
#include "VigenereEncryptorGeneral.hpp"
#include "VigenerFactory.hpp"

#include <fstream>

namespace Docler {
	namespace Tools {
		VigenereEncryptor* VigenerFactory::createInstance(const std::string &tableFile, const std::string &publicMessage, 
			const std::string &key) {
			std::string firstLine = readFirstRow(tableFile);
			if (isSequence(firstLine)) {
				return new VigenereEncryptorSequential(tableFile, publicMessage, key);
			} else {
				return new VigenereEncryptorGeneral(tableFile, publicMessage, key);
			}
			
		}

		std::string VigenerFactory::readFirstRow(const std::string &filename) {
			std::string line;
			std::ifstream f;
			f.open(filename);
			std::getline(f, line);
			f.close();
			return line;
		}

		bool VigenerFactory::isSequence(const std::string &str) {
			if (str.length() < 2) {
				return false;
			} else {
				for (unsigned int i = 1; i < str.length() - 1; i++) {
					if ( (str[i] - str[i-1]) != 1 ) {
						return false;
					}
				}
				return true;
			}
			
		}

	}
}

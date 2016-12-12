
#include "VigenereEncryptorSequential.hpp"

namespace Docler {
	namespace Tools {
		class VigenereEncryptorSequential::impl : public VigenereEncryptor {
		private:
			char getCodeChar(const unsigned char &messagechar, const unsigned char &keychar) {
				unsigned char row = messagechar - (unsigned char)table[0][0];
				unsigned char column = keychar - (unsigned char)table[0][0];
				return table[row][column];
			}

		public:
			impl::impl(const std::string &tableFile, const std::string &publicMessage,
				const std::string &key) : VigenereEncryptor(tableFile, publicMessage, key) {

			}

			std::string encrypt() {
				std::string encripted = std::string();
				for (unsigned int i = 0; i < publicMessage.length(); i++) {
					char messageChar = publicMessage.at(i);
					char keyChar = keysentence.at(i);
					char codeChar = getCodeChar(messageChar, keyChar);
					encripted.append(1, codeChar);
				}
				return encripted;
			}
			
		};

		VigenereEncryptorSequential::VigenereEncryptorSequential(const std::string &tableFile, const std::string &publicMessage, 
			const std::string &key) : VigenereEncryptor(tableFile, publicMessage, key), pimpl(new impl(tableFile, publicMessage, key)) {}

		std::string VigenereEncryptorSequential::encrypt() {
			return pimpl->encrypt();
		}
	}
}
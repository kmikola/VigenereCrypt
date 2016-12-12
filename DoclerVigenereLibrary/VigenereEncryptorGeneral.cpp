
#include "VigenereEncryptorGeneral.hpp"

namespace Docler {
	namespace Tools {
 
		class VigenereEncryptorGeneral::impl : public VigenereEncryptor {
		public:
			impl::impl(const std::string &tableFile, const std::string &publicMessage,
				const std::string &key) : VigenereEncryptor(tableFile, publicMessage, key) {

			}

			char getCodeChar(const char &messagechar, const char &keychar) {
				for (std::string row : table) {
					if (messagechar == row.at(0)) {
						int pos = table.at(0).find(keychar, 0);
						char codechar = row.at(pos);
						return codechar;
					}
				}
				return '#';
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

		VigenereEncryptorGeneral::VigenereEncryptorGeneral(const std::string &tableFile, const std::string &publicMessage,
			const std::string &key) : VigenereEncryptor(tableFile, publicMessage, key) , pimpl(new impl(tableFile, publicMessage, key)) {}

		std::string VigenereEncryptorGeneral::encrypt() {
			return pimpl->encrypt();
		}
		
	}
}
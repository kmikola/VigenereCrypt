
#include "Encryptor.hpp"

namespace Docler {
	namespace Tools {
		Encryptor::Encryptor(const std::string &publicMessage, const std::string &key) {
			this->key = key;
			this->publicMessage = publicMessage;
		}

		void Encryptor::setKey(const std::string &key) {
			this->key = key;
		}

		void Encryptor::setPublicMessage(const std::string &publicMessage) {
			this->publicMessage = publicMessage;
		}

		std::string Encryptor::getKey(){
			return key;
		}
		std::string Encryptor::getPublicMessage() {
			return publicMessage;
		}
	}
}
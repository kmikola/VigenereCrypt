#pragma once

#include <string>

#include "EncryptorI.hpp"

namespace Docler {
	namespace Tools {
		class Encryptor : public EncryptorI {
		protected:
			std::string key;
			std::string publicMessage;
		public:
			Encryptor(const std::string &key, const std::string &publicMessage);
			std::string getKey();
			virtual void setKey(const std::string &key);
			std::string getPublicMessage();
			virtual void setPublicMessage(const std::string &publicMessage);
		};
	}
}
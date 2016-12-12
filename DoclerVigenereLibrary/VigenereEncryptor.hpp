#pragma once

#include <string>
#include <vector>

#include "Encryptor.hpp"

namespace Docler {
	namespace Tools {
		class VigenereEncryptor : public Encryptor {
		private:
			void readFile(const std::string &filename);
			std::string generateKeySentence(unsigned int messageLength, const std::string &key);
		protected:
			std::vector<std::string> table;
			std::string keysentence;
			VigenereEncryptor(const std::string &tableFile, const std::string &publicMessage, const std::string &key);
		public:
			std::string getKeySentence();
			void setKey(const std::string &key) override;
			void setPublicMessage(const std::string &publicMessage) override;
			virtual std::string encrypt() = 0;
		};
	}
}
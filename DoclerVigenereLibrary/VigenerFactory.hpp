#pragma once

#include "VigenereEncryptor.hpp"

#include <string>

namespace Docler {
	namespace Tools {
		class VigenerFactory {
		private:
			static std::string readFirstRow(const std::string &filename);
			static bool isSequence(const std::string &str);
		public:
			static VigenereEncryptor* createInstance(const std::string &tableFile, const std::string &publicMessage, 
				const std::string &key);
		};
	}
}
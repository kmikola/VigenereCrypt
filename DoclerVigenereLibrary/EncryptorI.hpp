#pragma once
#include <string>

namespace Docler {
	namespace Tools {
		class EncryptorI {
		public:
			virtual std::string encrypt() = 0;
			virtual void setKey(const std::string&) = 0;
			virtual void setPublicMessage(const std::string&) = 0;
		};
	}
}
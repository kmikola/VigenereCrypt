#pragma once
#include <string>

namespace Docler {
	namespace Tools {
		class StringTools {
		public:
			static std::string toUppercase(const std::string &str);
			static std::string eliminateSpecialChars(const std::string &str);
		};
	}
}
#pragma once
#include <string>

namespace Docler {
	namespace Tools {

		//static class implementation example
		class StringTools {
		public:
			//std style implementation
			static std::string toUppercase(const std::string &str);
			//without std string tools
			static std::string eliminateSpecialChars(const std::string &str);
		};
	}
}
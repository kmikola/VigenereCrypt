#include "stdafx.h"
#include "StringTools.hpp"
#include <cctype>
#include <algorithm>


namespace Docler {
	namespace Tools {
		std::string StringTools::toUppercase(const std::string &str) {
			std::string upperstr = std::string(str);
			std::transform(upperstr.begin(), upperstr.end(), upperstr.begin(), [](unsigned char c) { return std::toupper(c); });
			return upperstr;
		}

		//
		std::string StringTools::eliminateSpecialChars(const std::string &str) {
			std::string eliminated = std::string();
			for (const unsigned char &c : str) {
				if (c == 0x82) {
					eliminated.append(1, 'e');
				} else if (c == 0xA0) {
					eliminated.append(1, 'a');
				} else if (c == 0xFB) {
					eliminated.append(1, 'u');
				} else if (c == 0x8B) {
					eliminated.append(1, 'o');
				} else if (c == 0xA3) {
					eliminated.append(1, 'u');
				} else if (c == 0xA2) {
					eliminated.append(1, 'o');
				} else if (c == 0x81) {
					eliminated.append(1, 'u');
				} else if (c == 0x94) {
					eliminated.append(1, 'o');
				} else if (c == 0xA1) {
					eliminated.append(1, 'i');
				} else if (c == 0x90) {
					eliminated.append(1, 'E');
				} else if (c == 0xB5) {
					eliminated.append(1, 'A');
				} else if (c == 0xEB) {
					eliminated.append(1, 'U');
				} else if (c == 0x8A) {
					eliminated.append(1, 'O');
				} else if (c == 0xE9) {
					eliminated.append(1, 'U');
				} else if (c == 0xE0) {
					eliminated.append(1, 'O');
				} else if (c == 0x9A) {
					eliminated.append(1, 'U');
				} else if (c == 0x99) {
					eliminated.append(1, 'O');
				} else if (c == 0xD6) {
					eliminated.append(1, 'I');
				} else if ( (c>64 && c<91) || (c>96 && c<123) ){
					eliminated.append(1, c);
				}
			}
			return eliminated;
		}


	}
}



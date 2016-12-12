#pragma once

#include "VigenereEncryptor.hpp"

#include <memory>

namespace Docler {
	namespace Tools {
		class VigenereEncryptorSequential : public VigenereEncryptor {
		private:
			class impl; std::unique_ptr<impl> pimpl;
		public:
			VigenereEncryptorSequential(const std::string &tableFile, const std::string &publicMessage, const std::string &key);
			std::string encrypt();
		};
	}
}
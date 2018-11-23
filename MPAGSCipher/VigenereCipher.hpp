#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include <string>

#include "CipherMode.hpp"

class VigenereCipher {
	public:
		explicit VigenereCipher( const std::string& key );

		void setKey ( const std::string& key );

		std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const;
	private:
		std::string key_ {""};
};

#endif

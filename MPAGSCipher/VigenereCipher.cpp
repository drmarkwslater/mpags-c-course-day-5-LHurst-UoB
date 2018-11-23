
#include <string>

#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key ) {
	setKey(key);
}

void VigenereCipher::setKey ( const std::string& key ) {
	key_ = key;
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const {
	if (cipherMode == CipherMode::Encrypt)
		return inputText;
	else
		return inputText;
}

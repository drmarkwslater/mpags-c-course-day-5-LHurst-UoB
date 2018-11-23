
#include <string>
#include <memory>

#include "CipherFactory.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory( const CipherType type, const std::string& key ) {
	switch (type) {
		case CipherType::Caesar :
			return std::make_unique<CaesarCipher>(key);
		case CipherType::Playfair :
			return std::make_unique<PlayfairCipher>(key);
		case CipherType::Vigenere :
			return std::make_unique<VigenereCipher>(key);
		// Default to Caesar
		default:
			return std::make_unique<CaesarCipher>(key);
	}
}


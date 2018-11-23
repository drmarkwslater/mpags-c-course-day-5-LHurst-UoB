#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include <map>
#include <string>

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "Cipher.hpp"

class VigenereCipher : public Cipher {
	public:
		explicit VigenereCipher( const std::string& key );

		void setKey ( const std::string& key );

		std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const override;
	private:
		/// The cipher key
		std::string key_ {""};
		
		/// Lookup table
		std::map<char, CaesarCipher> charLookup_;
};

#endif

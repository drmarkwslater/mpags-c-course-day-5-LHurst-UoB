
#include <algorithm>
#include <iostream>
#include <string>

#include "Alphabet.hpp"
#include "TransformChar.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key ) {
	setKey(key);
}

void VigenereCipher::setKey ( const std::string& key ) {
	// Store the key
	key_ = key;

	// Make sure key is uppercase
	std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

	// Remove non-alphabet characters
	key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
		std::end(key_) );

	// Check if the key is empty and replace with default if so
	if ( key_.empty() ) {
		std::cerr << "Empty key specified for VigenereCipher.  Using \"FOOBAR\".  This is probably not what you inteneded - specify a key next time!" << std::endl;
		key_ = "FOOBAR";
	}
	
	// loop over the key
	for ( char ch : key ) {
		// Find the letter position in the alphabet
		int position {-1};
		for ( size_t i = 0; i < Alphabet::size; i++ ) {
			if (Alphabet::alphabet[i] == ch) {
				position = i;
				break; // Escape the for loop, we found it!
			}
		}
		
		// XXX if position is -1, didn't find it - should test for this and throw an exception

		// Create a CaesarCipher using this position as a key
		CaesarCipher cipher = CaesarCipher {(size_t)position};

		// Insert a std::pair of the letter and CaesarCipher into the lookup
		auto pair = std::make_pair(ch, cipher);
		charLookup_.insert(pair);
	}
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const {
	std::string outputText {""};
	unsigned int key_counter = 0;
	// For each letter in input:
	for ( char ch : inputText ) {
		// Find the corresponding letter in the key,
		// repeating/truncating as required
		const char key_char = key_[key_counter];
		
		// Point to the next character in the key, looping if required
		// ready for the next character
		key_counter = (key_counter + 1) % key_.size();

		// Find the Caesar Cipher from the lookup
		auto cipherIter = charLookup_.find(key_char);
		// XXX test for cipher == charLookup_.end() and throw exception
		const CaesarCipher cipher = cipherIter->second;
		
		// Run the (de)encryption
		// Add the result to the output
		outputText += cipher.applyCipher(std::string {ch}, cipherMode);
	}
	return outputText;
}

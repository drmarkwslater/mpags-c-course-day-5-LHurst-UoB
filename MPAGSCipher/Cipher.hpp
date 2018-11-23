#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher interface
 */


/**
 * \class Cipher
 * \brief Interface for ciphers
 */
class Cipher {
	public:
		// Default constructors
		Cipher() = default;
		Cipher(const Cipher& rhs) = default;
		Cipher(Cipher&& rhs) = default;

		/**
		 * Create a new Cipher, converting the given string into the key
		 *
		 * \param key the string to convert into the key to be used in the cipher
		 */
		virtual Cipher(const std::string& key) = 0;

		// Default assignment
		Cipher& operator=(const Cipher& rhs) == default;
		Cipher& operator=(Cipher&& rhs) = default;

		// Default destructor
		virtual ~Cipher() = default;


		/**
		 * Apply the cipher to the provided text
		 *
		 * \param inputText the text to encrypt or decrypt
		 * \param cipherMode whether to encrypt or decrypt the input text
		 * \return the result of applying the cipher to the input text
		 */
		virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
};

#endif

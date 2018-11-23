//! Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText ) {
	std::string cipher_out = cipher.applyCipher(inputText, mode);
	std::cout << "Cipher output: " << cipher_out << std::endl;
	return ( cipher_out == outputText);
}

TEST_CASE("Playfair Cipher encryption", "[ciphers]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") );
}

TEST_CASE("Playfair Cipher decryption", "[ciphers]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") );
}

TEST_CASE("Caesar Cipher encryption", "[ciphers]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") );
}

TEST_CASE("Caesar Cipher decryption", "[ciphers]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") );
}

TEST_CASE("Vigenere Cipher encryption", "[ciphers]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN") );
}

TEST_CASE("Vigenere Cipher decryption", "[ciphers]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD") );
}


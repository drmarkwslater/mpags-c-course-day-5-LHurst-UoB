//! Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <memory>
#include <iostream>
#include <vector>

#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include "CipherMode.hpp"

bool testCipher( const std::unique_ptr<Cipher>& cipher_ptr, const CipherMode mode, const std::string& inputText, const std::string& outputText ) {
	std::cout << "Input text: " << inputText;
	std::string cipher_out = cipher_ptr->applyCipher(inputText, mode);
	std::cout << " - cipher output: " << cipher_out << std::endl;
	return ( cipher_out == outputText);
}

struct testCase {
	std::string inputText;
	std::string outputText;
};

TEST_CASE("Ciphers test", "[ciphers]") {
	std::vector<std::unique_ptr<Cipher>> ciphers;
	// turn into a vector of vectors of test cases if multiple tests per cipher desired
	std::vector<testCase> encryption_tests;
	std::vector<testCase> decryption_tests;
	
	ciphers.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
	encryption_tests.push_back( testCase {"BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"} );
	decryption_tests.push_back( testCase {"FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"} );
	
	ciphers.push_back( cipherFactory( CipherType::Caesar, "10") );
	encryption_tests.push_back( testCase {"HELLOWORLD", "ROVVYGYBVN"} );
	decryption_tests.push_back( testCase {"ROVVYGYBVN", "HELLOWORLD"} );
	
	ciphers.push_back( cipherFactory( CipherType::Vigenere, "key") );
	encryption_tests.push_back( testCase {"HELLOWORLD", "RIJVSUYVJN"} );
	decryption_tests.push_back( testCase {"RIJVSUYVJN", "HELLOWORLD"} );
	
	for ( size_t i = 0; i < ciphers.size(); i++ ) {
		REQUIRE( testCipher( ciphers[i], CipherMode::Encrypt, encryption_tests[i].inputText, encryption_tests[i].outputText ) );
		REQUIRE( testCipher( ciphers[i], CipherMode::Decrypt, decryption_tests[i].inputText, decryption_tests[i].outputText ) );
	}
}



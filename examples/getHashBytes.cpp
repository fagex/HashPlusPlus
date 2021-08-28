/*

  getHashFromBytes.cpp
    Example to show how to get the byte array of hashed data.
  
*/

#include "hashpp.h"

using namespace hashpp;

int main() {
	// assign the SHA2-256 hash bytes of "sample text" to byteArray
	uint8_t* byteArray = get::getBytes(ALGORITHMS::SHA2_256, "sample text");

	// assign the hash object to _hex from getHash<uint8_t*>() for byte arrays
	hash _hex = get::getHash<uint8_t*>(ALGORITHMS::SHA2_256, byteArray);
	// or use .getString()

  // print the hex representation of the string
	std::cout << _hex;
}

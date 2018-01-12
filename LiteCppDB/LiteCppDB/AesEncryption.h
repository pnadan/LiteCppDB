#pragma once


//#include "dll.h"
//#include "aes.h"


namespace LiteCppDB
{
	// Encryption AES wrapper to encrypt data pages
	class AesEncryption
	{
	private:
		/*Aes _aes;*/

	public:

		//AesEncryption(string password, byte[] salt);

		//// Encrypt byte array returning new encrypted byte array with same length of original array (PAGE_SIZE)
		//std::vector<uint8_t> Encrypt(std::vector<uint8_t> bytes);

		//// Decrypt and byte array returning a new byte array
		//std::vector<uint8_t> Decrypt(std::vector<uint8_t> encryptedValue);

		//// Hash a password using SHA1 just to verify password
		//static std::vector<uint8_t> HashSHA1(std::string password);

		//// Generate a salt key that will be stored inside first page database
		//// <returns></returns>
		//static std::vector<uint8_t> Salt(int32_t maxLength = 16);

		//void Dispose();
	};
}
#include "Ivy.h"
#include "FileHandler.h"

void UsageInfo()
{
	std::cout << "Usage:\n"
			  << "ivy [-e]/[-d] [input filename] [output filename] [key]\n"
			  << "\n"
			  << "Switches:\n"
			  << "-e - encrypt\n"
			  << "-d - decrypt\n"
			  << "\n"
			  << "You can also use backslash (/e, /d).\n"			 
			  << "\n"
			  << "Examples:\n"
			  << "ivy -e input.txt output.txt D8W9EF0JBF89W1IQ\n"
			  << "ivy /d input.txt output.txt D8W9EF0JBF89W1IQ\n"
			  << "\n";
}

int main(int argc, char *argv[])
{
	std::wstring unencrypted;
	std::vector<int> encrypted;
	std::string in, out, op, key;

	std::cout << "Ivy\n"
			  << "Version 1.1\n"
			  << "A really simple text encryption algorithm.\n"
			  << "(C) 2022 Nazar Fedorenko.\n"
		      << "\n";

	if (argc < 5)
	{
		UsageInfo();
	}
	else
	{
		op = std::string(argv[1]);
		in = std::string(argv[2]);
		out = std::string(argv[3]);
		key = argv[4];

		if (op == "-e" || op == "/e")
		{
			std::cout << "Reading data from " << in << "...\n";
			unencrypted = ReadDataFromFile(in);
			std::cout << "Done.\n\n";

			std::cout << "Encrypting data...\n";
			encrypted = IvyEncrypt(&unencrypted, key);
			std::cout << "Done.\n\n";

			std::cout << "Writing encrypted data to " << out << "...\n";
			WriteEncryptedDataToFile(out, &encrypted);
			std::cout << "Done.\n\n";

			std::cout << "Encryption complete!\n\n";
		}
		else if (op == "-d" || op == "/d")
		{
			std::cout << "Reading encrypted data from " << in << "...\n";
			encrypted = ReadEncryptedDataFromFile(in);
			std::cout << "Done.\n\n";

			std::cout << "Decrypting data...\n";
			unencrypted = IvyDecrypt(&encrypted, key);
			std::cout << "Done.\n\n";

			std::cout << "Writing decrypted data to " << out << "...\n";
			WriteDecryptedDataToFile(out, &unencrypted);
			std::cout << "Done.\n\n";

			std::cout << "Decryption complete!\n\n";
		}
		else
		{
			std::cout << "Unknown parameter: " << op << "\n\n";
			UsageInfo();
		}
	}

	return 0;
}
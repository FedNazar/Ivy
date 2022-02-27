#include "Ivy.h"
#include "FileHandler.h"

void UsageInfo()
{
	cout << "Usage:" << endl;
	cout << "ivy [operation] [input filename] [output filename] [key]" << endl;
	cout << endl;
	cout << "Operation parameters:" << endl;
	cout << "-e - encrypt" << endl;
	cout << "-d - decrypt" << endl;
	cout << endl;
	cout << "Example:" << endl;
	cout << "ivy -e input.txt output.txt D8W9EF0JBF89W1IQ" << endl;
	cout << endl;
}

int main(int argc, char *argv[])
{
	wstring data;
	vector<int> encrypted;
	string in, out, op, key;

	cout << "Ivy" << endl;
	cout << "Version 1.0" << endl;
	cout << "A really simple text encryption algorithm." << endl;
	cout << "(C) 2022 Nazar Fedorenko." << endl;
	cout << endl;
	if (argc < 5)
	{
		UsageInfo();
	}
	else
	{
		op = string(argv[1]);
		in = string(argv[2]);
		out = string(argv[3]);
		key = argv[4];
		if (op == "-e")
		{
			cout << "Reading data from " << in << "..." << endl;
			data = ReadDataFromFile(in);
			cout << "Done." << endl;
			cout << endl;

			cout << "Encrypting data..." << endl;
			encrypted = IvyEncrypt(data, key);
			cout << "Done." << endl;
			cout << endl;

			cout << "Writing encrypted data to " << out << "..." << endl;
			WriteEncryptedDataToFile(out, encrypted);
			cout << "Done." << endl;
			cout << endl;

			cout << "Encryption complete!" << endl;
			cout << endl;
		}
		else if (op == "-d")
		{
			cout << "Reading encrypted data from " << in << "..." << endl;
			encrypted = ReadEncryptedDataFromFile(in);
			cout << "Done." << endl;
			cout << endl;

			cout << "Decrypting data..." << endl;
			data = IvyDecrypt(encrypted, key);
			cout << "Done." << endl;
			cout << endl;

			cout << "Writing decrypted data to " << out << "..." << endl;
			WriteDecryptedDataToFile(out, data);
			cout << "Done." << endl;
			cout << endl;

			cout << "Decryption complete!" << endl;
			cout << endl;
		}
		else
		{
			UsageInfo();
		}
	}

	return 0;
}
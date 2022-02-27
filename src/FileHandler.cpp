#include "FileHandler.h"

vector<int> ReadEncryptedDataFromFile(string fileName)
{
	vector<int> data;

	wifstream file;
	
	file.open(fileName);
	file.imbue(locale(locale(), new codecvt_utf16<wchar_t, 0x10ffffUL,
		codecvt_mode::consume_header>));

	int tmp;
	while (!file.fail())
	{
		file >> tmp;
		data.push_back(tmp);
	}
	data.pop_back();

	file.close();

	return data;
}

wstring ReadDataFromFile(string fileName)
{
	wstring data;
	
	wifstream file;
	file.open(fileName);

	file.imbue(locale(locale(), new codecvt_utf16<wchar_t, 0x10ffffUL, 
		codecvt_mode::consume_header>));

	wstringstream wss;
	wss << file.rdbuf();

	file.close();

	return wss.str();
}

void WriteEncryptedDataToFile(string fileName, vector<int> data)
{
	wofstream file;
	file.open(fileName);
	file.imbue(locale(locale(), new codecvt_utf16<wchar_t, 0x10ffffUL,
		codecvt_mode::generate_header>));

	int length = data.size();
	for (int i = 0; i < length; i++)
	{
		file << data[i] << ' ';
	}

	file.close();
}

void WriteDecryptedDataToFile(string fileName, wstring data)
{
	wofstream file;
	file.open(fileName);
	file.imbue(locale(locale(), new codecvt_utf16<wchar_t, 0x10ffffUL,
		codecvt_mode::generate_header>));

	file << data;

	file.close();
}

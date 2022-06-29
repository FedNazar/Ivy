#include "FileHandler.h"

void OpenFile(std::string fileName, std::wifstream *wifstream)
{
	wifstream->open(fileName);
	wifstream->imbue(std::locale(std::locale(), new std::codecvt_utf16<wchar_t, 0x10ffffUL,
		std::codecvt_mode::consume_header>));
}

void OpenFile(std::string fileName, std::wofstream *wofstream)
{
	wofstream->open(fileName);
	wofstream->imbue(std::locale(std::locale(), new std::codecvt_utf16<wchar_t, 0x10ffffUL,
		std::codecvt_mode::generate_header>));
}

std::vector<int> ReadEncryptedDataFromFile(std::string fileName)
{
	std::vector<int> data;

	std::wifstream file;
	OpenFile(fileName, &file);

	int encryptedWChar;
	while (!file.fail())
	{
		file >> encryptedWChar;
		data.emplace_back(encryptedWChar);
	}
	data.pop_back();

	file.close();

	return data;
}

std::wstring ReadDataFromFile(std::string fileName)
{
	std::wstring data;
	
	std::wifstream file;
	OpenFile(fileName, &file);

	std::wstringstream wss;
	wss << file.rdbuf();

	file.close();

	return wss.str();
}

void WriteEncryptedDataToFile(std::string fileName, std::vector<int> *data)
{
	std::wofstream file;
	OpenFile(fileName, &file);

	for (auto& i : *data)
	{
		file << i << ' ';
	}

	file.close();
}

void WriteDecryptedDataToFile(std::string fileName, std::wstring *data)
{
	std::wofstream file;
	OpenFile(fileName, &file);

	file << *data;

	file.close();
}

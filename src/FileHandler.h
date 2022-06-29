#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

void OpenFile(std::string fileName, std::wifstream *wifstream);
void OpenFile(std::string fileName, std::wofstream *wofstream);

std::vector<int> ReadEncryptedDataFromFile(std::string fileName);
std::wstring ReadDataFromFile(std::string fileName);

void WriteEncryptedDataToFile(std::string fileName, std::vector<int> *data);
void WriteDecryptedDataToFile(std::string fileName, std::wstring *data);
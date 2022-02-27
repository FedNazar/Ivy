#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>
using namespace std;

vector<int> ReadEncryptedDataFromFile(string fileName);
wstring ReadDataFromFile(string fileName);
void WriteEncryptedDataToFile(string fileName, vector<int> data);
void WriteDecryptedDataToFile(string fileName, wstring data);
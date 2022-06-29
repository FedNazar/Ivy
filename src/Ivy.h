#pragma once
#include <iostream>
#include <string>
#include <vector>

const int IVY_NUMBER = 47;

std::vector<int> IvyEncrypt(std::wstring *unencrypted, std::string key);
std::wstring IvyDecrypt(std::vector<int> *encrypted, std::string key);

int CalculateFirstOffset(std::string *key);
std::vector<int> CalculateSecondOffsets(std::string *key);
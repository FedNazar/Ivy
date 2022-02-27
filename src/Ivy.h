#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ASCII_START_POS = 47;

vector<int> IvyEncrypt(wstring data, string key);
wstring IvyDecrypt(vector<int> encrypted, string key);
#include "Ivy.h"

vector<int> IvyEncrypt(wstring data, string key)
{
	vector<int> encrypted;
	int charValue;
	short int aKeyCharNum = 0;

	int dataLength = data.length();
	int keyLength = key.length();

	for (int i = 0; i < dataLength; i++)
	{
		charValue = int(data[i]);
		for (int j = 1; j <= keyLength; j++)
		{
			if (j % 2 == 0)
			{
				charValue += (int(key[j - 1]) - ASCII_START_POS);
			}
			else
			{
				charValue -= (int(key[j - 1]) - ASCII_START_POS);
			}
		}
		
		if (key[aKeyCharNum] % 2 == 0)
		{
			charValue += ((key[aKeyCharNum] - ASCII_START_POS) * 16);
		}
		else
		{
			charValue -= ((key[aKeyCharNum] - ASCII_START_POS) * 8);
		}

		if (aKeyCharNum == keyLength - 1)
		{
			aKeyCharNum = 0;
		}
		else
		{
			aKeyCharNum++;
		}

		encrypted.push_back(charValue);
	}
	return encrypted;
}

wstring IvyDecrypt(vector<int> encrypted, string key)
{
	wstring decrypted = L"";
	int charValue;
	short int aKeyCharNum = 0;

	int encryptedSize = encrypted.size();
	int keyLength = key.length();

	for (int i = 0; i < encryptedSize; i++)
	{
		charValue = encrypted[i];
		for (int j = 1; j <= keyLength; j++)
		{
			if (j % 2 == 0)
			{
				charValue -= (int(key[j - 1]) - ASCII_START_POS);
			}
			else
			{
				charValue += (int(key[j - 1]) - ASCII_START_POS);
			}
		}

		if (key[aKeyCharNum] % 2 == 0)
		{
			charValue -= ((key[aKeyCharNum] - ASCII_START_POS) * 16);
		}
		else
		{
			charValue += ((key[aKeyCharNum] - ASCII_START_POS) * 8);
		}

		if (aKeyCharNum == keyLength - 1)
		{
			aKeyCharNum = 0;
		}
		else
		{
			aKeyCharNum++;
		}

		decrypted += static_cast<wchar_t>(charValue);
	}

	return decrypted;
}


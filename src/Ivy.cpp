#include "Ivy.h"

std::vector<int> IvyEncrypt(std::wstring *unencrypted, std::string key)
{
	std::vector<int> encrypted;
	int charValue;
	size_t aKeyCharNum = 0;

	int firstOffset = CalculateFirstOffset(&key);
	std::vector<int> secondOffsets = CalculateSecondOffsets(&key);

	for (auto& unencryptedWChar : *unencrypted)
	{
		charValue = int(unencryptedWChar);
		
		charValue -= firstOffset;

		charValue += secondOffsets[aKeyCharNum];

		if (aKeyCharNum == key.length() - 1)
		{
			aKeyCharNum = 0;
		}
		else
		{
			aKeyCharNum++;
		}

		encrypted.emplace_back(charValue);
	}
	return encrypted;
}

std::wstring IvyDecrypt(std::vector<int> *encrypted, std::string key)
{
	std::wstring decrypted = L"";
	int charValue, currentWChar = 0;
	size_t aKeyCharNum = 0;

	int firstOffset = CalculateFirstOffset(&key);
	std::vector<int> secondOffsets = CalculateSecondOffsets(&key);

	for (auto& encryptedWChar : *encrypted)
	{
		charValue = encryptedWChar;
		
		charValue += firstOffset;

		charValue -= secondOffsets[aKeyCharNum];

		if (aKeyCharNum == key.length() - 1)
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

int CalculateFirstOffset(std::string *key)
{
	int offset = 0, currentKeyChar = 1;

	for (auto& keyChar : *key)
	{
		if (currentKeyChar % 2 == 0)
		{
			offset -= (int(keyChar) - IVY_NUMBER);
		}
		else
		{
			offset += (int(keyChar) - IVY_NUMBER);
		}
		currentKeyChar++;
	}

	return offset;
}

std::vector<int> CalculateSecondOffsets(std::string *key)
{
	std::vector<int> offsets;

	for (auto& keyChar : *key)
	{
		if (keyChar % 2 == 0)
		{
			offsets.emplace_back((keyChar - IVY_NUMBER) * 16);
		}
		else
		{
			offsets.emplace_back((keyChar - IVY_NUMBER) * -8);
		}
	}

	return offsets;
}


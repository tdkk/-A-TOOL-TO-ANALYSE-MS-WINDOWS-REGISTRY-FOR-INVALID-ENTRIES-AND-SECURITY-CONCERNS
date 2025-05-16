#include "registryScanner.h"
#include <iostream>

std::vector<RegistryEntry> ScanRegistryHive(HKEY rootKey, const std::string& subKey) {
	std::vector<RegistryEntry> entries;
	HKEY hKey;
	// Open the specified registry key
	if (RegOpenKeyExA(rootKey, subKey.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
		std::cerr << "Failed to open registry key: " << subKey << std::endl;
		return entries;
	}

	char valueName[256];	
	BYTE data[1024];	
	DWORD valueNameSize, dataSize, type;	
	DWORD index = 0;	

	while (true) {
		valueNameSize = sizeof(valueName);
		dataSize = sizeof(data);
		LONG ret = RegEnumValueA(hKey, index++, valueName, &valueNameSize, NULL, &type, data, &dataSize);
		if (ret == ERROR_NO_MORE_ITEMS) {
			break; // No more items
		}

		if (ret == ERROR_SUCCESS) {
			RegistryEntry entry;
			entry.keyName = subKey;
			entry.valueName = std::string(valueName);
			entry.valueData = std::string((char*)data, dataSize);
			entries.push_back(entry);
		}
	}
	// Close the registry key	
	RegCloseKey(hKey);
	return entries;	
}
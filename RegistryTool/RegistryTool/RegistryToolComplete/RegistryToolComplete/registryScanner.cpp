#include "registryScanner.h"
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cctype>


std::vector<RegistryEntry> ScanRegistryHive(HKEY rootKey, const std::string& subKey) {
    std::vector<RegistryEntry> entries;
    HKEY hKey;

    if (RegOpenKeyExA(rootKey, subKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
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
        if (ret == ERROR_NO_MORE_ITEMS) break;

        if (ret == ERROR_SUCCESS) {
            RegistryEntry entry;
            entry.keyName = subKey;
            entry.valueName = std::string(valueName);
            std::string valueStr;
            for(DWORD i = 0; i < dataSize; ++i) {
                if (isprint(data[i])) {
                    valueStr += static_cast<char>(data[i]);
                }
                else {
                    valueStr += '.';
                }
            }
            entry.valueData = valueStr;
            entries.push_back(entry);
        }
    }

    RegCloseKey(hKey);
    return entries;
}
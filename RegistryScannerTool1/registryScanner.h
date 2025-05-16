#pragma once
#include <windows.h>
#include <string>
#include <vector>

struct RegistryEntry {
	std::string keyName;
	std::string valueName;
	std::string valueData;
};

std::vector<RegistryEntry> ScanRegistryHive(HKEY hKey, const std::string& subKey);

struct AnalysisResult {
	RegistryEntry entry;
	std::string issue;	
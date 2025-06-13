#pragma once
#include <string>
#include <windows.h>
#include <vector>
#include "registryScanner.h"

void writeReport(const std::vector<RegistryEntry>& entries, const std::string& filename);
void writeFlaggedEntries(const std::vector<RegistryEntry>& entries, const std::string& filename);
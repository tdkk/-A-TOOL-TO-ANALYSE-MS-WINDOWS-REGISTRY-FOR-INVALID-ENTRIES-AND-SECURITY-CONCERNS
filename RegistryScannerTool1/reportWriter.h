#pragma once	
#include <windows.h>
#include <string>
#include "registryScanner.h"

void writeReport(const std::vector<RegistryEntry>& entries, const std::string& filename);

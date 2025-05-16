#include "reportWriter.h"
#include <fstream>

void writeReport(const std::vector<RegistryEntry>& entries, const std::string& filename) {
	std::ofstream reportFile(filename);
	if (!reportFile.is_open()) {
		std::cerr << "Failed to open report file: " << filename << std::endl;
		return;
	}
	for (const auto& entry : entries) {
		reportFile << "Key: " << entry.keyName << "\n";
		reportFile << "Value Name: " << entry.valueName << "\n";
		reportFile << "Value Data: " << entry.valueData << "\n";
		reportFile << "----------------------------------------\n";
	}
	reportFile << "\n[Total entries found}: " << entries.size() << "\n";
	reportFile.close();
}
#include "reportWriter.h"
#include <fstream>
#include <iostream>

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

    reportFile << "\n[Total entries found]: " << entries.size() << "\n";
    reportFile.close();
}

void writeFlaggedEntries(const std::vector<RegistryEntry>& entries, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open report file: " << filename << std::endl;
        return;
    }

    for (const auto& entry : entries) {
        outFile << "Flagged Entry:\n";
        outFile << "Key: " << entry.keyName << "\n";
        outFile << "Value Name: " << entry.valueName << "\n";
        outFile << "Value Data: " << entry.valueData << "\n";
        outFile << "----------------------------------------\n";
    }

    outFile << "\n[Total flagged entries]: " << entries.size() << "\n";
    outFile.close();
}
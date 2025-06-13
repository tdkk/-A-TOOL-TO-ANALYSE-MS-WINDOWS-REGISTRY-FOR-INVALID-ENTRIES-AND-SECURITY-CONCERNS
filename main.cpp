#include <iostream>
#include "registryScanner.h"
#include "reportWriter.h"
#include <windows.h>

int main() {
    std::string subKey = "SOFTWARE";
    std::vector<RegistryEntry> results = ScanRegistryHive(HKEY_LOCAL_MACHINE, subKey);

    std::cout << "[*] Scan complete. Total entries found: " << results.size() << std::endl;
    writeReport(results, "full_report.txt");

    std::vector<RegistryEntry> flagged;
    for (const auto& entry : results) {
        if (entry.valueData.find(".exe") != std::string::npos || entry.valueData.find("AppData") != std::string::npos) {
            flagged.push_back(entry);
        }
    }

    std::cout << "[*] Analysis complete. Flagged suspicious entries: " << flagged.size() << std::endl;
    writeFlaggedEntries(flagged, "flagged_report.txt");

    std::cout << "[*] Reports saved to full_report.txt and flagged_report.txt" << std::endl;
    return 0;
}
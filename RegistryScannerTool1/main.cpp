#include <iostream>
#include "registryScanner.h"
#include "reportWriter.h"

int main() {
	std::string subKey = "SOFTWARE"; //This can be changed to scan other registry paths if needed

	// Scan the selected registry hive and subkey
	std::vector<RegistryEntry> results = scanRegistryHive(HKEY_LOCAL_MACHINE, subKey);

	// Write the results to a text file
	std::cout << "Registry scan complete, Report has been saved to report.txt" << std::endl;

	retunt 0;	

}
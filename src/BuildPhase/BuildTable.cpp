#include "BuildTable.h"


void BuildTable::Start() {
    std::cout << "Build table launched..." << std::endl;

    // Loop amount of cycles
    for (int cycle = 0; cycle < amountCycles; ++cycle) {

        // Loop to fill entries
        for (int index = 0; index < bufferSize; ++index) {

            // Operation that generates one row
            entries[index] = GenerateEntry();
        }

        // Write array to the disk
        diskWriter.Add(entries);
    }

    std::cout << "====================== DONE ======================" << std::endl;
}

std::string BuildTable::GenerateEntry() {
    // TODO
    std::string firstHash = hasher.sha256Hash("lol");
    std::string secondHash = hasher.sha256Hash("mdr");

    return firstHash + "," + secondHash;
}

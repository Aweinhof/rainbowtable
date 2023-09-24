#include "DiskWriter.h"

DiskWriter::DiskWriter() {
    // Throw error if the file exist
    if (std::filesystem::exists(filePath)) {
        throw std::runtime_error("File already exists. Cannot overwrite. This is a safety measure.");
    }

    // Open the file in binary mode for writing (overwrite if it exists)
    fileStream.open(filePath, std::ios::out | std::ios::binary);

    // Check if the file was opened successfully
    if (!fileStream.is_open()) {
        throw std::runtime_error("Failed to open or create the file.");
    }
}

DiskWriter::~DiskWriter() {
    fileStream.close();
}

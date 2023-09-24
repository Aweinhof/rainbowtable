#ifndef DISKWRITER_H
#define DISKWRITER_H

#include <fstream>
#include <string>
#include <array>
#include <filesystem>
#include <iostream>

class DiskWriter {
public:
    // Constructor: Takes a file path and creates the file if it doesn't exist
    DiskWriter();
    ~DiskWriter();

    // Add lines from a fixed-size array to the file
    // Gods knows why I need to implement it here for compiler -_-
    template <std::size_t N>
    void Add(const std::array<std::string, N> &lines) {
        for (const std::string &line : lines) {
            fileStream << line << '\n';
        }
        fileStream.flush();
    }

private:
    const std::string filePath = "res/table.data";     // This is the rainbow table file
    std::ofstream fileStream;
};

#endif // DISKWRITER_H

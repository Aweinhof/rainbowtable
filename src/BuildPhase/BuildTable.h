#ifndef RAINBOWTABLE_BUILDTABLE_H
#define RAINBOWTABLE_BUILDTABLE_H

#include <iostream>
#include <string>
#include <array>
#include "../Common/Hasher.h"
#include "DiskWriter.h"


class BuildTable {
public:
    void Start();

private:
    Hasher hasher;
    DiskWriter diskWriter;

    static constexpr int amountCycles = 2;      // 1 cycle fills entries and writes it
    static constexpr int bufferSize = 3;        // Amount of entries the array has before it stores it in the file
    std::array<std::string, bufferSize> entries;

    std::string GenerateEntry();
};


#endif //RAINBOWTABLE_BUILDTABLE_H

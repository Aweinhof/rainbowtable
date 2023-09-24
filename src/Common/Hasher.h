#ifndef HASHER_H
#define HASHER_H

#include <string>

class Hasher {
public:
    // Constructor
    Hasher();

    // Destructor
    ~Hasher();

    // Hash data using MD5 (deprecated)
    //std::string md5Hash(const std::string &data);

    // Hash data using SHA-256
    std::string sha256Hash(const std::string &data);
};

#endif // HASHER_H


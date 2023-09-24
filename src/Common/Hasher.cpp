#include "Hasher.h"
#include <iostream>
#include <cstring>
#include <openssl/sha.h>
//#include <openssl/md5.h>

Hasher::Hasher() {
    // Constructor
}

Hasher::~Hasher() {
    // Destructor
}

// Throws an ugly deprecated warning
/*std::string Hasher::md5Hash(const std::string &data) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char *>(data.c_str()), data.length(), digest);

    char md5String[MD5_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&md5String[i * 2], "%02x", (unsigned int)digest[i]);
    }

    return std::string(md5String);
}*/

std::string Hasher::sha256Hash(const std::string &data) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(data.c_str()), data.length(), digest);

    char sha256String[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(&sha256String[i * 2], "%02x", (unsigned int)digest[i]);
    }

    return std::string(sha256String);
}

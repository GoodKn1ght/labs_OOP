#include "Utils.h"

using namespace std;

unsigned int customHash(const string& str) {
    unsigned int hash1 = 5381;
    unsigned int hash2 = 0;
    for (char c : str) {
        hash1 = ((hash1 << 5) + hash1) + c;
        hash2 = c + (hash2 << 6) + (hash2 << 16) - hash2;
    }
    return hash1 + hash2;
}

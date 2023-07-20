#include <iostream>

uint64_t sum(uint64_t a, uint64_t b) {
    uint64_t s = 0;
    for (int i = a; i <= b; i++) {
        s += i;
    }
    return s;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    std::cout << sum(1,n) << std::endl;
}
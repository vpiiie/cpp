#include <iostream>
#include <unordered_map>
#include <cstdint>

class CachingFibonachiNumberCalculator {
public:
uint64_t operator()(size_t n) {    
    auto it = cache.find(n);
    if (it != cache.end()) {
        return it->second;
    }
    uint64_t result;
    if (n <= 1) {
        result = n;
    } else {
        result = (*this)(n - 1) + (*this)(n - 2);
    }
    cache[n] = result;
    return result;
}
private:
    std::unordered_map<size_t, uint64_t> cache;
};

int main() {
    CachingFibonachiNumberCalculator fib;

    std::cout << fib(0) << std::endl;
    std::cout << fib(1) << std::endl;
    std::cout << fib(2) << std::endl;
    std::cout << fib(3) << std::endl; 
    std::cout << fib(4) << std::endl; 

    std::cout << fib(4) << std::endl;
    std::cout << fib(5) << std::endl;
    std::cout << fib(6) << std::endl;
}

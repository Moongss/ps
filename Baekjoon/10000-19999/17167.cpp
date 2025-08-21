#include <iostream>
#include <string>
#include <vector>

using ll = long long;

int main() {
    ll A, B;
    std::vector<std::string> v;
    std::cin >> A >> B;

    while (A != B) {
        while (A % 2 == 0) {
            A /= 2;
            v.push_back("B+=B");
        }
        while (B % 2 == 0) {
            B /= 2;
            v.push_back("A+=A");
        }
        if (A < B) {
            B += A;
            v.push_back("B+=A");
        } else if (A > B) {
            A += B;
            v.push_back("A+=B");
        }
    }    

    std::cout << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}
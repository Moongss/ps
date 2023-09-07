#include <iostream>
#include <string>
#include <list>

int N;
void solve() {

    std::string L;
    std::list<char> result;
    std::list<char>::iterator cursor = result.begin();

    //STL erase, insert 
    //vector, list, deque -> not delete iterator
    //map, set -> delete iterator
    std::cin >> L;
    for (size_t i = 0; i < L.length(); i++) {
        if (L[i] == '-') {
            if (cursor != result.begin()) {
                cursor--;
                cursor = result.erase(cursor);
            }
        }
        else if (L[i] == '<') {
            if (cursor != result.begin())
                cursor--;    
        }
        else if (L[i] == '>') {
            if (cursor != result.end())
                cursor++;
        } else {
            cursor = result.insert(cursor, L[i]);
            cursor++;
        }
    }

    for (cursor = result.begin(); cursor != result.end(); cursor++) {
        std::cout << *cursor;
    }
    std::cout << std::endl;
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        solve();
    }
    return 0;
}
#include <iostream>

class Deque {
    private:
        int save[10000];
        int current;

    public:
        Deque(): current(-1) {};
        virtual ~Deque() {};
        
        void push_front(int value) {
            for (int i = current; i >= 0; i--) {
                save[i + 1] = save[i];
            }
            current++;
            save[0] = value;
        }

        void push_back(int value) {
            current++;
            save[current] = value;
        }

        int pop_front() {
            if (empty())
                return current;

            int popValue = front();
            for (int i = 1; i <= current; i++) {
                save[i - 1] = save[i];
            }
            current--;
            return popValue;
        }

        int pop_back() {
            if (empty())
                return current;

            int popValue = back();
            current--;
            return popValue;
        }

        int size() {
            return current + 1;
        }

        int empty() {
            return (current < 0);
        }

        int front() {
            if (empty())
                return current;
            return (save[0]);
        }

        int back() {
            if (empty())
                return current;
            return (save[current]);
        }       
};

int main() {
    int N, value;
    Deque deque;
    std::string command;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> command;
        if (command.compare("push_front") == 0) {
            std::cin >> value;
            deque.push_front(value);
        }

        if (command.compare("push_back") == 0) {
            std::cin >> value;
            deque.push_back(value);
        }

        if (command.compare("pop_front") == 0) {
            std::cout << deque.pop_front() << std::endl;
        }

        if (command.compare("pop_back") == 0) {
            std::cout << deque.pop_back() << std::endl;
        }

        if (command.compare("size") == 0) {
            std::cout << deque.size() << std::endl;
        }
        
        if (command.compare("empty") == 0) {
            std::cout << deque.empty() << std::endl;
        }

        if (command.compare("front") == 0) {
            std::cout << deque.front() << std::endl;
        }

        if (command.compare("back") == 0) {
            std::cout << deque.back() << std::endl;
        }
    }
    return 0;
}
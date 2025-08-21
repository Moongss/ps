#include <iostream>

class Stack {
    private:
        int save[10000];
        int current;

    public:
        Stack(): current(-1) {};
        virtual ~Stack() {};
        
        void push(int value) {
            current++;
            save[current] = value;
        }

        int pop() {
            if (empty())
                return current;
            return save[current--];
        }

        int size() {
            return current + 1;
        }

        int empty() {
            return (current < 0);
        }

        int top() {
            if (empty())
                return current;
            return (save[current]);
        }
};

int main() {
    int N, value;
    Stack stack;
    std::string command;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> command;
        if (command.compare("push") == 0) {
            std::cin >> value;
            stack.push(value);
        }

        if (command.compare("pop") == 0) {
            std::cout << stack.pop() << std::endl;
        }

        if (command.compare("size") == 0) {
            std::cout << stack.size() << std::endl;
        }
        
        if (command.compare("empty") == 0) {
            std::cout << stack.empty() << std::endl;
        }
        if (command.compare("top") == 0) {
            std::cout << stack.top() << std::endl;
        }
    }
    return 0;
}
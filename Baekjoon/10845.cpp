#include <iostream>

class Queue {
    private:
        int save[10000];
        int current;

    public:
        Queue(): current(-1) {};
        virtual ~Queue() {};
        
        void push(int value) {
            current++;
            save[current] = value;
        }

        int pop() {
            if (empty())
                return current;

            int popValue = front();
            for (int i = 1; i <= current; i++) {
                save[i - 1] = save[i];
            }
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
    Queue queue;
    std::string command;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> command;
        if (command.compare("push") == 0) {
            std::cin >> value;
            queue.push(value);
        }

        if (command.compare("pop") == 0) {
            std::cout << queue.pop() << std::endl;
        }

        if (command.compare("size") == 0) {
            std::cout << queue.size() << std::endl;
        }
        
        if (command.compare("empty") == 0) {
            std::cout << queue.empty() << std::endl;
        }

        if (command.compare("front") == 0) {
            std::cout << queue.front() << std::endl;
        }

        if (command.compare("back") == 0) {
            std::cout << queue.back() << std::endl;
        }
    }
    return 0;
}
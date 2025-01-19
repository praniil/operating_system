#include<iostream>

int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    std::cout << "the task is added. Task id: " << x << std::endl;
    ++mutex;
}

void consumer() {
    --mutex;
    ++empty;
    --full;
    x--;
    std::cout << "the task consumed is. Task id: " << std::endl;
    ++mutex;
}

int main() {
    int choice;
    bool inloop = true;
    while (inloop) {
        printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
        
        std::cout << "enter your choice: " << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (mutex == 1 && empty != 0) {
                producer();
            } else {
                std::cout << "the buffer is full" << std::endl;
            }
            break;

        case 2: 
            if (mutex == 1 && full != 0) {
                consumer();
            } else {
                std::cout << "the buffer is empty" << std::endl;
            }
            break;
        case 3:
            inloop = false;
        default:
            break;
        }
    }
    return 0;
}
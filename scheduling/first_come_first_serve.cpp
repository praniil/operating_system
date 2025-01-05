#include<iostream>

class Processes {
    public:
    int process_no;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;

    Processes() {
        this -> process_no = 0;
        this -> arrival_time = 0;
        this -> burst_time = 0;
        this -> completion_time = 0;
        this -> turn_around_time = 0;
        this -> waiting_time = 0;
    }

    Processes(int process_no, int arrival_time, int burst_time) {
        this -> process_no = process_no;
        this -> arrival_time = arrival_time;
        this -> burst_time = burst_time;
    }

    int compute_completion_time(Processes p1) {
        if (this -> arrival_time >  p1.completion_time) {
            int difference = this -> arrival_time - p1.completion_time;
            return difference + p1.completion_time + this -> burst_time;
        }
        return p1.completion_time + this -> burst_time;
    }

    ~Processes() {
        std::cout << "destructor called" << std::endl;
    }
};

int main() {
    int i = 0;
    int process_size;
    std::cout << "give the number of process: " << std::endl;
    std::cin >> process_size;
    Processes* process_array = new Processes[process_size];

    while (i < process_size) {
        process_array[i].process_no = i + 1;
        std::cout << "enter the arrival time of " << i + 1 << " th task: " << std::endl;
        std::cin >> process_array[i].arrival_time;

        std::cout << "enter the burst time of " << i + 1 << " th task" << std::endl;
        std::cin >> process_array[i].burst_time;

        i++;
    }

    for (int i = 0; i < process_size; i++) {
        if (i == 0) {
            process_array[i].completion_time = process_array[i].burst_time;
        } else {
            process_array[i].completion_time = process_array[i].compute_completion_time(process_array[i - 1]);
        }
    }

    for (int i = 0; i < process_size; i++) {
        // std::cout << "process no: " << process_array[i].process_no << std::endl;
        // std::cout << "arrival time: " << process_array[i].arrival_time << std::endl;
        // std::cout << "burst time: " << process_array[i].burst_time << std::endl;   
        std::cout << "completion time: " << process_array[i].completion_time << std::endl;     
    }

    delete[] process_array;
}
#include <iostream>
#include <string>
#include "Task.h"
#include "PartB_RawDynamic.h"

int main() {
    std::cout << "=== Part B: Dynamic Raw Pointers ===\n";

    int capacity = 5;
    int size = 0;
    Task* tasks = new Task[capacity];

    addTask(tasks, size, capacity, "Finish homework");
    addTask(tasks, size, capacity, "Study pointers");
    listTasks(tasks, size);

    completeTaskById(tasks, size, 1);
    removeTask(tasks, size, 2);
    listTasks(tasks, size);

    delete[] tasks;   // REQUIRED
    tasks = nullptr;

    return 0;
}

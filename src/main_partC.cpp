#include <iostream>
#include "TaskManager.h"

int main() {
    std::cout << "=== Part C: Smart Pointers (unique_ptr) ===\n";

    TaskManager manager(3);

    manager.addTask("Write reflection");
    manager.addTask("Submit assignment");
    manager.listTasks();

    manager.removeTask(1);
    manager.listTasks();

    // No delete needed
    return 0;
}

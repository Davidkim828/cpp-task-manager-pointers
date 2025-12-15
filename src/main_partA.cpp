#include <iostream>
#include "Task.h"

void completeTask(Task* t) {
    if (t) {
        t->markCompleted();
    }
}

int main() {
    std::cout << "=== Part A: Raw Pointers to Stack Objects ===\n";

    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    Task* p1 = &t1;
    Task* p2 = &t2;

    completeTask(p1);
    completeTask(p2);

    std::cout << t1.getDescription()
              << " completed: " << t1.isCompleted() << "\n";
    std::cout << t2.getDescription()
              << " completed: " << t2.isCompleted() << "\n";

    return 0;
}

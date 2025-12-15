#include "PartB_RawDynamic.h"
#include <iostream>

void ensureCapacity(Task*& tasks, int& capacity, int size) {
    if (size < capacity) return;

    int newCapacity = capacity * 2;
    Task* newTasks = new Task[newCapacity];

    // Copy old -> new (Task has std::string, but copy assignment is fine)
    for (int i = 0; i < size; ++i) {
        newTasks[i] = tasks[i];
    }

    delete[] tasks;     // free old heap array
    tasks = newTasks;   // move pointer to new array
    capacity = newCapacity;

    std::cout << "Resized capacity to " << capacity << ".\n";
}

void addTask(Task* tasks, int& size, int capacity, const std::string& desc) {
    // NOTE: Signature required by assignment.
    // We'll keep it, but in main() we will call ensureCapacity BEFORE addTask.

    static int nextId = 1;

    if (size >= capacity) {
        std::cout << "Task list is full (capacity " << capacity << ").\n";
        std::cout << "Resize was not called. (Call ensureCapacity before addTask)\n";
        return;
    }

    tasks[size] = Task(nextId, desc);
    ++nextId;
    ++size;
}

void removeTask(Task* tasks, int& size, int id) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if ((tasks + i)->getId() == id) { // pointer arithmetic demo
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "Task id " << id << " not found.\n";
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    --size;
    std::cout << "Removed task id " << id << ".\n";
}

void listTasks(Task* tasks, int size) {
    if (size == 0) {
        std::cout << "(No tasks)\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        const Task& t = tasks[i];
        std::cout << "[" << t.getId() << "] "
                  << (t.isCompleted() ? "(Done) " : "(Todo) ")
                  << t.getDescription() << "\n";
    }
}

void completeTaskById(Task* tasks, int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (tasks[i].getId() == id) {
            tasks[i].markCompleted();
            std::cout << "Marked task id " << id << " completed.\n";
            return;
        }
    }
    std::cout << "Task id " << id << " not found.\n";
}

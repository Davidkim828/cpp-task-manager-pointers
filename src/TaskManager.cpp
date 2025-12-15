#include "TaskManager.h"
#include <iostream>
#include <utility>

TaskManager::TaskManager(int initialCapacity)
    : tasks(std::make_unique<Task[]>(initialCapacity)),
      size(0),
      capacity(initialCapacity),
      nextId(1) {}

void TaskManager::resizeIfNeeded() {
    if (size < capacity) return;

    int newCapacity = capacity * 2;
    auto newTasks = std::make_unique<Task[]>(newCapacity);

    for (int i = 0; i < size; ++i) {
        newTasks[i] = tasks[i];
    }

    tasks = std::move(newTasks);
    capacity = newCapacity;
}

void TaskManager::addTask(const std::string& desc) {
    resizeIfNeeded();
    tasks[size] = Task(nextId, desc);
    ++nextId;
    ++size;
}

void TaskManager::removeTask(int id) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].getId() == id) {
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

void TaskManager::listTasks() const {
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

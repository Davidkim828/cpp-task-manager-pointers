#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <memory>
#include <string>
#include "Task.h"

class TaskManager {
private:
    std::unique_ptr<Task[]> tasks;
    int size;
    int capacity;
    int nextId;

    void resizeIfNeeded();

public:
    explicit TaskManager(int initialCapacity);

    void addTask(const std::string& desc);
    void removeTask(int id);
    void listTasks() const;
};

#endif

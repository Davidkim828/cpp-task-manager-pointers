#ifndef PARTB_RAWDYNAMIC_H
#define PARTB_RAWDYNAMIC_H

#include <string>
#include "Task.h"

// Required functions (given by rubric)
void addTask(Task* tasks, int& size, int capacity, const std::string& desc);
void removeTask(Task* tasks, int& size, int id);
void listTasks(Task* tasks, int size);

// Extra helper (still pointer-based, helps your menu)
void completeTaskById(Task* tasks, int size, int id);

// BONUS: dynamic resize using raw pointers
void ensureCapacity(Task*& tasks, int& capacity, int size);

#endif

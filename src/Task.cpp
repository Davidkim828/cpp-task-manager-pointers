#include "Task.h"

Task::Task() : id(0), description(""), completed(false) {}

Task::Task(int idParam, const std::string& desc)
    : id(idParam), description(desc), completed(false) {}

void Task::markCompleted() { completed = true; }
void Task::markIncomplete() { completed = false; }

bool Task::isCompleted() const { return completed; }
int Task::getId() const { return id; }
std::string Task::getDescription() const { return description; }

void Task::setId(int newId) { id = newId; }
void Task::setDescription(const std::string& desc) { description = desc; }

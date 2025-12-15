#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task();
    Task(int id, const std::string& desc);

    void markCompleted();
    void markIncomplete();

    bool isCompleted() const;
    int getId() const;
    std::string getDescription() const;

    // Helpful for Part B array usage (not required, but practical)
    void setId(int newId);
    void setDescription(const std::string& desc);
};

#endif

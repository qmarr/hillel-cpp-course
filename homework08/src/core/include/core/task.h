#pragma once
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum class Priority {
    LOW,
    MEDIUM,
    HIGH,
    MAX_PRIORITY,
};

enum class Status {
    ON_HOLD,
    TO_DO,
    COMPLETED,
    MAX_STATUS,
};

class Task {

    
    int m_taskId{0};
    std::string m_title;
    Priority m_priority;
    Status m_status;
public:
    static int m_nextTaskID;
    explicit Task(std::string title);
    Task(std::string title, Priority priority, Status status);



    int getId() const;
    const std::string getTitle() const;
    Priority getPriority() const;
    Status getStatus() const;
    void setPriority(Priority p);
    void setStatus(Status s);
};


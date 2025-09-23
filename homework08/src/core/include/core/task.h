#pragma once
#include <string>
//#include <nlohmann/json.hpp>

//using json = nlohmann::json;

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

    //static int m_nextTaskID;
    int m_taskId{0};
    std::string m_title;
    Priority m_priority;
    Status m_status;
public:
    
    explicit Task(std::string title) 
        : m_taskId(m_taskId++), m_title(title), m_priority(Priority::LOW), m_status(Status::ON_HOLD) {
        
    }
    Task(std::string title, Priority priority, Status status) 
        : m_taskId(m_taskId++), m_title(title), m_priority(priority), m_status(status) {
        
    }


    int getId() const;
    const std::string& getTitle() const;
    Priority getPriority() const;
    Status getStatus() const;
    void setPriority(Priority p);
    void setStatus(Status s);
};


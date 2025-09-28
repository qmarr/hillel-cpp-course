#include "core/task.h"


int Task::m_nextTaskID = 0;

Task::Task(std::string title) : 
    m_taskId(m_nextTaskID++), m_title(title), 
    m_priority(Priority::LOW), m_status(Status::ON_HOLD) {
        
}

Task::Task(std::string title, Priority priority, Status status) : 
    m_taskId(m_nextTaskID++), m_title(title), 
    m_priority(priority), m_status(status) {
        
}


int Task::getId() const {

    return m_taskId;
};

const std::string Task::getTitle() const {
    return m_title; //lnk2019
};

Priority Task::getPriority() const {
    return m_priority;
};

Status Task::getStatus() const {
    return m_status;
};

void Task::setPriority(Priority p) {
    m_priority = p;
};

void Task::setStatus(Status s) {
    m_status = s;
};

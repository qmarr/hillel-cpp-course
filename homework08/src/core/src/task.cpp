#include <core/task.h>


//int Task::m_nextTaskID = 0;

int Task::getId() const {
    return m_taskId;
};

const std::string& Task::getTitle() const {
    return m_title;
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

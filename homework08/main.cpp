#include <iostream>
#include "core/task.h"
#include "TutorialConfig.h"
#include "app/app.h"

int main(int argc, char* argv[]) {
  Task task("First task");
  std::cout << "Here's my main!\n";

  std::cout << "ID: " <<  task.getId() << std::endl; 


  auto task_name("blank name");
  std::cout << "TASK NAME: " << task_name << std::endl;

  app showmsg;
  showmsg.printApp();

  if (argc < 2) {
  // report version
  std::cout << argv[0] << " Version " << CMAKETASTING_VERSION_MAJOR << "."
            << CMAKETASTING_VERSION_MINOR << std::endl;
  std::cout << "Usage: " << argv[0] << " number" << std::endl;
  return 1; 
  }
}
#ifndef EISENHOWER_TASK_BINARY_H
#define EISENHOWER_TASK_BINARY_H

#include "Task.h"

/*Punto 3*/
//Remember you will need a taskBinary struct 
//to write and read from the binary file

struct TaskBinary {
    
};

TaskBinary toBinaryTask(Task& task) {
    TaskBinary taskBinary;
    

    
    return taskBinary;
}

Task toTask(TaskBinary& taskBinary) {
    Task task;
   
    return task;
}

List<TaskBinary> toTaskBinaryList(List<Task>& tasks) {
    List<TaskBinary> taskBinaries;

    return taskBinaries;
}

List<Task> toTaskList(List<TaskBinary>& taskBinaries) {
    List<Task> tasks;

    return tasks;
}

List<Task> readTasksFromBinaryFile(string& path) {
    List<TaskBinary> taskBinaries;
    List<Task> tasks;

    return tasks;
}


bool writeTasksToBinaryFile(List<Task>& tasks, string& path) {
    
    List<TaskBinary> taskBinaries;

    return false;
}





#endif
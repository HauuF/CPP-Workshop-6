#ifndef EISENHOWER_TASK_BINARY_H
#define EISENHOWER_TASK_BINARY_H

#include "Task.h"
#include <string.h>
#include <stdlib.h>

/*Punto 3*/
//Remember you will need a taskBinary struct 
//to write and read from the binary file

struct TaskBinary {
    char binaryDescription[100];
    char binaryUrgent[100];
    char binaryImportant[100];
    char binaryTime[100];
};

TaskBinary toBinaryTask(Task& task) {
    TaskBinary taskBinary;
    string importante, urgente;
        strcpy(taskBinary.binaryDescription, task.description.c_str());
        if(task.isUrgent == true){
            urgente = '1';
        }else{
            urgente = '0';
        }
        strcpy(taskBinary.binaryUrgent, urgente.c_str());
        if(task.isImportant == true){
            importante = '1';
        }else{
            importante = '0';
        }
        strcpy(taskBinary.binaryImportant, importante.c_str());
        strcpy(taskBinary.binaryTime, to_string(task.estimatedTime).c_str());  
    return taskBinary;
}

Task toTask(TaskBinary& taskBinary) {
    Task task;
    task.description = string(taskBinary.binaryDescription);
    task.isUrgent = (taskBinary.binaryUrgent[0] == '1');
    task.isImportant = (taskBinary.binaryImportant[0] == '1');
    task.estimatedTime = atoi(taskBinary.binaryTime);
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
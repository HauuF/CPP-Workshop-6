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
            urgente = '0';
        }else{
            urgente = '1';
        } 
        strcpy(taskBinary.binaryUrgent, urgente.c_str());
        if(task.isImportant == true){
            importante = '0';
        }else{
            importante = '1';
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
    for (int i = 0; i < tasks.size; i++) {
        Task task = tasks.get(i);
        TaskBinary taskBinary = toBinaryTask(task);
        taskBinaries.add(taskBinary);
    }
    return taskBinaries;
}

List<Task> toTaskList(List<TaskBinary>& taskBinaries) {
    List<Task> tasks;
    for (int i = 0; i < taskBinaries.size; i++) {
        TaskBinary taskBinary = taskBinaries.get(i);
        Task task = toTask(taskBinary);
        tasks.add(task);
    }
    return tasks;
}

List<Task> readTasksFromBinaryFile(string& path) {
    List<Task> tasks;
    BinaryFileHandler<TaskBinary> fileHandler(path);
    List<TaskBinary> taskBinaries = fileHandler.readBinaryFile();
    for (int i = 0; i < taskBinaries.size; i++) {
        TaskBinary taskBinary = taskBinaries.get(i);
        Task task = toTask(taskBinary);
        tasks.add(task);
    }
    return tasks;
}

bool writeTasksToBinaryFile(List<Task>& tasks, string& path) {
    List<TaskBinary> taskBinaries = toTaskBinaryList(tasks);
    BinaryFileHandler<TaskBinary> fileHandler(path);
    return fileHandler.writeBinaryFile(taskBinaries);
}

#endif
#ifndef EISENHOWER_TASK_H
#define EISENHOWER_TASK_H

#include <string>
#include "List.h"
#include "TextFileHandler.h"
#include "BinaryFileHandler.h"

using namespace std;
/*Punto 1*/
struct Task {
string description;
bool isUrgent = true;
bool isImportant = true;
int estimatedTime = 0;
};

/*Punto 2*/
Task getTaskFromLine(string line, char delimiter = ';') {
    Task task;
    List<string> tokens = split(line, delimiter);
    int parabool1, parabool2;
    task.description = tokens.get(0);
    parabool1 = stoi(tokens.get(1));
    if(parabool1 == 0){
        task.isUrgent = true;
    }else{
        task.isUrgent = false;
    }
    parabool2 = stoi(tokens.get(2));
    if(parabool2 == 0){
        task.isImportant = true;
    }else{
        task.isImportant = false;
    }
    task.estimatedTime = stoi(tokens.get(3));
    return task;
}

List<Task> getTasksFromLines(List<string>& lines, char delimiter = ';') {
    List<Task> tasks;
    for (int i = 0; i < lines.size; i++) {
        Task task = getTaskFromLine(lines.get(i), delimiter);
        tasks.add(task);
    }
    return tasks;
}

List<Task> readTasksFromTextFile(string& path) {

    List<Task> tasks;
    TextFileHandler fileHandler(path);
    List<string> lines = fileHandler.readLines();
    tasks = getTasksFromLines(lines);
    return tasks;
}

/*Punto 5 - parte 1*/
string getLineReportFromTask(Task& task) {
    string line = task.description + ":" + to_string(task.estimatedTime);
    return line;
}

List<string> getLinesReportFromTasks(List<Task>& tasks) {
    List<string> lines;
    for (int i = 0; i < tasks.size; i++) {
        Task task = tasks.get(i);
        string line = getLineReportFromTask(task);
        lines.add(line);
    }
    return lines;
}

/*Punto 4 parte 2*/
List<Task> sortTasksByMinutes(List<Task>& tasks) {
    List<Task> sortedTasks = tasks.copy();
    for (int i = 0; i < sortedTasks.size; i++) {
        for (int j = 0; j < sortedTasks.size; j++) {
            Task currentTask = sortedTasks.get(j);
            Task nextTask = sortedTasks.get(j + 1);
            if (currentTask.estimatedTime < nextTask.estimatedTime) {
                sortedTasks.set(j, nextTask);
                sortedTasks.set(j + 1, currentTask);
            }
        }
    }
    return sortedTasks;
}

/*Punto 4 parte 1*/
List<Task> removeDeleteQuadrantTasks(List<Task>& tasks) {
    List<Task> newTasks;
    for (int i = 0; i < tasks.size; i++) {
        Task task = tasks.get(i);
        if((task.isImportant && task.isUrgent) || (task.isImportant && !task.isUrgent) || (!task.isImportant && task.isUrgent)){
            
            newTasks.add(task);
        }
    }
    return newTasks;
}

#endif
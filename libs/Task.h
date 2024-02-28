#ifndef EISENHOWER_TASK_H
#define EISENHOWER_TASK_H

#include <string>
//#include "List.h"
#include "TextFileHandler.h"
#include "BinaryFileHandler.h"

using namespace std;
/*Punto 1*/
struct Task {

    

};

/*Punto 2*/
Task getTaskFromLine(string &line, char delimiter = ';') {
    Task task;
    
    //parse the line and create a task
    List<string> tokens = split(line, delimiter);
    
    

    //remember to free the memory of tokens
    

    return task;
}

List<Task> getTasksFromLines(List<string>& lines, char delimiter = ';') {
    List<Task> tasks;



    return tasks;
}

List<Task> readTasksFromTextFile(string& path) {

    List<Task> tasks;
    
     
    return tasks;
}

/*Punto 5 - parte 1*/
string getLineReportFromTask(Task& task) {
    

    return "";
}

List<string> getLinesReportFromTasks(List<Task>& tasks) {
    List<string> lines;

    return lines;
}

/*Punto 4 parte 2*/
List<Task> sortTasksByMinutes(List<Task>& tasks) {
    List<Task> sortedTasks = tasks.copy();
    //sort the tasks by estimated time
    return sortedTasks;
}

/*Punto 4 parte 1*/
List<Task> removeDeleteQuadrantTasks(List<Task>& tasks) {
    List<Task> newTasks;

    //remove tasks from delete quadrant

    return newTasks;
}








#endif
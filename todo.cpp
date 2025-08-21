#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
struct Task {
    string description;
    bool completed;
};
void displayMenu() {
    cout << "\n=== TO-DO LIST APPLICATION ===\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Complete\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}
void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "\nEnter task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks in your to-do list!\n";
        return;
    }
    cout << "\n=== YOUR TASKS ===\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}
void markComplete(vector<Task> &tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    int taskNumber;
    cout << "\nEnter the task number to mark as complete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber-1].completed = true;
        cout << "Task marked as complete!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}
void deleteTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    int taskNumber;
    cout << "\nEnter the task number to delete: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}
void saveTasksToFile(const vector<Task> &tasks, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Task &task : tasks) {
            file << task.completed << " " << task.description << endl;
        }
        file.close();
    }
}
void loadTasksFromFile(vector<Task> &tasks, const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        string line;
        while (getline(file, line)) {
            if (line.length() > 2) {
                Task task;
                task.completed = (line[0] == '1');
                task.description = line.substr(2);
                tasks.push_back(task);
            }
        }
        file.close();
    }
}
int main() {
    vector<Task> tasks;
    const string filename = "tasks.txt";
    loadTasksFromFile(tasks, filename);
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markComplete(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        saveTasksToFile(tasks, filename);
    } while (choice != 5);
    return 0;
}
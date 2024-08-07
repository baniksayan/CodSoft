#include <iostream>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task() : description(""), isCompleted(false) {}
};

const int MAX_TASKS = 100;

void showMenu();
void addTask(Task tasks[], int& taskCount);
void viewTasks(const Task tasks[], int taskCount);
void markTaskCompleted(Task tasks[], int taskCount);
void removeTask(Task tasks[], int& taskCount);

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask(tasks, taskCount);
            break;
        case 2:
            viewTasks(tasks, taskCount);
            break;
        case 3:
            markTaskCompleted(tasks, taskCount);
            break;
        case 4:
            removeTask(tasks, taskCount);
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    cout << "\n---- To-Do List Manager ----\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

void addTask(Task tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full. Cannot add more tasks.\n";
        return;
    }

    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].isCompleted = false;
    taskCount++;
    cout << "Task added successfully!\n";
}

void viewTasks(const Task tasks[], int taskCount) {
    cout << "\n---- Task List ----\n";
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(Task tasks[], int taskCount) {
    viewTasks(tasks, taskCount);

    if (taskCount == 0) return;

    cout << "Enter the task number to mark as completed: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= taskCount) {
        tasks[taskNum - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(Task tasks[], int& taskCount) {
    viewTasks(tasks, taskCount);

    if (taskCount == 0) return;

    cout << "Enter the task number to remove: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum >= 1 && taskNum <= taskCount) {
        for (int i = taskNum - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

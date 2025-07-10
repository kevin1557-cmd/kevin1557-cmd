#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isDone;
};

vector<Task> todoList;

void addTask() {
    Task task;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, task.description);
    task.isDone = false;
    todoList.push_back(task);
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\n=== TO-DO LIST ===\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". [" << (todoList[i].isDone ? "✔" : " ") << "] "
             << todoList[i].description << "\n";
    }
}

void markTaskDone() {
    int index;
    viewTasks();
    cout << "Enter task number to mark as done: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    todoList[index - 1].isDone = true;
    cout << "Task marked as done.\n";
}

void deleteTask() {
    int index;
    viewTasks();
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    todoList.erase(todoList.begin() + index - 1);
    cout << "Task deleted.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n=== TO-DO LIST MENU ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskDone(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Task {
private:
    string title;
    bool completed;

public:
    // Constructor
    Task(string t) {
        title = t;
        completed = false;
    }

    // Mark task as completed
    void markCompleted() {
        completed = true;
    }

    string getTitle() const {
        return title;
    }

    bool isCompleted() const {
        return completed;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a new task
    void addTask() {
        string title;
        cout << "Enter Task Title: ";
        cin.ignore(); 
        getline(cin, title);
        tasks.push_back(Task(title));
        cout << "Task added successfully!\n";
    }

    // Display all tasks
    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\n----- To-Do List -----\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].getTitle();
            if (tasks[i].isCompleted()) {
                cout << " [Completed]";
            }
            cout << endl;
        }
        cout << "---------------------\n";
    }

    // Delete a task
    void deleteTask() {
        displayTasks();
        if (tasks.empty()) return;

        int index;
        cout << "Enter the task number to delete: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid Task Number!\n";
        } else {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully!\n";
        }
    }

    // Mark a task as completed
    void markTaskCompleted() {
        displayTasks();
        if (tasks.empty()) return;

        int index;
        cout << "Enter the task number to mark as completed: ";
        cin >> index;

        if (index < 1 || index > tasks.size()) {
            cout << "Invalid Task Number!\n";
        } else {
            tasks[index - 1].markCompleted();
            cout << "Task marked as completed!\n";
        }
    }
};

// Main function to interact with the To-Do List
int main() {
    ToDoList todo;
    int choice;

    while (true) {
        cout << "\n====== To-Do List ======" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                todo.addTask();
                break;
            case 2:
                todo.displayTasks();
                break;
            case 3:
                todo.deleteTask();
                break;
            case 4:
                todo.markTaskCompleted();
                break;
            case 5:
                cout << "Thank you for using the To-Do List App!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
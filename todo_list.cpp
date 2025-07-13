#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

// Display the main menu
void displayMenu() {
    cout << "\n📝 TO-DO LIST MENU" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

// Add a task
void addTask(vector<Task>& tasks) {
    cout << "Enter task description: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "✅ Task added successfully!" << endl;
}

// View tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "📭 No tasks in your list." << endl;
        return;
    }

    cout << "\n📋 Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] " << tasks[i].description << endl;
    }
}

// Mark task as completed
void markCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter task number to mark as completed: ";
    int index;
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "❌ Invalid task number!" << endl;
        return;
    }

    tasks[index - 1].completed = true;
    cout << "✅ Task marked as completed!" << endl;
}

// Remove a task
void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter task number to remove: ";
    int index;
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "❌ Invalid task number!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "🗑️ Task removed successfully!" << endl;
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "🎯 Welcome to the Simple To-Do List Manager\n";

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
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "👋 Exiting... Have a productive day!\n";
                break;
            default:
                cout << "❗ Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

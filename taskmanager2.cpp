#include <iostream>
#include <string>

using namespace std;

// كلاس الجزء (المهمة الواحدة) 
class task {
public:
    string title;
    int priority;

    task() {
        title = "";
        priority = 0;
    }

    task(string t, int p) {
        title = t;
        priority = p; 
    }
}; 

//  2. كلاس الكل (مدير المهام) 
class task_manager {
private:
    task* taskslist;
    int capacity;
    int taskcount;

public:
    task_manager(int cap) {
        capacity = cap;
        taskcount = 0;
        taskslist = new task[capacity];
    }

    ~task_manager() {
        delete[] taskslist;
    }

    string addmission() {
        if (taskcount >= capacity) {
            cout << "The manager is full! Cannot add more tasks." << endl;
            return "";
        }

        string tempTitle;
        int tempPriority;

        cout << "enter the subject of the mission: " << endl;
        getline(cin, tempTitle);

        cout << "enter the priority: " << endl;
        cin >> tempPriority;

        taskslist[taskcount] = task(tempTitle, tempPriority);
        taskcount++;

        return taskslist[taskcount - 1].title;
    }

    void deletemission() {
        if (taskcount == 0) {
            cout << "No tasks available to delete!" << endl;
            return;
        }

    
        cout << "Available tasks to delete: " << endl;
        viewtasks();

        int taskNumber;
        cout << "Enter the number of the task you want to delete: ";
        cin >> taskNumber;

      
        if (taskNumber < 1 || taskNumber > taskcount) {
            cout << "Invalid task number!" << endl;
            return;
        }

       
        int indexToDelete = taskNumber - 1;

        for (int i = indexToDelete; i < taskcount - 1; i++) {
            taskslist[i] = taskslist[i + 1];
        }

        
        taskcount--;
        cout << "Task deleted successfully!" << endl;
    }

    void viewtasks() {
        if (taskcount == 0) {
            cout << "No tasks available to view!" << endl;
            return;
        }

        for (int i = 0; i < taskcount; i++) {
            cout << (i + 1) << ") Task: " << taskslist[i].title 
                 << " | Priority: " << taskslist[i].priority << endl;
        }
    }
}; 

//  نقطة التشغيل الأساسية 
int main() {
    int capacity;
    cout << "enter the numbers of missions: ";
    cin >> capacity;

    task_manager manager(capacity);

    int choice;
    do {
        cout << "\n--- Smart Task Manager ---" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); 

        switch (choice) {
            case 1:
                manager.addmission();
                break;
            case 2:
                manager.viewtasks();
                break;
            case 3:
                manager.deletemission(); 
                break;
            case 4:
                cout << "Exiting program and freeing memory... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4); 

    return 0;
}

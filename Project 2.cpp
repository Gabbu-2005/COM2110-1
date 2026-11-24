#include <iostream>
using namespace std;

// Creating a student class
class Student {
public:
    char name[50];
    char admissionNumber[20];
    char course[50];
    int age;
    float marks;
};

Student s[100]; //creates an array of 100 student objects
int total = 0;//counts how many students have been registered

// Register a student
void registerStudent() {

    if (total >= 100) {
        cout << "Registration limit reached!\n";
        return;
    }

    cout << "\n--- STUDENT REGISTRATION ---\n";

    cout << "Enter student name: ";
    cin >> s[total].name;

    cout << "Enter admission number: ";
    cin >> s[total].admissionNumber;

    cout << "Enter age: ";
    cin >> s[total].age;

    cout << "Enter course: ";
    cin >> s[total].course;

    cout << "Enter marks: ";
    cin >> s[total].marks;

    total++;

    cout << "Student registered successfully!\n";
}

// View students
void viewStudents() {

    for (int i = 0; i < total; i++) {

        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << s[i].name << endl;
        cout << "Admission: " << s[i].admissionNumber << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Course: " << s[i].course << endl;
        cout << "Marks: " << s[i].marks << endl;
    }
}

// Search student
void searchStudent() {

    char adm[20];
    int found = 0;

    cout << "Enter admission number: ";
    cin >> adm;

    for (int i = 0; i < total; i++) {

        int j = 0;

        while (adm[j] == s[i].admissionNumber[j] &&
               adm[j] != '\0') {
            j++;
        }

        if (adm[j] == '\0' &&
            s[i].admissionNumber[j] == '\0') {

            cout << "Student found!\n";
            cout << "Name: " << s[i].name << endl;
            cout << "Age: " << s[i].age << endl;
            cout << "Course: " << s[i].course << endl;
            cout << "Marks: " << s[i].marks << endl;

            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "Student not found!\n";
    }
}

// Update student
void updateStudent() {

    char adm[20];
    int found = 0;

    cout << "Enter admission number: ";
    cin >> adm;

    for (int i = 0; i < total; i++) {

        int j = 0;

        while (adm[j] == s[i].admissionNumber[j] &&
               adm[j] != '\0') {
            j++;
        }

        if (adm[j] == '\0' &&
            s[i].admissionNumber[j] == '\0') {

            cout << "Enter new name: ";
            cin >> s[i].name;

            cout << "Enter new age: ";
            cin >> s[i].age;

            cout << "Enter new course: ";
            cin >> s[i].course;

            cout << "Enter new marks: ";
            cin >> s[i].marks;

            found = 1;

            cout << "Student updated successfully!\n";
            break;
        }
    }

    if (found == 0) {
        cout << "Student not found!\n";
    }
}


// Main function
int main() {

    int choice;

    do {

        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                registerStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name[100];
    string admission[100];
    string course[100];
    int age[100];
    float marks[100];
    int total = 0;
};

// Register a student
void registerStudent(Student &s) {
    if (s.total >= 100) {
        cout << "Student limit reached!\n";
        return;
    }

    int i = s.total;

    cout << "\n--- REGISTER STUDENT ---\n";

    cout << "Enter student name: ";
    getline(cin, s.name[i]);

    cout << "Enter admission number: ";
    getline(cin, s.admission[i]);

    cout << "Enter age: ";
    cin >> s.age[i];
    cin.ignore();

    cout << "Enter course: ";
    getline(cin, s.course[i]);

    cout << "Enter marks: ";
    cin >> s.marks[i];
    cin.ignore();

    if (s.age[i] <= 0 || s.marks[i] < 0 ||
        s.marks[i] > 100) {
        cout << "Invalid details!\n";
        return;
    }

    s.total++;

    cout << "Student registered successfully!\n";
}

// View all students
void viewStudents(Student s) {
    cout << "\n--- ALL STUDENTS ---\n";

    if (s.total == 0) {
        cout << "No students registered.\n";
        return;
    }

    for (int i = 0; i < s.total; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << s.name[i] << endl;
        cout << "Admission: " << s.admission[i] << endl;
        cout << "Age: " << s.age[i] << endl;
        cout << "Course: " << s.course[i] << endl;
        cout << "Marks: " << s.marks[i] << endl;
    }
}

// Search for a student
void searchStudent(Student s) {
    string adm;
    int found = 0;

    cout << "\nEnter admission number: ";
    getline(cin, adm);

    for (int i = 0; i < s.total; i++) {
        if (s.admission[i] == adm) {
            cout << "Student found!\n";
            cout << "Name: " << s.name[i] << endl;
            cout << "Age: " << s.age[i] << endl;
            cout << "Course: " << s.course[i] << endl;
            cout << "Marks: " << s.marks[i] << endl;
            found = 1;
            break;
        }
    }

    if (found == 0) {
        cout << "Student not found!\n";
    }
}

// Update student details
void updateStudent(Student &s) {
    string adm;
    int found = 0;

    cout << "\nEnter admission number: ";
    getline(cin, adm);

    for (int i = 0; i < s.total; i++) {
        if (s.admission[i] == adm) {
            cout << "Enter new name: ";
            getline(cin, s.name[i]);

            cout << "Enter new age: ";
            cin >> s.age[i];
            cin.ignore();

            cout << "Enter new course: ";
            getline(cin, s.course[i]);

            cout << "Enter new marks: ";
            cin >> s.marks[i];
            cin.ignore();

            found = 1;
            cout << "Student updated successfully!\n";
            break;
        }
    }

    if (found == 0) {
        cout << "Student not found!\n";
    }
}

// Delete a student
void deleteStudent(Student &s) {
    string adm;
    int found = 0;

    cout << "\nEnter admission number: ";
    getline(cin, adm);

    for (int i = 0; i < s.total; i++) {
        if (s.admission[i] == adm) {

            for (int j = i; j < s.total - 1; j++) {
                s.name[j] = s.name[j + 1];
                s.admission[j] = s.admission[j + 1];
                s.course[j] = s.course[j + 1];
                s.age[j] = s.age[j + 1];
                s.marks[j] = s.marks[j + 1];
            }

            s.total--;
            found = 1;

            cout << "Student deleted successfully!\n";
            break;
        }
    }

    if (found == 0) {
        cout << "Student not found!\n";
    }
}

// Calculate average marks
void calculateAverage(Student s) {
    if (s.total == 0) {
        cout << "No student records available.\n";
        return;
    }

    float sum = 0;

    for (int i = 0; i < s.total; i++) {
        sum = sum + s.marks[i];
    }

    cout << "Average marks: " << sum / s.total << endl;
}

// Save student records to a file
void saveStudents(Student s) {
    ofstream file("students.txt");

    file << s.total << endl;

    for (int i = 0; i < s.total; i++) {
        file << s.name[i] << endl;
        file << s.admission[i] << endl;
        file << s.course[i] << endl;
        file << s.age[i] << endl;
        file << s.marks[i] << endl;
    }

    file.close();
}

// Load student records from a file
void loadStudents(Student &s) {
    ifstream file("students.txt");

    if (!file) {
        return;
    }

    file >> s.total;
    file.ignore();

    for (int i = 0; i < s.total; i++) {
        getline(file, s.name[i]);
        getline(file, s.admission[i]);
        getline(file, s.course[i]);
        file >> s.age[i];
        file >> s.marks[i];
        file.ignore();
    }

    file.close();
}

// Main function
int main() {
    Student s;

    loadStudents(s);

    int choice;

    do {
        cout << "\n==============================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "==============================\n";

        cout << "1. Register Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Calculate Average Marks\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                registerStudent(s);
                break;

            case 2:
                viewStudents(s);
                break;

            case 3:
                searchStudent(s);
                break;

            case 4:
                updateStudent(s);
                break;

            case 5:
                deleteStudent(s);
                break;

            case 6:
                calculateAverage(s);
                break;

            case 7:
                saveStudents(s);
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

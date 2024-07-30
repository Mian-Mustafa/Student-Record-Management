#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_FACULTY = 10;

class Person {
public:
    string name;
    string address;
    string phone;
    string dob;
    string pass;
    string id;

    virtual void addNew() = 0;
    virtual void display() const = 0;
};

class Student : public Person {
public:
    int roll;
    float math, physics, computer, chemistry, english, percentage;

    void calculatePercentage() {
        percentage = ((math + physics + computer + chemistry + english) / 500) * 100;
    }

    void addNew() override {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Date of Birth: ";
        getline(cin, dob);
        cout << "Enter Password: ";
        getline(cin, pass);
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter ID: ";
        getline(cin, id);
    }

    void uploadMarks() {
        cout << "Enter marks for Math, Physics, Computer, Chemistry, and English respectively: ";
        cin >> math >> physics >> computer >> chemistry >> english;
        calculatePercentage();
    }

    void display() const override {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "DOB: " << dob << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "ID: " << id << endl;
        cout << "Math: " << math << endl;
        cout << "Physics: " << physics << endl;
        cout << "Computer: " << computer << endl;
        cout << "Chemistry: " << chemistry << endl;
        cout << "English: " << english << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "----------------------" << endl;
    }
};

class Faculty : public Person {
public:
    int facultyID;

    void addNew() override {
        cout << "Enter Faculty Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> facultyID;
        cin.ignore();
        cout << "Enter Password: ";
        getline(cin, pass);
    }

    void display() const override {
        cout << "Name: " << name << endl;
        cout << "ID: " << facultyID << endl;
        cout << "----------------------" << endl;
    }
};

class Introduction {
public:
    void intro() {
        system("color A");
        cout << "\n\n\n";
        cout << "\t\t\t\t *  *  *  *****  *     *****  ***    * * *    *****   " << endl;
        Sleep(300);
        cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *        " << endl;
        Sleep(300);
        cout << "\t\t\t\t *  *  *  *****  *     *     *   *  *  *  *   *****    " << endl;
        Sleep(300);
        cout << "\t\t\t\t *  *  *  *      *     *     *   *  *  *  *   *         " << endl;
        Sleep(300);
        cout << "\t\t\t\t  * * *   *****  ****  *****  ***   *  *  *   *****     " << endl;
        Sleep(300);
        cout << endl;
        cout << "\t\t\t\t=============================================" << endl;
        Sleep(300);
        cout << "\t\t\t\t  THIS IS STUDENT RECORD MANAGEMENT SYSTEM" << endl;
        Sleep(300);
        cout << "\t\t\t\t=============================================" << endl;
        Sleep(300);
        cout << "\nPress enter to continue...";
        cin.get();
    }
};

class LoginSystem {
public:
    void adminLogin();
    void studentLogin();
    void facultyLogin();
    void logout();
    void home();
    void loadStudents();
    void loadFaculties();
    void saveStudents();
    void saveFaculties();

private:
    void adminMenu();
    void viewExistingStudentRecord();
    void viewSpecificStudentMarks(int roll);
    void uploadStudentMarks(int roll);
    void viewSpecificStudentMarksFaculty(int roll);
    void uploadStudentMarksFaculty(int roll);
    void viewExistingFacultyRecord();
    void modifyExistingFacultyDetails(int id);
    void deleteFacultyData(int id);
    void addNewFaculty();
};

Student students[MAX_STUDENTS];
Faculty faculties[MAX_FACULTY];
int studentCount = 0;
int facultyCount = 0;

int main() {
    Introduction I;
    I.intro();
    system("CLS");
    system("color E");

    LoginSystem L;
    L.loadStudents(); // Load existing students from file
    L.loadFaculties(); // Load existing faculties from file

    while (true) {
        L.home();
        int num;
        cin >> num;
        switch (num) {
            case 1:
                L.adminLogin();
                break;
            case 2:
                L.studentLogin();
                break;
            case 3:
                L.facultyLogin();
                break;
            case 4:
                L.logout();
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    }

    // Save data to files before exit
    L.saveStudents();
    L.saveFaculties();

    return 0;
}

void LoginSystem::home() {
    system("CLS");
    cout << "Enter 1 for Admin Login " << endl;
    cout << "Enter 2 for Student Login " << endl;
    cout << "Enter 3 for Faculty Login " << endl;
    cout << "Enter 4 for Logout " << endl;
}

void LoginSystem::adminLogin() {
    string pass, id;
    cout << endl;
    cout << "Enter your Id and Password :" << endl;
    cin.ignore();
    cout << "Enter ID :";
    getline(cin, id);
    cout << "Enter Password :";
    getline(cin, pass);
    system("CLS");

    if (id == "admin" && pass == "admin") {
        adminMenu();
    } else {
        cout << "Invalid Password & ID :" << endl;
        char a;
        cout << "Enter H or h to go back to the Home page :" << endl;
        cin >> a;
        if (a == 'h' || a == 'H')
            return;
    }
}

void LoginSystem::adminMenu() {
    while (true) {
        system("CLS");
        cout << "\t\t Students :" << endl;
        cout << "Add New Student         : Press 1" << endl;
        cout << "View Existing Students  : Press 2" << endl;
        cout << "Modify Existing Student : Press 3" << endl;
        cout << "View Specific Student   : Press 4" << endl;
        cout << "Delete Student          : Press 5" << endl;
        cout << "Upload Student Marks    : Press 6" << endl;
        cout << "\t\t Faculty :" << endl;
        cout << "Add New Faculty         : Press 8" << endl;
        cout << "View Existing Faculty   : Press 9" << endl;
        cout << "Modify Existing Faculty : Press 10" << endl;
        cout << "Delete Faculty          : Press 11" << endl;
        cout << "Log Out                 : Press 7" << endl;
        int n;
        cout << "Enter the Number :" << endl;
        cin >> n;
        switch (n) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    students[studentCount].addNew();
                    studentCount++;
                    saveStudents(); // Save after adding
                    cout << "Student added successfully!" << endl;
                    Sleep(1000);
                } else {
                    cout << "Maximum student limit reached!" << endl;
                    Sleep(1000);
                }
                break;
            case 2:
                viewExistingStudentRecord();
                break;
            case 3:
                {
                    int roll;
                    cout << "Enter Roll Number of student to modify: ";
                    cin >> roll;
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].roll == roll) {
                            students[i].addNew();
                            saveStudents(); // Save after modifying
                            cout << "Student details updated successfully!" << endl;
                            break;
                        }
                    }
                }
                break;
            case 4:
                {
                    int roll;
                    cout << "Enter Roll Number of student to view: ";
                    cin >> roll;
                    viewSpecificStudentMarks(roll);
                    Sleep(3000);
                    system("CLS");
                }
                break;
            case 5:
                {
                    int roll;
                    cout << "Enter Roll Number of student to delete: ";
                    cin >> roll;
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].roll == roll) {
                            for (int j = i; j < studentCount - 1; j++) {
                                students[j] = students[j + 1];
                            }
                            studentCount--;
                            saveStudents(); // Save after deleting
                            cout << "Student deleted successfully!" << endl;
                            break;
                        }
                    }
                }
                break;
            case 6:
                {
                    int roll;
                    cout << "Enter Roll Number of student to upload marks: ";
                    cin >> roll;
                    uploadStudentMarks(roll);
                }
                break;
            case 8:
                if (facultyCount < MAX_FACULTY) {
                    faculties[facultyCount].addNew();
                    facultyCount++;
                    saveFaculties(); // Save after adding
                    cout << "Faculty added successfully!" << endl;
                    Sleep(1000);
                } else {
                    cout << "Maximum faculty limit reached!" << endl;
                    Sleep(1000);
                }
                break;
            case 9:
                viewExistingFacultyRecord();
                break;
            case 10:
                {
                    int id;
                    cout << "Enter ID of faculty to modify: ";
                    cin >> id;
                    modifyExistingFacultyDetails(id);
                }
                break;
            case 11:
                {
                    int id;
                    cout << "Enter ID of faculty to delete: ";
                    cin >> id;
                    deleteFacultyData(id);
                }
                break;
            case 7:
                return;
            default:
                cout << "Invalid Number. Please try again." << endl;
                Sleep(1000);
        }
    }
}

void LoginSystem::viewExistingStudentRecord() {
    system("CLS");
    for (int i = 0; i < studentCount; i++) {
        students[i].display();
    }
    cout << "Press any key to go back...";
    _getch();
}

void LoginSystem::viewSpecificStudentMarks(int roll) {
    system("CLS");
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            students[i].display();
            break;
        }
    }
    cout << "Press any key to go back...";
    _getch();
}

void LoginSystem::uploadStudentMarks(int roll) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            students[i].uploadMarks();
            saveStudents(); // Save after uploading marks
            cout << "Marks uploaded successfully!" << endl;
            Sleep(1000);
            break;
        }
    }
}

void LoginSystem::studentLogin() {
    string id, pass;
    cout << endl;
    cout << "Enter your Id and Password :" << endl;
    cin.ignore();
    cout << "Enter ID :";
    getline(cin, id);
    cout << "Enter Password :";
    getline(cin, pass);
    system("CLS");

    bool loggedIn = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id && students[i].pass == pass) {
            while (true) {
                system("CLS");
                cout << "\t\t Welcome " << students[i].name << endl;
                cout << "View Details         : Press 1" << endl;
                cout << "View Marks           : Press 2" << endl;
                cout << "Log Out              : Press 3" << endl;
                int n;
                cout << "Enter the Number :" << endl;
                cin >> n;
                switch (n) {
                    case 1:
                        students[i].display();
                        Sleep(3000);
                        system("CLS");
                        break;
                    case 2:
                        viewSpecificStudentMarks(students[i].roll);
                        Sleep(3000);
                        system("CLS");
                        break;
                    case 3:
                        return;
                    default:
                        cout << "Invalid Number. Please try again." << endl;
                        Sleep(1000);
                }
            }
            loggedIn = true;
            break;
        }
    }
    if (!loggedIn) {
        cout << "Invalid ID or Password." << endl;
        char a;
        cout << "Enter H or h to go back to the Home page :" << endl;
        cin >> a;
        if (a == 'h' || a == 'H')
            return;
    }
}

void LoginSystem::facultyLogin() {
    string pass;
    int id;
    cout << endl;
    cout << "Enter your Id and Password :" << endl;
    cin.ignore();
    cout << "Enter ID :";
    cin >> id;
    cin.ignore();
    cout << "Enter Password :";
    getline(cin, pass);
    system("CLS");

    for (int i = 0; i < facultyCount; i++) {
        if (faculties[i].facultyID == id && faculties[i].pass == pass) {
            cout << "Welcome " << faculties[i].name << "!" << endl;
            cout << "Upload Student Marks : Press 1" << endl;
            cout << "View Student Marks   : Press 2" << endl;
            cout << "Log Out              : Press 3" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    {
                        int roll;
                        cout << "Enter Roll Number of student to upload marks: ";
                        cin >> roll;
                        uploadStudentMarksFaculty(roll);
                    }
                    break;
                case 2:
                    {
                        int roll;
                        cout << "Enter Roll Number of student to view marks: ";
                        cin >> roll;
                        viewSpecificStudentMarksFaculty(roll);
                    }
                    break;
                case 3:
                    return;
                default:
                    cout << "Invalid option." << endl;
            }
        }
    }
    cout << "Invalid Password & ID :" << endl;
    char a;
    cout << "Enter H or h to go back to the Home page :" << endl;
    cin >> a;
    if (a == 'h' || a == 'H')
        return;
}

void LoginSystem::viewSpecificStudentMarksFaculty(int roll) {
    system("CLS");
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            students[i].display();
            break;
        }
    }
    cout << "Press any key to go back...";
    _getch();
}

void LoginSystem::uploadStudentMarksFaculty(int roll) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            students[i].uploadMarks();
            saveStudents(); // Save after uploading marks
            cout << "Marks uploaded successfully!" << endl;
            Sleep(1000);
            break;
        }
    }
}

void LoginSystem::viewExistingFacultyRecord() {
    system("CLS");
    for (int i = 0; i < facultyCount; i++) {
        faculties[i].display();
    }
    cout << "Press any key to go back...";
    _getch();
}

void LoginSystem::modifyExistingFacultyDetails(int id) {
    for (int i = 0; i < facultyCount; i++) {
        if (faculties[i].facultyID == id) {
            faculties[i].addNew();
            saveFaculties(); // Save after modifying
            cout << "Faculty details updated successfully!" << endl;
            Sleep(1000);
            break;
        }
    }
}

void LoginSystem::deleteFacultyData(int id) {
    for (int i = 0; i < facultyCount; i++) {
        if (faculties[i].facultyID == id) {
            for (int j = i; j < facultyCount - 1; j++) {
                faculties[j] = faculties[j + 1];
            }
            facultyCount--;
            saveFaculties(); // Save after deleting
            cout << "Faculty deleted successfully!" << endl;
            Sleep(1000);
            break;
        }
    }
}

void LoginSystem::logout() {
    cout << "Logging out..." << endl;
    Sleep(1000);
    home();
}

void LoginSystem::loadStudents() {
    ifstream fin("students.txt");
    if (!fin.is_open()) {
        cout << "Failed to open students file." << endl;
        return;
    }
    studentCount = 0;
    while (fin >> ws && getline(fin, students[studentCount].name)) {
        getline(fin, students[studentCount].address);
        getline(fin, students[studentCount].phone);
        getline(fin, students[studentCount].dob);
        getline(fin, students[studentCount].pass);
        fin >> students[studentCount].roll;
        fin.ignore();
        getline(fin, students[studentCount].id);
        fin >> students[studentCount].math >> students[studentCount].physics >> students[studentCount].computer >> students[studentCount].chemistry >> students[studentCount].english;
       // students[studentCount].total = students[studentCount].math + students[studentCount].physics + students[studentCount].computer + students[studentCount].chemistry + students[studentCount].english;
        studentCount++;
    }
    fin.close();
}

void LoginSystem::saveStudents() {
    ofstream fout("students.txt");
    if (!fout.is_open()) {
        cout << "Failed to open students file." << endl;
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fout << students[i].name << endl;
        fout << students[i].address << endl;
        fout << students[i].phone << endl;
        fout << students[i].dob << endl;
        fout << students[i].pass << endl;
        fout << students[i].roll << endl;
        fout << students[i].id << endl;
        fout << students[i].math << " " << students[i].physics << " " << students[i].computer << " " << students[i].chemistry << " " << students[i].english << endl;
    }
    fout.close();
}

void LoginSystem::loadFaculties() {
    ifstream fin("faculties.txt");
    if (!fin.is_open()) {
        cout << "Failed to open faculties file." << endl;
        return;
    }
    facultyCount = 0;
    while (fin >> ws && getline(fin, faculties[facultyCount].name)) {
        getline(fin, faculties[facultyCount].address);
        getline(fin, faculties[facultyCount].phone);
        getline(fin, faculties[facultyCount].dob);
        getline(fin, faculties[facultyCount].pass);
        fin >> faculties[facultyCount].facultyID;
        fin.ignore();
    //    getline(fin, faculties[facultyCount].department);
        facultyCount++;
    }
    fin.close();
}

void LoginSystem::saveFaculties() {
    ofstream fout("faculties.txt");
    if (!fout.is_open()) {
        cout << "Failed to open faculties file." << endl;
        return;
    }
    for (int i = 0; i < facultyCount; i++) {
        fout << faculties[i].name << endl;
        fout << faculties[i].address << endl;
        fout << faculties[i].phone << endl;
        fout << faculties[i].dob << endl;
        fout << faculties[i].pass << endl;
        fout << faculties[i].facultyID << endl;
       // fout << faculties[i].department << endl;
    }
    fout.close();
}



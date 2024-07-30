# Student-Record-Management
Introduction:
                        The Student record Management System is a comprehensive software solution aimed at facilitating efficient management of various administrative tasks within a university. This project proposal outlines the objectives, features, and implementation details of the Student Record
Management System, developed using Object-Oriented Programming (OOP) principles in C++.
Objectives:
	To provide an user interface for administration ,faculty members , and students to interact with the system efficiently. 
Features:
	User Authentication 
	Student Management 
	Faculty Data Management 
	Course Management
	Examination Shedule
Technologies & Tools:
	Programming Languages
•	C++ for Development 
•	OOP Principal for Efficient Code Design 
Conclusion:
                       By leveraging OOP principles in C++, the system will ensure scalability, maintainability, and extensibility, thereby meeting the evolving needs of the Student Record Management System Project. 
Team:
             The Team for this C++ OPP Project consists on two members Ghulam Mustafa (Id:F2023266796) and Muhammad Ahmad (Id:F2023266795) that have been Submitted to dr.Nadeem Ashraf (Prof. of University of Management and Technoloy) before the Final Term of 2nd Smester .    
Overview:

# Student Record Management System
•	This is a menu driven C++ based student report management system where there are three users - admin, faculty and student.
•	All users can login to the system using their respective id and password given by the department at the time of their id creation.

## Admin
Admin has the credentials:
id: admin
password: admin
After login admin menu will open, and he can use his features. 

An admin has the complete access to the system. He can add new students and faculties, modify and delete their data. He can update student scores and can view everyone result. Basically, he has whole data transparency of the system.

Their is a feature called Publish Student Result in admin menu, until it's off Student cannot see his result.

## Faculty
A faculty will login to the system using faculty id and password created by the admin. Then a faculty menu will open and he can select his features there.

He has the features to view his profile, to view any student profile, update student marks. Basically partial access to the system.

## Student
A Student will login to the system using student id and password created by the admin.  Then a student menu will open and he can select his features there.
He has the features to view his profile and to view his final result. Basically limited access to only view his information.

Note: A student cannot view his result until admin review and publish final result in his menu, until then student will be shown "result not published yet status".


“Student Record Management System”
Overview :
The Student Record Management System is a comprehensive console application designed to manage student and faculty records efficiently. It provides functionalities for administrators, students, and faculty members to perform various tasks, including adding new records, viewing existing records, modifying records, and uploading student marks.
Key Components
1. Libraries and Headers
•	<iostream>: Handles input and output stream operations.
•	<fstream>: Manages file input and output operations for data persistence.
•	<windows.h>: Provides system-specific functionalities such as console color and sleep functions.
•	<conio.h>: Manages console input/output, including keyboard input functions.
•	<string>: Facilitates string manipulations and operations.
2. Constants
•	MAX_STUDENTS: Defines the maximum number of students the system can handle, set to 100.
•	MAX_FACULTY: Defines the maximum number of faculty members the system can handle, set to 10.
3. Classes
Person Class
•	Attributes: Common attributes for both students and faculty, including name, address, phone, dob, pass, and id.
•	Methods: Pure virtual functions addNew() and display() for adding new records and displaying existing records.
Student Class
•	Inherits: From Person.
•	Additional Attributes: roll, math, physics, computer, chemistry, english, and percentage.
•	Methods:
o	calculatePercentage(): Calculates the percentage of marks.
o	addNew(): Adds a new student record.
o	uploadMarks(): Uploads marks for various subjects.
o	display(): Displays student details.
Faculty Class
•	Inherits: From Person.
•	Additional Attribute: facultyID.
•	Methods:
o	addNew(): Adds a new faculty record.
o	display(): Displays faculty details.
Introduction Class
•	Method: intro(): Displays an animated introduction message.
LoginSystem Class
•	Attributes: Manages login and main functionalities of the system.
•	Methods:
o	adminLogin(), studentLogin(), facultyLogin(): Handle login for admin, students, and faculty.
o	logout(): Logs out the user.
o	home(): Displays the home menu.
o	loadStudents(), loadFaculties(): Load existing student and faculty records from files.
o	saveStudents(), saveFaculties(): Save current student and faculty records to files.
o	adminMenu(): Displays the admin menu and handles various administrative tasks.
o	Record Management: Methods to view, modify, delete, and upload marks for student and faculty records.
4. Global Variables
•	students[MAX_STUDENTS]: Array to store student records.
•	faculties[MAX_FACULTY]: Array to store faculty records.
•	studentCount: Keeps track of the number of students.
•	facultyCount: Keeps track of the number of faculty members.
Main Function
•	Introduction: Displays an animated introduction.
•	Load Records: Loads existing student and faculty records from files.
•	Home Menu: Presents login options (admin, student, faculty). Depending on the user's choice, it invokes appropriate login methods and handles administrative tasks.
LoginSystem Methods
Home Menu
•	Displays the main menu options for login.
Admin Login
•	Validates admin credentials.
•	Provides functionalities for:
o	Adding new student and faculty records.
o	Viewing existing student and faculty records.
o	Modifying existing student and faculty records.
o	Deleting student and faculty records.
o	Uploading student marks.
Student Login
•	Validates student credentials.
•	Provides options for:
o	Viewing student details.
o	Viewing student marks.
Faculty Login
•	Validates faculty credentials.
•	Provides options for:
o	Uploading student marks.
o	Viewing student marks.
Record Management
•	Add New Student/Faculty: Adds new records.
•	View Existing Records: Displays all records.
•	Modify Existing Records: Updates records.
•	Delete Records: Removes records.
•	Upload Marks: Uploads marks for students.
Usage
•	Admin: Manages student and faculty records, including adding, modifying, deleting, and viewing details, as well as uploading student marks.
•	Student: Views their own details and marks after logging in.
•	Faculty: Uploads and views student marks.
Summary
The Student Record Management System streamlines the management of student and faculty records through a user-friendly console application. It offers comprehensive functionalities for administrators, students, and faculty members, ensuring efficient handling of academic records and information.


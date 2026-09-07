#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constants
const int MAX_STUDENTS = 100;
const int NUM_SUBJECTS = 5;

// Structs definitions
struct Subject {
    string name;
    float marks;
    string grade;
    float gpaPoints;
};

struct Student {
    int rollNo;
    string name;
    Subject subjects[NUM_SUBJECTS];
    float gpa;
    int rank;
};

// Global variables or array to hold data in memory
Student students[MAX_STUDENTS];
int studentCount = 0;
string subjectNames[NUM_SUBJECTS] = {"CP theory", "Calculus", "CA theory", "CP lab", "CA lab"};
void improvementSuggestion(Student st);
void subjectStatistics();
void generateTranscript();

// Function to calculate Grade and Points based on Pakistani university scale
void calculateSubjectGrade(Subject &sub) {
    if (sub.marks >= 85) { sub.grade = "A"; sub.gpaPoints = 4.0; }
    else if (sub.marks >= 80) { sub.grade = "A-"; sub.gpaPoints = 3.7; }
    else if (sub.marks >= 75) { sub.grade = "B+"; sub.gpaPoints = 3.3; }
    else if (sub.marks >= 71) { sub.grade = "B";  sub.gpaPoints = 3.0; }
    else if (sub.marks >= 68) { sub.grade = "B-"; sub.gpaPoints = 2.7; }
    else if (sub.marks >= 64) { sub.grade = "C+"; sub.gpaPoints = 2.3; }
    else if (sub.marks >= 61) { sub.grade = "C";  sub.gpaPoints = 2.0; }
    else if (sub.marks >= 58) { sub.grade = "C-"; sub.gpaPoints = 1.7; }
    else if (sub.marks >= 54) { sub.grade = "D+"; sub.gpaPoints = 1.3; }
    else if (sub.marks >= 50) { sub.grade = "D";  sub.gpaPoints = 1.0; }
    else { sub.grade = "F"; sub.gpaPoints = 0.0; }
}

// Function to calculate overall student GPA
void computeStudentGPA(Student &st) {
    float totalPoints = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        calculateSubjectGrade(st.subjects[i]);
        totalPoints += st.subjects[i].gpaPoints;
    }
    st.gpa = totalPoints / NUM_SUBJECTS;
}

// Feature 1: Load Records from File
void loadStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error: Cannot open students.txt file!"<<endl;
        return;
    }
    
    studentCount = 0;
    while (file >> students[studentCount].rollNo >> students[studentCount].name) {
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            students[studentCount].subjects[i].name = subjectNames[i];
            file >> students[studentCount].subjects[i].marks;
        }
        computeStudentGPA(students[studentCount]);
        studentCount++;
        if (studentCount >= MAX_STUDENTS) break;
    }
    file.close();
    cout << "Students loaded: " << studentCount << " | Subjects: CP Theory, Calculus, CA Theory, CP Lab, CA Lab"<<endl;
}

// Function to save records back to file
void saveStudents() {
    ofstream file("students.txt");
    for (int i = 0; i < studentCount; i++) {
        file << students[i].rollNo << " " << students[i].name;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            file << " " << students[i].subjects[j].marks;
        }
        file << "\n";
    }
    file.close();
}

// Feature 4: Sort by GPA using Bubble Sort and Assign Rank
void sortByGPA() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    // Assign Rank
    for (int i = 0; i < studentCount; i++) {
        students[i].rank = i + 1;
    }
}

// Feature 2: Display All Students (Ranked)
void displayAll() {
    sortByGPA(); // Ensure they are sorted before displaying

    cout << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Rank\tRoll No\tName           CP Theory\tCalculus\tCA Theory\tCP Lab\t\tCA Lab\t\tGPA" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++) {

        cout << students[i].rank << "\t";
        cout << students[i].rollNo << "\t";
        cout << students[i].name;

        // Make Name column fixed to 15 characters
        int spaces = 15 - students[i].name.length();

        if (spaces < 1)
            spaces = 1;

        for (int k = 0; k < spaces; k++)
            cout << " ";

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            cout << students[i].subjects[j].marks << "\t\t";
        }

        cout << students[i].gpa << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

cout << "Total Students : "
     << studentCount
     << endl;

}

// Feature 3: Search Student
void searchStudent() {
    int choice;
    cout << "Search by: (1) Roll Number (2) Name: ";
    cin >> choice;
    
    bool found = false;
    if (choice == 1) {
        int roll;
        cout << "Enter roll number: ";
        cin >> roll;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].rollNo == roll) {
                cout << "\n--- STUDENT RECORD FOUND ---\n";
                cout << "Roll No : " << students[i].rollNo << "\nName : " << students[i].name << "\nRank : " << students[i].rank << "\n";
                cout << "Subject\tMarks\tGrade\tGPA Pts\n";
                for (int j = 0; j < NUM_SUBJECTS; j++) {
                    cout << students[i].subjects[j].name << "\t" << students[i].subjects[j].marks << "\t" << students[i].subjects[j].grade << "\t" << students[i].subjects[j].gpaPoints << "\n";
                }
                cout << "Overall GPA : " << students[i].gpa << endl;
                
                float percentage = 0;

for (int j = 0; j < NUM_SUBJECTS; j++)
{
    percentage += students[i].subjects[j].marks;
}

percentage = percentage / NUM_SUBJECTS;

cout << "Percentage : "
     << percentage
     << "%" << endl;

bool failed = false;

for (int j = 0; j < NUM_SUBJECTS; j++)
{
    if (students[i].subjects[j].grade == "F")
    {
        failed = true;
        break;
    }
}

if (failed)
    cout << "Status      : FAIL" << endl;
else
    cout << "Status      : PASS" << endl;

improvementSuggestion(students[i]);
				found = true;
                break;
            }
        }
    } else {
    string searchName;
    cout << "Enter Name: ";
    cin >> searchName;

    for (int i = 0; i < studentCount; i++) {

        if (students[i].name == searchName) {

            cout << "\n--- STUDENT RECORD FOUND ---\n";
            cout << "Roll No : " << students[i].rollNo << endl;
            cout << "Name    : " << students[i].name << endl;
            cout << "Rank    : " << students[i].rank << endl;

            cout << "\nSubject\t\tMarks\tGrade\tGPA Points\n";

            for (int j = 0; j < NUM_SUBJECTS; j++) {

                cout << students[i].subjects[j].name << "\t"
                     << students[i].subjects[j].marks << "\t"
                     << students[i].subjects[j].grade << "\t"
                     << students[i].subjects[j].gpaPoints << endl;
            }

           cout << "Overall GPA : " << students[i].gpa << endl;
           float percentage = 0;

for (int j = 0; j < NUM_SUBJECTS; j++)
{
    percentage += students[i].subjects[j].marks;
}

percentage = percentage / NUM_SUBJECTS;

cout << "Percentage : "
     << percentage
     << "%" << endl;

bool failed = false;

for (int j = 0; j < NUM_SUBJECTS; j++)
{
    if (students[i].subjects[j].grade == "F")
    {
        failed = true;
        break;
    }
}

if (failed)
    cout << "Status      : FAIL" << endl;
else
    cout << "Status      : PASS" << endl;

improvementSuggestion(students[i]);
			
            found = true;
            break;
        }
    }
}
    if (!found) cout << "Student record not found.\n";
}

// Feature 4: Add New Student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Database full!\n";
        return;
    }
    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNo;
    
    // Check duplication
    for(int i = 0; i < studentCount; i++) {
        if(students[i].rollNo == newStudent.rollNo) {
            cout << "Error: Duplicate Roll Number!\n";
            return;
        }
    }
    
    cout << "Enter Name (use underscore for spaces): ";
    cin >> newStudent.name;
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        newStudent.subjects[i].name = subjectNames[i];
        cout << "Enter marks for " << subjectNames[i] << " (0-100): ";
        cin >> newStudent.subjects[i].marks;
        if (newStudent.subjects[i].marks < 0 || newStudent.subjects[i].marks > 100) {
            cout << "Invalid marks! Add operation aborted.\n";
            return;
        }
    }
    computeStudentGPA(newStudent);
    students[studentCount] = newStudent;
    studentCount++;
    saveStudents();
    cout << "Student added successfully and saved to file!\n";
}

// Feature 5: Update Marks
void updateMarks() {
    int roll;
    cout << "Enter roll number to update marks: ";
    cin >> roll;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            cout << "Student found: " << students[i].name << "\n";
            for (int j = 0; j < NUM_SUBJECTS; j++) {

    cout << "Enter new marks for " << students[i].subjects[j].name << " (0-100): ";
    cin >> students[i].subjects[j].marks;

    if (students[i].subjects[j].marks < 0 || students[i].subjects[j].marks > 100) {
        cout << "Invalid Marks! Update operation cancelled.\n";
        return;
    }
}
            computeStudentGPA(students[i]);
            saveStudents();
            cout << "Marks updated and saved to file successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    int index = -1;

    // Find the student
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Student not found!\n";
        return;
    
    }
    
    char choice;

cout << "Are you sure you want to delete "
     << students[index].name
     << "? (Y/N): ";

cin >> choice;

if (choice != 'Y' && choice != 'y')
{
    cout << "Delete operation cancelled.\n";
    return;
}

    // Shift all students one position left
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;

    saveStudents();

    cout << "Student deleted successfully!\n";
}

// Feature 6: Generate Class Report File
void generateReport() {
    ofstream report("report.txt");

    if (!report) {
        cout << "Error generating report file.\n";
        return;
    }

    sortByGPA();

    report << "=========================================================\n";
    report << "          STUDENT MANAGEMENT SYSTEM REPORT\n";
    report << "=========================================================\n";
    report << "Class : BS Computer Systems Engineering\n";
    report << "Subjects : CP Theory, Calculus, CA Theory, CP Lab, CA Lab\n";
    report << "Date : ____________\n";
    report << "=========================================================\n\n";

    report << "Rank\tRoll No\tName\t\tGPA\n";
    report << "---------------------------------------------------------\n";

    float totalClassGPA = 0;
    int failCount = 0;
    int passCount = 0;

    // Ranked List
    for (int i = 0; i < studentCount; i++) {

        report << students[i].rank << "\t"
               << students[i].rollNo << "\t"
               << students[i].name << "\t"
               << students[i].gpa << "\n";

        totalClassGPA += students[i].gpa;

        bool failed = false;

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].subjects[j].grade == "F") {
                failed = true;
                break;
            }
        }

        if (failed)
    failCount++;
else
    passCount++;
    }

// Summary
    report << "\n=========================================================\n";
    report << "SUMMARY\n";
    report << "=========================================================\n";

    if (studentCount > 0) {

        report << "Class Average GPA : "
               << totalClassGPA / studentCount << endl;

        report << "Highest GPA : "
               << students[0].gpa
               << " (" << students[0].name << ")" << endl;

        report << "Lowest GPA : "
               << students[studentCount - 1].gpa
               << " (" << students[studentCount - 1].name << ")" << endl;
    }

   		 report << "Students Failing Any Subject : "
           << failCount << endl;
           report << "Students Passed : "
       << passCount << endl;

report << "Students Failed : "
       << failCount << endl;

    // At-Risk Students
    report << "\n=========================================================\n";
    report << "AT-RISK STUDENTS\n";
    report << "=========================================================\n";

    bool anyRisk = false;

    for (int i = 0; i < studentCount; i++) {

        bool failed = false;

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            if (students[i].subjects[j].grade == "F") {
                failed = true;
                break;
            }
        }

        if (students[i].gpa < 2.0 || failed) {

            report << students[i].rollNo
                   << "\t"
                   << students[i].name
                   << "\tGPA : "
                   << students[i].gpa
                   << endl;

            anyRisk = true;
        }
    }

    if (!anyRisk) {
        report << "No at-risk students.\n";
    }

    report.close();

    cout << "Report successfully generated in 'report.txt'!\n";
}

void generateTranscript()
{
    
    sortByGPA();    // <-- Paste this line here

    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            string fileName = "transcript_" + to_string(roll) + ".txt";

            ofstream file(fileName.c_str());

            if (!file)
            {
                cout << "Unable to create transcript file.\n";
                return;
            }

            file << "=========================================\n";
            file << "          STUDENT TRANSCRIPT\n";
            file << "=========================================\n\n";
            
            file << "University : UET Peshawar\n";
			file << "Program    : BS Computer Systems Engineering\n";
			file << "Semester   : 1st Semester\n";
			file << "-----------------------------------------\n\n";

            file << "Roll Number : " << students[i].rollNo << endl;
            file << "Name        : " << students[i].name << endl;
            file << "Rank        : " << students[i].rank << endl;
            file << "Overall GPA : " << students[i].gpa << endl;
            
			float percentage = 0;

for (int j = 0; j < NUM_SUBJECTS; j++)
{
    percentage += students[i].subjects[j].marks;
}

percentage = percentage / NUM_SUBJECTS;

file << "Percentage : "
     << percentage
     << "%" << endl;

            bool failed = false;

            file << "\n-----------------------------------------\n";
            file << "Subject\t\tMarks\tGrade\n";
            file << "-----------------------------------------\n";

            for (int j = 0; j < NUM_SUBJECTS; j++)
            {
                file << students[i].subjects[j].name
                     << "\t"
                     << students[i].subjects[j].marks
                     << "\t"
                     << students[i].subjects[j].grade
                     << endl;

                if (students[i].subjects[j].grade == "F")
                    failed = true;
            }

            file << "\n-----------------------------------------\n";

            if (failed)
                file << "Status : FAIL\n";
            else
                file << "Status : PASS\n";

            file << "=========================================\n";

            file.close();

            cout << "Transcript generated successfully!\n";
            cout << "File Name : " << fileName << endl;

            return;
        }
    }

    cout << "Student not found.\n";
}

void subjectStatistics()
{
    cout << "\n=============================================================\n";
    cout << "                SUBJECT-WISE STATISTICS\n";
    cout << "=============================================================\n";

    cout << "Subject\t\tAverage\tHighest\tLowest\tFailures\n";
    cout << "-------------------------------------------------------------\n";

	if (studentCount == 0)
{
    cout << "No student records available.\n";
    return;
}
    for (int j = 0; j < NUM_SUBJECTS; j++)
    {
        float total = 0;
        float highest = students[0].subjects[j].marks;
        float lowest = students[0].subjects[j].marks;
        int failCount = 0;

        for (int i = 0; i < studentCount; i++)
        {
            float marks = students[i].subjects[j].marks;

            total += marks;

            if (marks > highest)
                highest = marks;

            if (marks < lowest)
                lowest = marks;

            if (marks < 50)
                failCount++;
        }

      	cout << subjectNames[j];

		int spaces = 15 - subjectNames[j].length();

		if (spaces < 1)
    	spaces = 1;

		for (int k = 0; k < spaces; k++)
    	cout << " ";

		cout << total / studentCount
	     << "\t"
	     << highest
	     << "\t"
	     << lowest
	     << "\t"
	     << failCount
	     << endl;
    }

    cout << "=============================================================\n";
}


void improvementSuggestion(Student st)
{
    int weakest = 0;

    // Find weakest subject
    for (int i = 1; i < NUM_SUBJECTS; i++)
    {
        if (st.subjects[i].marks < st.subjects[weakest].marks)
        {
            weakest = i;
        }
    }

    float marks = st.subjects[weakest].marks;
    int target = -1;

    if (marks < 50)
        target = 50;
    else if (marks < 54)
        target = 54;
    else if (marks < 58)
        target = 58;
    else if (marks < 61)
        target = 61;
    else if (marks < 64)
        target = 64;
    else if (marks < 68)
        target = 68;
    else if (marks < 71)
        target = 71;
    else if (marks < 75)
        target = 75;
    else if (marks < 80)
        target = 80;
    else if (marks < 85)
        target = 85;

    cout << "\n----------------------------------------\n";
    cout << "GRADE IMPROVEMENT SUGGESTION\n";
    cout << "----------------------------------------\n";

    cout << "Weakest Subject : "
         << st.subjects[weakest].name << endl;

    cout << "Current Marks   : "
         << marks << endl;

    string nextGrade = "";

if (target == 50)
    nextGrade = "D";
else if (target == 54)
    nextGrade = "D+";
else if (target == 58)
    nextGrade = "C-";
else if (target == 61)
    nextGrade = "C";
else if (target == 64)
    nextGrade = "C+";
else if (target == 68)
    nextGrade = "B-";
else if (target == 71)
    nextGrade = "B";
else if (target == 75)
    nextGrade = "B+";
else if (target == 80)
    nextGrade = "A-";
else if (target == 85)
    nextGrade = "A";

if (target == -1)
{
    cout << "Current Grade   : A" << endl;
    cout << "Excellent! You already have the highest grade." << endl;
}
else
{
    cout << "Current Grade   : "
         << st.subjects[weakest].grade << endl;

    cout << "Next Grade      : "
         << nextGrade << endl;

    cout << "Need            : "
         << target - marks
         << " Marks" << endl;

    cout << "\nSuggestion:\n";
    cout << "Focus on "
         << st.subjects[weakest].name
         << " first. Improving this subject will increase your GPA."
         << endl;
}

    cout << "----------------------------------------\n";
}
// Main Menu Driver Program
int main() {
    loadStudents(); // Auto load records on start
    
    int choice = 0;
    while (choice != 9) {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Display All Students (Ranked)\n";
        cout << "2. Search Student\n";
        cout << "3. Add New Student\n";
        cout << "4. Update Student Marks\n";
        cout << "5. Delete Student\n";
		cout << "6. Generate Class Report\n";
		cout << "7. Generate Transcript\n";
		cout << "8. Subject-wise Statistics\n";
		cout << "9. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: displayAll(); break;
            case 2: searchStudent(); break;
            case 3: addStudent(); break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
			case 6: generateReport(); break;
			case 7: generateTranscript(); break;
			case 8: subjectStatistics(); break;
			case 9: cout << "Exiting system. Goodbye!"<<endl; break;
            
			default: cout << "Invalid choice! Please try again.\n";	
        }
    }
    return 0;
}
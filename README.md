# 🎓 Student Grade Book Management System

> **A complete console-based C++ academic record management system with file handling, structured data, automated GPA calculation, student ranking, reports, transcripts, statistics, and grade improvement suggestions.**

---

## 📌 Overview

The **Student Grade Book Management System** is a complete console-based application developed in **C++** to efficiently manage student academic records.

The system uses **structures, arrays, modular programming, file handling, searching, sorting, input validation, and decision-making** to provide a practical academic management solution.

It allows instructors to maintain student records, calculate subject grades and overall GPA automatically, rank students according to academic performance, generate class reports and individual transcripts, analyze subject-wise statistics, and provide personalized grade improvement suggestions.

Unlike a basic grade calculator, this project focuses on **complete record management and persistent academic data storage**.

---

## 🎯 Objectives

The main objectives of the project are to:

* Manage student academic records efficiently.
* Store student data permanently using file handling.
* Use structures to organize student and subject information.
* Automatically calculate subject grades and GPA.
* Rank students according to academic performance.
* Provide Add, Search, Update, and Delete operations.
* Generate class-level academic reports.
* Generate individual student transcripts.
* Analyze subject-wise academic performance.
* Identify failing and at-risk students.
* Provide grade improvement suggestions.
* Apply proper input validation and error handling.
* Demonstrate practical implementation of C++ programming concepts.

---

## ✨ Key Features

### 👨‍🎓 Student Record Management

The system provides complete student record management through:

* ➕ Add new student
* 🔍 Search student by roll number
* 🔍 Search student by name
* ✏️ Update student marks
* 🗑️ Delete student record
* 📋 Display all students
* 💾 Permanent record storage

### 📊 Automatic Grade & GPA Calculation

The system automatically:

* Calculates the grade of each subject.
* Assigns corresponding GPA points.
* Calculates the overall GPA.
* Determines pass/fail status.
* Updates GPA whenever marks are changed.

### 🏆 Student Ranking

Students are ranked according to their GPA.

The system:

1. Sorts students in descending order of GPA.
2. Assigns academic ranks.
3. Displays the ranked student list.

**Sorting Algorithm:** Bubble Sort

### 📑 Class Report Generation

The application generates a `report.txt` file containing academic information such as:

* Ranked student list
* GPA statistics
* Pass/fail summary
* At-risk student information

### 🧾 Individual Transcript Generator

The system can generate an individual transcript for a selected student.

A transcript includes:

* Student name
* Roll number
* Subject-wise marks
* Subject grades
* Overall GPA
* Percentage
* Academic rank
* Final status

Generated transcripts are saved as:

```text
transcript_<RollNo>.txt
```

### 📈 Subject-wise Statistics

The system analyzes every subject and calculates:

* Class average
* Highest marks
* Lowest marks
* Number of failed students

This provides an overview of class performance across different subjects.

### 💡 Grade Improvement Suggestions

The application identifies a student's weakest subject and calculates the minimum marks required to achieve the next higher grade.

If the student has already achieved the highest grade, the system provides an appreciation message instead.

### 🛡️ Input Validation

The system includes validation to help maintain accurate records.

Examples include:

* Marks must remain within `0–100`.
* Duplicate roll numbers are rejected.
* Invalid student records are prevented.
* Deletion requires confirmation.
* Missing data files are handled appropriately.

---

## 📚 Subjects

The current system manages five subjects:

| # | Subject                     |
| - | --------------------------- |
| 1 | Computer Programming Theory |
| 2 | Calculus                    |
| 3 | Circuit Analysis Theory     |
| 4 | Computer Programming Lab    |
| 5 | Circuit Analysis Lab        |

---

## 📐 Grading Scale

The application uses the following grading scale:

|    Marks | Grade | GPA Points |
| -------: | :---: | ---------: |
| 85 – 100 |   A   |        4.0 |
|  80 – 84 |   A−  |        3.7 |
|  75 – 79 |   B+  |        3.3 |
|  71 – 74 |   B   |        3.0 |
|  68 – 70 |   B−  |        2.7 |
|  64 – 67 |   C+  |        2.3 |
|  61 – 63 |   C   |        2.0 |
|  58 – 60 |   C−  |        1.7 |
|  54 – 57 |   D+  |        1.3 |
|  50 – 53 |   D   |        1.0 |
| Below 50 |   F   |        0.0 |

---

## 🧮 GPA Calculation

Since the system currently contains five equally weighted subjects, the overall GPA is calculated as:

```text
Overall GPA = (CP Theory GPA + Calculus GPA + CA Theory GPA + CP Lab GPA + CA Lab GPA) / 5
```

### Example

Suppose a student receives:

```text
CP Theory   = 4.0
Calculus    = 4.0
CA Theory   = 4.0
CP Lab      = 4.0
CA Lab      = 4.0
```

Then:

```text
GPA = (4.0 + 4.0 + 4.0 + 4.0 + 4.0) / 5

GPA = 20.0 / 5

GPA = 4.0
```

The manually calculated result matches the GPA generated by the program.

---

## 🧱 Data Structure Design

The project uses two main structures:

### `Subject`

The `Subject` structure stores information related to an individual subject.

```text
Subject
├── Name
├── Marks
├── Grade
└── GPA Points
```

### `Student`

The `Student` structure stores personal and academic information.

```text
Student
├── Roll Number
├── Name
├── Subjects[5]
├── GPA
└── Rank
```

The nested structure design keeps related information organized and makes the system easier to maintain and extend.

---

## 📁 File Handling

The project uses text files for persistent data storage.

### `students.txt`

Stores student records in a space-separated format.

Example:

```text
101 Ali 85 78 88 78 85
102 Ahmad 43 56 87 0 9
103 Hamza 5 6 78 78 98
```

The general record format is:

```text
RollNo Name CP_Theory Calculus CA_Theory CP_Lab CA_Lab
```

The program loads records from `students.txt` when it starts and saves modifications after operations such as adding, updating, or deleting students.

### `report.txt`

Generated automatically by the report generation feature.

### `transcript_<RollNo>.txt`

Generated automatically when an individual student transcript is requested.

---

## ⚙️ Main Functions

The project follows a modular programming approach.

| Function                  | Purpose                                 |
| ------------------------- | --------------------------------------- |
| `calculateSubjectGrade()` | Calculates subject grade and GPA points |
| `computeStudentGPA()`     | Calculates overall student GPA          |
| `loadStudents()`          | Loads records from `students.txt`       |
| `saveStudents()`          | Saves records to the data file          |
| `sortByGPA()`             | Sorts students and assigns ranks        |
| `displayAll()`            | Displays ranked student records         |
| `searchStudent()`         | Searches by roll number or name         |
| `addStudent()`            | Adds a new student                      |
| `updateMarks()`           | Updates existing student marks          |
| `deleteStudent()`         | Deletes a student record                |
| `generateReport()`        | Generates the class report              |
| `generateTranscript()`    | Generates an individual transcript      |
| `subjectStatistics()`     | Calculates subject-wise statistics      |
| `improvementSuggestion()` | Provides grade improvement guidance     |
| `main()`                  | Controls overall program execution      |

---

## 🔄 Program Flow

The overall execution process follows this general flow:

```text
                 ┌──────────────────┐
                 │   Program Start  │
                 └────────┬─────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │ Load students.txt│
                 └────────┬─────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │   Main Menu      │
                 └────────┬─────────┘
                          │
          ┌───────────────┼────────────────┐
          │               │                │
          ▼               ▼                ▼
     Add/Search       Update/Delete    Reports/Stats
          │               │                │
          └───────────────┼────────────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │ Calculate Grades │
                 │ & GPA / Ranking  │
                 └────────┬─────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │ Save Changes     │
                 │ to students.txt  │
                 └────────┬─────────┘
                          │
                          ▼
                 ┌──────────────────┐
                 │    Main Menu     │
                 └────────┬─────────┘
                          │
                     Exit selected
                          │
                          ▼
                 ┌──────────────────┐
                 │   Program End    │
                 └──────────────────┘
```

---

## 🛠️ Technologies & Concepts

### Language

* **C++**

### Core Programming Concepts

* Variables and data types
* Conditional statements
* Loops
* Functions
* Arrays
* Structures
* Nested structures
* String handling
* File input/output
* Searching
* Sorting
* Input validation
* Decision making
* Modular programming

### Algorithms

* Sequential searching
* Bubble Sort
* Grade calculation
* GPA calculation
* Statistical calculations

---

## 📂 Project Structure

```text
student-gradebook-management-system/
│
├── main.cpp              # Main C++ source code
├── students.txt          # Student records / sample data
├── report.txt             # Generated class report
├── README.md              # Project documentation
└── .gitignore             # Files excluded from Git
```

Generated transcript files can be stored separately when produced by the application:

```text
transcript_<RollNo>.txt
```

---

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/student-gradebook-management-system.git
```

### 2. Open the Project Directory

```bash
cd student-gradebook-management-system
```

### 3. Compile the Program

Using `g++`:

```bash
g++ main.cpp -o gradebook
```

### 4. Run the Program

#### Windows

```bash
gradebook.exe
```

#### Linux / macOS

```bash
./gradebook
```

> **Note:** Make sure `students.txt` is located in the same working directory as the executable so that the program can load the student records correctly.

---

## 🧪 Example Data

The project can work with records such as:

```text
101 Ali 85 78 88 78 85
102 Ahmad 43 56 87 0 9
103 Hamza 5 6 78 78 98
```

The program reads these records, calculates grades and GPA, and uses the resulting information throughout the system.

---

## 🚀 Implemented Extensions

The project extends the basic Grade Book requirements with several additional features.

### Extension A — Delete Student Record

Allows an instructor to remove an existing student using the student's roll number.

A confirmation step is included to reduce accidental deletion.

### Extension C — Transcript Generator

Creates a detailed individual transcript containing academic performance and final status.

### Extension D — Subject-wise Statistics

Provides statistical analysis for each subject, including:

* Average marks
* Highest marks
* Lowest marks
* Failure count

### Extension E — Grade Improvement Suggestions

Identifies the weakest subject and determines the marks required to reach the next grade level.

---

## 🔐 Data Integrity & Validation

The application takes several measures to maintain reliable academic records:

* Prevents duplicate roll numbers.
* Validates marks between `0` and `100`.
* Recalculates grades after mark updates.
* Recalculates GPA after academic changes.
* Saves modifications to permanent storage.
* Requires confirmation before deleting records.
* Handles file-based student data systematically.

---

## 🎓 Academic Context

This project was developed as an **Open Ended Lab Project** for:

**CSE102L — Computer Programming Lab**

**Department of Computer Systems Engineering,**
**University of Engineering and Technology, Peshawar**

**Semester:** Spring 2026

### Submitted By

**Muhammad Qasim Usman**

### Submitted To

**Engr. Abdullah Hamid**

---

## 📌 Future Improvements

The current console-based system provides a strong foundation for further development.

Possible future enhancements include:

* 🖥️ Graphical User Interface (GUI)
* 🗄️ Database integration
* 🔐 Secure user authentication
* 📚 Multiple semester support
* 🔎 Advanced search and filtering
* 📊 Interactive performance dashboards
* 📄 PDF transcript generation
* 📤 Export to CSV/Excel
* 👥 Separate student and instructor accounts
* ☁️ Cloud-based data storage

---

## 🧠 Learning Outcomes

Developing this project provided practical experience in combining multiple C++ concepts into a complete working application.

Through the project, the following skills were strengthened:

* Designing structured data models
* Working with nested structures
* Reading and writing files
* Developing modular functions
* Implementing searching and sorting
* Performing GPA and statistical calculations
* Validating user input
* Managing persistent records
* Generating structured reports
* Designing a complete menu-driven application

---

## 👨‍💻 Author

### Muhammad Qasim Usman

**Computer Systems Engineering,**
**University of Engineering and Technology, Peshawar**

> Built as an academic project demonstrating practical C++ programming, file handling, data structures, algorithms, and modular software design.

---

## ⭐ Project Highlights

```text
✔ Complete Student Record Management
✔ Persistent File Storage
✔ Nested Structures
✔ Automatic Grade Calculation
✔ Automatic GPA Calculation
✔ GPA-Based Student Ranking
✔ Add / Search / Update / Delete
✔ Class Report Generation
✔ Individual Transcript Generation
✔ Subject-wise Statistics
✔ Failing / At-Risk Identification
✔ Grade Improvement Suggestions
✔ Input Validation
✔ Modular C++ Design
```

---

## 📄 License

This project was developed for **academic and educational purposes** as part of the CSE102L Computer Programming Lab.

You are welcome to study the implementation and use it as a learning reference.

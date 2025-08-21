# todo-list-yt
To-Do List Application
A simple and efficient command-line to-do list manager written in C++. This application allows you to manage your tasks with ease, including adding, viewing, completing, and deleting tasks. All tasks are automatically saved to a file for persistence between sessions.

Features
Add Tasks: Quickly add new tasks to your to-do list
View Tasks: Display all tasks with completion status
Mark Tasks Complete: Check off completed tasks
Delete Tasks: Remove tasks you no longer need
Persistence: Tasks are automatically saved to and loaded from a file
Simple Interface: Clean, menu-driven command-line interface

How to Use
Compile the Program:
g++ -o todo todo.cpp
Run the Application:
./todo

Navigate the Menu:
Select option 1 to add a new task
Select option 2 to view all tasks
Select option 3 to mark a task as complete
Select option 4 to delete a task
Select option 5 to exit the program

File Storage
Tasks are automatically saved to a file named tasks.txt in the same directory as the executable. The file format is simple:
Each line represents one task
The first character indicates completion status (0 for incomplete, 1 for complete)
The rest of the line contains the task description

Requirements
A C++ compiler (GCC, Clang, or MSVC)
Standard C++ library

License
This project is open source and available under the MIT License.

Contributing
Contributions are welcome! Please feel free to submit a Pull Request.



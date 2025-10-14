#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int studentID;
    int units;
    float gpa;
    string securityCode;
    Student* next;
};

void addStudent(Student* &head, const string& name, int studentID, int units, float gpa, const string& securityCode)
{
    Student* newStudent = new Student;

    newStudent -> name = name;
    newStudent -> studentID = studentID;
    newStudent -> units = units;
    newStudent -> gpa = gpa;
    newStudent -> securityCode = securityCode;
    newStudent -> next = nullptr;

    //if list is empty
    if (head == nullptr){
        head = newStudent;
        return;
    }

    Student* current = head;
}

bool deleteStudent(Student* &head, int studentID)
{
    if (head == nullptr){
        return false;
    }

    Student* current = head;
    Student* prev = nullptr;

    while (current != nullptr && current->studentID != studentID){
        prev = current;
        current = current->next;
    }

    //if student not found
    if (current == nullptr){
        return false;
    }

    if (prev == nullptr){
        head = current->next;
    }
    else{
        prev->next = current->next;
    }

    delete current;
    return true;
}

Student* searchStudent(Student* head, int studentID)
{
    Student* current = head;

    while (current != nullptr){
        if (current->studentID == studentID){
            return current;
        }

        current = current->next;
    }

    //if current == nullptr
    return nullptr;
}


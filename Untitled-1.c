#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student data
typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int count = 0;

// Function to add a student
void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("\nMaximum student limit reached!\n");
        return;
    }
    printf("\nEnter Roll No: ");
    scanf("%d", &students[count].roll_no);
    printf("Enter Name: ");
    scanf(" %49[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("\nStudent added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("----------------------------------------\n");
    printf("Roll No | Name                | Marks\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%7d | %-20s | %.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

// Function to save students to file
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    fclose(file);
    printf("\nData saved to file successfully!\n");
}

// Function to load students from file
void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("\nNo previous records found.\n");
        return;
    }
    count = 0;
    while (fscanf(file, "%d %49s %f", &students[count].roll_no, students[count].name, &students[count].marks) == 3) {
        count++;
    }
    fclose(file);
    printf("\nData loaded from file successfully!\n");
}

int main() {
    int choice;
    loadFromFile();
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

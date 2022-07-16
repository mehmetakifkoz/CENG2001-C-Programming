#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char *student_name;
    char *student_id;
    float midterm_grade;
    float final_grade;
    float course_grade; // 0.4 Midterm + 0.6 Final Exam
    int status;         // 1--> pass, 0 --> fail
};

int main()
{
    printf("*Grade Master by Mehmet Akif KOZ 192010010023\n");
    printf("*This program saves, finds, deletes a student record and shows basic statistics for a set of students.\n");
    printf("*Instructions: Type an operation and then type the required informations.\n");
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    struct student students[100];
    char student_name[20];
    char student_id[20];
    float midterm_grade = 0;
    float final_grade = 0;
    int index = 0;
    int number_of_students = 0;
    char input_id[20];

    while (1)
    {
        printf("Press \"q\" or \"Q\" to leave.\n");
        printf("Press \"a\" or \"A\" to add a new record.\n");
        printf("Press \"f\" or \"F\" to find a record.\n");
        printf("Press \"s\" or \"S\" to show basic statistics.\n");
        printf("Press \"d\" or \"D\" to delete a record.\n");
        printf("\n");

        printf("Operation: ");
        char c;
        scanf(" %c", &c);

        if (c == 'q' || c == 'Q')
        {
            return 0;
        }
        else if (c == 'a' || c == 'A')
        {
            number_of_students++;

            printf("Student Name: ");
            scanf(" %[^\n]", student_name);

            printf("Student ID: ");
            scanf(" %[^\n]", student_id);

            printf("Midterm Grade: ");
            scanf("%f", &midterm_grade);

            printf("Final Grade: ");
            scanf("%f", &final_grade);
            printf("\n");
            printf("--------------------------------------------------\n");
            printf("\n");

            students[index].student_name = calloc(strlen(student_name), sizeof(char));
            strcpy(students[index].student_name, student_name);

            students[index].student_id = calloc(strlen(student_name), sizeof(char));
            strcpy(students[index].student_id, student_id);

            students[index].midterm_grade = midterm_grade;
            students[index].final_grade = final_grade;
            students[index].course_grade = 0.4 * midterm_grade + 0.6 * final_grade;

            if (students[index].course_grade > 60)
            {
                students[index].status = 1;
            }
            else
            {
                students[index].status = 0;
            }
            index++;
        }
        else if (c == 'f' || c == 'F')
        {
            printf("Student ID: ");
            scanf(" %s", input_id);
            int found = 0;

            for (int i = 0; i < index; i++)
            {
                if (strcmp(input_id, students[i].student_id) == 0)
                {
                    printf("\n");
                    printf("Student Name: %s\n", students[i].student_name);
                    printf("Student ID: %s\n", students[i].student_id);
                    printf("Midterm Grade: %.2f\n", students[i].midterm_grade);
                    printf("Final Grade: %.2f\n", students[i].final_grade);
                    printf("Course Grade: %.2f\n", students[i].course_grade);
                    printf("Status: ");
                    if (students[i].status == 0)
                    {
                        printf("fail\n");
                    }
                    else if (students[i].status == 1)
                    {
                        printf("pass\n");
                    }

                    printf("\n");
                    printf("--------------------------------------------------\n");
                    printf("\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("The record does not exist.\n");
                printf("\n");
                printf("--------------------------------------------------\n");
                printf("\n");
            }
        }
        else if (c == 's' || c == 'S')
        {
            int number_of_passed = 0;
            int number_of_failed = 0;
            float average_course_grade = 0;

            for (int i = 0; i < number_of_students; i++)
            {
                if (students[i].status == 1)
                {
                    number_of_passed++;
                }
                else if (students[i].status == 0)
                {
                    number_of_failed++;
                }
            }

            for (int i = 0; i < number_of_students; i++)
            {
                average_course_grade += students[i].course_grade / number_of_students;
            }

            printf("Number of Passed Students = %d\n", number_of_passed);
            printf("Number of Failed Students = %d\n", number_of_failed);
            printf("Average Course Grade = %.2f\n", average_course_grade);
            printf("Number of Students = %d\n", number_of_students);
            printf("\n");
            printf("--------------------------------------------------\n");
            printf("\n");
        }
        else if (c == 'd' || c == 'D')
        {
            printf("Student ID: ");
            scanf(" %s", input_id);
            int found = 0;

            for (int i = 0; i < number_of_students; i++)
            {
                if (strcmp(input_id, students[i].student_id) == 0)
                {
                    for (int j = i; j < number_of_students; j++)
                    {
                        students[j] = students[j + 1];
                    }

                    printf("The record is deleted.\n");
                    printf("\n");
                    printf("--------------------------------------------------\n");
                    printf("\n");
                    found = 1;

                    number_of_students--;
                    index--;

                    break;
                }
            }

            if (found == 0)
            {
                printf("Invalid record to be deleted.\n");
                printf("\n");
                printf("--------------------------------------------------\n");
                printf("\n");
            }
        }
    }
}

/**     Hệ thống đánh giá sinh viên:
 * Tạo một struct để lưu trữ thông tin sinh viên: Tên, Mã số và Điểm.
 * Sử dụng union để lưu trữ điểm dưới dạng số hoặc chữ cái A, B, C, D, F.
 * Sử dụng con trỏ hàm để sắp xếp sinh viên theo Tên, Mã số hoặc Điểm.
 * 
 * 
 *      CODE SỬ DỤNG THƯ VIỆN
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//tạo union để lưu điểm dưới dạng số hoặc chữ
typedef union{
    char gradeChar;
    float gradeNum;
}Grade;


typedef enum{
    CHAR,
    NUMBER
}GradeType;


typedef struct{
    char name[50];
    char id[10];
    Grade grade;
    GradeType type;
}Student;

//sort by name

int compareByName(const Student *a, Student *b){
    const char *nameA = a->name;
    const char *nameB = b->name;

    while (*nameA && *nameB && *nameA == *nameB)
    {
        ++nameA;
        ++nameB;
    }
    return (int)(*nameA) - (int)(*nameB);
    
}


// sort by id
int compareByid(const Student *a, Student *b){
    const char *idA = a->id;
    const char *idB = b->id;

    while (*idA && *idB && *idA == *idB)
    {
        ++idA;
        ++idB;
    }
    return (int)(*idA) - (int)(*idB);
    
}

// sort by score
int compareByGrade(const Student *a, Student *b){

 if(a->type == NUMBER && b->type == NUMBER){
    return a->grade.gradeNum - b->grade.gradeNum;
 }else if(a->type == CHAR && b->type == CHAR){
    return (int)(a->grade.gradeChar) - (int)(b->grade.gradeChar);
 }else if(a->type == CHAR && b->type == NUMBER){
    return (int)(a->grade.gradeChar) - (int)(b->grade.gradeNum);
 }else{
    return (int)(a->grade.gradeNum) - (int)(b->grade.gradeChar);
 }
    
}


int sortStudents(Student students[], int size, int(compare)(const Student*, const Student*)){

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(compare(students + i, students + j) > 0){
              Student temp = students[i];
              students[i] = students[j];
              students[j] = temp;
            }
        }
        
    }
    
}

void printfStudents(Student *students, int n){
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s, ID: %s, Grade: ", students[i].name, students[i].id);
        if (students[i].type == CHAR)
        {
            printf("%c\n", students[i].grade.gradeChar);
        }else{
            printf("%f\n", students[i].grade.gradeNum);
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    
     Student students[] = {{.name = "Tuan", .id = "I101", .grade.gradeNum = 7.8, .type = NUMBER},
                           {.name = "Binh", .id = "I103", .grade.gradeChar = 'B', .type = CHAR},
                           {.name = "An", .id = "I107", .grade.gradeNum = 5.3, .type = NUMBER},
                           {.name = "Vy", .id = "I105", .grade.gradeChar = 'B', .type = CHAR}
                          };
    
    sortStudents(students, 4, compareByGrade);

    printfStudents(students, 4);

    return 0;
}

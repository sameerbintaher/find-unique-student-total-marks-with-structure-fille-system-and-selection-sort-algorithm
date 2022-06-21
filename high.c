#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Student{
    char name[100];
    int id;
    int marks;
};
struct Unique_Student{
    char name[100];
    int id;
    int total;
};

int main(){
    FILE *inputFile = fopen("input.txt", "r");
    if(inputFile == NULL){
        printf("Not Found\n");
        return 0;
    }
    FILE *outputFile = fopen("output.txt", "w");
    int n;
    fscanf(inputFile, "%d",&n);
    struct Student students[n];
    struct Unique_Student unique_students[n];
    int k=0;

    for (int i=0; i<n; i++){
        fscanf(inputFile,"%s %d %d", students[i].name, &students[i].id, &students[i].marks);
        bool found = false;
        for (int j=0; j<k; j++){
            if(unique_students[j].id == students[i].id){
                unique_students[j].total += students[i].marks;
                found = true;
            }
        }
        if(found == false){
            strcpy(unique_students[k].name, students[i].name);
            unique_students[k].id = students[i].id;
            unique_students[k].total = students[i].marks;
            k++;
        }
    }

    for (int i=0;i<k-1;i++) {
        for (int j=i+1;j<k;j++) {
            if(unique_students[i].total<unique_students[j].total){
                struct Unique_Student temp = unique_students[i];
                unique_students[i] = unique_students[j];
                unique_students[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < k;i++){
        fprintf(outputFile,"%s %d %d\n", unique_students[i].name, unique_students[i].id, unique_students[i].total);
    }
}
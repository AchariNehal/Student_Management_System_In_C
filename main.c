#include<stdio.h>
#include<stdlib.h>
struct student{
    int id;
    char name[50];
    float marks;
};
int main(){
    struct student s;
    while(1){
        int choice;
        printf("......MENU......\n");
        printf("1.Add Students \n");
        printf("2.Delete Students\n");
        printf("3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Add Student selected\n");
                    break;
            case 2:printf("Delete Student selected\n");
                    break;
            case 3:exit(0);
            default: printf("Invalid choice.Please try again!!\n");
        }

    }
    return 0;
}
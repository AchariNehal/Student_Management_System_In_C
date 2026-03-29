#include<stdio.h>
#include<stdlib.h>
struct student{
    int id;
    char name[50];
    float marks;
};
int main(){
    struct student s;
    FILE*fp;
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
                    fp=fopen("students.txt","a");
                    if(fp==NULL){
                        printf("File is not opened");
                        break;
                    }
                    printf("Enter id:");
                    scanf("%d",&s.id);
                    printf("Enter name:");
                    scanf("%s",s.name);
                    printf("Enter marks:");
                    scanf("%f",&s.marks);

                    fprintf(fp,"ID: %d\n",s.id);
                    fprintf(fp,"NAME: %s\n",s.name);
                    fprintf(fp,"MARKS: %f\n",s.marks);
                    fprintf(fp,"-------------------\n");
                    fclose(fp);
                    break;
            case 2:printf("Delete Student selected\n");
                    fp=fopen("students.txt","r");
                      if(fp==NULL){
                        printf("Error opening file\n");
                        break;
                    }
                    
                    char ch;
                    while((ch=fgetc(fp))!=EOF){
                    printf("%c",ch);
                    }
                    fclose(fp);
                    break;
            case 3:exit(0);
            default: printf("Invalid choice.Please try again!!\n");
        }

    }
    return 0;
}
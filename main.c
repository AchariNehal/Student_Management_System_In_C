#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int id;
    char name[50];
    float marks;
};
int main(){
    struct student s;
    FILE*fp1;
    FILE*fp2;
    while(1){
        int choice;
        printf("......MENU......\n");
        printf("1.Add Students \n");
        printf("2.Delete Students\n");
        printf("3.View Students\n");
        printf("4.Search a student\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Add Student selected\n");
                    fp1=fopen("students.txt","a");
                    if(fp1==NULL){
                        printf("File is not opened");
                        break;
                    }
                    printf("Enter id:");
                    scanf("%d",&s.id);
                    printf("Enter name:");
                    scanf(" %[^\n]", s.name);
                    printf("Enter marks:");
                    scanf("%f",&s.marks);

                    fprintf(fp1,"ID: %d\n",s.id);
                    fprintf(fp1,"NAME: %s\n",s.name);
                    fprintf(fp1,"MARKS: %.2f\n",s.marks);
                    fprintf(fp1,"-------------------\n");
                    fclose(fp1);
                    break;
            case 2:printf("Delete Student selected\n");
                    fp1=fopen("students.txt","r");
                    fp2=fopen("temp.txt","w");
                      if(fp1==NULL || fp2==NULL){
                        printf("Error opening file\n");
                        break;
                    }
                    char line[100];
                    int current_id;
                    int delete_id;
                    int found=0;
                    printf("Enter id to be deleted:");
                    scanf("%d",&delete_id);
                    while(fgets(line,sizeof(line),fp1)){
                        if(sscanf(line, "ID: %d", &current_id) == 1){
                            if(current_id == delete_id){
                                for(int i=0;i<3;i++)
                                    fgets(line,sizeof(line),fp1);
                                found=1;
                        }else{
                            fputs(line,fp2);
                            for(int i=0;i<3;i++){
                                fgets(line,sizeof(line),fp1);
                                fputs(line, fp2);
                            }
                        }
                    }
                }
                    if(!found){
                        printf("ID not found\n");
                    }else{
                        printf("Student deleted successfully\n");
                    }
                    fclose(fp1);
                    fclose(fp2);
                    remove("students.txt");
                   rename("temp.txt", "students.txt");
                    break;
            case 3:printf("-----STUDENTS_VIEWED-----\n");
                    printf("-------------------------\n");
                    fp1=fopen("students.txt","r");
                    if(fp1==NULL){
                        printf("File is not opened");
                        break;
                    }
                    char ch[100];
                    int empty = 1;
                    while(fgets(ch,sizeof(ch),fp1)){
                        printf("%s",ch);
                        empty = 0;
                    }
                    if(empty)
                        printf("No records to display\n");
                    fclose(fp1);
                    break;
            case 4:printf("Search Student selected\n");
                    fp1=fopen("students.txt","r");
                      if(fp1==NULL ){
                        printf("Error opening file\n");
                        break;
                    }
                     char sen[100];
                    int present_id;
                    int search_id;
                    int start=0;
                    printf("Enter id to be search:");
                    scanf("%d",&search_id);
                    printf("-----STUDENTS_FOUND-----\n");
                    while(fgets(sen,sizeof(sen),fp1)){
                        if(sscanf(sen, "ID: %d", &present_id) == 1)
                            if(present_id == search_id){
                                printf("%s",sen);
                                for(int i=0;i<3;i++){
                                fgets(sen,sizeof(sen),fp1);
                                    printf("%s",sen);
                                }
                                start=1;
                                break;
                        }
                        }
                    if(!start){
                        printf("ID not found\n");
                    }
                        fclose(fp1);
                        break;
                  
            case 5:exit(0);
            default: printf("Invalid choice.Please try again!!\n");
        }

    }
    return 0;
}







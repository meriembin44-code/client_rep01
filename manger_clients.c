#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//declaration of sructures
struct client{
int Id;
char name[30];
char first_name[30];
struct Date_of_birth{
int day;
int month;
int year;
}dob;
char address[100];
char Tel[12];
}client;
struct account{
int client_ID;
char Account_Type;
int balance;
bool blocked;
}account;

//show the menu for user
void menu(){
printf("\nWelcome to manager clients\n");
printf("\nyou have 5 options:");
printf("\n1.Add a new client.\n2.Find a client.\n3.Modify client data.\n4.Delete a client.\n5.Exit the program.\n");
};
//ask from user his infomationself
int informationself(){
printf("Enter the number of your ID:");
scanf("%d", &client.Id);
printf("Enter your name:");
scanf("%s",client.name);
printf("Enter your first name:");
scanf("%s", client.first_name);
printf("Enter your date of birth(../../....):");
scanf("%d/%d/%d",&client.dob.day, &client.dob.month, &client.dob.year );
printf("Enter your address:");
scanf("%s", client.address);
printf("Enter your telephone:");
scanf("%s", client.Tel);
};
void print_clients(struct client *account){
printf("name and first name : %p %p", account->name account->first_name);
};
int main(){
menu();
int choice;
printf("Please!Enter the number of  your choice:");
scanf("%d", &choice);
if (choice == 1){
informationself();
printf(".....It's Done....");
};
if (choice == 2){
print_clients();
};

return 0;
}

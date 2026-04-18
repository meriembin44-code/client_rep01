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
}Birthday;
char address[100];
char Tel[12];
}client;
struct account{
int client_ID;
char Account_Type;
int balance;
bool blocked;
};
struct account accounts[100];
int account_count = 0; 
//show the menu for user
void menu(){
printf("\nWelcome to manager clients\n");
printf("\nyou have 5 options:");
printf("\n1.Add a new client.\n2.Search a client.\n3.Modify client data.\n4.Delete a client.\n5.Exit the program.\n");
};
//function compt Age
bool age(int y){
return (2026 - y >= 18);
};
//function_Add_Account
int Add_Account(int client_id, char type){
if(account_count >= 100){
printf("Error: Maximum number of accounts reached (%d)\n", 100);
return -1;};
accounts[account_count].client_ID = client_id;
accounts[account_count].Account_Type = type;
accounts[account_count].balance = 0;
accounts[account_count].blocked = false;
account_count++;
return (account_count - 1); };
//function search
bool function_search( int *id_Gu){
for (int i = 0; i<account_count; i++){
if (accounts[i].client_ID == *id_Gu){
return true;};
};
return false;
};
//ask from user his infomationself
void  informationself(){
char type;
int id_Gu;
printf("Enter the number of your ID:");
scanf("%d", &client.Id);
printf("Enter your name:");
scanf("%s",client.name);
printf("Enter your first name:");
scanf("%s", client.first_name);
printf("Enter your date of birth(../../....):");
scanf("%d/%d/%d",&client.Birthday.day, &client.Birthday.month, &client.Birthday.year );
printf("Enter your address:");
scanf("%s", client.address);
printf("Enter your telephone:");
scanf("%s", client.Tel);
printf("Choose the type of account you want to add.\nIndividual (P), Minor (M), or Commercial (C);(P/M/C):");
scanf(" %c", &type);
if (type == 'P' || type == 'p'){
bool Age = age(client.Birthday.year);
if (Age == true){
printf("✅ Age condition satisfied (age >= 18)");
Add_Account(client.Id, type);
printf("\nAccount created successfully!\n");
}else{
printf("❌ Error: Individual account requires age >= 18.\nAccount not created."); 
};
}else{
if (type =='M' || type == 'm'){
printf("Enter guardian client ID: ");
scanf("%d", &id_Gu);
bool resul_S = function_search(&id_Gu);
if (resul_S == true){
Add_Account(client.Id, type);
printf("\nAccount created successfully!\n");
}else{
printf("❌ Error: Guardian has no bank account.\nAccount not created\n");};
}else{
if (type == 'C' || type =='c'){
Add_Account(client.Id, type);
printf("Account created successfully!\n");
}else{
printf("\nPlease enter (P/M/C)\n");
};};}; 

};
void print_clients(struct client *person){
printf("name and first name : %s %s", person->name, person->first_name);
};
int main(){
menu();
int choice;
printf("Please!Enter the number of  your choice:");
scanf("%d", &choice);
while (choice != 5){
if (choice == 1){
informationself();
//printf(".....It's Done....\n");
};
if (choice == 2){
int id_C;
printf("Enter ID of the client you want to search him:");
scanf("%d", &id_C);
bool resul_S = function_search( &id_C);
if (resul_S == true){
printf("We find him:");
print_clients(&client);
}else{
printf("We don't find him");};
};
printf("\n---------------------------------");
menu();
printf("Please!Enter the number of  your choice:");
scanf("%d", &choice);
};
printf("Exiting the program!\n");
return 0;
} 

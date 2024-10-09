#include "contact.h"

int main()
{
    //all function calls should be inside the main 

    //creating structure variable
    AddressBook addressBook; //datatype and variable name
    
    //initializing the address book
    initialize(&addressBook);
    int choice=0;
do
{

    // show the menu again and again until user selecting eit
    printf("................Menu................. \n");
    printf("\t1.Add contact\n\t2.Delete contact\n\t3.Search contact\n\t4.Edit contact\n\t5.Save contact\n\t6.List all contact\n\t7.EXIT\n");
    printf("......................................\n");
    printf("Enter the choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            createContact(&addressBook);
        break;
        case 2:
            deleteContact(&addressBook);
        break;
        case 3:
            searchContact(&addressBook);
        break;
        case 4:
            editContact(&addressBook);
        break;
        case 5:
            saveContact(&addressBook);
        break;
        case 6:
            listContacts(&addressBook);
        break;
        default:
            printf("oops!!! Invalid choice, choose bw 1 to 6 , TRY AGAIN ~*-*~\n");
        break;

    }

getchar();

}while(choice!=7);

}
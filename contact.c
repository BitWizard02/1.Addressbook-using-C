#include "contact.h"


void initialize(AddressBook *addressBook) 
{
    //fetch data dummy conatcts and load into address book
    addressBook ->contactCount=0;

    populate(addressBook);

}

void listContacts(AddressBook *addressBook) 
{
    printf("Sl.no:\tNAME\t\tPHONE\t\t\tEMAIL\n");
    printf("...............................................................\n");
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        Contact contact = addressBook -> contacts[i];
         printf("[%d]\t", i+1);
         printf("%s\t\t", contact.name);  
         printf("%s\t\t", contact.phone); 
         printf("%s\n",contact.email);
    }
    printf("...............................................................\n");
}

int phone1(AddressBook *addressBook,int i)
{
    //phone number
    while (1)
    {
        
        char phone[50]; 
        printf("Enter the Phone Number:");
        scanf("%s",phone);
        
        int len=strlen(phone);
        int count=0;
        int j;
        for (j = 0; j<addressBook->contactCount; j++)
        {
            if(strcmp(addressBook->contacts[j].phone,phone)==0)
            {
                printf("Entered number already exists\n");
                j=2222;
                break;

            }
        }
        if(j!=2222)
        {
        for(int k=0;k<len;k++)
        {
            if(phone[k]>='0' && phone[k]<='9')
            {
                count++;
            }
        }
        }

        if(count==10)
        {
            {
                strcpy(addressBook->contacts[i].phone,phone);
                break;
            }
        }
        else
        {
            printf("Invalid Phone Number\n");
        }
    
    }
    
}

int email1(AddressBook *addressBook,int i)
{
    //email creation...........
    char mail[30];
    char check[10]=".com";
    while(1)
    {
        
        printf("Enter the Email-ID :");
        scanf(" %s", mail);
    
        int a,z,j,count=0;
        int flage=0;
        int flag=0;
        int pole=0;
        
            for (j = 0; mail[j]!='@'; j++)
            {
                if((mail[j]>='a' && mail[j]<='z')||(mail[j]>='A' && mail[j]<='Z')||(mail[j]>='0' && mail[j]<='9'))
                {
                    flag=1;
                    break;
                }
            }
        
            for (j = 0; mail[j]!='\0'; j++)
            {
                if(mail[j]=='@')
                {
                    z=j;
                    count=1;
                    break;
                }
            }

            for (j = z; mail[j]!='.'; j++)
            {
                if((mail[j]>='a' && mail[j]<='z')||(mail[j]>='A' && mail[j]<='Z')||(mail[j]>='0' && mail[j]<='9'))
                {
                    pole=1;
                    break;
                }
            }

            int lencheck=strlen(check);
            int lenmail=strlen(mail);
            if(lenmail>lencheck)
            {
            if(strcmp(&mail[lenmail-lencheck], check)==0)
            {
            flage=1;
            }
            }



            if(count!=1 || flage!=1 || flag!=1 || pole!=1)
            {
                printf("_invalid email");
            }
            else{
                strcpy(addressBook->contacts[i].email,mail);
                //printf("valid email");
                break;
        
            }
            printf("\n");
    }
}
void createContact(AddressBook *addressBook) 
{       
    //name creation 
   int i=addressBook->contactCount++;
    char name[100];
    printf("Enter the Name:");
    scanf("%s",addressBook->contacts[i].name);

    
    phone1(addressBook,i);
    
    
    email1(addressBook,i);  
}

//search by phone 

    int phone(AddressBook *addressBook)
    {
        int i;
        char phone[20];
        int status;
        printf("enter the phone u want to search for");
        scanf(" %[^\n]",phone);
        for (i = 0; i < addressBook->contactCount; i++)
        {

            if (strcmp(addressBook->contacts[i].phone, phone) == 0)
            {
                status=1;
                break;
               
            }
           
       }
       if (status==1)
       {
                printf("......PHONE NUMBER FOUND.......\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                return i;
       }
        else 
        {
                printf("......number NOT FOUND.......\n");
                return -1;
        }
       
        
    }

//search by email 

    int email(AddressBook *addressBook)
    {
        int i;
        char email[50];
        int status=0;
        printf("enter the email u want to search for");
        scanf(" %[^\n]",email);
        for (i = 0; i < addressBook->contactCount; i++)
        {

            if (strcmp(addressBook->contacts[i].email, email) == 0)
            {
                status=1;
                
                break;
            }
        }
            if(status==1)
            {
                printf("......EMAIL FOUND.......\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                return i;
            }
            else
            {
                printf("......EMAIL NOT FOUND.......\n");
                return -1;
            }
        
    }


// search by name

    int name(AddressBook *addressBook)
    {
        int i,j,flag=0;
        char name[50];
        printf("enter the name u want to search for: ");
        scanf(" %[^\n]",name);
        for (i = 0; i < addressBook->contactCount; i++)
        {

            if (strcmp(addressBook->contacts[i].name, name) == 0)
            {
                printf("......NAME FOUND.......\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Phone Number: %s\n", addressBook->contacts[i].phone);
                printf("Email: %s\n", addressBook->contacts[i].email);
                printf("\n");
                flag++;
                j=i;            
            }


        }
        if(flag==1)
        {
            return j;
        }
        if(flag>1)
        {
            int choice;
            printf("multiple names are there \n");
            printf("enter choice:\n");
            printf("1 to search by ph.no\n 2.search by email:\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                phone(addressBook);

            }
            else if(choice==2)
            {
                email(addressBook);
            }
        }
        else
        {
            return -1;
        }
        
    }


void searchContact(AddressBook *addressBook) 
{
    int choice;
    printf("1.search by name\n2.search by phone number\n3.search by email\n");
    printf("Enter the choice you want to search for: ");
    scanf("%d", &choice);
    int i;
  
    switch (choice)
    {
        case 1:
            name(addressBook);
            break;
        case 2:
            phone(addressBook);
            break;
        case 3:
            email(addressBook);
            break;
    }

}

int edit1(AddressBook *addressBook,int i)
{
    int edit;
    printf(" ........EDIT:......\n\t1.name\n\t2.phone\n\t3.email\n ");
    scanf("%d",&edit);
        switch (edit)
        {
            case 1:
                printf("Enter the new name: ");
                scanf(" %[^\n]",addressBook->contacts[i].name);
            break;
            case 2:
                phone1(addressBook,i);
            break;
            case 3:
                email1(addressBook,i); 
            break;
        }
}
void editContact(AddressBook *addressBook) 
{
    printf("Edit contact through:\n");
    printf("\t1.Name\n\t2.Phone\n\t3.email\n");
    printf("Enter the choice you want to edit: ");
    int choice;
    int i;
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            i=name(addressBook);
            edit1(addressBook,i);
            
            break;
        case 2:
            i=phone(addressBook);
            edit1(addressBook,i);

            break;
        case 3:
            i=email(addressBook);
            edit1(addressBook,i);  
            break;
        }
    
}
int delete1(AddressBook *addressBook,int i)
{
    int j;
        if(i!=-1)
        {
        for(j=i;j<addressBook->contactCount;j++)
        {
            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
            strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
            
        }
        }
}
void deleteContact(AddressBook *addressBook) 
{
    printf("Delete the contact through:");
    printf("\n\t1.Name\n\t2.Phone\n\t3.email\n");
    printf("Enter the choice you want to delete: ");
    int choice;
    int i,j;
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
        int i=name(addressBook);
        delete1(addressBook,i);
        break;
        
        case 2:
        i=phone(addressBook);
        delete1(addressBook,i);
        break;
        
        case 3:
        i=email(addressBook);
        delete1(addressBook,i);
        break;
        
    }
    addressBook->contactCount--;
}



void saveContact(AddressBook *addressBook)
{
    FILE *fp=fopen ("addr_const.csv","w");
    int i;
    if(fp==NULL)
    {
        printf("file is not opened\n");
        return ;
    }
    // int contactCount = 0;
    // while (addressBook->contacts[contactCount].name != NULL)
    // {
    //     contactCount++;
    // }
    fprintf(fp,"#%d#",addressBook->contactCount);
    printf("CONTACTS=%d\n",addressBook->contactCount);
    for(i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"\n%s,%s,%s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
    return ;
}

#include "contact.h"
// Dummy contact data
// static Contact dummyContacts[] = {
//     {"John Doe", "1234567890", "john@example.com"},
//     {"Alice Smith", "0987654321", "alice@example.com"},
//     {"Bob Johnson", "1112223333", "bob@company.com"},
//     {"Carol White", "4445556666", "carol@company.com"},
//     {"David Brown", "7778889999", "david@example.com"},
//     {"Eve Davis", "6665554444", "eve@example.com"},
//     {"Frank Miller", "3334445555", "frank@example.com"},
//     {"Grace Wilson", "2223334444", "grace@example.com"},
//     {"Hannah Clark", "5556667777", "hannah@example.com"},
//     {"Ian Lewis", "8889990000", "ian@example.com"}
// };

void populate(AddressBook *addressBook)
{
    // int dummy_size = sizeof(dummyContacts) / sizeof(dummyContacts[0]);

    // for(int i=0;i< dummy_size; i++)
    // {
    //     addressBook-> contacts[i] = dummyContacts[i];
    //     addressBook->contactCount++;
    // }

    FILE *fp=fopen ("addr_const.csv","r");
    int i;
    if(fp==NULL)
    {
        printf("file is not opened\n");
        return ;
    }
    fscanf(fp,"#%d#\n",&addressBook->contactCount);
    printf("\tNUMBER OF CONTACTS=%d\n",addressBook->contactCount);
    for(i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
    return ;

} 


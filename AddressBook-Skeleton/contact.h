#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>

typedef struct {
    Contacts contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;



void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void populate(AddressBook *addressBook);
void saveContact(AddressBook *addressBook);
int name(AddressBook *addressBook);
int phone(AddressBook *addressBook);
int email(AddressBook *addressBook);
int phone1(AddressBook *addressBook,int i);
int email1(AddressBook *addressBook,int i);
int edit1(AddressBook *addressBook,int i);
int delete1(AddressBook *addressBook,int i);


#endif

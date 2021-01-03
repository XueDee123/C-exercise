#pragma once
#ifndef __ADDRESSBOOK_H__
#define __ADDRESSBOOK_H__

#include <iostream>
#include <string.h>
#include <string>

#define MaxContacts 10



typedef struct Contacts    //92×Ö½Ú
{
	char sex[3];
	int age;
	char tel[12];
	char name[20];
	char address[50]; 
}cons;
typedef struct AddressBook
{
	cons cons[MaxContacts];
	int current;
}addbook;


void init(addbook* ab);
void add(addbook* ab);
void display(addbook* ab);
void del(addbook* ab);
void select(addbook* ab);
void update(addbook* ab);
void clear(addbook* ab);
#endif // !__ADDRESSBOOK_H__


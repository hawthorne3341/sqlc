#ifndef CONSTANTS_H
#define CONSTANTS_H

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

#define TABLE_MAX_PAGES 100
#define PAGE_SIZE 4096

#endif

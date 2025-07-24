/*
 *Author : Abdallah Abdelbaset
 *Created : 14/7/2025 6:00 PM
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "PLATFORM.h"
enum Gender_Type
{
    Female = 0,
    Male // 1
};
enum Slots
{
    Slot1,
    Slot2,
    Slot3,
    Slot4,
    Slot5,
    Null_Slot
};
typedef struct Patient Patient;
struct Patient
{
    u16 ID;
    u8 Age;
    s8 name[50];
    enum Gender_Type Gender;
    enum Slots Slot;
    Patient *next;
};
#endif

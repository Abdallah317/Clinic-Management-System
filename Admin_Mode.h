/*
 *Author : Abdallah Abdelbaset
 *Created : 14/7/2025 6:00 PM
 */
#ifndef ADMIN_MODE_H
#define ADMIN_MODE_H
#include <stdio.h>
#include <stdlib.h>
#include "PLATFORM.h"
#include "Linked_List.h"
u8 Register_New_Patient(Patient **Head,Patient **Tail);
void Add_New_Patient(Patient **Head, Patient **Tail, s8 *name, u8 Age, enum Gender_Type gender, u16 ID);
void Edit_Patient_Record(Patient **Head);
u8 Reserve_Slot(Patient **Head, u8 *slots);
u8 Cancel_Reservation(Patient **Head,u8 *slots);
u8 Check_ID_Uniqueness(Patient **Head, u16 ID, Patient **Return_ID);
#endif

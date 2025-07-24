/*
 *Author : Abdallah Abdelbaset
 *Created : 14/7/2025 6:00 PM
 */
#include "Admin_Mode.h"
u8 Verify_Patient_Id()
{
    /*Code*/
}
u8 Register_New_Patient(Patient **Head, Patient **Tail)
{
    u8 counter = 3, Age = 0, gender_var = 1;
    s8 name[50] = {'\0'};
    u16 ID = 0;
    enum Gender_Type gender_enum = Male;
    Patient *Return_Id = NULL;
    printf("Enter Patient Name : ");
    scanf(" %49[^\n]", name);
    // gets(name);
    // printf("name : %s",name);
    /*using scanf("%s",name); will work only if your name doesn't have a whitespace
     (if i want to enter the first 2 names of patient i will need to insert whitespace after the first name!!)
     gets(name) will get string u enter including whitespaces till u enter 'enter' button
      scanf("%[^\n]",name); will work also  */
    printf("Enter Patient Gender (0 For Female,1 For Male) : ");
    scanf("%hhu", &gender_var);
    if (gender_var == 0 || gender_var == 1) /*its ok*/
    {
    }
    else
    {
        counter = 3;
        while (counter)
        {
            printf("Wrong Input For Gender Try Again (0 For Female,1 For Male) : ");
            scanf("%hhu", &gender_var);
            if (gender_var == 0 || gender_var == 1)
            {
                break; // exit from loop
            }
            if (counter == 4)
            {
                printf("You Entered Wrong Input For Gender For 3 Times.Program Exiting...\n");
                return 0;
            }
            counter++;
        }
    }
    gender_enum = (enum Gender_Type)gender_var;
    printf("Enter Patient Age : ");
    scanf("%hhu", &Age);
    printf("Enter Patient ID : ");
    scanf("%hu", &ID);
    if (Check_ID_Uniqueness(Head, ID, &Return_Id) == 1) /*ID Entered Is Unique*/
    {
    }
    else
    {
        printf("ID %hu Already Taken For Patient Name : %s ,Patient Age : %hhu", Return_Id->ID, Return_Id->name, Return_Id->Age);
        if (Male == (Return_Id->Gender))
        {
            printf(",Patient Gender : Male \n");
        }
        else
        {
            printf(",Patient Gender : Female \n");
        }

        counter = 3;
        while (counter)
        {
            printf("Enter Another ID : ");
            scanf("%hu", &ID);
            if (Check_ID_Uniqueness(Head, ID, &Return_Id) == 1) /*ID Entered Is Unique*/
            {
                break; // exit from loop
            }
            else if (counter == 4)
            {
                printf("You Entered Reserved ID For 3 Times.Program Exiting...\n");
                return 0;
            }
            counter++;
        }
    }
    Add_New_Patient(Head, Tail, name, Age, gender_enum, ID);
    return 1;
}
void Add_New_Patient(Patient **Head, Patient **Tail, s8 *name, u8 Age, enum Gender_Type gender, u16 ID)
{
    Patient *temp = (Patient *)malloc(sizeof(Patient));
    if (temp == NULL)
    {
        printf("There's No Enough Space At Heap To Add New Patient !!\n");
    }
    else
    {
        temp->Gender = gender;
        temp->ID = ID;
        temp->Age = Age;
        temp->Slot = Null_Slot;
        u8 i = 0;
        while (*(name + i))
        {
            (temp->name)[i] = name[i];
            i++;
        }
        (temp->name)[i] = '\0';
        temp->next = NULL;
        if (*Tail == NULL) /*empty list if u check for *Head its same*/
        {
            *Tail = temp;
            *Head = temp;
        }
        else
        {
            (*Tail)->next = temp;
            *Tail = temp;
        }
    }
}
void Edit_Patient_Record(Patient **Head)
{
    u8 Age = 0, gender_var = 1, i = 0,Status_ID=0;
    s8 name[50] = {'\0'};
    u16 ID = 0;
    enum Gender_Type gender_enum = Male;
    Patient *Return_Id = NULL;

    printf("Enter Patient ID : ");
    scanf("%hu", &ID);
    Status_ID=Check_ID_Uniqueness(Head, ID, &Return_Id);
    if(Status_ID==0 || Status_ID==2) //ID Is Exist!
    {
        printf("ID %hu For Patient Name : %s , Patient Age : %hhu ", Return_Id->ID, Return_Id->name, Return_Id->Age);
        if (Male == (Return_Id->Gender))
        {
            printf(", Patient Gender : Male \n");
        }
        else
        {
            printf(", Patient Gender : Female \n");
        }

        printf("Enter New Name : ");
        scanf(" %49[^\n]", name);
        printf("Enter New Age : ");
        scanf("%hhu", &Age);
        printf("Enter New Gender (0 For Female,1 For Male) : ");
        scanf("%hhu", &gender_var);
        gender_enum = (enum Gender_Type)gender_var;

        // update data
        i = 0;
        while (*(name + i))
        {
            Return_Id->name[i] = name[i];
            i++;
        }
        Return_Id->name[i] = '\0';
        Return_Id->Age = Age;
        Return_Id->Gender = gender_enum;

        printf("Edits Saved Successfully\n");
    }
    else
    {
        printf("ID %hu Does not Exist !!\n", ID);
    }
}
u8 Check_ID_Uniqueness(Patient **Head, u16 ID, Patient **Return_ID)
{
    u8 status = 1;
    *Return_ID = NULL;
    if (*Head == NULL) /*List Is Empty No Need TO Check ID Uniqueness!!*/
    {
        status = 1;
        *Return_ID = NULL;
    }
    else
    {
        Patient *temp = *Head;
        while (temp)
        {
            if (temp->ID == ID)
            {
                status = 0;
                *Return_ID = temp;
                if ((*Return_ID)->Slot != Null_Slot)
                {
                    status = 2; /*we will need it for reservation !!*/
                }
                break;
            }
            temp = temp->next;
        }
    }
    /*will return 1 for unique ID*/
    return status;
}
u8 Reserve_Slot(Patient **Head, u8 *slots)
{
    u8 slot_select = 0, ID_Status = 0, counter = 3;
    u16 ID = 0;
    Patient *Return_Id = NULL;

    printf("--------------Available Slots--------------\n");
    for (u8 i = 1; i <= 5; i++)
    {
        if (i == 1 && !slots[0])
        {
            printf("1- 2:00 PM To 2:30 PM\n");
        }
        else if (i == 2 && !slots[1])
        {
            printf("2- 2:30 PM To 3:00 PM\n");
        }
        else if (i == 3 && !slots[2])
        {
            printf("3- 3:00 PM To 3:30 PM\n");
        }
        else if (i == 4 && !slots[3])
        {
            printf("4- 4:00 PM To 4:30 PM\n");
        }
        else if (i == 5 && !slots[4])
        {
            printf("5- 4:30 PM To 5:00 PM\n");
        }
    }

    printf("Enter A Choice To Reserve A Slot From The Above Menu : ");
    scanf("%hhu", &slot_select);

    if (slot_select < 1 || slot_select > 5)
    {
        printf("Invalid slot selection!\n");
        return 1;
    }

    printf("Enter Patient ID : ");
    scanf("%hu", &ID);

    ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);

    // Handle ID verification
    if (ID_Status == 1) // ID doesn't exist
    {
        counter = 3;
        while (counter)
        {
            printf("The entered ID does not exist. Please enter a different ID : ");
            scanf("%hu", &ID);
            ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);

            if (ID_Status == 0 || ID_Status == 2)
            {
                if (ID_Status == 2)
                {
                    printf("Patient Already Has Reserved A Slot !!\n");
                    return 1; // Continue operation
                }
                break;
            }

            if (--counter == 0)
            {
                printf("You have entered a non-existent ID three times.\n");
                return 0; // Terminate operation
            }
        }
    }
    else if (ID_Status == 2) // ID exists with reservation
    {
        printf("Patient Already Has Reserved A Slot !!\n");
        return 1; // Continue operation
    }

    // Assign the selected slot
    switch (slot_select)
    {
    case 1:
        Return_Id->Slot = Slot1;
        slots[0] = 1;
        break;
    case 2:
        Return_Id->Slot = Slot2;
        slots[1] = 1;
        break;
    case 3:
        Return_Id->Slot = Slot3;
        slots[2] = 1;
        break;
    case 4:
        Return_Id->Slot = Slot4;
        slots[3] = 1;
        break;
    case 5:
        Return_Id->Slot = Slot5;
        slots[4] = 1;
        break;
    }

    printf("Slot reserved successfully!\n");
    return 1; // Continue operation
}
u8 Cancel_Reservation(Patient **Head, u8 *slots)
{

    u8 ID_Status = 0, counter = 3;
    u16 ID = 0;
    Patient *Return_Id = NULL;
    printf("Enter Patient ID : ");
    scanf("%hu", &ID);
    ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
    if (ID_Status == 0)
    {
        printf("ID %hu Has not Reserved any Slot!\n", ID);
        printf("Enter Another ID : ");
        scanf("%hu", &ID);
        ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
        counter = 3;
        while (counter)
        {
            if (ID_Status == 2)
            {
                break;
            }
            else if (ID_Status == 0)
            {
                printf("ID %hu Has not Reserved any Slot!\n", ID);
                printf("Enter Another ID : ");
                scanf("%hu", &ID);
                ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            }
            else // ID_Status=1
            {
                printf("ID %hu not registered !\n", ID);
                printf("Enter Another ID : ");
                scanf("%hu", &ID);
                ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            }

            if (counter == 4)
            {
                printf("You have entered a wrong ID three times. The program will now exit.\n");
                return 0;
            }
            counter++;
        }
    }
    else if(ID_Status==1)
    {
        printf("ID %hu not registered !\n", ID);
        printf("Enter Another ID : ");
        scanf("%hu", &ID);
        ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
        counter = 3;
        while (counter)
        {
            if (ID_Status == 2)
            {
                break;
            }
            else if (ID_Status == 0)
            {
                printf("ID %hu Has not Reserved any Slot!\n", ID);
                printf("Enter Another ID : ");
                scanf("%hu", &ID);
                ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            }
            else // ID_Status=1
            {
                printf("ID %hu not registered !\n", ID);
                printf("Enter Another ID : ");
                scanf("%hu", &ID);
                ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            }

            if (counter == 4)
            {
                printf("You have entered a wrong ID three times. The program will now exit.\n");
                return 0;
            }
            counter++;
        }
    }
    switch (Return_Id->Slot)
    {
    case Slot1:
        slots[0] = 0;
        Return_Id->Slot = Null_Slot;
        break;
    case Slot2:
        slots[1] = 0;
        Return_Id->Slot = Null_Slot;
        break;
    case Slot3:
        slots[2] = 0;
        Return_Id->Slot = Null_Slot;
        break;
    case Slot4:
        slots[3] = 0;
        Return_Id->Slot = Null_Slot;
        break;
    case Slot5:
        slots[4] = 0;
        Return_Id->Slot = Null_Slot;
        break;
    }
    printf("Reservation Has Canceled Successfully!\n");
}

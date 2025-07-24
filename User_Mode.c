/*
 *Author : Abdallah Abdelbaset
 *Created : 14/7/2025 6:00 PM
 */
#include "User_Mode.h"
void View_Reservations(Patient **Head)
{
    u8 counter=0;
    Patient *temp=*Head;
    if (*Head == NULL)
    {
        printf("No Data To Be Shown,Please Add Patients Data From Admin Mode.\n");
    }
    else
    {
        while (temp)
        {
            switch (temp->Slot)
            {
            case Slot1:
                printf("Patient ID : %hu , Slot Selected : 2:00 PM To 2:30 PM\n", temp->ID);
                counter++;
                break;
            case Slot2:
                printf("Patient ID : %hu , Slot Selected : 2:30 PM To 3:00 PM\n", temp->ID);
                counter++;
                break;
            case Slot3:
                printf("Patient ID : %hu , Slot Selected : 3:00 PM To 3:30 PM\n", temp->ID);
                counter++;
                break;
            case Slot4:
                printf("Patient ID : %hu , Slot Selected : 4:00 PM To 4:30 PM\n", temp->ID);
                counter++;
                break;
            case Slot5:
                printf("Patient ID : %hu , Slot Selected : 4:30 PM To 5:00 PM\n", temp->ID);
                counter++;
                break;
            case Null_Slot:
                break;
            default:
                break;
            }
            temp = temp->next;
        }
        if(counter==0)
        {
            printf("No Slots Is Reserved!\n");
        }
    }
}
void View_Patient_Record(Patient **Head)
{
    Patient *Return_Id = NULL;
    u8 ID_Status=0,counter=0;
    u16 ID=0;
    printf("Enter Patient ID : ");
    scanf("%hu", &ID);
    ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
    if (ID_Status == 2 || ID_Status == 0)
    {
        printf("Patient Name : %s , Patient Age : %hhu ", Return_Id->name, Return_Id->Age);
        if (Male == (Return_Id->Gender))
        {
            printf(", Patient Gender : Male \n");
        }
        else
        {
            printf(", Patient Gender : Female \n");
        }
    }
    else /*ID_Status=1*/
    {

        counter = 3;
        printf("ID %hu not registered !\n", ID);
        printf("Enter Another ID : ");
        scanf("%hu", &ID);
        while (counter)
        {
            ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            if (ID_Status == 0 || ID_Status == 2)
            {
                printf("Patient Name : %s , Patient Age : %hhu ", Return_Id->name, Return_Id->Age);
                if (Male == (Return_Id->Gender))
                {
                    printf(", Patient Gender : Male \n");
                }
                else
                {
                    printf(", Patient Gender : Female \n");
                }
				break;
            }
            else /*ID_Status=1*/
            {
                printf("ID %hu not registered !\n", ID);
                printf("Enter Another ID : ");
                scanf("%hu", &ID);
                ID_Status = Check_ID_Uniqueness(Head, ID, &Return_Id);
            }
            if (counter == 4)
            {
                printf("You have entered a non-existent ID three times. The program will now exit.\n");
                return;
            }

            counter++;
        }
    }
}

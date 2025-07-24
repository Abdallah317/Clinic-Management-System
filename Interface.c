#include "Interface.h"
void interface(Patient **Head, Patient **Tail)
{
    // varaible defintions +initializations !
    u8 flag = 1, Mode_Selection = 0, Internal_Selection = 0, counter = 3, Age = 0, gender_var = 1, slot_select = 0, ID_Status = 0, i = 0;
    s8 name[50] = {'\0'};
    u8 slots[5] = {0};
    u16 password = 0, ID = 0;
    enum Gender_Type gender_enum = Male;
    enum Slots Slot_Var = Null_Slot;
    Patient *Return_Id = NULL;
    Patient *temp = *Head;
    while (flag)
    {
        printf("-------------------Clinic Management System-------------------\n");
        printf("1-Admin Mode\n");
        printf("2-User Mode\n");
        printf("3-Exit\n");
        printf("Please Enter A Choice From Above Menu : ");
        scanf("%hhu", &Mode_Selection); // from web search found that %hhu for u8 ,%hu for u16 , %hhi for s8 ,%hi for s16
        switch (Mode_Selection)
        {
        case 1:
            // Admin Mode
            printf("------------------------Admin Mode------------------------\n");
            printf("Please Enter Your Password : ");
            scanf("%hu", &password);
            if (password == Default_Password)
            {
            }
            else
            {
                counter = 3;
                while (counter)
                {
                    printf("Password Is Wrong , Try Again : ");
                    scanf("%hu", &password);
                    if (password == Default_Password)
                    {
                        break; // exist from while loop!!
                    }
                    else if (counter == 4)
                    {
                        printf("You Entered Wrong Password For 3 Times .Prorgram Exiting....\n");
                        return; // exist from program
                    }
                    counter++;
                }
            }
            printf("1-Add New Patient Record\n");
            printf("2-Edit Patient Record\n");
            printf("3-Reserve A Slot With The Doctor\n");
            printf("4-Cancel Reservation\n");
            printf("Please Enter A Choice From Above Menu : ");
            scanf("%hhu", &Internal_Selection);
            switch (Internal_Selection)
            {
            case 1:
                if (Register_New_Patient(Head, Tail) == 0)
                {
                    return;
                }
                else
                {
                    // Registered Successfully!->Do Nothing
                }
                break;
            case 2:
                Edit_Patient_Record(Head);
                break;
            case 3:
                if (Reserve_Slot(Head, slots) == 0)
                {
                    return; // Exit if function returns 0
                }
                break;
            case 4:
                if(Cancel_Reservation(Head, slots)==0)
				{
					return;
				}
                break;
            default:
                break;
            }
            break;
        case 2:
            // User Mode
            printf("-------------------------User Mode------------------------\n");
            printf("1-View Patient Record\n");
            printf("2-View Today's Reservations\n");
            printf("Please Enter A Choice From Above Menu : ");
            scanf("%hhu", &Internal_Selection);
            switch (Internal_Selection)
            {
            case 1:
                View_Patient_Record(Head);
                break;
            case 2:
                View_Reservations(Head);
                break;
            default:
                break;
            }
            break;
        case 3:
            flag = 0;
            break;
        default:
            printf("invalid choice !!\n");
            break;
        }
    }
}

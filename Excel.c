#include "Excel.h"
void Add_New_Patient_To_CSV_File(Patient *New_Patient)
{
    static u8 state = 0;
    FILE *Patients_Data;
    if (state == 0) // first time
    {
        Patients_Data = fopen("Patients_Data.csv", "w"); /* "w" >>Open for writing in text mode.
        If the file exists, its contents are overwritten.
        //If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file.*/
        if (Patients_Data != NULL) // file opened successfully !
        {
            fprintf(Patients_Data, "ID,Name,Gender,Age,Slot_Status\n");
            fprintf(Patients_Data, "%hu,%s,", New_Patient->ID, New_Patient->name);
            if (New_Patient->Gender == Male)
            {
                fprintf(Patients_Data, "Male,");
            }
            else
            {
                fprintf(Patients_Data, "Female,");
            }
            fprintf(Patients_Data, "%hhu,", New_Patient->Age);
            switch (New_Patient->Slot)
            {
            case Slot1:
                fprintf(Patients_Data,"2:00 PM To 2:30 PM\n");
                break;
            case Slot2:
                fprintf(Patients_Data,"2:30 PM To 3:00 PM\n");
                break;
            case Slot3:
                fprintf(Patients_Data,"3:00 PM To 3:30 PM\n");
                break;
            case Slot4:
                fprintf(Patients_Data,"4:00 PM To 4:30 PM\n");
                break;
            case Slot5:
                fprintf(Patients_Data,"4:30 PM To 5:00\n");
                break;
           case Null_Slot:
                fprintf(Patients_Data,"NULL_Slot\n");
           break;
           }
            state++;
        }
        else
        {
            printf("Error In Opening This File !!\n");
        }
    }
    else
    {

        Patients_Data=fopen("Patients_Data.csv", "a"); // append!
        if (Patients_Data != NULL) // file opened successfully !
        {
            fprintf(Patients_Data, "%hu,%s,", New_Patient->ID, New_Patient->name);
            if (New_Patient->Gender == Male)
            {
                fprintf(Patients_Data, "Male,");
            }
            else
            {
                fprintf(Patients_Data, "Female,");
            }
            fprintf(Patients_Data, "%hhu,", New_Patient->Age);
            switch (New_Patient->Slot)
            {
            case Slot1:
                fprintf(Patients_Data,"2:00 PM To 2:30 PM\n");
                break;
            case Slot2:
                fprintf(Patients_Data,"2:30 PM To 3:00 PM\n");
                break;
            case Slot3:
                fprintf(Patients_Data,"3:00 PM To 3:30 PM\n");
                break;
            case Slot4:
                fprintf(Patients_Data,"4:00 PM To 4:30 PM\n");
                break;
            case Slot5:
                fprintf(Patients_Data,"4:30 PM To 5:00\n");
                break;
           case Null_Slot:
                fprintf(Patients_Data,"NULL_Slot\n");
           break;
           }
            state++;
        }
        else
        {
            printf("Error In Opening This File !!\n");
        }
    }

    if(fclose(Patients_Data)==0) //file closed successfully !
    {

    }
    else
    {
        printf("Error While Closing File !!\n");
    }
}

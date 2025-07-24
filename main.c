#include <stdio.h>
#include "Interface.h"
#include "Excel.h"
int main(void)
{
	Patient *Head=NULL, *Tail=NULL;
	interface(&Head,&Tail);
	Patient *temp=Head;
	while(temp)
    {
        Add_New_Patient_To_CSV_File(temp);
        temp=temp->next;
    }
    if(Head!=NULL)
    printf("Last Update Of Patients Data Saved Into CSV FILE !!\n");
    return 0;
}

#include "FlashMemory.h"

int main(){
    char *data = "hello FLASH from ControllerTech\
			  This is a test to see how many words can we work with";

    // uint32_t data2[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};

    uint32_t Rx_Data[30];

    char string[100];

    // int number = 123;

    // float val = 123.456;

    // float RxVal;

    // Flash_Write_Data(0x080FF800 , (uint32_t *)data2, 9);
    // Flash_Read_Data(0x080FF800 , Rx_Data, 10);


    int numofwords = (strlen(data)/4)+((strlen(data)%4)!=0);
    Flash_Write_Data(0x080FF800 , (uint32_t *)data, numofwords);
    Flash_Read_Data(0x080FF800 , Rx_Data, numofwords);
    // Convert_To_Str(Rx_Data, string);


    // Flash_Write_NUM(0x08005C10, number);
    // RxVal = Flash_Read_NUM(0x08005C10);

    // Flash_Write_NUM(0x08012000, val);
    // RxVal = Flash_Read_NUM(0x08012000);
}
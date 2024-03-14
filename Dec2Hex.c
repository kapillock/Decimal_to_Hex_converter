#include <stdio.h>
#include <string.h>
unsigned char hex_buff[2];//This variable must be global.
/*
 *@brf : Decimal to Hex value converter.
 *@arg : long int
 *@ret : char *
 *@exp : strcpy(hex_str,DEC2HEX(decimalNum)); 
 *@INP : decimalNum=43981 
 *@OUT : printf("HEX output: %.2X %.2X \n\r", hex_str[1], hex_str[0]);
       : HEX output: AB CD
 */
char * DEC2HEX(unsigned long int decimalNum)
{

    unsigned char buff[4];
    unsigned char buff_len=0;
    unsigned char i=0;
    sprintf(buff,"%lX",decimalNum);
    buff_len = strlen(buff);
       
    
    for(i=0;i<buff_len;i++)
    {
        if((buff[i] >= 48) && (buff[i] <= 57))  buff[i] -= 48;
        else if((buff[i] >= 65) && (buff[i] <= 70)) buff[i] -= 55;
    }
    if(buff_len == 4) 
    {
        hex_buff[1] = buff[1]|(buff[0]<<4);
        hex_buff[0] = buff[3]|(buff[2]<<4);
    }
    else if(buff_len == 3)
    {
        hex_buff[1] = buff[0];
        hex_buff[0] = buff[2]|(buff[1]<<4);
    }
    else if(buff_len == 2)
    {
        hex_buff[1] = 0x00;
        hex_buff[0] = buff[1]|(buff[0]<<4);
    }
    else if(buff_len == 1)
    {
        hex_buff[1] = 0x00;
        hex_buff[0] = buff[0];
    }
    else 
    {
        hex_buff[1] = 0x00;
        hex_buff[0] = 0x00;
    }
    return hex_buff;
}


int main()
{
    unsigned char hex_str[2];

    strcpy(hex_str,DEC2HEX(43981));

    printf("HEX output : %.2X %.2X \n\r", hex_str[1], hex_str[0]);


    return 0;
}

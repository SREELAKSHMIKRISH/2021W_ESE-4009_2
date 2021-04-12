#include "./common_dht_read.h"    //including the header file delay function declarations
#include "./common_dht_read.c"   //including the header file containing the delay function
#include "./bbb_mmio.h"          //including the header files for gpio function declarations in the memory
#include "./bbb_mmio.c"          //including the header files for th gpio functions in the memory
#include "./bbb_dht_read.h"      //including the header files for the function declarations
#include "./bbb_dht_read.c"      //including the header files for the functions read by the sensor
#include<stdio.h>                //including the header file for the printf function
#include<unistd.h>               //including the header file for the delay 
void main()
{
int r;                          //variable to store return value of the bbb_dht_read function
float humid=0.00,temp=0.00;     //declaring humidity and temperature variables
while(1)
{
r=bbb_dht_read(11,1,15,&humid,&temp); //variable for calling the read function 0 on success else a negative value 
printf("%d\n",r);                     //printing the return value
if (r==0)                             //check whether the sensor reading is success
{
printf("success");
}
printf("%f %f \n",humid,temp);        //printing the temperature and humidity values 
sleep(2);                             //delay of 2 seconds to refresh the whole process
}
}

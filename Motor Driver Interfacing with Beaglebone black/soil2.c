#include<stdio.h> //Used for standard input and output
#include<stdlib.h> //header file for standard library
#include<unistd.h> //for the delay generating functions
#include<string.h> // Include header file having string functions
void main()
{
    FILE *fp; //create a file pointer
    char buf[3]; //declaring a string
    char zero[3]="0"; //storing the value 0 in a string 
    //system("sudo su"); //to access root function
    system("echo \"44\" >/sys/class/gpio/export 2>/dev/null"); // select beaglebone pin P8_12
    usleep(100);
    system("echo \"45\" >/sys/class/gpio/export 2>/dev/null");  // Select beaglebone pin P8_11
    usleep(100);
    system("echo \"46\" >/sys/class/gpio/export 2>/dev/null");   // select beaglebone pin P8_16
    usleep(100);
    system("echo \"47\" >/sys/class/gpio/export 2>/dev/null");  // Select beaglebone pin P8_12
    usleep(100);
    system("echo \"out\" >/sys/class/gpio/gpio44/direction");   // Set direction of P8_12 as Output
    usleep(100);
    system("echo \"in\" >/sys/class/gpio/gpio45/direction");    // Set direction of P8_11 as Input
    usleep(100);
    system("echo \"out\" >/sys/class/gpio/gpio46/direction");   // Set direction of P8_16 as Output
    usleep(100);
    system("echo \"out\" >/sys/class/gpio/gpio47/direction");    // Set direction of P8_15 as Input
    usleep(100);
    system("echo \"1\" >/sys/class/gpio/gpio47/value");          //set enable
    usleep(100);
    system("echo \"0\" >/sys/class/gpio/gpio46/value");          //to set input 2 as logic low
    usleep(100);
while(1)
{
  fp=popen("cat /sys/class/gpio/gpio45/value","r");      //Store the value of input status pin of P8_11
  fscanf(fp,"%s",buf);      //Store the value from the file to a varible
if(strncmp(buf,zero,1)==0) // Strncmp is a function to compare two string and it returns zero if two strings are equal
{
      printf("Driver OFF - Soil is Wet \n"); //to print output
      system("echo \"0\" >/sys/class/gpio/gpio44/value");   //Drive the output pin P8_12 to HIGH
      sleep(1);
}
else
{
      printf("Driver ON - Soil is Dry \n"); //to print the output
      system("echo \"1\" >/sys/class/gpio/gpio44/value");   //Drive the output pin P8_12 to LOW
      sleep(1); //to make the processor wait for 1 second
}
fclose(fp); //close the file which is pointed by an open file pointer.
}
}
 

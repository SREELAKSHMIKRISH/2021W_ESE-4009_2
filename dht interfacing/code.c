#include "./common_dht_read.h"
#include "./common_dht_read.c"
#include "./bbb_mmio.h"
#include "./bbb_mmio.c"
#include "./bbb_dht_read.h"
#include "./bbb_dht_read.c"
#include<stdio.h>
#include<unistd.h>
void main()
{
int r;
float humid=0.00,temp=0.00;
while(1)
{
r=bbb_dht_read(11,1,15,&humid,&temp);
printf("%d\n",r);
if (r==0)
{
printf("success");
}
printf("%f %f \n",humid,temp);
sleep(2);
}
}

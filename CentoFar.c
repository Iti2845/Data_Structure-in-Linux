#include<stdio.h>

int main()
{
    //Declare Variables
    
     float far,cel;
     printf("Enter temperature in celsius: ");
     scanf("%f",&cel);

     //Calculate Temperature
     
     far = ((9*cel)/5)+32;
     printf("The temperature in farenhite is : %f",far);


}

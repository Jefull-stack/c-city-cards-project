#include <stdio.h>

int main() {

    // Declare variables to store user input
   char c;
   char e;
   char d [20];
   char f [20];
   char city1[20];
   char city2[20];
   int populacao1;
   int populacao2;
   float areakm2_1;
   float areakm2_2;
   float pib1;
   float pib2;
   int numeropontosturisticos1, numeropontosturisticos2;
   
   // Prompt the user for input and read the values

    printf ("Enter one character between a-h:\n");
    scanf(" %c", &c); 
   
    printf ("Enter the second character: between a-h:\n");
    scanf(" %c", &e);
   
    printf ("Enter the first card number between A1, B2, C3... H8: ");
    scanf("%19s", d);
    
    printf ("Enter the second card number between A1, B2, C3... H8: ");
    scanf("%19s", f);
    
    printf ("Enter the name of the first city: ");
    scanf("%19s", city1);
    
    printf ("Enter the second city name: ");
    scanf("%19s", city2);

    printf ("Enter the population of the first city: ");
    scanf("%d", &populacao1);
    
    printf ("Enter the population of the second city: ");
    scanf("%d", &populacao2);

    
    printf ("Enter the area of the first city in km2: ");
    scanf("%f", &areakm2_1);
    
    printf ("Enter the area of the second city in km2: ");
    scanf("%f", &areakm2_2);
    
    printf ("Enter the pib of the first city: ");
    scanf("%f", &pib1);
    
    printf ("Enter the pib of the second city: ");
    scanf("%f", &pib2);
    
    printf ("Enter the number of tourist attractions in the city: ");
    scanf("%d", &numeropontosturisticos1);
   
    printf ("Enter the number of tourist attractions in the second city: ");
    scanf("%d", &numeropontosturisticos2);
    printf ("-----------------------------\n"); //print a separator line for better readability of the output

  //print the collected information of the first city
   printf ("Card letter: %c\n", c);
   printf ("Card number: %s\n", d);
   printf ("City name: %s\n", city1);
   printf ("Population: %d\n", populacao1);
   printf ("Area in km2: %.2f\n", areakm2_1);
   printf ("PIB: %.2f\n", pib1);
   printf ("Number of tourist attractions: %d\n", numeropontosturisticos1);
   printf ("-----------------------------\n");
   //print the collected information of the second city
   printf ("Second card letter: %c\n", e);
   printf ("Second card number: %s\n", f);
   printf ("Name of second city: %s\n", city2);
   printf ("Population of city 2: %d\n", populacao2);
   printf ("Area of city 2: %.2f\n", areakm2_2);
   printf ("PIB of city 2: %.2f\n", pib2);
   printf ("Number of tourist attractions in city 2: %d\n", numeropontosturisticos2);

    return 0;
}
#include <stdio.h>

int main() {

 // Declare variables to store user input
   char c, e;
   char d [20], f [20];
   char city1[20], city2[20];
   unsigned long int population1, population2;
   double areaKm2_1, areaKm2_2;
   double gdp1, gdp2;
   int numberOfTouristPoints1, numberOfTouristPoints2;

 // Prompt the user for input and read the values

    printf ("Enter one character between a-h:");
    scanf(" %c", &c);

    printf ("Enter the second character: between a-h:");
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
    scanf("%lu", &population1);

    printf ("Enter the population of the second city: ");
    scanf("%lu", &population2);

    printf ("Enter the area of the first city in km2: ");
    scanf("%lf", &areaKm2_1);

    printf ("Enter the area of the second city in km2: ");
    scanf("%lf", &areaKm2_2);

    printf ("Enter the GDP of the first city in full: ");
    scanf("%lf", &gdp1);

    printf ("Enter the GDP of the second city in full: ");
    scanf("%lf", &gdp2);

    printf ("Enter the number of tourist attractions in the first city: ");
    scanf("%d", &numberOfTouristPoints1);

    printf ("Enter the number of tourist attractions in the second city: ");
    scanf("%d", &numberOfTouristPoints2);
    printf ("-----------------------------\n"); //print a separator line for better readability of the output

 // Calculate population density and GDP per capita for both cities
 double populationDensity1 = (double)population1 / areaKm2_1;
 double populationDensity2 = (double)population2 / areaKm2_2;
 double gdpPerCapita1 = gdp1 / (double)population1;
 double gdpPerCapita2 = gdp2 / (double) population2;

 //superpower comparison
 double superpowerComparison1 = ((double) population1 + areaKm2_1 + gdp1 + numberOfTouristPoints1 + gdpPerCapita1)
                                          / populationDensity1;
 double superpowerComparison2 = ((double) population2 + areaKm2_2 + gdp2 +
                                numberOfTouristPoints2 + gdpPerCapita2) / populationDensity2;

 short int result1 = population1 > population2;
 short int result2 = areaKm2_1 > areaKm2_2;
 short int result3 = gdp1 > gdp2;
 short int result4 = numberOfTouristPoints1 > numberOfTouristPoints2;
 short int result5 = gdpPerCapita1 > gdpPerCapita2;
 short int result6 = populationDensity1 < populationDensity2;
 short int result7 = superpowerComparison1 > superpowerComparison2;


  //print the collected information of the first city
   printf ("Card letter: %c\n", c);
   printf ("Card number: %s\n", d);
   printf ("City name: %s\n", city1);
   printf ("Population: %lu\n", population1);
   printf ("Area in km2: %.2f\n", areaKm2_1);
   printf ("GDP: %.2f\n", gdp1);
   printf ("Number of tourist attractions: %d\n", numberOfTouristPoints1);
   printf ("Population density: %.2f people per km2\n", populationDensity1);
   printf ("GDP per capita: %.2f\n", gdpPerCapita1);
   printf ("superpower: %.2f\n", superpowerComparison1);
   printf ("-----------------------------\n");

   //print the collected information of the second city
   printf ("Second card letter: %c\n", e);
   printf ("Second card number: %s\n", f);
   printf ("Name of second city: %s\n", city2);
   printf ("Population: %lu\n", population2);
   printf ("Area: %.2f\n", areaKm2_2);
   printf ("GDP: %.2f\n", gdp2);
   printf ("Number of tourist attractions: %d\n", numberOfTouristPoints2);
   printf ("Population density: %.2f people per km2\n", populationDensity2);
   printf ("GDP per capita: %.2f\n", gdpPerCapita2);
   printf ("superpower: %.2f\n", superpowerComparison2);
   printf ("-----------------------------\n");

    //print the results of the comparisons in 0 and 1 format
    printf ("Is the population of the first city greater than the second? %d\n", result1);
    printf ("Is the area of the first city greater than the second? %d\n", result2);
    printf ("Is the GDP of the first city greater than the second? %d\n", result3);
    printf ("Does the first city have more tourist attractions than the second? %d\n", result4);
    printf ("Is the GDP per capita of the first city greater than the second? %d\n", result5);
    printf ("Is the population density of the first city less than the second? %d\n", result6);
    printf ("Is the superpower comparison of the first city greater than the second? %d\n", result7);

    return 0;
}
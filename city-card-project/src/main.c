#include <stdio.h>

int main() {
    char c, e;
    char d [20], f [20];
    char city1[20], city2[20];
    unsigned long int population1, population2;
    double areaKm2_1, areaKm2_2;
    double gdp1, gdp2;
    int numberOfTouristPoints1, numberOfTouristPoints2;

    /* Input section:
   * Collects raw user data for both cities.
   * No validation is performed.
   */

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

    /* Derived metrics used for economic and structural comparison
    Note: assumes non-zero area and population */
    double populationDensity1 = (double)population1 / areaKm2_1;
    double populationDensity2 = (double)population2 / areaKm2_2;
    double gdpPerCapita1 = gdp1 / (double)population1;
    double gdpPerCapita2 = gdp2 / (double) population2;

    /* Composite index combining demographic and economic indicators
     * WARNING: Not statistically normalized */
    double superpowerComparison1 = ((double) population1 + areaKm2_1 + gdp1 + numberOfTouristPoints1 + gdpPerCapita1)
                                             / populationDensity1;
    double superpowerComparison2 = ((double) population2 + areaKm2_2 + gdp2 +
                                   numberOfTouristPoints2 + gdpPerCapita2) / populationDensity2;

// Calculates the possibilities of the results and format them
    short int result1 = population1 > population2;
    short int result2 = areaKm2_1 > areaKm2_2;
    short int result3 = gdp1 > gdp2;
    short int result4 = numberOfTouristPoints1 > numberOfTouristPoints2;
    short int result5 = gdpPerCapita1 > gdpPerCapita2;
    short int result6 = populationDensity1 < populationDensity2;
    short int result7 = superpowerComparison1 > superpowerComparison2;


    // Output section: structured report for City 1

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

    // Output section: structured report for City 2
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

    // Boolean comparison flags (1 = true, 0 = false)
    printf ("Is the population of the first city greater than the second? %d\n", result1);
    printf ("Is the area of the first city greater than the second? %d\n", result2);
    printf ("Is the GDP of the first city greater than the second? %d\n", result3);
    printf ("Does the first city have more tourist attractions than the second? %d\n", result4);
    printf ("Is the GDP per capita of the first city greater than the second? %d\n", result5);
    printf ("Is the population density of the first city less than the second? %d\n", result6);
    printf ("Is the superpower comparison of the first city greater than the second? %d\n", result7);

    /*Compare the populations of the two cities.
     *Print them to the user depending on which one of them wins.
     */
    if (result1) {
        printf("City 1 Wins");
    }else if (population1 == population2) {
        printf ("It's a draw");
    } else {
        printf("City 2 Wins");
    }
    return 0;
}

#include <stdio.h>

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main()
{
    char input1, input2;
    char d[20], f[20];
    char city1[20], city2[20];
    unsigned long int population1, population2;
    double areaKm2_1, areaKm2_2;
    double gdp1, gdp2;
    int numberOfTouristPoints1, numberOfTouristPoints2;

    /* Input section:
     * Collects user data and performs basic validation.
     */
    printf("Enter one character between a-h:");
    scanf(" %c", &input1);
    flush_in();

    while (!((input1 >= 'a' && input1 <= 'h') || (input1 >= 'A' && input1 <= 'H') || (input1 == '\0')))
    {
        printf("Invalid character. Please enter a character between a-h.\n");
        printf("Enter one character between a-h:");
        scanf(" %c", &input1);
        flush_in();
    }

    printf("Enter the first card number between A1, B2, C3... H8: ");
    scanf("%18s", d);
    while (d [0] < 'A' || d [0] > 'H' || d [1] < '1' || d [1] > '8' || d [2] != '\0')
    {
        printf("Invalid card number. Please enter a valid card number between A1 and H8.\n");
        printf("Enter the first card number between A1, B2, C3... H8: ");
        scanf("%18s", d);
        flush_in();
    }

    printf("Enter the name of the first city: ");
    scanf("%18s", city1);
    flush_in();

    printf("Enter the population of the first city: ");
    scanf("%lu", &population1);
    while (population1 == 0)
    {
        printf("Population cannot be zero.\n");
        scanf("%lu", &population1);
        flush_in();
    }

    printf("Enter the area of the first city in km2: ");
    scanf("%lf", &areaKm2_1);
    flush_in();

    while (areaKm2_1 <= 0)
    {
        printf("Area must be greater than zero.\n");
        scanf("%lf", &areaKm2_1);
        flush_in();
    }

    printf("Enter the GDP of the first city in full: ");
    scanf("%lf", &gdp1);
    flush_in();

    printf("Enter the number of tourist attractions in the first city: ");
    scanf("%d", &numberOfTouristPoints1);
    flush_in();

    printf("Enter the second character: between a-h:");
    scanf(" %c", &input2);
    flush_in();

    while (!((input2 >= 'a' && input2 <= 'h') || (input2 >= 'A' && input2 <= 'H')))
    {
        printf("Invalid character. Please enter a character between a-h.\n");
        printf("Enter the second character: between a-h:");
        scanf(" %c", &input2);
        flush_in();
    }

    printf("Enter the second card number between A1, B2, C3... H8: ");
    scanf("%18s", f);
    flush_in();

    while (f [0] < 'A' || f [0] > 'H' || f [1] < '1' || f [1] > '8' || f [2]  != '\0')
    {
        printf("Invalid card number. Please enter a valid card number between A1 and H8.\n");
        printf("Enter the second card number between A1, B2, C3... H8: ");
        scanf("%18s", f);
        flush_in();
    }

    printf("Enter the second city name: ");
    scanf("%18s", city2);
    flush_in();

    printf("Enter the population of the second city: ");
    scanf("%lu", &population2);
    flush_in();

    while (population2 == 0)
    {
        printf("Population cannot be zero.\n");
        scanf("%lu", &population2);
        flush_in();
    }

    printf("Enter the area of the second city in km2: ");
    scanf("%lf", &areaKm2_2);
    flush_in();

    while (areaKm2_2 <= 0)
    {
        printf("Area must be greater than zero.\n");
        scanf("%lf", &areaKm2_2);
        flush_in();
    }

    printf("Enter the GDP of the second city in full: ");
    scanf("%lf", &gdp2);
    flush_in();

    printf("Enter the number of tourist attractions in the second city: ");
    scanf("%d", &numberOfTouristPoints2);
    flush_in();

    printf("-----------------------------\n"); // print a separator line for better readability of the output

    /* Derived metrics used for economic and structural comparison
    Note: assumes non-zero area and population */
    double populationDensity1 = (double)population1 / areaKm2_1;
    double populationDensity2 = (double)population2 / areaKm2_2;
    double gdpPerCapita1 = gdp1 / (double)population1;
    double gdpPerCapita2 = gdp2 / (double)population2;

    /* Composite index combining demographic and economic indicators
     * WARNING: Not statistically normalized */
    double superpowerComparison1 = ((double)population1 + areaKm2_1 + gdp1 + numberOfTouristPoints1 + gdpPerCapita1) / populationDensity1;
    double superpowerComparison2 = ((double)population2 + areaKm2_2 + gdp2 +
                                    numberOfTouristPoints2 + gdpPerCapita2) /
                                   populationDensity2;

    // Boolean flags indicating whether City 1 outperforms City 2
    short int result1 = population1 > population2;
    short int result2 = areaKm2_1 > areaKm2_2;
    short int result3 = gdp1 > gdp2;
    short int result4 = numberOfTouristPoints1 > numberOfTouristPoints2;
    short int result5 = gdpPerCapita1 > gdpPerCapita2;
    short int result6 = populationDensity1 < populationDensity2;
    short int result7 = superpowerComparison1 > superpowerComparison2;
    int option, option1;
    // Output section: structured report for City 1

    printf("Card letter: %c\n", input1);
    printf("Card number: %s\n", d);
    printf("City name: %s\n", city1);
    printf("Population: %lu\n", population1);
    printf("Area in km2: %.2f\n", areaKm2_1);
    printf("GDP: %.2f\n", gdp1);
    printf("Number of tourist attractions: %d\n", numberOfTouristPoints1);
    printf("Population density: %.2f people per km2\n", populationDensity1);
    printf("GDP per capita: %.2f\n", gdpPerCapita1);
    printf("superpower: %.2f\n", superpowerComparison1);
    printf("-----------------------------\n");

    // Output section: structured report for City 2
    printf("Second card letter: %c\n", input2);
    printf("Second card number: %s\n", f);
    printf("Name of second city: %s\n", city2);
    printf("Population: %lu\n", population2);
    printf("Area: %.2f\n", areaKm2_2);
    printf("GDP: %.2f\n", gdp2);
    printf("Number of tourist attractions: %d\n", numberOfTouristPoints2);
    printf("Population density: %.2f people per km2\n", populationDensity2);
    printf("GDP per capita: %.2f\n", gdpPerCapita2);
    printf("superpower: %.2f\n", superpowerComparison2);
    printf("-----------------------------\n");
    /*
     * User selects which metric to compare.
     * The program prints which city performs better in that category.
     */
    printf("Choose two comparison options (1-7):\n");
    printf("1: Population\n");
    printf("2: Area\n");
    printf("3: GDP\n");
    printf("4: Number of tourist attractions\n");
    printf("5: GDP per capita\n");
    printf("6: Population density\n");
    printf("7: Superpower comparison\n");
    scanf("%d", &option);
    printf("second option: \n");
    printf("1: Population\n");
    printf("2: Area\n");
    printf("3: GDP\n");
    printf("4: Number of tourist attractions\n");
    printf("5: GDP per capita\n");
    printf("6: Population density\n");
    printf("7: Superpower comparison\n");
    scanf("%d", &option1);

    // Validate user input for comparison options
    if (option < 1 || option > 7)
    {
        printf("Invalid option. Please choose a number between 1 and 7.\n");
        return 1;
    }
    switch (option)
    {
    case 1:
        printf("%s\n",
               population1 == population2 ? "It's a tie" : result1 ? "The first city wins"
                                                                   : "The second city wins");
        break;

    case 2:
        printf("%s\n",
               areaKm2_1 == areaKm2_2 ? "It's a tie" : result2 ? "The first city wins"
                                                               : "The second city wins");
        break;

    case 3:
        printf("%s\n",
               gdp1 == gdp2 ? "It's a tie" : result3 ? "The first city wins"
                                                     : "The second city wins");
        break;

    case 4:
        printf("%s\n",
               numberOfTouristPoints1 == numberOfTouristPoints2 ? "It's a tie" : result4 ? "The first city wins"
                                                                                         : "The second city wins");
        break;

    case 5:
        printf("%s\n",
               gdpPerCapita1 == gdpPerCapita2 ? "It's a tie" : result5 ? "The first city wins"
                                                                       : "The second city wins");
        break;

    case 6:
        printf("%s\n",
               populationDensity1 == populationDensity2 ? "It's a tie" : result6 ? "The first city wins"
                                                                                 : "The second city wins");
        break;

    case 7:
        printf("%s\n",
               superpowerComparison1 == superpowerComparison2 ? "It's a tie" : result7 ? "The first city wins"
                                                                                       : "The second city wins");
        break;

    default:
        printf("Invalid option. Please choose a number between 1 and 7.\n");
        break;
    }
    if (option1 < 1 || option1 > 7)
    {
        printf("Invalid option. Please choose a number between 1 and 7.\n");
        return 1;
    }
    switch (option1)
    {
    case 1:
        printf("%s\n",
               population1 == population2 ? "It's a tie" : result1 ? "The first city wins"
                                                                   : "The second city wins");
        break;

    case 2:
        printf("%s\n",
               areaKm2_1 == areaKm2_2 ? "It's a tie" : result2 ? "The first city wins"
                                                               : "The second city wins");
        break;

    case 3:
        printf("%s\n",
               gdp1 == gdp2 ? "It's a tie" : result3 ? "The first city wins"
                                                     : "The second city wins");
        break;

    case 4:
        printf("%s\n",
               numberOfTouristPoints1 == numberOfTouristPoints2 ? "It's a tie" : result4 ? "The first city wins"
                                                                                         : "The second city wins");
        break;

    case 5:
        printf("%s\n",
               gdpPerCapita1 == gdpPerCapita2 ? "It's a tie" : result5 ? "The first city wins"
                                                                       : "The second city wins");
        break;

    case 6:
        printf("%s\n",
               populationDensity1 == populationDensity2 ? "It's a tie" : result6 ? "The first city wins"
                                                                                 : "The second city wins");
        break;

    case 7:
        printf("%s\n",
               superpowerComparison1 == superpowerComparison2 ? "It's a tie" : result7 ? "The first city wins"
                                                                                       : "The second city wins");
        break;

    default:
        printf("Invalid option. Please choose a number between 1 and 7.\n");
        break;
    }
    if (result1 == result2 && result2 == result3 && result3 == result4 && result4 == result5 && result5 == result6 && result6 == result7)
    {
        printf("Overall, it's a tie between the two cities based on the selected metrics.\n");
    }
    return 0;
}
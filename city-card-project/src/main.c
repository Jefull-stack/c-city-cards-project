#include <stdio.h>
#include <string.h>

typedef struct
{
    char namecity[50];
    unsigned long int population;
    double areaKm2;
    double gdp;
    int numberOfTouristPoints;
} City;

typedef struct
{
    char input[10];
    char numcard[4];
} Card;

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

int main()
{

    City city1, city2;
    Card c1, c2;

    /* Input section:
     * Collects user data and performs basic validation.
     */
    printf("Enter one character between a-h:");
    scanf("%9s", c1.input);

    while (strlen(c1.input) != 1 || !((c1.input[0] >= 'a' && c1.input[0] <= 'h') || (c1.input[0] >= 'A' && c1.input[0] <= 'H')))
    {
        printf("Invalid character. Please enter a character between a-h.\n");
        printf("Enter one character between a-h:");
        scanf("%9s", c1.input);
    }

    printf("Enter the first card number between A1, B2, C3... H8: ");
    scanf("%3s", c1.numcard);
    while (c1.numcard[0] < 'A' || c1.numcard[0] > 'H' || c1.numcard[1] < '1' || c1.numcard[1] > '8' || c1.numcard[2] != '\0')
    {
        printf("Invalid card number. Please enter a valid card number between A1 and H8.\n");
        printf("Enter the first card number between A1, B2, C3... H8: ");
        scanf("%3s", c1.numcard);
        flush_in();
    }

    printf("Enter the name of the first city: ");
    scanf("%49s", city1.namecity);
    flush_in();

    printf("Enter the population of the first city: ");
    scanf("%lu", &city1.population);
    while (city1.population == 0)
    {
        printf("Population cannot be zero.\n");
        scanf("%lu", &city1.population);
        flush_in();
    }

    printf("Enter the area of the first city in km2: ");
    scanf("%lf", &city1.areaKm2);

    while (city1.areaKm2 <= 0)
    {
        printf("Area must be greater than zero.\n");
        scanf("%lf", &city1.areaKm2);
        flush_in();
    }

    printf("Enter the GDP of the first city in full: ");
    scanf("%lf", &city1.gdp);
    flush_in();

    printf("Enter the number of tourist attractions in the first city: ");
    scanf("%d", &city1.numberOfTouristPoints);
    flush_in();

    printf("Enter one character between a-h:");
    scanf("%3s", c2.input);

    while (strlen(c2.input) != 1 || !((c2.input[0] >= 'a' && c2.input[0] <= 'h') || (c2.input[0] >= 'A' && c2.input[0] <= 'H')))
    {
        printf("Invalid character. Please enter a character between a-h.\n");
        printf("Enter one character between a-h:");
        scanf("%3s", c2.input);
    }

    printf("Enter the second card number between A1, B2, C3... H8: ");
    scanf("%3s", c2.numcard);

    while (c2.numcard[0] < 'A' || c2.numcard[0] > 'H' || c2.numcard[1] < '1' || c2.numcard[1] > '8' || c2.numcard[2] != '\0')
    {
        printf("Invalid card number. Please enter a valid card number between A1 and H8.\n");
        printf("Enter the second card number between A1, B2, C3... H8: ");
        scanf("%3s", c2.numcard);
        flush_in();
    }

    printf("Enter the second city name: ");
    scanf("%49s", city2.namecity);
    flush_in();

    printf("Enter the population of the second city: ");
    scanf("%lu", &city2.population);
    flush_in();

    while (city2.population == 0)
    {
        printf("Population cannot be zero.\n");
        scanf("%lu", &city2.population);
        flush_in();
    }

    printf("Enter the area of the second city in km2: ");
    scanf("%lf", &city2.areaKm2);
    flush_in();

    while (city2.areaKm2 <= 0)
    {
        printf("Area must be greater than zero.\n");
        scanf("%lf", &city2.areaKm2);
        flush_in();
    }

    printf("Enter the GDP of the second city in full: ");
    scanf("%lf", &city2.gdp);
    flush_in();

    printf("Enter the number of tourist attractions in the second city: ");
    scanf("%d", &city2.numberOfTouristPoints);
    flush_in();

    printf("-----------------------------\n"); // print a separator line for better readability of the output

    /* Derived metrics used for economic and structural comparison
    Note: assumes non-zero area and population */
    double populationDensity1 = (double)city1.population / city1.areaKm2;
    double populationDensity2 = (double)city2.population / city2.areaKm2;
    double gdpPerCapita1 = city1.gdp / (double)city1.population;
    double gdpPerCapita2 = city2.gdp / (double)city2.population;

    /* Composite index combining demographic and economic indicators
     * WARNING: Not statistically normalized */
    double superpowerComparison1 = ((double)city1.population + city1.areaKm2 + city1.gdp + city1.numberOfTouristPoints + gdpPerCapita1) / populationDensity1;
    double superpowerComparison2 = ((double)city2.population + city2.areaKm2 + city2.gdp +
                                    city2.numberOfTouristPoints + gdpPerCapita2) /
                                   populationDensity2;

    // Boolean flags indicating whether City 1 outperforms City 2
    short int result1 = city1.population > city2.population;
    short int result2 = city1.areaKm2 > city2.areaKm2;
    short int result3 = city1.gdp > city2.gdp;
    short int result4 = city1.numberOfTouristPoints > city2.numberOfTouristPoints;
    short int result5 = gdpPerCapita1 > gdpPerCapita2;
    short int result6 = populationDensity1 < populationDensity2;
    short int result7 = superpowerComparison1 > superpowerComparison2;
    int option, option1;
    // Output section: structured report for City 1

    printf("Card letter: %s\n", c1.input);
    printf("Card number: %s\n", c1.numcard);
    printf("City name: %s\n", city1.namecity);
    printf("Population: %lu\n", city1.population);
    printf("Area in km2: %.2f\n", city1.areaKm2);
    printf("GDP: %.2f\n", city1.gdp);
    printf("Number of tourist attractions: %d\n", city1.numberOfTouristPoints);
    printf("Population density: %.2f people per km2\n", populationDensity1);
    printf("GDP per capita: %.2f\n", gdpPerCapita1);
    printf("superpower: %.2f\n", superpowerComparison1);
    printf("-----------------------------\n");

    // Output section: structured report for City 2
    printf("Second card letter: %c\n", c2.input[0]);
    printf("Second card number: %s\n", c2.numcard);
    printf("Name of second city: %s\n", city2.namecity);
    printf("Population: %lu\n", city2.population);
    printf("Area: %.2f\n", city2.areaKm2);
    printf("GDP: %.2f\n", city2.gdp);
    printf("Number of tourist attractions: %d\n", city2.numberOfTouristPoints);
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
    while (option < 1 || option > 7)
    {
        printf("Invalid option. Please choose a number between 1 and 7.\n");
        printf("Choose two comparison options (1-7):\n");
        scanf("%d", &option);
    }
    switch (option)
    {
    case 1:
        printf("%s\n",
               city1.population == city2.population ? "It's a tie" : result1 ? "The first city wins"
                                                                             : "The second city wins");
        break;

    case 2:
        printf("%s\n",
               city1.areaKm2 == city2.areaKm2 ? "It's a tie" : result2 ? "The first city wins"
                                                                       : "The second city wins");
        break;

    case 3:
        printf("%s\n",
               city1.gdp == city2.gdp ? "It's a tie" : result3 ? "The first city wins"
                                                               : "The second city wins");
        break;

    case 4:
        printf("%s\n",
               city1.numberOfTouristPoints == city2.numberOfTouristPoints ? "It's a tie" : result4 ? "The first city wins"
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
               city1.population == city2.population ? "It's a tie" : result1 ? "The first city wins"
                                                                             : "The second city wins");
        break;

    case 2:
        printf("%s\n",
               city1.areaKm2 == city2.areaKm2 ? "It's a tie" : result2 ? "The first city wins"
                                                                       : "The second city wins");
        break;

    case 3:
        printf("%s\n",
               city1.gdp == city2.gdp ? "It's a tie" : result3 ? "The first city wins"
                                                               : "The second city wins");
        break;

    case 4:
        printf("%s\n",
               city1.numberOfTouristPoints == city2.numberOfTouristPoints ? "It's a tie" : result4 ? "The first city wins"
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
    return 0;
}
// --- HEADER FILE FOR CITY CARD PROJECT ---

#include <stdio.h>
#include <string.h>

// Define the City structure to hold city information
typedef struct
{
    char namecity[50];
    unsigned long int population;
    double areaKm2;
    double gdp;
    int numberoftouristpoints;
} City;

// Define the Card structure to hold card information
typedef struct
{
    char input[10];
    char numcard[4];
} Card;

// function to flush the input buffer
void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
        ;
}

// function to compare two cities based on the selected option
void compareresults(int option, City city1, City city2, double gdppercapita1, double gdppercapita2, double populationdensity1, double populationdensity2, double superpowercomparison1, double superpowercomparison2)
{
    switch (option)
    {
    case 1:
        printf("%s\n",
               city1.population == city2.population ? "It's a tie" : city1.population > city2.population ? "The first city wins"
                                                                                                         : "The second city wins");
        break;

    case 2:
        printf("%s\n",
               city1.areaKm2 == city2.areaKm2 ? "It's a tie" : city1.areaKm2 > city2.areaKm2 ? "The first city wins"
                                                                                             : "The second city wins");
        break;

    case 3:
        printf("%s\n",
               city1.gdp == city2.gdp ? "It's a tie" : city1.gdp > city2.gdp ? "The first city wins"
                                                                             : "The second city wins");
        break;

    case 4:
        printf("%s\n",
               city1.numberoftouristpoints == city2.numberoftouristpoints ? "It's a tie" : city1.numberoftouristpoints > city2.numberoftouristpoints ? "The first city wins"
                                                                                                                                                     : "The second city wins");
        break;

    case 5:
        printf("%s\n",
               gdppercapita1 == gdppercapita2 ? "It's a tie" : gdppercapita1 > gdppercapita2 ? "The first city wins"
                                                                                             : "The second city wins");
        break;

    case 6:
        printf("%s\n",
               populationdensity1 == populationdensity2 ? "It's a tie" : populationdensity1 < populationdensity2 ? "The first city wins"
                                                                                                                 : "The second city wins");
        break;

    case 7:
        printf("%s\n",
               superpowercomparison1 == superpowercomparison2 ? "It's a tie" :superpowercomparison1 > superpowercomparison2 ? "The first city wins"  : "The second city wins");
        break;
         default : printf("Invalid option. Please choose a number between 1 and 7.\n");
    }
}

// Function to print the comparison menu
void printmenu()
{
    printf("Choose a comparison option (1-7):\n");
    printf("1: Population\n");
    printf("2: Area\n");
    printf("3: GDP\n");
    printf("4: Number of tourist attractions\n");
    printf("5: GDP per capita\n");
    printf("6: Population density\n");
    printf("7: Superpower comparison\n");
}
// function to calculate population density, GDP per capita, and the composite superpower index for two cities
void calculatemetrics(City city1, City city2,
                      double *gdppercapita1, double *gdppercapita2,
                      double *populationdensity1, double *populationdensity2,
                      double *superpowercomparison1, double *superpowercomparison2)
{
    *populationdensity1 = (double)city1.population / city1.areaKm2;
    *populationdensity2 = (double)city2.population / city2.areaKm2;
    *gdppercapita1 = city1.gdp / (double)city1.population;
    *gdppercapita2 = city2.gdp / (double)city2.population;

    /* Composite index combining demographic and economic indicators
     * WARNING: Not statistically normalized */
    *superpowercomparison1 = ((double)city1.population + city1.areaKm2 + city1.gdp + city1.numberoftouristpoints + *gdppercapita1) / *populationdensity1;
    *superpowercomparison2 = ((double)city2.population + city2.areaKm2 + city2.gdp +
                              city2.numberoftouristpoints + *gdppercapita2) /
                             *populationdensity2;
}
// Function to ask the user for city data and perform basic validation
void askCityData(City *city, Card *card, int cityNumber)
{
    printf("City %d: Enter one character between a-h: ", cityNumber);
    scanf("%9s", card->input);
    while (strlen(card->input) != 1 || !((card->input[0] >= 'a' && card->input[0] <= 'h') || (card->input[0] >= 'A' && card->input[0] <= 'H')))
    {
        printf("Invalid. Enter a character a-h: ");
        scanf("%9s", card->input);
    }

    printf("Enter card number A1-H8: ");
    scanf("%3s", card->numcard);
    while (card->numcard[0] < 'A' || card->numcard[0] > 'H' || card->numcard[0] < 'a' || card->numcard[0] > 'h' || card->numcard[1] < '1' || card->numcard[1] > '8' || card->numcard[2] != '\0')
    {
        printf("Invalid. Enter A1-H8: ");
        scanf("%3s", card->numcard);
        flush_in();
    }

    printf("Enter city name: ");
    scanf("%s49[^\n]", city->namecity);
    flush_in();

    printf("Enter population: ");
    scanf("%lu", &city->population);
    while (city->population == 0)
    {
        printf("Cannot be zero: ");
        scanf("%lu", &city->population);
        flush_in();
    }

    printf("Enter area km2: ");
    scanf("%lf", &city->areaKm2);
    while (city->areaKm2 <= 0)
    {
        printf("Must be > 0: ");
        scanf("%lf", &city->areaKm2);
        flush_in();
    }

    printf("Enter GDP: ");
    scanf("%lf", &city->gdp);
    flush_in();

    printf("Enter number of tourist attractions: ");
    scanf("%d", &city->numberoftouristpoints);
    flush_in();

    printf("---------------------\n");
}

// Function to print city information in a structured format
void printCityInfo(City city, Card card)
{
    printf("Card Input: %s\n", card.input);
    printf("Card Number: %s\n", card.numcard);
    printf("City Name: %49s[^\n]", city.namecity);
    printf("Population: %lu\n", city.population);
    printf("Area (km2): %.2lf\n", city.areaKm2);
    printf("GDP: %.2lf\n", city.gdp);
    printf("Number of Tourist Attractions: %d\n", city.numberoftouristpoints);
    printf("GDP per Capita: %.2lf\n", city.gdp / (double)city.population);
    printf("Population Density: %.2lf people/km2\n", (double)city.population / city.areaKm2);
    printf("Superpower Comparison Index: %.2lf\n", ((double)city.population + city.areaKm2 + city.gdp + city.numberoftouristpoints + (city.gdp / (double)city.population)) / ((double)city.population / city.areaKm2));
    printf("---------------------\n");
}

// score function to determine the winner based on the score
void score(City city1, City city2, double populationdensity1, double populationdensity2, double superpowercomparison1, double superpowercomparison2)
{
    short int result1, result2, result3, result4, result5, result6, result7;
    result1 = city1.population > city2.population;
    result2 = city1.areaKm2 > city2.areaKm2;
    result3 = city1.gdp > city2.gdp;
    result4 = city1.numberoftouristpoints > city2.numberoftouristpoints;
    result5 = city1.gdp > city2.gdp;
    result6 = populationdensity1 < populationdensity2;
    result7 = superpowercomparison1 > superpowercomparison2;
    int player1score = result1 + result2 + result3 + result4 + result5 + result6 + result7;
    int player2score = 7 - player1score;

    printf("Player 1 score: %d\n", player1score);
    printf("Player 2 score: %d\n", player2score);

    if (player1score > player2score)
    {
        printf("Congratulations player 1! You win!\n");
    }
    else if (player2score > player1score)
    {
        printf("Congratulations player 2, you win!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

void funtions()
{
    // This function is a placeholder for any additional functions that may be needed in the future.
}
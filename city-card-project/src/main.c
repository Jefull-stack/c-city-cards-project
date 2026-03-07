#include <library.h>

int main()
{
    printf("Welcome to the City Card Comparison Game!\n");
    double populationdensity1, populationdensity2;
    double gdpPerCapita1, gdpPerCapita2;
    double superpowercomparison1, superpowercomparison2;
    City city1, city2;
    Card c1, c2;
    int option = 0;

    /* Input section:
     * Collects user data and performs basic validation.
     */
    askCityData(&city1, &c1, 1);
    askCityData(&city2, &c2, 2);

    /* Composite index combining demographic and economic indicators
     * WARNING: Not statistically normalized */
    calculatemetrics(city1, city2, &gdpPerCapita1, &gdpPerCapita2, &populationdensity1, &populationdensity2, &superpowercomparison1, &superpowercomparison2);

    // Output section: structured report for City 1
    printCityInfo(city1, c1);

    // Output section: structured report for City 2
    printCityInfo(city2, c2);

    /*
     * User selects which metric to compare in the menu.
     * The program prints which city performs better in that category.
     */
    printmenu();
    compareresults(option, city1, city2, gdpPerCapita1, gdpPerCapita2, populationdensity1, populationdensity2, superpowercomparison1, superpowercomparison2);
    // Final score comparison to determine the overall winner

    printmenu();
    compareresults(option, city1, city2, gdpPerCapita1, gdpPerCapita2, populationdensity1, populationdensity2, superpowercomparison1, superpowercomparison2);
    // Call the compare function to determine which city performs better based on the user's choice
    score(city1, city2, populationdensity1, populationdensity2, superpowercomparison1, superpowercomparison2);

    return 0;
}
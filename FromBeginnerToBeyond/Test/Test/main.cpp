#include <iostream>
#include <cmath>
using namespace std;

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION PROTOTYPES BELOW THIS LINE----
double farenheit_to_celsius(double);
double farenheit_to_kelvin(double);


//----WRITE YOUR FUNCTION PROTOTYPES ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void temperature_conversion(double fahrenheit_temperature) {
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR FUNCTION CALLS BELOW THIS LINE----
    double celsius_temperature {farenheit_to_celsius(fahrenheit_temperature)};
    double kelvin_temperature {farenheit_to_kelvin(fahrenheit_temperature)};
    
    
    //----WRITE YOUR FUNCTION CALLS ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "The fahrenheit temperature " << fahrenheit_temperature << " degrees is equivalent to " << celsius_temperature << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

int main() {
    temperature_conversion(10.0);
    return 0;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR FUNCTION DEFINITIONS BELOW THIS LINE----

double farenheit_to_celsius(double temperature) {
    return round((5.0/9.0)*(temperature - 32));
}

double farenheit_to_kelvin(double temperature) {
    return round((5.0 / 9.0) * (temperature - 32) + 273);
}

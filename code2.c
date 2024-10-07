#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temp, converted_temp;
    int input_scale, target_scale;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);

    if (input_scale < 1 || input_scale > 3) {
        printf("Invalid input. \n");
        return 1;
    }

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);

    if (target_scale < 1 || target_scale > 3) {
        printf("Invalid target scale. Please try again.\n");
        return 1;
    }

    if (input_scale == target_scale) {
        printf("The input is the same as the conversion. Not necessary to perform conversion.\n");
        return 1;
    }

    switch (input_scale) {
        case 1:
            if (target_scale == 2) { // celsius to fahrenheit
                converted_temp = celsius_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            } else if (target_scale == 3) { // celsius to kelvin.
                converted_temp = celsius_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            break;

        case 2: // Fahrenheit
            if (target_scale == 1) { // fahrenheit to celsius
                converted_temp = fahrenheit_to_celsius(temp);
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else if (target_scale == 3) { // fahrenheit to kelvin
                converted_temp = fahrenheit_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            break;

        case 3: // Kelvin
            if (target_scale == 1) { // kelvin to celsius.
                if (temp < 0) {
                    printf("Invalid temperature: Kelvin cannot be negative.\n");
                    return 1;
                }
                converted_temp = kelvin_to_celsius(temp);
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else if (target_scale == 2) { // kelvin to fahrenheit
                if (temp < 0) {
                    printf("Kelvin can't be negative\n");
                    return 1;
                }
                converted_temp = kelvin_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            }
            break;
    }

    // Basically provides celcius equivalent of input and provides the advisory
    if (target_scale == 1 || input_scale == 1) {
        categorize_temperature(converted_temp);
    } else if (target_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temp));
    } else if (target_scale == 3) {
        categorize_temperature(kelvin_to_celsius(converted_temp));
    }

    return 0;
}

// Conversion Functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's frigid! Stay bundled!!!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Whip out those sweaters! \n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: The weather will be pleasureable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Remember to stay hydrated :)\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors, if you go out you'll melt into the concrete!\n");
    }
}

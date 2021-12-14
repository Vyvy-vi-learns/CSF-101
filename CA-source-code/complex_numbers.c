#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Struct for representing a complex number
typedef struct
{
    int real;
    int imaginary;
}
complex;

// Global variable to store last read complex number
complex last_complex_number = {
    .real = 0,
    .imaginary = 0
};

// Global variable to store whether a number has been read
int read = 0;



/****************************************************
 * FUNCTIONS FOR THE COMPLEX NUMBER LOGIC
 ****************************************************
 */

 // Function for (a) Reading a complex number
 complex read_complex_number() {
     complex num;

     printf("Enter the real part of the number: ");
     scanf("%d", &num.real);
     printf("Enter the imaginary part of the number: ");
     scanf("%d", &num.imaginary);

     return num;
 }

 // Function for (b) Writing a complex number
 void write_complex_number(complex num) {
     if (num.imaginary < 0) {
         printf("%d - %di\n", num.real, - num.imaginary);
     }
     else if (num.imaginary == 1) {
         printf("%d + i\n", num.real);
     }
     else {
         printf("%d + %di\n", num.real, num.imaginary);
     }
 }

 // Function for (c) Addition of two complex numbers
 complex add_complex_numbers(complex num1, complex num2) {
     complex sum = {
       .real = num1.real + num2.real,
       .imaginary = num1.imaginary + num2.imaginary,
     };
     return sum;
 }

 // Function for (d) Subtraction of two complex numbers
 complex subtract_complex_numbers(complex num1, complex num2) {
     complex diff = {
       .real = num1.real - num2.real,
       .imaginary = num1.imaginary - num2.imaginary,
     };
     return diff;
 }

 /**
 * Function for (e) Multiplication of two complex numbers
 * (a + ib) * (x + iy) = ax + ayi + bxi - by
 */
 complex multiply_complex_numbers(complex num1, complex num2) {
     complex product = {
       .real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary),
       .imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real),
     };
     return product;
 }

/****************************************************
 * FUNCTIONS FOR THE MENU OPTIONS
 ****************************************************
 */

// Utility function to get user choice for menu
char get_user_choice() {
    char choice;
    printf("Select which action you would like to perform.");
    printf("\n\
(a) Reading a complex number\n\
(b) Writing a complex number\n\
(c) Addition of two complex numbers\n\
(d) Subtraction of two complex numbers\n\
(e) Multiplication of two complex numbers\n\
    \nPress (q) to exit\n");
    printf("Enter Choice: ");
    scanf("%c", &choice);

    return tolower(choice);
}


// Utility function to return a random complex number
complex random_complex_number() {
    complex num;
    num.real = rand() / 100000;
    num.imaginary = rand() /100000;
    return num;
}


/**
 * Function to perform menu action for option 'a':
 * Reading a complex number and storing it
 */
void option_a()
{
    last_complex_number = read_complex_number();
    read = 1;
    printf("Complex number read and stored.\n");
}

/**
 * Function to perform menu action for option 'b':
 * Write the Complex Number read previously to STDOUT
 * If a number wasn't read, prompt user to enter one
 * Or print a randomly generated complex number
 */
void option_b()
{
    int choice;
    if (read == 1) {
        printf("Press 1 to print last entered complex number\n");
        printf("Press 2 to enter a complex number and have it printed\n");
        printf("Press 3 to have a random complex number be printed\n");

        printf("Enter choice: ");
        scanf("%i", &choice);

        if (choice == 2) {
            last_complex_number = read_complex_number();
        } else if (choice != 1) {
            last_complex_number = random_complex_number();
        }
    }
    else {
        printf("No complex number has been entered previously\n");
        printf("Press 1 to enter a complex number now\n");
        printf("Press 2 to have a random complex number be printed\n");

        printf("Enter choice: ");
        scanf("%i", &choice);

        if (choice == 1) {
            last_complex_number = read_complex_number();
        } else {
            last_complex_number = random_complex_number();
        }
    }
    write_complex_number(last_complex_number);
}

/**
 * Function to perform menu action for option 'c':
 * Taking input for two complex numbers and Adding them.
 */
void option_c()
{
    printf("ADDITION\n");
    printf("Taking input for first number...\n");
    complex num1 = read_complex_number();

    printf("Taking input for second number...\n");
    complex num2 = read_complex_number();

    printf("Sum of numbers-\n");
    write_complex_number(num1);
    printf("+\n");
    write_complex_number(num2);
    printf("= ");
    write_complex_number(add_complex_numbers(num1, num2));
}

/**
 * Function to perform menu action for option 'd':
 * Taking input for two complex numbers and Subtracting one from other.
 */
void option_d()
{
    printf("SUBTRACTION\n");
    printf("Taking input for first number...\n");
    complex num1 = read_complex_number();

    printf("Taking input for second number...\n");
    complex num2 = read_complex_number();

    printf("Difference of numbers-\n");
    write_complex_number(num1);
    printf("-\n");
    write_complex_number(num2);
    printf("= ");
    write_complex_number(subtract_complex_numbers(num1, num2));
}

/**
 * Function to perform menu action for option 'e':
 * Taking input for two complex numbers and Multiplying them.
 */
void option_e()
{
    printf("MULTIPLICATION\n");
    printf("Taking input for first number...\n");
    complex num1 = read_complex_number();

    printf("Taking input for second number...\n");
    complex num2 = read_complex_number();

    printf("Product of numbers-\n");
    write_complex_number(num1);
    printf("x\n");
    write_complex_number(num2);
    printf("= ");
    write_complex_number(multiply_complex_numbers(num1, num2));
}



int main(void)
{
    printf("Complex Number Manipulation Program Menu\n");
    printf("----------------------------------------\n");

    // Get user input for choice
    char input = get_user_choice();

    // Run Menu and get input until someone quits...
    while (input != 'q') {
        switch (input) {
            // Read Complex Number and store it
            case 'a': {
                option_a();
                break;
            }
            // Write Complex Number
            case 'b': {
                option_b();
                break;
            }
            // Add two complex numbers
            case 'c': {
                option_c();
                break;
            }
            // Subtract two complex numbers
            case 'd': {
                option_d();
                break;
            }
            // Multiply two complex numbers
            case 'e': {
                option_e();
                break;
            }
            default: {
                printf("ERROR: Invalid Choice\n");
                break;
            }
        }
        printf("----------------------------------------\n");
        getchar();
        input = get_user_choice();
    }

    printf("Exiting...\nThanks for using!\n");
    printf("----------------------------------------\n");
}

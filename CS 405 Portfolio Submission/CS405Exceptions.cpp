// CS405Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Mitchell Ibarra 
// CS 405 Secure Coding
// Southern New Hampshire University 
// 3/27/2021
//

#include <iostream>

class customeException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "My custom exception thrown.";
    }
} myex;

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    //Creating class that will to be used to throw standard exception - Mitchell
    class Polymorphic { virtual void member() {} };
   
    Polymorphic* pb = 0;
    typeid(*pb); // throws a bad_typeid exception    

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    //Wrapping call to do_even_more_custom_application_logic() with
    // exception handler - Mitchell 
    try
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch(std::exception& exception)
    {
        std::cout << "Standard exception caught: " << exception.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    // Throwing custom uncaught exception - Mitchell
    throw myex;
    std::cout << "Leaving Custom Application Logic." << std::endl;


}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
   
    // Checking to see if the denominator will be 0.0, if it is then we 
    // throw the exceptions - Mitchell Ibarra
    if (den == 0.0f)
    {
        throw "Divide by zero exception thrown!";
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    //Placing code in try/catch block - Mitchell
    try
    {
        //If divide by zero, exception will be thrown from divide() - Mitchell
        auto result = divide(numerator, denominator);
        //If no exception thrown, then we continue and output result - Mitchell
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch(const char* msg)
    {
        //This catches the thrown exception from divide by 0 - Mitchell
        std::cerr << msg << std::endl;
    }    
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    
    //Wrapping method calls in try/catch block to catch exceptions - Mitchell
    do_division();
    try
    {
        do_custom_application_logic();
        
    }
    catch (std::exception& excpetion)
    {
        std::cout << "Uncaught exception caught: " << excpetion.what() << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
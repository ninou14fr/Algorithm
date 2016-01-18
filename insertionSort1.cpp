#include<iostream>
#include<stdlib.h>
#include<limits>

void InsertionSort(long *listOfInteger, long size)
{
    for ( long i = 0; i < size; i++ )
    {
        long temp = listOfInteger[i]; //store one element in a temporary 
        long j;
        for ( j = i - 1; j >= 0 && temp < listOfInteger[j]; j-- )
        {
            listOfInteger[j + 1] = listOfInteger[j];
        }
        listOfInteger[j + 1] = temp;
    }
}

int main(int argc, char** argv)
{
    long size;
    long *list;
    bool flag = true;

    if ( argc <= 1 ) //if no argument passed to the program
    {
        while (flag)//make sure that the input is right
        {
            std::cin >> size; //size of the inputs

            if ( std::cin.fail() )
            {
                std::cin.clear(); //clear the input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //reset cin ignore bad input
                std::cout << "\n-- Wrong size - try again --\n";
                std::cin >> size; // store size in
                flag = true;

            } else
            {
                flag = false;
            }
        }
        try
        {
            list = new long[size];
        } catch (const std::bad_alloc&)
        { //catch bad allocation
            std::cout << "\nErreur in the size of the input can't be negative\n";
            return -1;
        }
        for ( long i = 0; i < size; i++ ) //take the input of the specified length
        {
            std::cin >> list[i];

            if ( std::cin.fail() )
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //reset cin ignore bad input
                std::cout << "\n-- Invalid Input - try again -- \n";
                i--;
            }
        }

        InsertionSort(list, size); //invoke function
        std::cout << std::endl;

        for ( long i = 0; i < size; i++ ) //display the ordered list
        {
            std::cout << list[i] << std::endl;
        }

    } else //if argument are provided
    {
        size = argc;

        try
        {
            list = new long[size];

            for ( long i = 0; i < argc; i++ )
            {
                list[i] = atoi(argv[i]);
            }
            InsertionSort(list, size); //invoke function
            std::cout << std::endl;

            for ( long i = 0; i < size; i++ ) //display the ordered list
            {
                std::cout << list[i] << std::endl;
            }
        } catch (const std::bad_alloc&)//catch bad allocation in the size
        {
            std::cout << "\nBad input\n";
            return -1;
        }
    }
}

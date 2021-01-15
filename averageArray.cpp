// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by: Roman Cernetchi
// Created on: January 2021
// This program prints a 2D array and finds the average of all the numbers

#include <iostream>
#include <random>
#include <array>


template<int rows, int columns>
float average2D(float (&array_2D)[rows][columns]) {
    // This program finds the smallest number

    float total = 0;
    float numOfRows = sizeof(array_2D) / sizeof(array_2D[0]);
    float numOfCols = sizeof(array_2D[0]) / sizeof(int);

    // process
    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < columns;
             ++columnElement)
            total += array_2D[rowElement][columnElement];
    }

    float average = total / (numOfRows * numOfCols);

    return average;
}


int main() {
    // This program prints 10 random integers and output

    // variables
    int randomNum;
    const int rows = 4;
    const int columns = 6;
    float array_2D[rows][columns];

    // creating 2D array
    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns;
             columnElement++) {
            // random number generation
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(0, 50);
            randomNum = idist(rgen);
            array_2D[rowElement][columnElement] = randomNum;
            std::cout << randomNum << ", ";
        }
        std::cout << std::endl;
    }

    float averageOfArray = average2D(array_2D);

    std::cout << "" << std::endl;
    std::cout << "The average of all numbers is: " << averageOfArray
              << std::endl;
}

#pragma once
#include <iostream>
using namespace std;

struct Path {
    int routeNumber;
    char startPoint[100];
    char endPoint[100];
    double ticketPrice;
    double routeLength;
};
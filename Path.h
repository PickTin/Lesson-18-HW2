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

void addRoute(Path routes[], int& count, int maxRoutes) {
    if (count < maxRoutes) {
        cout << "Enter Route Number: ";
        cin >> routes[count].routeNumber;
        cout << "Enter Start Point: ";
        cin.ignore(); 
        cin.getline(routes[count].startPoint, 100);
        cout << "Enter End Point: ";
        cin.getline(routes[count].endPoint, 100);
        cout << "Enter Ticket Price: ";
        cin >> routes[count].ticketPrice;
        cout << "Enter Route Length: ";
        cin >> routes[count].routeLength;

        count++;
        cout << "Route added successfully!" << endl;
    }
    else {
        cout << "Maximum routes reached. Cannot add more." << endl;
    }
}
Path findRouteWithMaxLength(Path routes[], int count) {
    Path maxRoute;
    if (count > 0) {
        maxRoute = routes[0];
        for (int i = 1; i < count; ++i) {
            if (routes[i].routeLength > maxRoute.routeLength) {
                maxRoute = routes[i];
            }
        }
    }
    return maxRoute;
}
void sortRoutesByNumber(Path routes[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (routes[i].routeNumber > routes[j].routeNumber) {
                Path temp = routes[i];
                routes[i] = routes[j];
                routes[j] = temp;
            }
        }
    }
}
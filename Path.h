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
void printRoutesByPoint(Path routes[], int count, const char* point) {
    bool found = false;
    cout << "Routes starting or ending at " << point << ":" << endl;
    for (int i = 0; i < count; ++i) {
        if (strcmp(routes[i].startPoint, point) == 0 || strcmp(routes[i].endPoint, point) == 0) {
            cout << "Route Number: " << routes[i].routeNumber << ", Start Point: " << routes[i].startPoint
                << ", End Point: " << routes[i].endPoint << ", Ticket Price: " << routes[i].ticketPrice
                << ", Route Length: " << routes[i].routeLength << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No routes found starting or ending at " << point << "." << endl;
    }
}
void increaseTicketPrice(Path routes[], int count, double maxLength) {
    for (int i = 0; i < count; ++i) {
        if (routes[i].routeLength > maxLength) {
            routes[i].ticketPrice *= 1.15; 
        }
    }
}
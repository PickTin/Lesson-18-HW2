#include "Path.h"
int main() {
    const int MAX_ROUTES = 10;
    Path routes[MAX_ROUTES];
    int routeCount = 0;

    addRoute(routes, routeCount, MAX_ROUTES);
    addRoute(routes, routeCount, MAX_ROUTES);

    cout << "Routes in the array:" << endl;
    for (int i = 0; i < routeCount; ++i) {
        cout << "Route Number: " << routes[i].routeNumber << ", Start Point: " << routes[i].startPoint
            << ", End Point: " << routes[i].endPoint << ", Ticket Price: " << routes[i].ticketPrice
            << ", Route Length: " << routes[i].routeLength << endl;
    }

    Path maxRoute = findRouteWithMaxLength(routes, routeCount);
    cout << "Route with maximum length:" << endl;
    cout << "Route Number: " << maxRoute.routeNumber << ", Start Point: " << maxRoute.startPoint
        << ", End Point: " << maxRoute.endPoint << ", Ticket Price: " << maxRoute.ticketPrice
        << ", Route Length: " << maxRoute.routeLength << endl;

    sortRoutesByNumber(routes, routeCount);
    cout << "Routes after sorting by routeNumber:" << endl;
    for (int i = 0; i < routeCount; ++i) {
        cout << "Route Number: " << routes[i].routeNumber << ", Start Point: " << routes[i].startPoint
            << ", End Point: " << routes[i].endPoint << ", Ticket Price: " << routes[i].ticketPrice
            << ", Route Length: " << routes[i].routeLength << endl;
    }

    char point[100];
    cout << "Enter a point to search for routes: ";
    cin.ignore();
    cin.getline(point, 100);
    printRoutesByPoint(routes, routeCount, point);

    double maxLength;
    cout << "Enter maximum length for ticket price increase: ";
    cin >> maxLength;
    increaseTicketPrice(routes, routeCount, maxLength);
    cout << "Routes after increasing ticket price for routes longer than " << maxLength << " km:" << endl;
    for (int i = 0; i < routeCount; ++i) {
        cout << "Route Number: " << routes[i].routeNumber << ", Start Point: " << routes[i].startPoint
            << ", End Point: " << routes[i].endPoint << ", Ticket Price: " << routes[i].ticketPrice
            << ", Route Length: " << routes[i].routeLength << endl;
    }

    int routeNumberToDelete;
    cout << "Enter route number to delete: ";
    cin >> routeNumberToDelete;
    deleteRoute(routes, routeCount, routeNumberToDelete);

    cout << "Routes after operations:" << endl;
    for (int i = 0; i < routeCount; ++i) {
        cout << "Route Number: " << routes[i].routeNumber << ", Start Point: " << routes[i].startPoint
            << ", End Point: " << routes[i].endPoint << ", Ticket Price: " << routes[i].ticketPrice
            << ", Route Length: " << routes[i].routeLength << endl;
    }


}
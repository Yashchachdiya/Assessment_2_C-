#include <iostream>
using namespace std;
double CostPerHour = 18.50;
double CostPerMinute = 0.40;
double CostOfDinner = 20.70;

class Event 
{
private:
    string eventName;
    string firstName;
    string lastName;
    int numGuests;
    int numMinutes;
    int numServers;
    double costForOneServer;
    double totalFoodCost;
    double averageCost;
    double totalCost;

public:
    Event(string name = "", string first = "", string last = "", int guests = 0, int minutes = 0) {
        eventName = name;
        firstName = first;
        lastName = last;
        numGuests = guests;
        numMinutes = minutes;
    }
    void calculateCost() 
	{
        numServers = (double)numGuests / 20;

        double cost1 = (numMinutes / 60) * CostPerHour;
        double cost2 = (numMinutes % 60) * CostPerMinute;
        costForOneServer = cost1 + cost2;

        totalFoodCost = numGuests * CostOfDinner;

        averageCost = totalFoodCost / numGuests;

        totalCost = totalFoodCost + (costForOneServer * numServers);
    }

    void display() 
	{
        cout << "\nEvent Cost Estimation :" ;
        cout << "\n\t Event Name : " << eventName ;
        cout << "\n\t First Name : " << firstName ;
        cout << "\n\t Last Name : " << lastName ;
        cout << "\n\t Number of Guests : " << numGuests ;
        cout << "\n\t Number of Minutes : " << numMinutes;
        cout << "\n\t Number of Servers : " << numServers;
        cout << "\n\t Cost for One Server : " << costForOneServer;
        cout << "\n\t Total Food Cost : " << totalFoodCost;
        cout << "\n\t Average Cost per Person : " << averageCost;
        cout << "\n\t Total Cost : " << totalCost;
    }
};

main() 
{
    
    string eventName;
    cout << "Enter the name of the event: ";
    getline(cin, eventName);
    string firstName, lastName;
    cout << "Enter your first name: ";
    getline(cin, firstName);
    cout << "Enter your last name: ";
    getline(cin, lastName);
    int numGuests, numMinutes;
    cout << "Enter the number of guests: ";
    cin >> numGuests;
    cout << "Enter the number of minutes: ";
    cin >> numMinutes;
    Event E(eventName, firstName, lastName, numGuests, numMinutes);
    E.calculateCost();
    E.display();

}

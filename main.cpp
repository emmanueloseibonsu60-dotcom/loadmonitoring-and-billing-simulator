#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Appliance
{
public:
    string name;
    double power;
    double hours;

    Appliance(string n, double p, double h)
    {
        name = n;
        power = p;
        hours = h;
    }

    double getEnergy()
    {
        return (power * hours) / 1000;
    }
};

vector<Appliance> appliances;

void addAppliance()
{
    string name;
    double power, hours;

    cout << "Enter appliance name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter power in watts: ";
    cin >> power;

    cout << "Enter usage hours per day: ";
    cin >> hours;

    appliances.push_back(Appliance(name, power, hours));

    cout << "Appliance added successfully\n";
}

void showAppliances()
{
    if (appliances.size() == 0)
    {
        cout << "No appliances added yet\n";
        return;
    }

    for (int i = 0; i < appliances.size(); i++)
    {
        cout << i + 1 << ". "
             << appliances[i].name << " - "
             << appliances[i].power << "W - "
             << appliances[i].hours << "hrs\n";
    }
}

int main()
{
    addAppliance();
    showAppliances();

    return 0;
}
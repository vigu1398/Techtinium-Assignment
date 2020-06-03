#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    // Omitted the machines which does not satisfy the price/units ratio.
    // Contains the price of each machine considered for each country.
    vector<int> priceNY = {120, 230, 450, 774, 1400};
    vector<int> priceIndia = {140, 413, 890, 1300};
    vector<int> priceChina = {110, 200, 670, 1180};

    // Contains the units capacity of each machine for each country.
    vector<int> weightsChina = {10, 20, 80, 160};
    vector<int> weightsNY = {10, 20, 40, 80, 160};
    vector<int> weightsIndia = {10, 40, 80, 160};

    // Mapping the name of the machine to its capacity
    map <int, string> weightsMachine;
    map <string, int> numberOfMachines;
    weightsMachine.insert({10, "Large"});
    weightsMachine.insert({20, "XLarge"});
    weightsMachine.insert({40, "2XLarge"});
    weightsMachine.insert({80, "4XLarge"});
    weightsMachine.insert({160, "8XLarge"});
    weightsMachine.insert({320, "10XLarge"});
    int capacity, totalHours, hours, costNY = 0, costIndia = 0, costChina = 0, temp;

    cout << "Enter capacity: ";
    cin >> capacity;
    cout << "Enter hours: ";
    cin >> totalHours;
    temp = capacity;

    cout << "{\n\tOutput : [ \n \t{ \n\t\tregion : New York\n";

    for(int i = priceNY.size() - 1; i >= 0; i--)
    {
        if(capacity >= weightsNY[i])
        {
            hours = capacity/weightsNY[i];
            capacity = capacity - (weightsNY[i] * hours);
            costNY = costNY + priceNY[i] * hours;
            numberOfMachines.insert({weightsMachine[weightsNY[i]], hours}); // Contains the number of machines of a specific type used in NY.
        }
    }
    cout << "\t\ttotal_cost = $" << costNY * totalHours << ", \n";
    cout << "\t\tmachines : [\n";
    for(auto it = numberOfMachines.begin(); it != numberOfMachines.end(); it++)
    {
        cout <<"\t\t\t(" << it->first << ", " << it->second << "), \n";
    }
    cout <<" \t\t] \n\t},\n";
    numberOfMachines.clear();

    cout << "\t{ \n\t\tregion : India\n";
    capacity = temp;
    for(int i = priceIndia.size() - 1; i >= 0; i--)
    {
        if(capacity >= weightsIndia[i])
        {
            hours = capacity/weightsIndia[i];
            capacity = capacity - (weightsIndia[i] * hours);
            costIndia = costIndia + priceIndia[i] * hours;
            numberOfMachines.insert({weightsMachine[weightsIndia[i]], hours}); // Contains the number of machines of a specific type used in India.
        }
    }
    cout << "\t\ttotal_cost = $" << costIndia * totalHours<< ", \n";
    cout << "\t\tmachines : [\n";
    for(auto it = numberOfMachines.begin(); it != numberOfMachines.end(); it++)
    {
        cout <<"\t\t\t(" << it->first << ", " << it->second << "), \n";
    }
    cout <<" \t\t] \n\t},\n";
    numberOfMachines.clear();

    cout << "\t{ \n\t\tregion : China\n";
    capacity = temp;
    for(int i = priceChina.size() - 1; i >= 0; i--)
    {
        if(capacity >= weightsChina[i])
        {
            hours = capacity/weightsChina[i];
            capacity = capacity - (weightsChina[i] * hours);
            costChina = costChina + priceChina[i] * hours;
            numberOfMachines.insert({weightsMachine[weightsChina[i]], hours}); // Contains the number of machines of a specific type used in China.
        }
    }
    cout << "\t\ttotal_cost = $" << costChina * totalHours<< ", \n";
    cout << "\t\tmachines : [\n";
    for(auto it = numberOfMachines.begin(); it != numberOfMachines.end(); it++)
    {
        cout <<"\t\t\t(" << it->first << ", " << it->second << "), \n";
    }
    cout <<" \t\t] \n\t},\n";
    cout << "\t] \n}" ;
    numberOfMachines.clear();
    return 0;
}

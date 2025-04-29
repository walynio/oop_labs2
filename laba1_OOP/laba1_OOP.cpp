#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_CITIES = 10;

struct City
{
    string name;
    string country;
    string region;
    int population;
};

City cities[MAX_CITIES];
int numCities = 0;

ofstream logFile("operations.log", ios::app);

void LogOperation(const string& operation)
{
    logFile << operation << endl;
    cout << operation << endl;
}

void AddCity()
{
    if (numCities < MAX_CITIES)
    {
        City newCity;
        cout << "Enter city name: ";
        cin >> newCity.name;
        cout << "Enter country: ";
        cin >> newCity.country;
        cout << "Enter region: ";
        cin >> newCity.region;
        cout << "Enter population: ";
        cin >> newCity.population;
        cities[numCities++] = newCity;
        LogOperation("City added: " + newCity.name + ", " + newCity.country);
    }
    else
    {
        cout << "Maximum number of cities reached. \n";
    }
}

void DeleteCity(string cityName)
{
    for (int i = 0; i < numCities; ++i)
    {
        if (cities[i].name == cityName)
        {
            for (int j = i; j < numCities - 1; ++j)
            {
                cities[j] = cities[j + 1];
            }
            --numCities;
            LogOperation("City deleted: " + cityName);
            cout << "City " << cityName << " deleted successfully.\n";
            return;
        }
    }
    cout << "City " << cityName << " not found.\n";
}

void ModifyCity(string cityName)
{
    for (int i = 0; i < numCities; ++i)
    {
        if (cities[i].name == cityName)
        {
            cout << "Enter new country: ";
            cin >> cities[i].country;
            cout << "Enter new region: ";
            cin >> cities[i].region;
            cout << "Enter new population: ";
            cin >> cities[i].population;
            LogOperation("City modified: " + cityName + " to " + cities[i].country);
            cout << "City information modified successfully.\n";
            return;
        }
    }
    cout << "City " << cityName << " not found.\n";
}

void SortByCountry()
{
    for (int i = 0; i < numCities - 1; ++i)
    {
        for (int j = 0; j < numCities - i - 1; ++j)
        {
            if (cities[j].country > cities[j + 1].country)
            {
                City temp = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = temp;
            }
        }
    }
    LogOperation("Cities sorted by country.");
}

void SaveCitiesToFile()
{
    ofstream outFile("cities.bin", ios::binary | ios::out);
    if (!outFile)
    {
        cout << "Unable to open file.\n";
        return;
    }

    outFile.write((char*)&numCities, sizeof(numCities));
    outFile.write((char*)cities, numCities * sizeof(City));
    outFile.close();
    LogOperation("Cities saved to file.");
    cout << "Cities saved to file successfully.\n";
}

void LoadCitiesFromFile()
{
    ifstream inFile("cities.bin", ios::binary | ios::in);
    if (!inFile)
    {
        cout << "Unable to open file or file does not exist.\n";
        return;
    }

    inFile.read((char*)&numCities, sizeof(numCities));
    inFile.read((char*)cities, numCities * sizeof(City));
    inFile.close();
    LogOperation("Cities loaded from file.");
    cout << "Cities loaded from file successfully.\n";
}

void ShowCities()
{
    for (int i = 0; i < numCities; ++i)
    {
        cout << endl;
        cout << "City name: " << cities[i].name << endl;
        cout << "Country: " << cities[i].country << endl;
        cout << "Region: " << cities[i].region << endl;
        cout << "Population: " << cities[i].population << endl;
    }
}

void Menu(int choice)
{
    string cityName;

    switch (choice)
    {
    case 1:
        ShowCities();
        break;

    case 2:
        AddCity();
        break;

    case 3:
        cout << "Enter city name to delete: ";
        cin >> cityName;
        DeleteCity(cityName);
        break;

    case 4:
        cout << "Enter city name to modify: ";
        cin >> cityName;
        ModifyCity(cityName);
        break;

    case 5:
        SortByCountry();
        break;

    case 6:
        SaveCitiesToFile();
        break;

    case 7:
        cout << "Exiting program.\n";
        break;

    default:
        cout << "Invalid choice. Please try again.\n";
    }
}

int main()
{
    LoadCitiesFromFile();
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Show cities\n";
        cout << "2. Add city\n";
        cout << "3. Delete city\n";
        cout << "4. Modify city\n";
        cout << "5. Sort cities by country\n";
        cout << "6. Save cities to file\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Menu(choice);
    } while (choice != 7);

    logFile.close();
    return 0;
}

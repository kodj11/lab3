#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <Windows.h>

// Просто удобно хранить инфу в векторе
struct City {
    std::string name;
    std::string country;
    int population;
    double area;
};

// Кол-во городов в стране
int countCitiesInCountry(const std::vector<City>& cities, const std::string& country) {
    int count = 0;

    for (const City& city : cities) {
        if (city.country == country) {
            count++;
        }
    }

    return count;
}

// Более 1 000 000 человек
void printCountriesWithPopulationOverMillion(const std::vector<City>& cities) {
    std::vector<std::string> countries;
	bool a = false;

    for (const City& city : cities) {
        if (city.population > 1000000) {
			for (const std::string& country : countries) {
				if (country == city.country) {
					a = true;
				}
			}			
			if (!a) {
				countries.push_back(city.country);
			}
			
			a = false;
        }
    }

    for (const std::string& country : countries) {
        std::cout << country << std::endl;
    }
}

// Плотность
std::string findMostDenseCity(const std::vector<City>& cities) {
    std::string mostDenseCity;
    double maxDensity = 0.0;

    for (const City& city : cities) {
        double density = static_cast<double>(city.population) / city.area;
        if (density > maxDensity) {
            maxDensity = density;
            mostDenseCity = city.name;
        }
    }

    return mostDenseCity;
}

// Самый населённый 
std::string findMostPopulatedCity(const std::vector<City>& cities, const std::string& country) {
    std::string mostPopulatedCity;
    double maxPopulation = 0;

    for (const City& city : cities) {
        if (city.country == country && static_cast<double>(city.population) > maxPopulation) {
            maxPopulation = city.population;
            mostPopulatedCity = city.name;
        }
		
    }

    return mostPopulatedCity;
}

int main() {
	setlocale(LC_ALL, "Russian");
	
    std::ifstream file("cities.txt");
    std::string line;
	std::vector<City> cities;

    while (std::getline(file, line)) {
        City city;
        file >> city.name >> city.country >> city.population >> city.area;
		//std::cout << city.name << city.country << city.population << city.area << std::endl;
        cities.push_back(city);
    }

	std::wcout << L"Cамый населенный город в России: ";
	std::cout << findMostPopulatedCity(cities, "Russia") << std::endl;
	
	std::wcout << L"Cамый густонаселенный город: ";
	std::cout << findMostDenseCity(cities) << std::endl;
	
	std::wcout << L"Более 1 000 000 человек: " << std::endl;
	printCountriesWithPopulationOverMillion(cities);
	
	std::wcout << L"Кол-во городов в France: ";
	std::cout << countCitiesInCountry(cities, "France") << std::endl;
	
    file.close();
    return 0;
}
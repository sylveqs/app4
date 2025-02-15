#include <iostream>
#include <string>
#include <vector>

struct Monitor {
    std::string manufacturer;
    double screenSize;
    double price;
};

// функция ввода структуры из консоли (принимает указатель)
void inputMonitor(Monitor* monitor) {
    std::cout << "Enter manufacturer: ";
    std::cin >> monitor->manufacturer;

    std::cout << "Enter screen size: ";
    std::cin >> monitor->screenSize;

    std::cout << "Enter price: ";
    std::cin >> monitor->price;
}

// функция вывода структуры
void printMonitor(Monitor& monitor) {
    std::cout << "Manufacturer: " << monitor.manufacturer << std::endl;
    std::cout << "Screen size: " << monitor.screenSize << " cm" << std::endl;
    std::cout << "Price: " << monitor.price << std::endl;
}

// функция создания динамических экземпляров и сохранения в вектор
std::vector<Monitor> createMonitors(int count) {
    std::vector<Monitor> monitors; // хранение созданных объектов
    for (int i = 0; i < count; ++i) {
        Monitor* monitor = new Monitor; // динамическое выделение памяти
        std::cout << "Data entry for monitor #" << i + 1 << std::endl;
        inputMonitor(monitor);
        monitors.push_back(*monitor); // копируем структуру в вектор
        delete monitor;             // освобождаем выделенную память
    }
    return monitors;
}

int main() {
    // создаем два экземпляра структуры Monitor
    Monitor monitor1;
    Monitor monitor2;

    std::cout << "Data entry for monitor 1:" << std::endl;
    inputMonitor(&monitor1);
    std::cout << "Data entry for monitor 2:" << std::endl;
    inputMonitor(&monitor2);

    std::vector<Monitor> allMonitors;

    allMonitors.push_back(monitor1);
    allMonitors.push_back(monitor2);

    //меню
    int choice;
    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Display monitor information 1" << std::endl;
        std::cout << "2. Display monitor information 2" << std::endl;
        std::cout << "3. Create and add monitors to vector" << std::endl;
        std::cout << "4. Display information about all monitors in vector" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Select action: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\nInformation about monitor 1:" << std::endl;
            printMonitor(monitor1);
            break;
        case 2:
            std::cout << "\nInformation about monitor 2:" << std::endl;
            printMonitor(monitor2);
            break;
        case 3: {
            int count;
            std::cout << "How many monitors do you want to create and add? ";
            std::cin >> count;
            std::vector<Monitor> newMonitors = createMonitors(count);

            allMonitors.insert(allMonitors.end(), newMonitors.begin(), newMonitors.end());
            std::cout << "Monitors succesfully created and added to vector!" << std::endl;
            break;
        }
        case 4:
            std::cout << "\nInformation about all monitors:" << std::endl;
            if (allMonitors.empty()) {
                std::cout << "Monitor vector is empty." << std::endl;
            }
            else {
                for (size_t i = 0; i < allMonitors.size(); ++i) {
                    std::cout << "\nМonitor #" << i + 1 << ":" << std::endl;
                    printMonitor(allMonitors[i]);
                }
            }
            break;
        case 0:
            std::cout << "Exit the programm." << std::endl;
            break;
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}

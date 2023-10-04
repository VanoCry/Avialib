#include <iostream>
#include "../avialib/Avialib.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    AviaLib::Avia_DataBase aviaDB;

    // Тестирование функций ввода данных
    AviaLib::Customer customer = aviaDB.InputCustomerFromUser();
    AviaLib::Order order = aviaDB.InputOrderFromUser();
    AviaLib::Ticket ticket = aviaDB.InputTicketFromUser();
    AviaLib::Operation operation = aviaDB.InputOperationFromUser();

    // Добавление данных в базу данных
    aviaDB.AddCustomer(customer);
    aviaDB.AddOrder(order);
    aviaDB.AddTicket(ticket);
    aviaDB.AddOperation(operation);

    // Тестирование функций вывода данных
    std::cout << "Список покупателей:" << std::endl;
    aviaDB.PrintCustomerList();

    std::cout << "\nСписок заказов:" << std::endl;
    aviaDB.PrintOrderList();

    std::cout << "\nСписок билетов:" << std::endl;
    aviaDB.PrintTicketList();

    std::cout << "\nСписок операций:" << std::endl;
    aviaDB.PrintOperationList();

    return 0;
}
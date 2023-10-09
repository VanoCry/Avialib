#include <iostream>
#include "../avialib/Avialib.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    AviaLib::Avia_DataBase aviaDB;

    // Тестирование функций ввода данных
    std::cout << "Ввод Покупателя №1" << std::endl;
    AviaLib::Customer customer1 = aviaDB.InputCustomerFromUser();
    std::cout << "Ввод Покупателя №2" << std::endl;
    AviaLib::Customer customer2 = aviaDB.InputCustomerFromUser();
    std::cout << "Ввод заказа" << std::endl;
    AviaLib::Order order = aviaDB.InputOrderFromUser();
    std::cout << "Ввод билета" << std::endl;
    AviaLib::Ticket ticket = aviaDB.InputTicketFromUser(); 
    std::cout << "Ввод операции" << std::endl;
    AviaLib::Operation operation = aviaDB.InputOperationFromUser();

    // Добавление данных в базу данных
    aviaDB.AddCustomer(customer1);
    aviaDB.AddCustomer(customer2);
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
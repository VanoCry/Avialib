#include "avialib.h"
#include <iostream>
#include <limits>
namespace AviaLib {

    Customer::Customer(const std::string& fio, int tel, const std::string& date, const std::string& address)
        : fio(fio), tel(tel), date(date), address(address) {}

    std::string Customer::GetFIO() const {
        return fio;
    }

    int Customer::GetTel() const {
        return tel;
    }

    std::string Customer::GetDate() const {
        return date;
    }

    std::string Customer::GetAddress() const {
        return address;
    }

    Order::Order(const std::string& company_name, const std::string& distributor, int price, int ticket_id)
        : company_name(company_name), distributor(distributor), price(price), ticket_id(ticket_id) {}

    std::string Order::GetCompany() const {
        return company_name;
    }

    std::string Order::GetDistributor() const {
        return distributor;
    }

    int Order::GetPrice() const {
        return price;
    }

    int Order::GetTicketID() const {
        return ticket_id;
    }

    Ticket::Ticket(const std::string& depart, const std::string& destination, const std::string& distributor, int price, int ticket_id, const std::string& fio)
        : depart(depart), destination(destination), distributor(distributor), price(price), ticket_id(ticket_id), fio(fio) {}

    Ticket::Ticket(const std::string& depart, const std::string& destination, const std::string& distributor, int price, int ticket_id, const Customer& customer)
        : depart(depart), destination(destination), distributor(distributor), price(price), ticket_id(ticket_id), fio(customer.GetFIO()) {}

    std::string Ticket::GetDepart() const {
        return depart;
    }

    std::string Ticket::GetDestination() const {
        return destination;
    }

    std::string Ticket::GetDistributor() const {
        return distributor;
    }

    int Ticket::GetPrice() const {
        return price;
    }

    int Ticket::GetTicketID() const {
        return ticket_id;
    }

    std::string Ticket::GetFIO() const {
        return fio;
    }

    Operation::Operation(const std::string& ticket_operation, const std::string& operation_date, int tel, int ticketID)
        : ticket_operation(ticket_operation), operation_date(operation_date), tel(tel), ticket_id(ticketID) {}

    Operation::Operation(const std::string& ticket_operation, const std::string& operation_date, const Ticket& ticket, const Customer& customer)
        : ticket_operation(ticket_operation), operation_date(operation_date), tel(customer.GetTel()), ticket_id(ticket.GetTicketID()) {}

    std::string Operation::GetOperation() const {
        return ticket_operation;
    }

    std::string Operation::GetOperationDate() const {
        return operation_date;
    }

    int Operation::GetTicketID() const {
        return ticket_id;
    }

    int Operation::GetTel() const {
        return tel;
    }

    Avia_DataBase::Avia_DataBase() {}

    Avia_DataBase::~Avia_DataBase() {}

    void Avia_DataBase::AddCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void Avia_DataBase::AddOrder(const Order& order) {
        orders.push_back(order);
    }

    void Avia_DataBase::AddTicket(const Ticket& ticket) {
        tickets.push_back(ticket);
    }

    void Avia_DataBase::AddOperation(const Operation& operation) {
        operations.push_back(operation);
    }

    void Avia_DataBase::PrintCustomerList() const {
        if (customers.empty()) {
            std::cout << "Список покупателей пуст..." << std::endl;
        }
        else {
            std::cout << "            Список покупателей" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Customer& customer : customers) {
                std::cout << "ФИО: " << customer.GetFIO() << std::endl;
                std::cout << "Телефон: " << customer.GetTel() << std::endl;
                std::cout << "Дата: " << customer.GetDate() << std::endl;
                std::cout << "Адрес: " << customer.GetAddress() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void Avia_DataBase::PrintOrderList() const {
        if (orders.empty()) {
            std::cout << "Список заказов пуст..." << std::endl;
        }
        else {
            std::cout << "              Список Заказов" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Order& order : orders) {
                std::cout << "Название компании: " << order.GetCompany() << std::endl;
                std::cout << "Дистрибьютор: " << order.GetDistributor() << std::endl;
                std::cout << "Цена: " << order.GetPrice() << std::endl;
                std::cout << "ID билета: " << order.GetTicketID() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void Avia_DataBase::PrintTicketList() const {
        if (tickets.empty()) {
            std::cout << "Список билетов пуст..." << std::endl;
        }
        else {
            std::cout << "            Список билетов" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Ticket& ticket : tickets) {
                std::cout << "Отправление: " << ticket.GetDepart() << std::endl;
                std::cout << "Прибытие: " << ticket.GetDestination() << std::endl;
                std::cout << "Дистрибьютор: " << ticket.GetDistributor() << std::endl;
                std::cout << "Цена: " << ticket.GetPrice() << std::endl;
                std::cout << "ID билета: " << ticket.GetTicketID() << std::endl;
                std::cout << "ФИО: " << ticket.GetFIO() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void Avia_DataBase::PrintOperationList() const {
        if (operations.empty()) {
            std::cout << "Список операций пуст..." << std::endl;
        }
        else {
            std::cout << "              Список операций" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Operation& operation : operations) {
                std::cout << "Тип операции: " << operation.GetOperation() << std::endl;
                std::cout << "Дата операции: " << operation.GetOperationDate() << std::endl;
                std::cout << "ID билета: " << operation.GetTicketID() << std::endl;
                std::cout << "Телефон: " << operation.GetTel() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }
    Customer Avia_DataBase::InputCustomerFromUser() {
        std::string fio;
        int tel;
        std::string date;
        std::string address;

        std::cout << "Введите ФИО: ";
        std::cin.ignore();
        std::getline(std::cin, fio);

        std::cout << "Введите телефон: ";
        while (true) {
            std::string telStr;
            std::getline(std::cin, telStr);
            if (IsInteger(telStr)) {
                tel = std::stoi(telStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректный номер телефона: ";
            }
        }

        std::cout << "Введите дату: ";
        std::getline(std::cin, date);

        std::cout << "Введите адрес: ";
        std::getline(std::cin, address);

        return Customer(fio, tel, date, address);
    }

    Order Avia_DataBase::InputOrderFromUser() {
        std::string company_name;
        std::string distributor;
        int price;
        int ticket_id;

        std::cout << "Введите название компании: ";
        std::cin.ignore();
        std::getline(std::cin, company_name);

        std::cout << "Введите дистрибьютора: ";
        std::getline(std::cin, distributor);

        std::cout << "Введите цену: ";
        while (true) {
            std::string priceStr;
            std::getline(std::cin, priceStr);
            if (IsInteger(priceStr)) {
                price = std::stoi(priceStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректную цену: ";
            }
        }

        std::cout << "Введите номер билета: ";
        while (true) {
            std::string ticketIdStr;
            std::getline(std::cin, ticketIdStr);
            if (IsInteger(ticketIdStr)) {
                ticket_id = std::stoi(ticketIdStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректный номер билета: ";
            }
        }

        return Order(company_name, distributor, price, ticket_id);
    }

    Ticket Avia_DataBase::InputTicketFromUser() {
        std::string depart;
        std::string destination;
        std::string distributor;
        int price;
        int ticket_id;
        std::string fio;

        std::cout << "Введите место отправления: ";
        std::cin.ignore();
        std::getline(std::cin, depart);

        std::cout << "Введите место назначения: ";
        std::getline(std::cin, destination);

        std::cout << "Введите дистрибьютора: ";
        std::getline(std::cin, distributor);

        std::cout << "Введите цену: ";
        while (true) {
            std::string priceStr;
            std::getline(std::cin, priceStr);
            if (IsInteger(priceStr)) {
                price = std::stoi(priceStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректную цену: ";
            }
        }

        std::cout << "Введите номер билета: ";
        while (true) {
            std::string ticketIdStr;
            std::getline(std::cin, ticketIdStr);
            if (IsInteger(ticketIdStr)) {
                ticket_id = std::stoi(ticketIdStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректный номер билета: ";
            }
        }

        std::cout << "Введите ФИО: ";
        std::getline(std::cin, fio);

        return Ticket(depart, destination, distributor, price, ticket_id, fio);
    }

    Operation Avia_DataBase::InputOperationFromUser() {
        std::string ticket_operation;
        std::string operation_date;
        int ticket_id;
        int tel;

        std::cout << "Введите тип операции (выдача билета или возврат билета): ";
        std::cin.ignore();
        std::getline(std::cin, ticket_operation);

        std::cout << "Введите дату операции: ";
        std::getline(std::cin, operation_date);

        std::cout << "Введите номер билета: ";
        while (true) {
            std::string ticketIdStr;
            std::getline(std::cin, ticketIdStr);
            if (IsInteger(ticketIdStr)) {
                ticket_id = std::stoi(ticketIdStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректный номер билета: ";
            }
        }

        std::cout << "Введите номер телефона: ";
        while (true) {
            std::string telStr;
            std::getline(std::cin, telStr);
            if (IsInteger(telStr)) {
                tel = std::stoi(telStr);
                break;
            }
            else {
                std::cout << "Ошибка: Введите корректный номер телефона: ";
            }
        }

        return Operation(ticket_operation, operation_date, ticket_id, tel);
    }

    bool Avia_DataBase::IsInteger(const std::string& str) const {
        if (str.empty()) return false;
        for (char c : str) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    }

}


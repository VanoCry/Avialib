#include "pch.h"
#include "avialib.h"
#include <iostream>
using namespace std;
namespace AviaLib {

    // Customer class methods

    Customer::Customer(string fio, int tel, string date, string adress)
        : fio(fio), tel(tel), date(date), adress(adress) {}

    string Customer::GetFIO() const {
        return fio;
    }

    int Customer::GetTel() const {
        return tel;
    }

    string Customer::GetDate() const {
        return date;
    }

    string Customer::GetAdress() const {
        return adress;
    }

    Customer Customer::InputCustomer() {
        string fio;
        int tel;
        string date;
        string address;

        cout << "Введите ФИО: ";
        getline(cin, fio);

        cout << "Введите телефон: ";
        cin >> tel;

        cin.ignore(); // Clear the input buffer

        cout << "Введите дату: ";
        getline(cin, date);

        cout << "Введите адрес: ";
        getline(cin, address);

        return Customer(fio, tel, date, address);
    }

    // Order class methods

    Order::Order(string company_name, const Ticket& ticketObj)
        : company_name(company_name), distributor(ticketObj.getDistributor()), price(ticketObj.getPrice()), ticket_id(ticketObj.getTicketID()) {}

    Order::Order(string company_name, string distributor, int price, int ticket_id)
        : company_name(company_name), distributor(distributor), price(price), ticket_id(ticket_id) {}

    string Order::getCompany() const {
        return company_name;
    }

    string Order::getDistributor() const {
        return distributor;
    }

    int Order::getPrice() const {
        return price;
    }

    int Order::getTicketID() const {
        return ticket_id;
    }

    Order Order::InputOrder() {
        string company_name;
        string distributor;
        int price;
        int ticket_id;

        cin.ignore(); // Clear the input buffer

        cout << "Введите название компании: ";
        getline(cin, company_name);

        cout << "Введите дистрибьютора: ";
        getline(cin, distributor);

        cout << "Введите цену: ";
        cin >> price;

        cout << "Введите номер билета: ";
        cin >> ticket_id;

        cin.ignore(); // Clear the input buffer

        return Order(company_name, distributor, price, ticket_id);
    }

    // Ticket class methods

    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio)
        : depart(depart), destination(destination), distributor(distributor), price(price), ticket_id(ticket_id), fio(fio) {}

    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, const Customer& new_cust)
        : depart(depart), destination(destination), distributor(distributor), price(price), ticket_id(ticket_id), fio(new_cust.GetFIO()) {}

    string Ticket::getDepart() const {
        return depart;
    }

    string Ticket::getDestination() const {
        return destination;
    }

    string Ticket::getDistributor() const {
        return distributor;
    }

    int Ticket::getPrice() const {
        return price;
    }

    int Ticket::getTicketID() const {
        return ticket_id;
    }

    string Ticket::getFIO() const {
        return fio;
    }

    Ticket Ticket::InputTicket() {
        string depart;
        string destination;
        string distributor;
        int price;
        int ticket_id;
        string fio;

        cin.ignore(); // Clear the input buffer

        cout << "Введите место отправления: ";
        getline(cin, depart);

        cout << "Введите место назначения: ";
        getline(cin, destination);

        cout << "Введите дистрибьютора: ";
        getline(cin, distributor);

        cout << "Введите цену: ";
        cin >> price;

        cout << "Введите номер билета: ";
        cin >> ticket_id;

        cin.ignore(); // Clear the input buffer

        cout << "Введите ФИО: ";
        getline(cin, fio);

        return Ticket(depart, destination, distributor, price, ticket_id, fio);
    }

    // Operation class methods

    Operation::Operation(string ticket_operation, string operation_date, int tel, int ticketID)
        : ticket_operation(ticket_operation), operation_date(operation_date), tel(tel), ticket_id(ticketID) {}

    Operation::Operation(string ticket_operation, string operation_date, const Ticket& new_ticket, const Customer& new_cust)
        : ticket_operation(ticket_operation), operation_date(operation_date), tel(new_cust.GetTel()), ticket_id(new_ticket.getTicketID()) {}

    string Operation::getOperation() const {
        return ticket_operation;
    }

    string Operation::getOperationDate() const {
        return operation_date;
    }

    int Operation::getTicketID() const {
        return ticket_id;
    }

    int Operation::getTel() const {
        return tel;
    }

    Operation Operation::InputOperation() {
        string ticket_operation;
        string operation_date;
        int ticket_id;
        int tel;

        cin.ignore(); // Clear the input buffer

        cout << "Введите тип операции (выдача билета или возврат билета): ";
        getline(cin, ticket_operation);

        cout << "Введите дату операции: ";
        getline(cin, operation_date);

        cout << "Введите номер билета: ";
        cin >> ticket_id;

        cout << "Введите номер телефона: ";
        cin >> tel;

        cin.ignore(); // Clear the input buffer

        return Operation(ticket_operation, operation_date, ticket_id, tel);
    }

    // Avia_DataBase class methods

    Avia_DataBase::Avia_DataBase()
        : order_list(nullptr), customer_list(nullptr), operation_list(nullptr), ticket_list(nullptr),
        order_count(0), customer_count(0), operation_count(0), ticket_count(0) {}

    Avia_DataBase::~Avia_DataBase() {
        delete[] order_list;
        delete[] customer_list;
        delete[] operation_list;
        delete[] ticket_list;
    }

    void Avia_DataBase::AddCustomerToDB(const Customer& new_cast) {
        Customer* new_customer_list = new Customer[customer_count + 1];
        for (size_t i = 0; i < customer_count; ++i) {
            new_customer_list[i] = customer_list[i];
        }
        new_customer_list[customer_count] = new_cast;
        delete[] customer_list;
        customer_list = new_customer_list;
        customer_count++;
    }

    void Avia_DataBase::AddOrderToDB(const Order& new_order) {
        Order* new_order_list = new Order[order_count + 1];
        for (size_t i = 0; i < order_count; ++i) {
            new_order_list[i] = order_list[i];
        }
        new_order_list[order_count] = new_order;
        delete[] order_list;
        order_list = new_order_list;
        order_count++;
    }

    void Avia_DataBase::AddTicketToDB(const Ticket& new_ticket) {
        Ticket* new_ticket_list = new Ticket[ticket_count + 1];
        for (size_t i = 0; i < ticket_count; ++i) {
            new_ticket_list[i] = ticket_list[i];
        }
        new_ticket_list[ticket_count] = new_ticket;
        delete[] ticket_list;
        ticket_list = new_ticket_list;
        ticket_count++;
    }

    void Avia_DataBase::AddOperationToDB(const Operation& new_op) {
        Operation* new_operation_list = new Operation[operation_count + 1];
        for (size_t i = 0; i < operation_count; ++i) {
            new_operation_list[i] = operation_list[i];
        }
        new_operation_list[operation_count] = new_op;
        delete[] operation_list;
        operation_list = new_operation_list;
        operation_count++;
    }

    void Avia_DataBase::PrintCustomerList() const {
        if (customer_count > 0) {
            cout << "            Список покупателей" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < customer_count; ++i) {
                cout << "ФИО: " << customer_list[i].GetFIO() << endl;
                cout << "Телефон: " << customer_list[i].GetTel() << endl;
                cout << "Дата: " << customer_list[i].GetDate() << endl;
                cout << "Адрес: " << customer_list[i].GetAdress() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "Список покупателей пуст..." << endl;
    }

    void Avia_DataBase::PrintTicketList() const {
        if (ticket_count > 0) {
            cout << "            Список билетов" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < ticket_count; ++i) {
                cout << "Билет #" << i + 1 << endl;
                cout << "Отправление: " << ticket_list[i].getDepart() << endl;
                cout << "Прибытие: " << ticket_list[i].getDestination() << endl;
                cout << "Дистрибьютор: " << ticket_list[i].getDistributor() << endl;
                cout << "Цена: " << ticket_list[i].getPrice() << endl;
                cout << "ID билета: " << ticket_list[i].getTicketID() << endl;
                cout << "ФИО: " << ticket_list[i].getFIO() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "Список билетов пуст..." << endl;
    }

    void Avia_DataBase::PrintOrderList() const {
        if (order_count > 0) {
            cout << "              Список Заказов" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < order_count; ++i) {
                cout << "Заказ #" << i + 1 << endl;
                cout << "Название компании: " << order_list[i].getCompany() << endl;
                cout << "Дистрибьютор: " << order_list[i].getDistributor() << endl;
                cout << "Цена: " << order_list[i].getPrice() << endl;
                cout << "ID билета: " << order_list[i].getTicketID() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "Список заказов пуст..." << endl;
    }

    void Avia_DataBase::PrintOperationList() const {
        if (operation_count > 0) {
            cout << "              Список операций" << endl;
            cout << "-----------------------------------------" << endl;
            for (size_t i = 0; i < operation_count; ++i) {
                cout << "Операция #" << i + 1 << endl;
                cout << "Тип операции: " << operation_list[i].getOperation() << endl;
                cout << "Дата операции: " << operation_list[i].getOperationDate() << endl;
                cout << "ID билета: " << operation_list[i].getTicketID() << endl;
                cout << "Телефон: " << operation_list[i].getTel() << endl;
                cout << "-----------------------------------------" << endl;
            }
        }
        else cout << "Список операций пуст..." << endl;
    }
}
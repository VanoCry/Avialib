#pragma once
#include <string>
#include <vector>

namespace AviaLib {

    class Customer {
    private:
        std::string fio;
        std::string tel;
        std::string date;
        std::string address;

    public:
        Customer(const std::string& fio, const std::string& tel, const std::string& date, const std::string& address);
        std::string GetFIO() const;
        std::string GetTel() const;
        std::string GetDate() const;
        std::string GetAddress() const;
    };

    class Order {
    private:
        std::string company_name;
        std::string distributor;
        int price;
        int ticket_id;

    public:
        Order(const std::string& company_name, const std::string& distributor, int price, int ticket_id);
        std::string GetCompany() const;
        std::string GetDistributor() const;
        int GetPrice() const;
        int GetTicketID() const;
    };

    class Ticket {
    private:
        std::string depart;
        std::string destination;
        std::string distributor;
        int price;
        int ticket_id;
        std::string fio;

    public:
        Ticket(const std::string& depart, const std::string& destination, const std::string& distributor, int price, int ticket_id, const std::string& fio);
        Ticket(const std::string& depart, const std::string& destination, const std::string& distributor, int price, int ticket_id, const Customer& customer);
        std::string GetDepart() const;
        std::string GetDestination() const;
        std::string GetDistributor() const;
        int GetPrice() const;
        int GetTicketID() const;
        std::string GetFIO() const;
    };

    class Operation {
    private:
        std::string ticket_operation;
        std::string operation_date;
        int ticket_id;
        std::string tel;

    public:
        Operation(const std::string& ticket_operation, const std::string& operation_date, const std::string& tel, int ticketID);
        Operation(const std::string& ticket_operation, const std::string& operation_date, const Ticket& ticket, const Customer& customer);
        std::string GetOperation() const;
        std::string GetOperationDate() const;
        int GetTicketID() const;
        std::string GetTel() const;
    };

    class Avia_DataBase {
    public:
        Avia_DataBase();
        ~Avia_DataBase();

        void AddCustomer(const Customer& customer);
        void AddOrder(const Order& order);
        void AddTicket(const Ticket& ticket);
        void AddOperation(const Operation& operation);

        void PrintCustomerList() const;
        void PrintTicketList() const;
        void PrintOrderList() const;
        void PrintOperationList() const;
        Customer InputCustomerFromUser();
        Order InputOrderFromUser();
        Ticket InputTicketFromUser();
        Operation InputOperationFromUser();

    private:
        bool IsInteger(const std::string& str) const;

    private:
        std::vector<Customer> customers;
        std::vector<Order> orders;
        std::vector<Ticket> tickets;
        std::vector<Operation> operations;
    };
}



#pragma once
#include <string>

namespace AviaLib {

    class Customer {
    private:
        string fio;
        int tel;
        string date;
        string adress;

    public:
        Customer() = default;
        Customer(string fio, int tel, string date, string adress);
        string GetFIO() const;
        int GetTel() const;
        string GetDate() const;
        string GetAdress() const;
        static Customer InputCustomer();
    };

    class Order {
    private:
        string company_name;
        string distributor;
        int price;
        int ticket_id;

    public:
        Order() = default;
        Order(string company_name, const Ticket& ticketObj);
        Order(string company_name, string distributor, int price, int ticket_id);
        string getCompany() const;
        string getDistributor() const;
        int getPrice() const;
        int getTicketID() const;
        static Order InputOrder();
    };

    class Ticket {
    private:
        string depart;
        string destination;
        string distributor;
        int price;
        int ticket_id;
        string fio;

    public:
        Ticket() = default;
        Ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio);
        Ticket(string depart, string destination, string distributor, int price, int ticket_id, const Customer& new_cust);
        string getDepart() const;
        string getDestination() const;
        string getDistributor() const;
        int getPrice() const;
        int getTicketID() const;
        string getFIO() const;
        static Ticket InputTicket();
    };

    class Operation {
    private:
        string ticket_operation;
        string operation_date;
        int ticket_id;
        int tel;

    public:
        Operation() = default;
        Operation(string ticket_operation, string operation_date, int tel, int ticketID);
        Operation(string ticket_operation, string operation_date, const Ticket& new_ticket, const Customer& new_cust);
        string getOperation() const;
        string getOperationDate() const;
        int getTicketID() const;
        int getTel() const;
        static Operation InputOperation();
    };

    class Avia_DataBase {
    public:
        Order* order_list;
        Customer* customer_list;
        Operation* operation_list;
        Ticket* ticket_list;
        size_t order_count;
        size_t customer_count;
        size_t operation_count;
        size_t ticket_count;

    public:
        Avia_DataBase();
        ~Avia_DataBase();
        void PrintCustomerList() const;
        void PrintTicketList() const;
        void PrintOrderList() const;
        void PrintOperationList() const;
        static Avia_DataBase* createAviaDataBase();
        void destroyAviaDataBase();
        void AddCustomerToDB(const Customer& new_cast);
        void AddOrderToDB(const Order& new_order);
        void AddTicketToDB(const Ticket& new_ticket);
        void AddOperationToDB(const Operation& new_op);
    };
}

using Customer = AviaLib::Customer;
using Order = AviaLib::Order;
using Ticket = AviaLib::Ticket;
using Avia_DataBase = AviaLib::Avia_DataBase;

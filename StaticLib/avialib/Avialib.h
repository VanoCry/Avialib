#pragma once
#include <vector>
using namespace std;
/*
* Уже решаю проблему описанную в имейле
* конструкторы и деструкторы уже прописаны
* Сначала создаётся класс покупателя, потом билета, затем
* Заказа а за ним класс операции
*/
namespace AviaLib {
    //-----------------------------------------------------------------------------------------
    class Customer {
    private:
        string fio;
        int tel;
        string date;
        string adress;
    public:
        Customer();
        Customer(string fio, int tel, string date, string adress);
        string GetFIO();
        int GetTel();
        string GetDate();
        string GetAdress();
    };
    //-----------------------------------------------------------------------------------------
    class Order {
    private:
        string company_name;
        string distributor;
        int price;
        int ticket_id;
    public:
        Order();
        Order(string company_name,static Ticket& ticketObj);
        string getCompany();
        string getDistributor();
        int getPrice();
        int getTicketID();
    };
    //-----------------------------------------------------------------------------------------
    class Ticket {
    private:
        string depart;
        string destination;
        string distributor;
        int price;
        int ticket_id;
        string fio;
    public:
        Ticket();
        Ticket(string depart, string destination, string distributor, int price, int ticket_id, static Customer& new_cust);
        string getDepart();
        string getDestination();
        string getDistributor();
        int getPrice();
        int getTicketID();
        string getFIO();
    };
    //-----------------------------------------------------------------------------------------
     class Operation {
private:
    string ticket_operation; // "выдача билета" или "возврат билета"
    string operation_date;
    int ticket_id;
    int tel;
public:
    Operation();
    Operation(string ticket_operation, string operation_date, Ticket& new_ticket, Customer& new_cust) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = new_cust.GetTel();
        this->ticket_id = new_ticket.getTicketID();
    }
    string getOperation();
    string getOperationDate();
    int getTicketID();
    int getTel();
};
    //-----------------------------------------------------------------------------------------
     class Avia_DataBase {
     private:
         vector<Order> order_list;
         vector<Customer> customer_list;
         vector<Operation> operation_list;
         vector<Ticket> ticket_list;
    };
}

























/*
// Структура "Покупатель"
struct customer {
    std::string fio;
    int tel;
    std::string date;
    std::string adress;
};

// Структура "Билет"

// Структура "Операция"
struct operation {
    std::string ticket_operation; // "выдача билета" или "возврат билета"
    std::string operation_date;
    int ticket_id;
    int tel;
};

// Структура "Авиа_база_данных"
struct avia_database {
    std::vector<order> order_list;
    std::vector<customer> customer_list;
    std::vector<operation> operation_list;
    std::vector<ticket> ticket_list;

    
};*/



    /*
    class add_operations {
    public:
        static void addOrder(avia_database& db, const order& newOrder);
        static void addCustomer(avia_database& db, const customer& newCustomer);
        static void addTicket(avia_database& db, const ticket& newTicket);
        static void addOperation(avia_database& db, const operation& newOperation);
    };
    class remove_operations {
    public:
        static void removeOrderByID(avia_database& db, int orderID);
        static void removeCustomerByFIO(avia_database& db, const std::string& fio);
    };
    class find_operations {
    public:
        static order findOrderByID(const avia_database& db, int orderID);
        static customer findCustomerByFIO(const avia_database& db, const std::string& fio);
    };
}
// Псевдонимы для классов
using AviaAdd = AviaLib::add_operations;
using AviaRemove = AviaLib::remove_operations;
using AviaFind = AviaLib::find_operations;*/
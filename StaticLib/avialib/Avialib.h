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
        void AddCustomerToDB(struct Avia_DataBase* db, Customer& new_cast);
        Customer InputCustomer();
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
        void AddOrderToDB(struct Avia_DataBase* db, Order& new_order);
        Order InputOrder();
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
        Ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio);
        Ticket(string depart, string destination, string distributor, int price, int ticket_id, static Customer& new_cust);
        string getDepart();
        string getDestination();
        string getDistributor();
        int getPrice();
        int getTicketID();
        string getFIO();
        void AddTicketToDB(struct Avia_DataBase* db, struct Ticket& new_ticket);
        Ticket InputTicket();
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
    Operation(string ticket_operation, string operation_date, int tel, int ticketID);
    Operation(string ticket_operation, string operation_date, static Ticket& new_ticket, static Customer& new_cust);
    string getOperation();
    string getOperationDate();
    int getTicketID();
    int getTel();
    void AddOperationToDB(struct Avia_DataBase* db, struct Operation& new_op);
    Operation InputOperation();
};
    //-----------------------------------------------------------------------------------------
     class Avia_DataBase {
     public:
         struct Order* order_list;
         struct Customer* customer_list;
         struct Operation* operation_list;
         struct Ticket* ticket_list;
         size_t order_count;
         size_t customer_count;
         size_t operation_count;
         size_t ticket_count;
     public:
         struct Avia_DataBase* createAviaDataBase();
         // Функция для освобождения памяти базы данных
         void destroyAviaDataBase(struct Avia_DataBase* db);
    };
}

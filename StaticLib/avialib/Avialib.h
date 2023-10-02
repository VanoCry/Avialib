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
        void AddOrderToDB(struct Avia_DataBase* db, Order& new_order);
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
         struct Avia_DataBase* createAviaDataBase() {
             struct Avia_DataBase* db = (struct Avia_DataBase*)malloc(sizeof(struct Avia_DataBase));
             if (db == NULL) {
                 return NULL; // Ошибка выделения памяти
             }

             // Инициализируем списки как пустые
             db->order_list = NULL;
             db->customer_list = NULL;
             db->operation_list = NULL;
             db->ticket_list = NULL;
             db->order_count = 0;
             db->customer_count = 0;
             db->operation_count = 0;
             db->ticket_count = 0;

             return db;
         }
         // Функция для освобождения памяти базы данных
         void destroyAviaDataBase(struct Avia_DataBase* db) {
             if (db == NULL) {
                 return;
             }

             // Освобождаем память для списков и их элементов
             free(db->order_list);
             free(db->customer_list);
             free(db->operation_list);
             free(db->ticket_list);

         // Освобождаем память для самой базы данных
             free(db);
         }
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
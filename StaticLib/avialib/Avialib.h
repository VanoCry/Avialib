#pragma once
#include <string>
#include <vector>

// Структура "Заказ"
struct order {
    std::string company_name;
    std::string distributor;
    int price;
    int ticket_id; 
};

// Структура "Покупатель"
struct customer {
    std::string fio;
    int tel;
    std::string date;
    std::string adress;
};

// Структура "Билет"
struct ticket {
    std::string depart;
    std::string destination;
    std::string distributor;
    std::string price;
    std::string ticket_id;
    std::string fio; 
};

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
};

namespace AviaLib {
    
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
using AviaFind = AviaLib::find_operations;
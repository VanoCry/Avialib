#pragma once
#include <vector>
using namespace std;

namespace AviaLib {
    //-----------------------------------------------------------------------------------------
    class Order {
    private:
        string company_name;
        string distributor;
        int price;
        int ticket_id;
    public:
        Order();
        Order(string company_name, string distributor, int price, int ticket_id) {
            this->company_name = company_name;
            this->distributor = distributor;
            this->price = price;
            this->ticket_id = ticket_id;
        }
        string getCompany() {
            return company_name;
        }
        string getDistributor() {
            return distributor;
        }
        int getPrice() {
            return price;
        }
        int getTicketID() {
            return ticket_id;
        }
    };
    //-----------------------------------------------------------------------------------------
    class ticket {
    private:
        string depart;
        string destination;
        string distributor;
        int price;
        int ticket_id;
        string fio;
    public:
        ticket();
        ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio) {
            this->depart = depart;
            this->destination = destination;
            this->distributor = distributor;
            this->price = price;
            this->ticket_id = ticket_id;
            this->fio = fio;
        }
        string getDepart() {
            return depart;
        }
        string getDestination() {
            return destination;
        }
        string getDistributor(){
            return distributor;
        }
        int getPrice() {
            return price;
        }
        int getTicketID() {
            return ticket_id;
        }
        string getFIO() {
            return fio;
        }
    };
    //-----------------------------------------------------------------------------------------
     class operation {
private:
    string ticket_operation; // "выдача билета" или "возврат билета"
    string operation_date;
    int ticket_id;
    int tel;
public:
    operation();
    operation(string ticket_operation, string operation_date, int ticket_id, int tel) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = tel;
        this->ticket_id = ticket_id;
    }
    string getOperation() {
        return ticket_operation;
    }
    string getOperationDate() {
        return operation_date;
    }
    int getTicketID() {
        return ticket_id;
    }
    int getTel() {
        return tel;
    }
};
    //-----------------------------------------------------------------------------------------

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
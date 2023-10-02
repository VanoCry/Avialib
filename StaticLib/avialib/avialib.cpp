#include "pch.h"
#include "framework.h"
#include "avialib.h"
#include <string> 
#include <iostream>
/*
* Уже решаю проблему описанную в имейле
* конструкторы и деструкторы уже прописаны
*
*
*/
namespace AviaLib {
    Customer::Customer(string fio, int tel, string date, string adress) {
        this->fio = fio;
        this->tel = tel;
        this->date = date;
        this->adress = adress;
    }
    string Customer::GetFIO() {
        return fio;
    }
    int Customer::GetTel() {
        return tel;
    }
    string Customer::GetDate() {
        return date;
    }
    string Customer::GetAdress() {
        return adress;
    }
    void Customer::AddCustomerToDB(struct Avia_DataBase* db, Customer& new_cast) {
        struct Customer customerToAdd(
            new_cast.GetFIO(),
            new_cast.GetTel(),
            new_cast.GetDate(),
            new_cast.GetAdress()
        );
        // Увеличиваем размер списка покупателей и добавляем нового покупателя
        db->customer_count++;
        db->customer_list = (struct Customer*)realloc(db->customer_list, db->customer_count * sizeof(struct Customer));
        db->customer_list[db->customer_count - 1] = customerToAdd;
    }
    //-----------------------------------------------------------------------------------------
    Order::Order(string company_name,static Ticket& ticketObj) {
        this->company_name = company_name;
        this->distributor = ticketObj.getDistributor();
        this->price = ticketObj.getPrice();
        this->ticket_id = ticketObj.getTicketID();
    }
    string Order::getCompany() {
        return company_name;
    }

    string Order::getDistributor() {
        return distributor;
    }

    int Order::getPrice() {
        return price;
    }

    int Order::getTicketID() {
        return ticket_id;
    }
    void Order::AddOrderToDB(struct Avia_DataBase* db, Order& new_order) {
        // Выделяем память для нового заказа
        struct Order new_order;
        new_order.company_name = new_order.getCompany(); // Выделение памяти и копирование строки
        new_order.distributor = new_order.getDistributor();
        new_order.price = new_order.getPrice();
        new_order.ticket_id = new_order.getTicketID();

        // Увеличиваем размер списка заказов и добавляем новый заказ
        db->order_count++;
        db->order_list = (struct Order*)realloc(db->order_list, db->order_count * sizeof(struct Order));
        db->order_list[db->order_count - 1] = new_order;
    }
    //-----------------------------------------------------------------------------------------
    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, string fio) {
        this->depart = depart;
        this->destination = destination;
        this->distributor = distributor;
        this->price = price;
        this->ticket_id = ticket_id;
        this->fio = fio;
    }
    Ticket::Ticket(string depart, string destination, string distributor, int price, int ticket_id, Customer& new_cust) {
        this->depart = depart;
        this->destination = destination;
        this->distributor = distributor;
        this->price = price;
        this->ticket_id = ticket_id;
        this->fio = new_cust.GetFIO();
        }
    string Ticket::getDepart() {
        return depart;
    }
    string Ticket::getDestination() {
        return destination;
    }
    string Ticket::getDistributor() {
        return distributor;
    }
    int Ticket::getPrice() {
        return price;
    }
    int Ticket::getTicketID() {
        return ticket_id;
    }
    string Ticket::getFIO() {
        return fio;
    }
    void AddTicketToDB(struct Avia_DataBase* db, struct Ticket& new_ticket) {
        // Выделяем память для нового билета
        // Заполняем новый билет данными из параметра new_ticket
        struct Ticket ticketToAdd(
            new_ticket.getDepart(),
            new_ticket.getDestination(),
            new_ticket.getDistributor(),
            new_ticket.getPrice(),
            new_ticket.getTicketID(),
            new_ticket.getFIO()
        );
        // Увеличиваем размер списка билетов и добавляем новый билет
        db->ticket_count++;
        db->ticket_list = (struct Ticket*)realloc(db->ticket_list, db->ticket_count * sizeof(struct Ticket));
        db->ticket_list[db->ticket_count - 1] = ticketToAdd;
    }
    //-----------------------------------------------------------------------------------------
    Operation::Operation(string ticket_operation, string operation_date, static Ticket& new_ticket, static Customer& new_cust) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = new_cust.GetTel();
        this->ticket_id = new_ticket.getTicketID();
    }
    Operation::Operation(string ticket_operation, string operation_date, int tel, int ticketID) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = tel;
        this->ticket_id = ticketID;
    }
    string Operation::getOperation() {
        return ticket_operation;
    }
    string Operation::getOperationDate() {
        return operation_date;
    }
    int Operation::getTicketID() {
        return ticket_id;
    }
    int Operation::getTel() {
        return tel;
    }
    void AddOperationToDB(struct Avia_DataBase* db, struct Operation& new_op) {
        // Выделяем память для нового билета
        // Заполняем новый билет данными из параметра new_ticket
        struct Operation opToAdd(
            new_op.getOperation(),
            new_op.getOperationDate(),
            new_op.getTicketID(),
            new_op.getTel()
        );
        // Увеличиваем размер списка билетов и добавляем новый билет
        db->operation_count++;
        db->operation_list = (struct Operation*)realloc(db->operation_list, db->operation_count * sizeof(struct Operation));
        db->operation_list[db->operation_count - 1] = opToAdd;
    }
    //-----------------------------------------------------------------------------------------
}











/*
   // Операции добавления
   void addOrder(avia_database& db, const order& newOrder) {
       db.order_list.push_back(newOrder);
   }

   void addCustomer(avia_database& db, const customer& newCustomer) {
       db.customer_list.push_back(newCustomer);
   }

   void addTicket(avia_database& db, const ticket& newTicket) {
       db.ticket_list.push_back(newTicket);
   }

   void addOperation(avia_database& db, const operation& newOperation) {
       db.operation_list.push_back(newOperation);
   }
   // Операция удаления
   void removeOrderByID(avia_database& db, int orderID) {
       auto it = std::remove_if(db.order_list.begin(), db.order_list.end(),
           [orderID](const order& o) { return o.ticket_id == orderID; });

       if (it != db.order_list.end()) {
           db.order_list.erase(it, db.order_list.end());
       }
       else {
           std::cout << "Ошибка: Заказ с указанным ID не найден." << std::endl;
       }
   }

   void removeCustomerByFIO(avia_database& db, const std::string& fio) {
       auto it = std::remove_if(db.customer_list.begin(), db.customer_list.end(),
           [fio](const customer& c) { return c.fio == fio; });

       if (it != db.customer_list.end()) {
           db.customer_list.erase(it, db.customer_list.end());
       }
       else {
           std::cout << "Ошибка: Покупатель с указанным ФИО не найден." << std::endl;
       }
   }

   // Операции поиска

   order findOrderByID(const avia_database& db, int orderID) {
       for (const auto& order : db.order_list) {
           if (order.ticket_id == orderID) {
               return order;
           }
       }
       std::cout << "Заказ с указанным ID не существует." << std::endl;
       return order{}; // Вернуть "пустой" объект order
   }

   customer findCustomerByFIO(const avia_database& db, const std::string& fio) {
       for (const auto& customer : db.customer_list) {
           if (customer.fio == fio) {
               return customer;
           }
       }
       std::cout << "Пользователь с указанным ФИО не существует." << std::endl;
       return customer{}; // Вернуть "пустой" объект customer
   }

   */
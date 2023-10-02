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
    //-----------------------------------------------------------------------------------------
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
    //-----------------------------------------------------------------------------------------
    Operation::Operation(string ticket_operation, string operation_date,static Ticket& new_ticket,static Customer& new_cust) {
        this->ticket_operation = ticket_operation;
        this->operation_date = operation_date;
        this->tel = new_cust.GetTel();
        this->ticket_id = new_ticket.getTicketID();
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
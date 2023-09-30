#include "pch.h"
#include "framework.h"
#include "avialib.h"
#include <string> // Добавьте этот заголовок
#include <iostream>

namespace AviaLib {
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


}


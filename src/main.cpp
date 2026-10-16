#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook book;
    Order order1(1, 10000, 100, Side::Buy);
    Order order2(2, 9950, 200, Side::Buy);
    Order order3(3, 10050, 150, Side::Sell);
    Order order4(4, 10100, 300, Side::Sell);
    Order order5(5, 10000, 50, Side::Buy);

    book.addOrder(order1);
    book.addOrder(order2);
    book.addOrder(order3);
    book.addOrder(order4);
    book.addOrder(order5);

    std::cout << "Highest Bid: " << book.getBestBid() << std::endl;
    std::cout << "Lowest Ask: " << book.getBestAsk() << std::endl;

    std::cout << "Before cancel: " << book.getBestBid() << std::endl;
    book.cancelOrder(1);
    std::cout << "After cancel order 1: " << book.getBestBid() << std::endl;
    book.cancelOrder(5);
    std::cout << "After cancel order 5: " << book.getBestBid() << std::endl;
    std::cout << book.cancelOrder(9999) << std::endl;

    return 0;
}
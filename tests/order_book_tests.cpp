#include <cassert>
#include "OrderBook.h" 

int main() {
    OrderBook book;

    Order buy1(1, 10000, 100, Side::Buy);
    Order buy2(2, 9950, 200, Side::Buy);
    Order sell1(3, 10050, 150, Side::Sell);

    book.addOrder(buy1);
    book.addOrder(buy2);
    book.addOrder(sell1);

    assert(book.getBestBid() == 10000);
    assert(book.getBestAsk() == 10050);

    Order duplicate(1, 10100, 50, Side::Buy);
    assert(book.addOrder(duplicate) == false);
    assert(book.cancelOrder(1) == true);
    assert(book.getBestBid() == 9950);

    assert(book.cancelOrder(9999) == false);
    
    OrderBook emptybook;
    assert(emptybook.getBestBid() == -1);
    assert(emptybook.getBestAsk() == -1);

    return 0;
}
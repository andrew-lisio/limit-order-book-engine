#include "OrderBook.h"

void OrderBook::addOrder(const Order& order) {
    orders.insert_or_assign(order.id, order);

    if (order.side == Side::Buy) {
        bids[order.price] += order.quantity;
    } else {
        asks[order.price] += order.quantity;
    }
}

int OrderBook::getBestBid() const {
    if (bids.empty()) {
        return -1;
    } else {
        return bids.rbegin()->first;
    }
}

int OrderBook::getBestAsk() const {
    if (asks.empty()) {
        return -1;
    } else {
        return asks.begin()->first;
    }
}

bool OrderBook::cancelOrder(int orderId) {
    auto it = orders.find(orderId);
    if (it == orders.end()) {
        return false;
    } 

    const Order& order = it->second;

    if (order.side == Side::Buy) {
        bids[order.price] -= order.quantity;

        if (bids[order.price] == 0) {
            bids.erase(order.price);
        }

    } else {
        asks[order.price] -= order.quantity;

        if (asks[order.price] == 0) {
            asks.erase(order.price);
        }
    }

    orders.erase(it);

    return true;

}
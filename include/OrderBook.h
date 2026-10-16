#pragma once

#include "Order.h" 
#include <unordered_map>
#include <map>

class OrderBook {
    private:
    std::unordered_map<int, Order> orders;
    std::map<int, int> bids;
    std::map<int, int> asks;

    public:
    bool addOrder(const Order& order);
    int getBestBid() const;
    int getBestAsk() const;
    bool cancelOrder(int orderId);
};

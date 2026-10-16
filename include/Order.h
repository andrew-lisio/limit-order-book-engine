#pragma once

enum class Side {
    Buy,
    Sell
};

class Order {
    public:
    int id;
    int price;
    int quantity;
    Side side;

    Order(int orderID, int orderPrice, int orderQuantity, Side orderSide) {
        id = orderID;
        price = orderPrice;
        quantity = orderQuantity;
        side = orderSide;
    }
};


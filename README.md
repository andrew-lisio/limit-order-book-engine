# C++ Limit Order Book Engine

A basic limit order book programmed in C++ to demonstrate data structures, object-oriented programming, and market structure concepts.

## Features

- Add buy and sell orders
- Cancel orders by unique order ID
- Aggregate quantity at each price level
- Retrieve the best bid and best ask
- Reject duplicate order IDs
- Store individual orders separately from aggregated price levels
- Automated tests for core order book behavior

## Design

Each order stores:
- Order ID
- Price
- Quantity
- Side

The engine uses:
- `std::unordered_map<int, Order>` for average O(1) order ID lookup
- `std::map<int, int>` for sorted bid and ask price levels

Prices are stored as integers rather than floating-point values to avoid precision issues. For example, `10000` represents `$100.00`.

## Build

```bash
g++ -std=c++17 src/main.cpp src/OrderBook.cpp -Iinclude -o orderbook
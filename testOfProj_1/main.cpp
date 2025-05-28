#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

// ----------------- Client -----------------
class Client {
    int id;
    string name, phone, address;
public:
    Client(int id, string name, string phone, string address)
        : id(id), name(name), phone(phone), address(address) {}
    int getId() const { return id; }
    string getName() const { return name; }
};

// ----------------- Product -----------------
class Product {
    string code, name;
    int price, stock;
public:
    Product(string code, string name, int price, int stock)
        : code(code), name(name), price(price), stock(stock) {}
    string getCode() const { return code; }
    string getName() const { return name; }
    int getPrice() const { return price; }
    int getStock() const { return stock; }
    void reduceStock(int q) { stock -= q; }
};

// ----------------- Order -----------------
class Order {
    int orderId;
    int clientId;
    string clientName;
    string productCode;
    int quantity;
    string status;
public:
    Order(int oid, int cid, string cname, string pcode, int qty)
        : orderId(oid), clientId(cid), clientName(cname),
        productCode(pcode), quantity(qty), status("구매완료") {}
    void print() const {
        cout << "주문번호: " << orderId << ", 고객: " << clientName
             << ", 상품코드: " << productCode << ", 수량: " << quantity
             << ", 상태: " << status << endl;
    }
};

// ----------------- ClientManager -----------------
class ClientManager {
    map<int, Client*> clients;
public:
    void addClient(int id, string name, string phone, string addr) {
        clients[id] = new Client(id, name, phone, addr);
    }
    Client* findClient(int id) {
        return clients.count(id) ? clients[id] : nullptr;
    }
    ~ClientManager() {
        for (auto& p : clients) delete p.second;
    }
};

// ----------------- ProductManager -----------------
class ProductManager {
    map<string, Product*> products;
public:
    void addProduct(string code, string name, int price, int stock) {
        products[code] = new Product(code, name, price, stock);
    }
    Product* findProduct(string code) {
        return products.count(code) ? products[code] : nullptr;
    }
    ~ProductManager() {
        for (auto& p : products) delete p.second;
    }
};

// ----------------- OrderManager -----------------
class OrderManager {
    vector<Order*> orders;
    int counter = 1;
public:
    void createOrder(int cid, string cname, string pcode, int qty,
                     ProductManager& pm) {
        Product* p = pm.findProduct(pcode);
        if (p && p->getStock() >= qty) {
            p->reduceStock(qty);
            orders.push_back(new Order(counter++, cid, cname, pcode, qty));
        } else {
            cout << "[실패] 재고 부족 또는 상품 없음" << endl;
        }
    }
    void listOrders() const {
        for (auto o : orders) o->print();
    }
    ~OrderManager() {
        for (auto o : orders) delete o;
    }
};

// ----------------- main -----------------
int main() {
    ClientManager cm;
    ProductManager pm;
    OrderManager om;

    cm.addClient(1001, "최현구", "010-1234-5678", "서울시");
    pm.addProduct("GTR-001", "Stratocaster", 2090000, 10);

    Client* c = cm.findClient(1001);
    if (c) {
        om.createOrder(c->getId(), c->getName(), "GTR-001", 2, pm);
    }

    om.listOrders();
    return 0;
}

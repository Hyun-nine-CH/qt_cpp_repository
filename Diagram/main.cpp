#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

/*
 *
 *
[accessory.h]
#ifndef ACCESSORY_H
#define ACCESSORY_H

#include <string>

class Accessory {
private:
    std::string code;
    std::string model;
    std::string purpose;
    int price;
    int stock;

public:
    Accessory() = default;

    Accessory(const std::string& code,
            const std::string& model,
            const std::string& purpose,
            int price,
            int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getPurpose() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // ACCESSORY_H

[accessory.cpp]
#include "accessory.h"

Accessory::Accessory(const std::string& code,
                const std::string& model,
                const std::string& purpose,
                int price,
                int stock)
    : code(code), model(model), purpose(purpose),
      price(price), stock(stock) {}

std::string Accessory::getCode() const { return code; }
std::string Accessory::getModel() const { return model; }
std::string Accessory::getPurpose() const { return purpose; }
int Accessory::getPrice() const { return price; }
int Accessory::getStock() const { return stock; }

void Accessory::setPrice(int price) { this->price = price; }
void Accessory::setStock(int stock) { this->stock = stock; }

bool Accessory::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Accessory::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Accessory::addStock(int qty) {
    stock += qty;
}

[accessorymanager.h]
#ifndef ACCESSORYMANAGER_H
#define ACCESSORYMANAGER_H

#include <vector>
#include <string>
#include "accessory.h"

class AccessoryManager {
private:
    std::vector<Accessory> accessories;

public:
    AccessoryManager();

//    void loadFromFile(const std::string& filename = "data/pdList_accessories.txt");
//    void saveToFile(const std::string& filename = "data/pdList_accessories.txt") const;

    void loadFromFile();
    void saveToFile() const;

    void inputAccessory();    // 콘솔 입력
    void deleteAccessory();   // 코드 기준 삭제
    void displayAccessory() const;

    const Accessory* findByCode(const std::string& code) const;
    Accessory* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // ACCESSORYMANAGER_H

[accessorymanager.cpp]
#include "accessorymanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string ACCESSORY_FILE = "data/pdList_accessories.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

AccessoryManager::AccessoryManager() {
    loadFromFile(); // 기본 경로 사용
}

// 파일명 명시적 로드
void AccessoryManager::loadFromFile() {
    accessories.clear();
    std::ifstream file(ACCESSORY_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, purpose;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, purpose, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        accessories.emplace_back(code, model, purpose, price, stock);
    }
}

// 파일명 명시적 저장
void AccessoryManager::saveToFile() const {
    std::ofstream file(ACCESSORY_FILE);
    for (const auto& as : accessories) {
        file << as.getCode() << ","
             << as.getModel() << ","
             << as.getPurpose() << ","
             << as.getPrice() << ","
             << as.getStock() << "\n";
    }
}

void AccessoryManager::inputAccessory() {
    std::string code, model, purpose;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "용도: ";
    std::getline(std::cin, purpose);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    accessories.emplace_back(code, model, purpose, price, stock);
    saveToFile();  // 기본 경로 저장
}

void AccessoryManager::deleteAccessory() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(accessories.begin(), accessories.end(),
        [&](const Accessory& as) { return as.getCode() == code; });

    if (it != accessories.end()) {
        accessories.erase(it, accessories.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool AccessoryManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 액세서리 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputAccessory(); break;
            case 2: deleteAccessory(); break;
            case 3: displayAccessory(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void AccessoryManager::displayAccessory() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 용도     | 가격       | 재고\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& as : accessories) {
            std::cout << std::setw(10) << as.getCode() << " | "
                      << std::setw(12) << as.getModel() << " | "
                      << std::setw(12) << as.getPurpose() << " | "
                      << std::setw(10) << addComma(as.getPrice()) << " | "
                      << std::setw(5) << addComma(as.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 용도     | 가격       | 재고\n";
            std::cout << "------------------------------------------------------------\n";

            bool found = false;
            for (const auto& as : accessories) {
                if (as.getModel().find(keyword) != std::string::npos ||
                    as.getPurpose().find(keyword) != std::string::npos ||
                    as.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << as.getCode() << " | "
                              << std::setw(12) << as.getModel() << " | "
                              << std::setw(12) << as.getPurpose() << " | "
                              << std::setw(10) << addComma(as.getPrice()) << " | "
                              << std::setw(5)  << addComma(as.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Accessory* AccessoryManager::findByCode(const std::string& code) const{
    for (auto& as : accessories) {
        if (as.getCode() == code)
            return &as;
    }
    return nullptr;
}

Accessory* AccessoryManager::findByCode(const std::string& code) {
    for (auto& as : accessories) {
        if (as.getCode() == code)
            return &as;
    }
    return nullptr;
}

[amp.h]
#ifndef AMP_H
#define AMP_H

#include <string>

class Amp {
private:
    std::string code;
    std::string model;
    std::string brand;
    int price;
    int stock;

public:
    Amp() = default;

    Amp(const std::string& code,
           const std::string& model,
           const std::string& brand,
           int price,
           int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // AMP_H

[amp.cpp]
#include "amp.h"

Amp::Amp(const std::string& code,
                const std::string& model,
                const std::string& brand,
                int price,
                int stock)
    : code(code), model(model), brand(brand),
      price(price), stock(stock) {}

std::string Amp::getCode() const { return code; }
std::string Amp::getModel() const { return model; }
std::string Amp::getBrand() const { return brand; }
int Amp::getPrice() const { return price; }
int Amp::getStock() const { return stock; }

void Amp::setPrice(int price) { this->price = price; }
void Amp::setStock(int stock) { this->stock = stock; }

bool Amp::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Amp::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Amp::addStock(int qty) {
    stock += qty;
}

[ampmanager.h]
#ifndef AMPMANAGER_H
#define AMPMANAGER_H

#include <vector>
#include <string>
#include "amp.h"

class AmpManager {
private:
    std::vector<Amp> amps;

public:
    AmpManager();

    void loadFromFile();
    void saveToFile() const;

//    void loadFromFile(const std::string& filename = "data/pdList_amps.txt");
//    void saveToFile(const std::string& filename = "data/pdList_amps.txt") const;

    void inputAmp();    // 콘솔 입력
    void deleteAmp();   // 코드 기준 삭제
    void displayAmp() const;

    const Amp* findByCode(const std::string& code) const;
    Amp* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // AMPMANAGER_H

[ampmanager.cpp]
#include "ampmanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string AMP_FILE = "data/pdList_amps.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

AmpManager::AmpManager() {
    loadFromFile();
}

void AmpManager::loadFromFile() {
    amps.clear();
    std::ifstream file(AMP_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        amps.emplace_back(code, model, brand, price, stock);
    }
}

void AmpManager::saveToFile() const {
    std::ofstream file(AMP_FILE);
    for (const auto& a : amps) {
        file << a.getCode() << ","
             << a.getModel() << ","
             << a.getBrand() << ","
             << a.getPrice() << ","
             << a.getStock() << "\n";
    }
}

void AmpManager::inputAmp() {
    std::string code, model, brand;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    amps.emplace_back(code, model, brand, price, stock);
    saveToFile();
}

void AmpManager::deleteAmp() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(amps.begin(), amps.end(),
        [&](const Amp& a) { return a.getCode() == code; });

    if (it != amps.end()) {
        amps.erase(it, amps.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool AmpManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 앰프 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputAmp(); break;
            case 2: deleteAmp(); break;
            case 3: displayAmp(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void AmpManager::displayAmp() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& a : amps) {
            std::cout << std::setw(10) << a.getCode() << " | "
                      << std::setw(12) << a.getModel() << " | "
                      << std::setw(12) << a.getBrand() << " | "
                      << std::setw(10) << addComma(a.getPrice()) << " | "
                      << std::setw(5) << addComma(a.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
            std::cout << "------------------------------------------------------------\n";

            bool found = false;
            for (const auto& a : amps) {
                if (a.getModel().find(keyword) != std::string::npos ||
                    a.getBrand().find(keyword) != std::string::npos ||
                    a.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << a.getCode() << " | "
                              << std::setw(12) << a.getModel() << " | "
                              << std::setw(12) << a.getBrand() << " | "
                              << std::setw(10) << addComma(a.getPrice()) << " | "
                              << std::setw(5)  << addComma(a.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Amp* AmpManager::findByCode(const std::string& code) const{
    for (auto& a : amps) {
        if (a.getCode() == code)
            return &a;
    }
    return nullptr;
}

Amp* AmpManager::findByCode(const std::string& code) {
    for (auto& a : amps) {
        if (a.getCode() == code)
            return &a;
    }
    return nullptr;
}

[cable.h]
#ifndef CABLE_H
#define CABLE_H

#include <string>

class Cable {
private:
    std::string code;
    std::string model;
    std::string brand;
    int price;
    int stock;

public:
    Cable() = default;

    Cable(const std::string& code,
           const std::string& model,
           const std::string& brand,
           int price,
           int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // CABLE_H

[cable.cpp]
#include "cable.h"

Cable::Cable(const std::string& code,
                const std::string& model,
                const std::string& brand,
                int price,
                int stock)
    : code(code), model(model), brand(brand),
      price(price), stock(stock) {}

std::string Cable::getCode() const { return code; }
std::string Cable::getModel() const { return model; }
std::string Cable::getBrand() const { return brand; }
int Cable::getPrice() const { return price; }
int Cable::getStock() const { return stock; }

void Cable::setPrice(int price) { this->price = price; }
void Cable::setStock(int stock) { this->stock = stock; }

bool Cable::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Cable::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Cable::addStock(int qty) {
    stock += qty;
}

[cablemanager.h]
#ifndef CABLEMANAGER_H
#define CABLEMANAGER_H

#include <vector>
#include <string>
#include "cable.h"

class CableManager {
private:
    std::vector<Cable> cables;

public:
    CableManager();

//    void loadFromFile(const std::string& filename = "data/pdList_cables.txt");
//    void saveToFile(const std::string& filename = "data/pdList_cables.txt") const;

    void loadFromFile();
    void saveToFile() const;

    void inputCable();    // 콘솔 입력
    void deleteCable();   // 코드 기준 삭제
    void displayCable() const;

    const Cable* findByCode(const std::string& code) const;
    Cable* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // CABLEMANAGER_H

[cablemanager.cpp]
#include "cablemanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string CABLE_FILE = "data/pdList_cables.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

CableManager::CableManager() {
    loadFromFile();
}

void CableManager::loadFromFile() {
    cables.clear();
    std::ifstream file(CABLE_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        cables.emplace_back(code, model, brand, price, stock);
    }
}

void CableManager::saveToFile() const {
    std::ofstream file(CABLE_FILE);
    for (const auto& c : cables) {
        file << c.getCode() << ","
             << c.getModel() << ","
             << c.getBrand() << ","
             << c.getPrice() << ","
             << c.getStock() << "\n";
    }
}

void CableManager::inputCable() {
    std::string code, model, brand;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    cables.emplace_back(code, model, brand, price, stock);
    saveToFile();
}

void CableManager::deleteCable() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(cables.begin(), cables.end(),
        [&](const Cable& c) { return c.getCode() == code; });

    if (it != cables.end()) {
        cables.erase(it, cables.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool CableManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 케이블 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputCable(); break;
            case 2: deleteCable(); break;
            case 3: displayCable(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void CableManager::displayCable() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& c : cables) {
            std::cout << std::setw(10) << c.getCode() << " | "
                      << std::setw(12) << c.getModel() << " | "
                      << std::setw(12) << c.getBrand() << " | "
                      << std::setw(10) << addComma(c.getPrice()) << " | "
                      << std::setw(5) << addComma(c.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
            std::cout << "------------------------------------------------------------\n";

            bool found = false;
            for (const auto& c : cables) {
                if (c.getModel().find(keyword) != std::string::npos ||
                    c.getBrand().find(keyword) != std::string::npos ||
                    c.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << c.getCode() << " | "
                              << std::setw(12) << c.getModel() << " | "
                              << std::setw(12) << c.getBrand() << " | "
                              << std::setw(10) << addComma(c.getPrice()) << " | "
                              << std::setw(5)  << addComma(c.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Cable* CableManager::findByCode(const std::string& code) const{
    for (auto& c : cables) {
        if (c.getCode() == code)
            return &c;
    }
    return nullptr;
}

Cable* CableManager::findByCode(const std::string& code) {
    for (auto& c : cables) {
        if (c.getCode() == code)
            return &c;
    }
    return nullptr;
}

[client.h]
#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <string>

class Client {
public:
    Client(int id = 0, const std::string& name = "", const std::string& phone = "", const std::string& address = "");

    std::string getName() const;
    void setName(const std::string& name);

    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& phone);

    std::string getAddress() const;
    void setAddress(const std::string& address);

    int id() const;
    bool operator==(const Client& other) const;

private:
    int m_id;
    std::string m_name;
    std::string m_phoneNumber;
    std::string m_address;
};

#endif // __CLIENT_H__

[client.cpp]
#include "client.h"

Client::Client(int id, const std::string& name, const std::string& phoneNumber, const std::string& address)
    : m_id(id), m_name(name), m_phoneNumber(phoneNumber), m_address(address) {}

std::string Client::getName() const {
    return m_name;
}

void Client::setName(const std::string& name) {
    m_name = name;
}

std::string Client::getPhoneNumber() const {
    return m_phoneNumber;
}

void Client::setPhoneNumber(const std::string& phoneNumber) {
    m_phoneNumber = phoneNumber;
}

std::string Client::getAddress() const {
    return m_address;
}

void Client::setAddress(const std::string& address) {
    m_address = address;
}

int Client::id() const {
    return m_id;
}

bool Client::operator==(const Client& other) const {
    return m_id == other.m_id;
}

[clientmanager.h]
#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include <map>
#include <vector>
#include <string>
#include "client.h"

namespace ClientSystem {
class ClientManager {
public:
    ClientManager();
    ~ClientManager();

    void inputClient();                // 고객 입력
    void addClient(Client*);           // 고객 객체 추가
    void deleteClient(int);            // 고객 삭제
    void modifyClient(int);            // 고객 수정
    int makeId();                      // ID 생성
    void displayInfo();                // 전체 고객 정보 출력
    void saveToFile();                 // 텍스트 파일 저장
    std::vector<std::string> parseCSV(std::istream&, char); // CSV 파싱

    Client* findClientById(int) const;       // ID로 검색
    Client* findClientByName(const std::string&) const; // 이름으로 검색

    bool displayMenu();                // 메뉴 표시

private:
    std::map<int, Client*> clientList;
};
}

#endif // __CLIENTMANAGER_H__

[clientmanager.cpp]
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "client.h"
#include "clientmanager.h"

namespace ClientSystem {
const std::string CLIENT_FILE = "data/clientlist.txt";

inline std::string formatPhoneNumber(const std::string& phone) {
    if (phone.length() == 11) {
        return phone.substr(0, 3) + "-" + phone.substr(3, 4) + "-" + phone.substr(7, 4);
    }
    return phone;
}

ClientManager::ClientManager() {
    std::ifstream file(CLIENT_FILE);
    if (!file.fail()) {
        while (!file.eof()) {
            std::vector<std::string> row = parseCSV(file, ',');
            if (row.size() == 4) {
                int id = std::stoi(row[0]);
                Client* c = new Client(id, row[1], row[2], row[3]);
                clientList.insert({ id, c });
            }
        }
    }
}

ClientManager::~ClientManager() {
    saveToFile();  // 종료 시 자동 저장
}

void ClientManager::saveToFile() {
    std::ofstream file(CLIENT_FILE);
    if (file.is_open()) {
        for (const auto& v : clientList) {
            Client* c = v.second;
            file << c->id() << ", " << c->getName() << ", "
                 << c->getPhoneNumber() << ", "
                 << c->getAddress() << '\n';
        }
    }
}

void ClientManager::inputClient() {
    std::string name, number, address;
    std::cout << "name : "; std::cin >> name;
    std::cout << "number : "; std::cin >> number;
    std::cout << "address : "; std::cin.ignore(); std::getline(std::cin, address);

    int id = makeId();
    Client* c = new Client(id, name, number, address);
    clientList.insert({ id, c });

    saveToFile(); // 바로 저장
}

void ClientManager::deleteClient(int key) {
    if (clientList.find(key) == clientList.end()) {
        std::cerr << "존재하지 않는 고객입니다. 다시 입력하세요.\n";
        return;
    }
    clientList.erase(key);
    saveToFile();
}

void ClientManager::modifyClient(int key) {
    Client* c = findClientById(key);
    if (!c) {
        std::cerr << "존재하지 않는 고객입니다. 다시 입력하세요.\n";
        return;
    }

    std::cout << "  ID  |   Name   | Phone Number |   Address\n";
    std::cout << std::setw(5) << std::setfill('0') << std::right << c->id() << " | " << std::left;
    std::cout << std::setw(12) << std::setfill(' ') << c->getName() << " | ";
    std::cout << std::setw(12) << c->getPhoneNumber() << " | ";
    std::cout << c->getAddress() << "\n";

    std::string name, number, address;
    std::cout << "name : "; std::cin >> name;
    std::cout << "number : "; std::cin >> number;
    std::cout << "address : "; std::cin.ignore(); std::getline(std::cin, address);

    c->setName(name);
    c->setPhoneNumber(number);
    c->setAddress(address);

    saveToFile();
}

Client* ClientManager::findClientById(int id) const{
    auto it = clientList.find(id);
    if (it != clientList.end()) return it->second;
    return nullptr;
}

Client* ClientManager::findClientByName(const std::string& name) const{
    for (const auto& pair : clientList) {
        if (pair.second->getName() == name)
            return pair.second;
    }
    return nullptr;
}

bool ClientManager::displayMenu() {
    while (true) {
        int choice;
        std::cout << "\n--- 고객 관리 ---\n";
        std::cout << "1. 고객 목록 보기\n";
        std::cout << "2. 고객 등록\n";
        std::cout << "3. 고객 삭제\n";
        std::cout << "4. 고객 정보 수정\n";
        std::cout << "5. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice) {
            case 1:
                displayInfo();
                break;
            case 2:
                inputClient();
                break;
            case 3: {
                displayInfo();
                int key;
                std::cout << "   Choose Key : ";
                std::cin >> key;
                std::cin.ignore(1000, '\n');
                deleteClient(key);
                break;
            }
            case 4: {
                displayInfo();
                int key;
                std::cout << "   Choose Key : ";
                std::cin >> key;
                std::cin.ignore(1000, '\n');
                modifyClient(key);
                break;
            }
            case 5:
                return false;
            default:
                std::cout << "잘못된 선택입니다.\n";
                break;
        }
    }
    return true;
}

void ClientManager::displayInfo() {
    while (true) {
        std::cout << "\n  ID  |   Name    | Phone Number |   Address\n";
        std::cout << "---------------------------------------------\n";
        for (const auto& v : clientList) {
            Client* c = v.second;
            std::cout << std::setw(5) << std::setfill('0') << std::right << c->id() << " | " << std::left;
            std::cout << std::setw(12) << std::setfill(' ') << c->getName() << " | ";
            std::cout << std::setw(12) << formatPhoneNumber(c->getPhoneNumber()) << " | ";
            std::cout << c->getAddress() << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;
        std::cin.ignore(1000, '\n');

        if (opt == 1) {
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "  ID  |   Name    | Phone Number |   Address\n";
            std::cout << "---------------------------------------------\n";

            bool found = false;
            for (const auto& v : clientList) {
                Client* c = v.second;
                if (std::to_string(c->id()).find(keyword) != std::string::npos ||
                    c->getName().find(keyword) != std::string::npos ||
                    c->getPhoneNumber().find(keyword) != std::string::npos ||
                    c->getAddress().find(keyword) != std::string::npos) {

                    std::cout << std::setw(5) << std::setfill('0') << std::right << c->id() << " | " << std::left;
                    std::cout << std::setw(12) << std::setfill(' ') << c->getName() << " | ";
                    std::cout << std::setw(12) << formatPhoneNumber(c->getPhoneNumber()) << " | ";
                    std::cout << c->getAddress() << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
        } else if (opt == 2) {
            return;
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

void ClientManager::addClient(Client* c) {
    clientList.insert({ c->id(), c });
    saveToFile();
}

int ClientManager::makeId() {
    if (clientList.empty()) {
        return 1;
    } else {
        auto it = clientList.rbegin(); // reverse iterator로 가장 큰 ID
        return it->first + 1;
    }
}

std::vector<std::string> ClientManager::parseCSV(std::istream& file, char delimiter) {
    std::string line;
    std::vector<std::string> row;

    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, delimiter)) {
            size_t start = cell.find_first_not_of(" \n\r\t");
            size_t end = cell.find_last_not_of(" \n\r\t");
            if (start != std::string::npos && end != std::string::npos)
                row.push_back(cell.substr(start, end - start + 1));
            else
                row.push_back(""); // 공백만 있는 경우
        }
    }

    return row;
}
}

[effect.h]
#ifndef EFFECT_H
#define EFFECT_H

#include <string>

class Effect {
private:
    std::string code;
    std::string model;
    std::string brand;
    std::string effectType;
    int price;
    int stock;

public:
    Effect() = default;

    Effect(const std::string& code,
            const std::string& model,
            const std::string& brand,
            const std::string& effectType,
            int price,
            int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    std::string getEffectType() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // EFFECT_H

[effect.cpp]
#include "effect.h"

Effect::Effect(const std::string& code,
               const std::string& model,
               const std::string& brand,
               const std::string& effectType,
               int price,
               int stock)
    : code(code), model(model), brand(brand), effectType(effectType),
      price(price), stock(stock) {}

std::string Effect::getCode() const { return code; }
std::string Effect::getModel() const { return model; }
std::string Effect::getBrand() const { return brand; }
std::string Effect::getEffectType() const { return effectType; }
int Effect::getPrice() const { return price; }
int Effect::getStock() const { return stock; }

void Effect::setPrice(int price) { this->price = price; }
void Effect::setStock(int stock) { this->stock = stock; }

bool Effect::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Effect::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Effect::addStock(int qty) {
    stock += qty;
}

[effectmanager.h]
#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <vector>
#include <string>
#include "effect.h"

class EffectManager {
private:
    std::vector<Effect> effects;

public:
    EffectManager();

//    void loadFromFile(const std::string& filename = "data/pdList_effects.txt");
//    void saveToFile(const std::string& filename = "data/pdList_effects.txt") const;

    void loadFromFile();
    void saveToFile() const;

    void inputEffect();    // 콘솔 입력
    void deleteEffect();   // 코드 기준 삭제
    void displayEffect() const;

    const Effect* findByCode(const std::string& code) const;
    Effect* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // EFFECTMANAGER_H

[effectmanager.cpp]
#include "effectmanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// ✅ 파일 경로 상수 추가
const std::string EFFECT_FILE = "data/pdList_effects.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

EffectManager::EffectManager() {
    loadFromFile(); // ✅ 파일명 명시 제거
}

void EffectManager::loadFromFile() {
    effects.clear();
    std::ifstream file(EFFECT_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand, effectType;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        getline(ss, effectType, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        effects.emplace_back(code, model, brand, effectType, price, stock);
    }
}

void EffectManager::saveToFile() const {
    std::ofstream file(EFFECT_FILE);
    for (const auto& e : effects) {
        file << e.getCode() << ","
             << e.getModel() << ","
             << e.getBrand() << ","
             << e.getEffectType() << ","
             << e.getPrice() << ","
             << e.getStock() << "\n";
    }
}

void EffectManager::inputEffect() {
    std::string code, model, brand, effectType;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "타입: ";
    std::getline(std::cin, effectType);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    effects.emplace_back(code, model, brand, effectType, price, stock);
    saveToFile(); // ✅ 저장
}

void EffectManager::deleteEffect() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(effects.begin(), effects.end(),
        [&](const Effect& e) { return e.getCode() == code; });

    if (it != effects.end()) {
        effects.erase(it, effects.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile(); // ✅ 저장
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool EffectManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 이펙터 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputEffect(); break;
            case 2: deleteEffect(); break;
            case 3: displayEffect(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void EffectManager::displayEffect() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 브랜드       | 타입     | 가격       | 재고\n";
        std::cout << "--------------------------------------------------------------------------\n";
        for (const auto& e : effects) {
            std::cout << std::setw(10) << e.getCode() << " | "
                      << std::setw(12) << e.getModel() << " | "
                      << std::setw(12) << e.getBrand() << " | "
                      << std::setw(8) << e.getEffectType() << " | "
                      << std::setw(10) << addComma(e.getPrice()) << " | "
                      << std::setw(5) << addComma(e.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 브랜드       | 타입     | 가격       | 재고\n";
            std::cout << "--------------------------------------------------------------------------\n";

            bool found = false;
            for (const auto& e : effects) {
                if (e.getModel().find(keyword) != std::string::npos ||
                    e.getBrand().find(keyword) != std::string::npos ||
                    e.getEffectType().find(keyword) != std::string::npos ||
                    e.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << e.getCode() << " | "
                              << std::setw(12) << e.getModel() << " | "
                              << std::setw(12) << e.getBrand() << " | "
                              << std::setw(8)  << e.getEffectType() << " | "
                              << std::setw(10) << addComma(e.getPrice()) << " | "
                              << std::setw(5)  << addComma(e.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Effect* EffectManager::findByCode(const std::string& code) const {
    for (auto& e : effects) {
        if (e.getCode() == code)
            return &e;
    }
    return nullptr;
}

Effect* EffectManager::findByCode(const std::string& code) {
    for (auto& e : effects) {
        if (e.getCode() == code)
            return &e;
    }
    return nullptr;
}

[guitar.h]
#ifndef GUITAR_H
#define GUITAR_H

#include <string>

class Guitar {
private:
    std::string code;
    std::string model;
    std::string brand;
    std::string type;
    int price;
    int stock;

public:
    Guitar() = default;

    Guitar(const std::string& code,
           const std::string& model,
           const std::string& brand,
           const std::string& type,
           int price,
           int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    std::string getType() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // GUITAR_H

[guitar.cpp]
#include "guitar.h"

Guitar::Guitar(const std::string& code,
               const std::string& model,
               const std::string& brand,
               const std::string& type,
               int price,
               int stock)
    : code(code), model(model), brand(brand), type(type),
      price(price), stock(stock) {}

std::string Guitar::getCode() const { return code; }
std::string Guitar::getModel() const { return model; }
std::string Guitar::getBrand() const { return brand; }
std::string Guitar::getType() const { return type; }
int Guitar::getPrice() const { return price; }
int Guitar::getStock() const { return stock; }

void Guitar::setPrice(int price) { this->price = price; }
void Guitar::setStock(int stock) { this->stock = stock; }

bool Guitar::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Guitar::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Guitar::addStock(int qty) {
    stock += qty;
}

[guitarmanager.h]
#ifndef GUITARMANAGER_H
#define GUITARMANAGER_H

#include <vector>
#include <string>
#include "guitar.h"

class GuitarManager {
private:
    std::vector<Guitar> guitars;

public:
    GuitarManager();

    void loadFromFile();
    void saveToFile() const;

    void inputGuitar();    // 콘솔 입력
    void deleteGuitar();   // 코드 기준 삭제
    void displayGuitar() const;

    const Guitar* findByCode(const std::string& code) const;
    Guitar* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // GUITARMANAGER_H


[guitarmanager.cpp]
#include "guitarmanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string GUITAR_FILE = "data/pdList_guitars.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

GuitarManager::GuitarManager() {
    loadFromFile();
}

void GuitarManager::loadFromFile() {
    guitars.clear();
    std::ifstream file(GUITAR_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand, type;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        getline(ss, type, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        guitars.emplace_back(code, model, brand, type, price, stock);
    }
}

void GuitarManager::saveToFile() const {
    std::ofstream file(GUITAR_FILE);
    for (const auto& g : guitars) {
        file << g.getCode() << ","
             << g.getModel() << ","
             << g.getBrand() << ","
             << g.getType() << ","
             << g.getPrice() << ","
             << g.getStock() << "\n";
    }
}

void GuitarManager::inputGuitar() {
    std::string code, model, brand, type;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "타입: ";
    std::getline(std::cin, type);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    guitars.emplace_back(code, model, brand, type, price, stock);
    saveToFile();
}

void GuitarManager::deleteGuitar() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(guitars.begin(), guitars.end(),
        [&](const Guitar& g) { return g.getCode() == code; });

    if (it != guitars.end()) {
        guitars.erase(it, guitars.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool GuitarManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 일렉기타 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputGuitar(); break;
            case 2: deleteGuitar(); break;
            case 3: displayGuitar(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void GuitarManager::displayGuitar() const {
    while (true) {
        std::cout << "\n코드       | 모델명           | 브랜드       | 타입     | 가격       | 재고\n";
        std::cout << "--------------------------------------------------------------------------\n";
        for (const auto& g : guitars) {
            std::cout << std::setw(12) << g.getCode() << " | "
                      << std::setw(16) << g.getModel() << " | "
                      << std::setw(12) << g.getBrand() << " | "
                      << std::setw(8)  << g.getType() << " | "
                      << std::setw(10) << addComma(g.getPrice()) << " | "
                      << std::setw(5)  << addComma(g.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명           | 브랜드       | 타입     | 가격       | 재고\n";
            std::cout << "--------------------------------------------------------------------------\n";

            bool found = false;
            for (const auto& g : guitars) {
                if (g.getModel().find(keyword) != std::string::npos ||
                    g.getBrand().find(keyword) != std::string::npos ||
                    g.getType().find(keyword) != std::string::npos ||
                    g.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(12) << g.getCode() << " | "
                              << std::setw(16) << g.getModel() << " | "
                              << std::setw(12) << g.getBrand() << " | "
                              << std::setw(8)  << g.getType() << " | "
                              << std::setw(10) << addComma(g.getPrice()) << " | "
                              << std::setw(5)  << addComma(g.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Guitar* GuitarManager::findByCode(const std::string& code) const{
    for (auto& g : guitars) {
        if (g.getCode() == code)
            return &g;
    }
    return nullptr;
}

Guitar* GuitarManager::findByCode(const std::string& code) {
    for (auto& g : guitars) {
        if (g.getCode() == code)
            return &g;
    }
    return nullptr;
}

[powersupply.h]
#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include <string>

class Powersupply {
private:
    std::string code;
    std::string model;
    std::string brand;
    int price;
    int stock;

public:
    Powersupply() = default;

    Powersupply(const std::string& code,
           const std::string& model,
           const std::string& brand,
           int price,
           int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // POWERSUPPLY_H

[powersupply.cpp]
#include "powersupply.h"

Powersupply::Powersupply(const std::string& code,
                const std::string& model,
                const std::string& brand,
                int price,
                int stock)
    : code(code), model(model), brand(brand),
      price(price), stock(stock) {}

std::string Powersupply::getCode() const { return code; }
std::string Powersupply::getModel() const { return model; }
std::string Powersupply::getBrand() const { return brand; }
int Powersupply::getPrice() const { return price; }
int Powersupply::getStock() const { return stock; }

void Powersupply::setPrice(int price) { this->price = price; }
void Powersupply::setStock(int stock) { this->stock = stock; }

bool Powersupply::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Powersupply::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Powersupply::addStock(int qty) {
    stock += qty;
}

[powersupplymanager.h]
#ifndef POWERSUPPLYMANAGER_H
#define POWERSUPPLYMANAGER_H

#include <vector>
#include <string>
#include "powersupply.h"

class PowersupplyManager {
private:
    std::vector<Powersupply> powersupplies;

public:
    PowersupplyManager();

//    void loadFromFile(const std::string& filename = "data/pdList_powerSupplies.txt");
//    void saveToFile(const std::string& filename = "data/pdList_powerSupplies.txt") const;

    void loadFromFile();
    void saveToFile() const;

    void inputPowerSupply();    // 콘솔 입력
    void deletePowerSupply();   // 코드 기준 삭제
    void displayPowerSupply() const;

    const Powersupply* findByCode(const std::string& code) const;
    Powersupply* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // POWERSUPPLYMANAGER_H

[powersupplymanager.cpp]
#include "powersupplymanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string POWERSUPPLY_FILE = "data/pdList_powersupplies.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

PowersupplyManager::PowersupplyManager() {
    loadFromFile();
}

void PowersupplyManager::loadFromFile() {
    powersupplies.clear();
    std::ifstream file(POWERSUPPLY_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        powersupplies.emplace_back(code, model, brand, price, stock);
    }
}

void PowersupplyManager::saveToFile() const {
    std::ofstream file(POWERSUPPLY_FILE);
    for (const auto& ps : powersupplies) {
        file << ps.getCode() << ","
             << ps.getModel() << ","
             << ps.getBrand() << ","
             << ps.getPrice() << ","
             << ps.getStock() << "\n";
    }
}

void PowersupplyManager::inputPowerSupply() {
    std::string code, model, brand;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    powersupplies.emplace_back(code, model, brand, price, stock);
    saveToFile();
}

void PowersupplyManager::deletePowerSupply() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(powersupplies.begin(), powersupplies.end(),
        [&](const Powersupply& ps) { return ps.getCode() == code; });

    if (it != powersupplies.end()) {
        powersupplies.erase(it, powersupplies.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool PowersupplyManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 파워서플라이 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputPowerSupply(); break;
            case 2: deletePowerSupply(); break;
            case 3: displayPowerSupply(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void PowersupplyManager::displayPowerSupply() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& ps : powersupplies) {
            std::cout << std::setw(10) << ps.getCode() << " | "
                      << std::setw(12) << ps.getModel() << " | "
                      << std::setw(12) << ps.getBrand() << " | "
                      << std::setw(10) << addComma(ps.getPrice()) << " | "
                      << std::setw(5) << addComma(ps.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
            std::cout << "------------------------------------------------------------\n";

            bool found = false;
            for (const auto& ps : powersupplies) {
                if (ps.getModel().find(keyword) != std::string::npos ||
                    ps.getBrand().find(keyword) != std::string::npos ||
                    ps.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << ps.getCode() << " | "
                              << std::setw(12) << ps.getModel() << " | "
                              << std::setw(12) << ps.getBrand() << " | "
                              << std::setw(10) << addComma(ps.getPrice()) << " | "
                              << std::setw(5)  << addComma(ps.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Powersupply* PowersupplyManager::findByCode(const std::string& code) const{
    for (auto& ps : powersupplies) {
        if (ps.getCode() == code)
            return &ps;
    }
    return nullptr;
}

Powersupply* PowersupplyManager::findByCode(const std::string& code) {
    for (auto& ps : powersupplies) {
        if (ps.getCode() == code)
            return &ps;
    }
    return nullptr;
}

[genrestarterset.h]
#ifndef GENRESTARTERSET_H
#define GENRESTARTERSET_H

#include <string>
#include <vector>
#include <map>

namespace ClientSystem { class ClientManager; }
namespace ProductSystem { class ProductManager; }
namespace OrderSystem  { class OrderManager; }

namespace GenreStarter {

class GenreStarterSet {
public:
    GenreStarterSet();

    void displayGenreMenu(ClientSystem::ClientManager* clientManager,
                          ProductSystem::ProductManager* productManager,
                          OrderSystem::OrderManager* orderManager);

private:
    struct GenreConfig {
        std::string guitarType;
        std::vector<std::string> effectTypes;
    };

    std::map<int, std::string> genreNames;
    std::map<int, GenreConfig> genreConfigs;

    void processGenreSelection(int genreId,
                               ClientSystem::ClientManager* clientManager,
                               ProductSystem::ProductManager* productManager,
                               OrderSystem::OrderManager* orderManager);

    void loadGuitarMatches(const std::string& type);
    void loadEffectMatches(const std::vector<std::string>& types);

    void createGuitarOrder(ClientSystem::ClientManager* clientManager,
                           ProductSystem::ProductManager* productManager,
                           OrderSystem::OrderManager* orderManager);

    void createEffectOrders(const std::vector<std::string>& types,
                            ClientSystem::ClientManager* clientManager,
                            ProductSystem::ProductManager* productManager,
                            OrderSystem::OrderManager* orderManager);
};

}

#endif // GENRESTARTERSET_H

[genrestarterset.cpp]
#include "genrestarterset.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "productmanager.h"
#include "ordermanager.h"
#include "clientmanager.h"

using namespace std;
using namespace GenreStarter;
using namespace ProductSystem;
using namespace OrderSystem;
using namespace ClientSystem;

namespace  {
inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}
}

const std::string GUITAR_FILE = "data/pdList_guitars.txt";
const std::string EFFECT_FILE = "data/pdList_effects.txt";

GenreStarterSet::GenreStarterSet() {
    genreNames = {
        {1, "포크 록"}, {2, "블루스 록"}, {3, "프로그레시브 록"}, {4, "사이키델릭 록"},
        {5, "하드 록"}, {6, "팝 록"}, {7, "소프트 록"}, {8, "아트 록"},
        {9, "루츠 록"}, {10, "메탈"}, {11, "일렉트로닉 록"}, {12, "펑크 록"},
        {13, "얼터너티브 록"}, {14, "모던 록"}
    };

    genreConfigs = {
        {1, {"Superstrat", {"Reverb", "Chorus", "EQ"}}},
        {2, {"Semi-Hollow", {"Overdrive", "Reverb", "Compressor"}}},
        {3, {"Superstrat", {"Delay", "Phaser", "Flanger", "Reverb"}}},
        {4, {"Jazz", {"Fuzz", "Echo", "Vibrato"}}}, // "Offset" → "Jazz"
        {5, {"Les Paul", {"Overdrive", "Distortion", "EQ"}}},
        {6, {"Stratocaster", {"Chorus", "Delay", "Reverb"}}},
        {7, {"Telecaster", {"Reverb", "Compressor"}}},
        {8, {"Jazz", {"Reverb", "EQ", "Chorus"}}},   // "Offset" → "Jazz"
        {9, {"Stratocaster", {"Reverb", "EQ"}}},     // "Parlor" → "Stratocaster" (대체)
        {10, {"Flying V", {"Distortion", "Noise Gate", "EQ", "Delay"}}},
        {11, {"Superstrat", {"Synth", "Chorus", "Reverb"}}},
        {12, {"Jaguar", {"Fuzz", "Distortion", "EQ"}}}, // 없는 경우: 필요 시 "Jazz" 대체 가능
        {13, {"Stratocaster", {"Overdrive", "Distortion", "Flanger", "Chorus"}}},
        {14, {"Jazz", {"Reverb", "Overdrive", "EQ"}}} // "Offset" → "Jazz"
    };
}

void GenreStarterSet::displayGenreMenu(ClientManager* clientManager, ProductManager* productManager, OrderManager* orderManager) {
    while (true) {
        cout << "\n--- Genre Starter Pack ---\n";
        for (const auto& pair : genreNames) {
            cout << pair.first << ". " << pair.second << endl;
        }
        cout << "15. 이전 메뉴로 돌아가기" << endl;
        cout << "선택: ";
        int genreId;
        cin >> genreId;

        if (genreId == 15) return;
        if (genreNames.count(genreId)) {
            processGenreSelection(genreId, clientManager, productManager, orderManager);
        } else {
            cout << "잘못된 선택입니다." << endl;
        }
    }
}

void GenreStarterSet::processGenreSelection(int genreId, ClientManager* clientManager, ProductManager* productManager, OrderManager* orderManager) {
    string gtype = genreConfigs[genreId].guitarType;
    vector<string> etypes = genreConfigs[genreId].effectTypes;

    cout << "\n해당 장르는 일렉기타 1개와 이펙터의 타입 종류 총 " << etypes.size() << "개입니다. 구매를 진행하시겠습니까?\n";
    cout << "1. 예\n2. 아니오\n선택: ";
    int yn; cin >> yn;
    if (yn != 1) return;

    if (orderManager) orderManager->startNewOrderBundle();

    cout << "\n----------------------<해당 장르에 맞는 일렉기타 타입 제품 목록>----------------------\n";
    cout << "코드       | 모델명           | 브랜드       | 타입           | 가격       | 재고\n";
    cout << "--------------------------------------------------------------------------------------\n";
    loadGuitarMatches(gtype);

    cout << "\n--------일렉기타 구매 입력----------\n";
    createGuitarOrder(clientManager, productManager, orderManager);

    cout << "\n-----------------------<해당 장르에 맞는 이펙터 타입 제품 목록>-----------------------\n";
    cout << "코드       | 모델명           | 브랜드       | 타입           | 가격       | 재고\n";
    cout << "--------------------------------------------------------------------------------------\n";
    loadEffectMatches(etypes);

    cout << "\n--------이펙터 구매 입력-----------\n";
    createEffectOrders(etypes, clientManager, productManager, orderManager);

    if (orderManager) orderManager->endOrderBundle();

    cout << "\n주문이 완료되었습니다!\n" << endl;
}

void GenreStarterSet::loadGuitarMatches(const string& type) {
    ifstream file(GUITAR_FILE);
    string line;
    while (getline(file, line)) {
        vector<string> tokens;
        stringstream ss(line);
        string item;
        while (getline(ss, item, ',')) tokens.push_back(item);
        if (tokens.size() >= 6 && tokens[3].find(type) != string::npos) {
            cout << setw(10) << tokens[0] << " | "
                 << setw(15) << tokens[1] << " | "
                 << setw(12) << tokens[2] << " | "
                 << setw(13) << tokens[3] << " | "
                 << setw(10) << addComma(stoi(tokens[4])) << " | "
                 << setw(6) << addComma(stoi(tokens[5])) << endl;
        }
    }
    file.close();
}

void GenreStarterSet::loadEffectMatches(const vector<string>& types) {
    ifstream file(EFFECT_FILE);
    string line;
    while (getline(file, line)) {
        vector<string> tokens;
        stringstream ss(line);
        string item;
        while (getline(ss, item, ',')) tokens.push_back(item);
        if (tokens.size() >= 6) {
            for (const auto& t : types) {
                if (tokens[3] == t) {
                    cout << setw(10) << tokens[0] << " | "
                         << setw(15) << tokens[1] << " | "
                         << setw(12) << tokens[2] << " | "
                         << setw(13) << tokens[3] << " | "
                         << setw(10) << addComma(stoi(tokens[4])) << " | "
                         << setw(6) << addComma(stoi(tokens[5])) << endl;
                    break;
                }
            }
        }
    }
    file.close();
}

void GenreStarterSet::createGuitarOrder(ClientManager* clientManager, ProductManager* productManager, OrderManager* orderManager) {
    int cid; string code; int qty;
    cout << "고객 ID: "; cin >> cid;
    cout << "제품 코드: "; cin >> code;
    cout << "수량: "; cin >> qty;
    orderManager->createOrder(cid, code, qty, *clientManager, *productManager);
}

void GenreStarterSet::createEffectOrders(const vector<string>& types, ClientManager* clientManager, ProductManager* productManager, OrderManager* orderManager) {
    int cid;
    cout << "고객 ID: "; cin >> cid;
    cin.ignore();
    for (size_t i = 0; i < types.size(); ++i) {
        string code;
        int qty;
        cout << types[i] << " 제품 코드: ";
        getline(cin, code);
        cout << types[i] << " 수량: ";
        cin >> qty;
        cin.ignore();
        orderManager->createOrder(cid, code, qty, *clientManager, *productManager);
    }
}

[order.h]
#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
    Order(int orderId, int clientId, const std::string& productCode,
          int quantity, const std::string& date, const std::string& status = "구매완료");

    // Getter
    int getOrderId() const;
    int getClientId() const;
    std::string getProductCode() const;
    int getQuantity() const;
    std::string getDate() const;
    std::string getStatus() const;

    // Setter
    void setStatus(const std::string& newStatus);
    void setDate(const std::string& newDate);  // 날짜 수정 가능

private:
    int orderId;
    int clientId;
    std::string productCode;
    int quantity;
    std::string date;
    std::string status; // "구매완료", "환불완료"
};

#endif // ORDER_H

[order.cpp]
#include "order.h"

Order::Order(int orderId, int clientId, const std::string& productCode,
             int quantity, const std::string& date, const std::string& status)
    : orderId(orderId), clientId(clientId), productCode(productCode),
      quantity(quantity), date(date), status(status) {}

int Order::getOrderId() const {
    return orderId;
}

int Order::getClientId() const {
    return clientId;
}

std::string Order::getProductCode() const {
    return productCode;
}

int Order::getQuantity() const {
    return quantity;
}

std::string Order::getDate() const {
    return date;
}

std::string Order::getStatus() const {
    return status;
}

void Order::setStatus(const std::string& newStatus) {
    status = newStatus;
}

void Order::setDate(const std::string& newDate) {
    date = newDate;
}

[ordermanager.h]
#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <vector>
#include <string>
#include "order.h"
#include "clientmanager.h"
#include "productmanager.h"

namespace ClientSystem { class ClientManager; }
namespace ProductSystem { class ProductManager; }
namespace OrderSystem {
class OrderManager {
public:
    OrderManager();

    bool createOrder(int clientId, const std::string& productCode, int quantity,
                     ClientSystem::ClientManager& clientManager, ProductSystem::ProductManager& productManager); // 주문 생성

    bool refundOrder(int orderId, ProductSystem::ProductManager& productManager); // 환불

    void loadFromFile();
    void saveToFile() const;

    // ✅ 고객 이름 + 제품명 출력용 함수
    void showAllOrders(const ClientSystem::ClientManager& clientManager,
                       const ProductSystem::ProductManager& productManager) const;

    int getNextOrderId() const;
    std::string getTodayDateTime() const;

    Order* findOrderById(int orderId);
    void startNewOrderBundle();
    void endOrderBundle();

private:
    std::vector<Order*> orders;
    int nextOrderId;
    int currentBundleOrderId = 0;

    std::string getClientNameById(int clientId, const ClientSystem::ClientManager& cm) const;
};
}

#endif // ORDERMANAGER_H

[ordermanager.cpp]
#include "ordermanager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>

namespace OrderSystem {
const std::string ORDER_FILE = "data/orderlist.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

OrderManager::OrderManager() : nextOrderId(1), currentBundleOrderId(0) {
    loadFromFile();
}

void OrderManager::startNewOrderBundle() {
    currentBundleOrderId = nextOrderId++;
}

void OrderManager::endOrderBundle() {
    currentBundleOrderId = 0;
}

bool OrderManager::createOrder(int clientId, const std::string& productCode, int qty,
                               ClientSystem::ClientManager& clientManager, ProductSystem::ProductManager& productManager) {
    Client* client = clientManager.findClientById(clientId);
    if (!client) {
        std::cerr << "❌ 존재하지 않는 고객입니다.\n";
        return false;
    }

    auto& gm  = productManager.getGuitarManager();
    auto& em  = productManager.getEffectManager();
    auto& tm  = productManager.getTunerManager();
    auto& am  = productManager.getAmpManager();
    auto& pm  = productManager.getPowersupplyManager();
    auto& cm  = productManager.getCableManager();
    auto& acm = productManager.getAccessoryManager();

    Guitar*      g  = gm.findByCode(productCode);
    Effect*      e  = em.findByCode(productCode);
    Tuner*       t  = tm.findByCode(productCode);
    Amp*         a  = am.findByCode(productCode);
    Powersupply* p  = pm.findByCode(productCode);
    Cable*       c  = cm.findByCode(productCode);
    Accessory*   ac = acm.findByCode(productCode);

    std::vector<std::function<bool()>> actions = {
        [&]() { if (g  && g->isStockAvailable(qty)) { g->reduceStock(qty); gm.saveToFile(); return true; } return false; },
        [&]() { if (e  && e->isStockAvailable(qty)) { e->reduceStock(qty); em.saveToFile(); return true; } return false; },
        [&]() { if (t  && t->isStockAvailable(qty)) { t->reduceStock(qty); tm.saveToFile(); return true; } return false; },
        [&]() { if (a  && a->isStockAvailable(qty)) { a->reduceStock(qty); am.saveToFile(); return true; } return false; },
        [&]() { if (p  && p->isStockAvailable(qty)) { p->reduceStock(qty); pm.saveToFile(); return true; } return false; },
        [&]() { if (c  && c->isStockAvailable(qty)) { c->reduceStock(qty); cm.saveToFile(); return true; } return false; },
        [&]() { if (ac && ac->isStockAvailable(qty)) { ac->reduceStock(qty); acm.saveToFile(); return true; } return false; }
    };

    bool success = false;
    for (auto& act : actions) {
        if (act()) {
            success = true;
            break;
        }
    }

    if (!success) {
        std::cerr << "❌ 존재하지 않거나 재고가 부족한 제품입니다.\n";
        return false;
    }

    int orderIdToUse = (currentBundleOrderId > 0) ? currentBundleOrderId : nextOrderId++;
    Order* order = new Order(orderIdToUse, clientId, productCode, qty, getTodayDateTime());
    orders.push_back(order);
    saveToFile();

    std::cout << "✅ 주문이 완료되었습니다.\n";
    return true;
}

bool OrderManager::refundOrder(int orderId, ProductSystem::ProductManager& productManager) {
    bool anyRefunded = false;
    for (auto& order : orders) {
        if (order->getOrderId() == orderId && order->getStatus() != "환불완료") {
            std::string code = order->getProductCode();
            int qty = order->getQuantity();

            auto& gm  = productManager.getGuitarManager();
            auto& em  = productManager.getEffectManager();
            auto& tm  = productManager.getTunerManager();
            auto& am  = productManager.getAmpManager();
            auto& pm  = productManager.getPowersupplyManager();
            auto& cm  = productManager.getCableManager();
            auto& acm = productManager.getAccessoryManager();

            if (auto* g = gm.findByCode(code)) { g->addStock(qty); gm.saveToFile(); }
            else if (auto* e = em.findByCode(code)) { e->addStock(qty); em.saveToFile(); }
            else if (auto* t = tm.findByCode(code)) { t->addStock(qty); tm.saveToFile(); }
            else if (auto* a = am.findByCode(code)) { a->addStock(qty); am.saveToFile(); }
            else if (auto* p = pm.findByCode(code)) { p->addStock(qty); pm.saveToFile(); }
            else if (auto* c = cm.findByCode(code)) { c->addStock(qty); cm.saveToFile(); }
            else if (auto* ac = acm.findByCode(code)) { ac->addStock(qty); acm.saveToFile(); }

            order->setDate(getTodayDateTime());
            order->setStatus("환불완료");
            anyRefunded = true;
        }
    }

    if (anyRefunded) {
        saveToFile();
        std::cout << "✅ 묶음 주문 전체 환불이 완료되었습니다.\n";
        return true;
    } else {
        std::cerr << "❌ 해당 주문번호의 환불 가능한 항목이 없습니다.\n";
        return false;
    }
}

void OrderManager::loadFromFile() {
    std::ifstream file(ORDER_FILE);
    if (!file.is_open()) return;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        int id, clientId, qty;
        std::string productCode, date, status;

        ss >> id; ss.ignore();
        ss >> clientId; ss.ignore();
        getline(ss, productCode, ',');
        ss >> qty; ss.ignore();
        getline(ss, date, ',');
        getline(ss, status);

        Order* order = new Order(id, clientId, productCode, qty, date, status);
        orders.push_back(order);
        if (id >= nextOrderId) nextOrderId = id + 1;
    }
}

void OrderManager::saveToFile() const {
    std::ofstream file(ORDER_FILE);
    for (const auto& order : orders) {
        file << order->getOrderId() << ","
             << order->getClientId() << ","
             << order->getProductCode() << ","
             << order->getQuantity() << ","
             << order->getDate() << ","
             << order->getStatus() << "\n";
    }
}

void OrderManager::showAllOrders(const ClientSystem::ClientManager& clientManager, const ProductSystem::ProductManager& productManager) const {
    while (true) {
        std::cout << "\n주문번호 | 고객ID   | 고객이름      | 제품코드   | 제품명(모델명)           | 수량     | 날짜                | 상태\n";
        std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

        for (const auto& order : orders) {
            const Client* client = clientManager.findClientById(order->getClientId());
            std::string clientName = client ? client->getName() : "알 수 없음";
            std::string clientIdStr = client ? std::to_string(client->id()) : "알 수 없음";
            std::string productCode = order->getProductCode();
            std::string productName = "알 수 없음";

            if (const Guitar* g = productManager.getGuitarManager().findByCode(productCode)) {
                productName = g->getModel();
            } else if (const Effect* e = productManager.getEffectManager().findByCode(productCode)) {
                productName = e->getModel();
            } else if (const Tuner* t = productManager.getTunerManager().findByCode(productCode)) {
                productName = t->getModel();
            } else if (const Amp* a = productManager.getAmpManager().findByCode(productCode)) {
                productName = a->getModel();
            } else if (const Powersupply* p = productManager.getPowersupplyManager().findByCode(productCode)) {
                productName = p->getModel();
            } else if (const Cable* c = productManager.getCableManager().findByCode(productCode)) {
                productName = c->getModel();
            } else if (const Accessory* ac = productManager.getAccessoryManager().findByCode(productCode)) {
                productName = ac->getModel();
            }

            std::cout << std::setw(9) << order->getOrderId() << " | "
                      << std::setw(8) << clientIdStr << " | "
                      << std::setw(12) << clientName << " | "
                      << std::setw(10) << productCode << " | "
                      << std::setw(22) << productName << " | "
                      << std::setw(8) << addComma(order->getQuantity()) << " | "
                      << std::setw(19) << order->getDate() << " | "
                      << order->getStatus() << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "주문번호 | 고객ID   | 고객이름      | 제품코드   | 제품명(모델명)           | 수량     | 날짜                | 상태\n";
            std::cout << "------------------------------------------------------------------------------------------------------------------------\n";

            bool found = false;
            for (const auto& order : orders) {
                const Client* client = clientManager.findClientById(order->getClientId());
                std::string clientName = client ? client->getName() : "알 수 없음";
                std::string clientIdStr = client ? std::to_string(client->id()) : "알 수 없음";
                std::string productCode = order->getProductCode();
                std::string productName = "알 수 없음";

                if (const Guitar* g = productManager.getGuitarManager().findByCode(productCode)) {
                    productName = g->getModel();
                } else if (const Effect* e = productManager.getEffectManager().findByCode(productCode)) {
                    productName = e->getModel();
                } else if (const Tuner* t = productManager.getTunerManager().findByCode(productCode)) {
                    productName = t->getModel();
                } else if (const Amp* a = productManager.getAmpManager().findByCode(productCode)) {
                    productName = a->getModel();
                } else if (const Powersupply* p = productManager.getPowersupplyManager().findByCode(productCode)) {
                    productName = p->getModel();
                } else if (const Cable* c = productManager.getCableManager().findByCode(productCode)) {
                    productName = c->getModel();
                } else if (const Accessory* ac = productManager.getAccessoryManager().findByCode(productCode)) {
                    productName = ac->getModel();
                }

                if (std::to_string(order->getOrderId()).find(keyword) != std::string::npos ||
                    clientIdStr.find(keyword) != std::string::npos ||
                    clientName.find(keyword) != std::string::npos ||
                    productCode.find(keyword) != std::string::npos ||
                    productName.find(keyword) != std::string::npos ||
                    order->getStatus().find(keyword) != std::string::npos) {
                    std::cout << std::setw(9) << order->getOrderId() << " | "
                              << std::setw(8) << clientIdStr << " | "
                              << std::setw(12) << clientName << " | "
                              << std::setw(10) << productCode << " | "
                              << std::setw(22) << productName << " | "
                              << std::setw(8) << addComma(order->getQuantity()) << " | "
                              << std::setw(19) << order->getDate() << " | "
                              << order->getStatus() << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return;

        } else if (opt == 2) {
            return;
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

std::string OrderManager::getTodayDateTime() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[32];
    snprintf(buf, sizeof(buf), "%04d/%02d/%02d %02d:%02d:%02d",
             1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
             ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
    return std::string(buf);
}
}

[productmanager.h]
#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <string>

#include "guitarmanager.h"
#include "effectmanager.h"
#include "tunermanager.h"
#include "ampmanager.h"
#include "powersupplymanager.h"
#include "cablemanager.h"
#include "accessorymanager.h"

namespace ProductSystem {
class ProductManager {
private:
    GuitarManager guitarManager;
    EffectManager effectManager;
    TunerManager tunerManager;
    AmpManager ampManager;
    PowersupplyManager powerSupplyManager;
    CableManager cableManager;
    AccessoryManager accessoryManager;

public:
    ProductManager();
    ~ProductManager();

    void saveToFile();                     // 각 제품군 파일로 저장
    void loadFromFile();                   // 각 제품군 파일로부터 로드
    bool displayMenu();                    // 콘솔 기반 메뉴

    GuitarManager& getGuitarManager() { return guitarManager; }
    const GuitarManager& getGuitarManager() const { return guitarManager; }

    EffectManager& getEffectManager() { return effectManager; }
    const EffectManager& getEffectManager() const { return effectManager; }

    TunerManager& getTunerManager() { return tunerManager; }
    const TunerManager& getTunerManager() const { return tunerManager; }

    AmpManager& getAmpManager() { return ampManager; }
    const AmpManager& getAmpManager() const { return ampManager; }

    PowersupplyManager& getPowersupplyManager() { return powerSupplyManager; }
    const PowersupplyManager& getPowersupplyManager() const { return powerSupplyManager; }

    CableManager& getCableManager() { return cableManager; }
    const CableManager& getCableManager() const { return cableManager; }

    AccessoryManager& getAccessoryManager() { return accessoryManager; }
    const AccessoryManager& getAccessoryManager() const { return accessoryManager; }

};
}

#endif // PRODUCTMANAGER_H

[productmanager.cpp]
#include "productmanager.h"
#include <iostream>

namespace ProductSystem {
ProductManager::ProductManager() {
    loadFromFile();
}

ProductManager::~ProductManager() {
    saveToFile();
}

void ProductManager::saveToFile() {
    guitarManager.saveToFile();
    effectManager.saveToFile();
    tunerManager.saveToFile();
    ampManager.saveToFile();
    powerSupplyManager.saveToFile();
    cableManager.saveToFile();
    accessoryManager.saveToFile();
}

void ProductManager::loadFromFile() {
    guitarManager.loadFromFile();
    effectManager.loadFromFile();
    tunerManager.loadFromFile();
    ampManager.loadFromFile();
    powerSupplyManager.loadFromFile();
    cableManager.loadFromFile();
    accessoryManager.loadFromFile();
}

bool ProductManager::displayMenu() {
    int choice;
    std::cout << "\n========= 제품 관리 =========\n";
    std::cout << "1. 일렉기타 관리\n";
    std::cout << "2. 이펙터 관리\n";
    std::cout << "3. 튜너 관리\n";
    std::cout << "4. 앰프 관리\n";
    std::cout << "5. 파워서플라이 관리\n";
    std::cout << "6. 케이블 관리\n";
    std::cout << "7. 액세서리 관리\n";
    std::cout << "8. 메인 메뉴로 돌아가기\n";
    std::cout << "선택: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return guitarManager.displayMenu();
        case 2: return effectManager.displayMenu();
        case 3: return tunerManager.displayMenu();
        case 4: return ampManager.displayMenu();
        case 5: return powerSupplyManager.displayMenu();
        case 6: return cableManager.displayMenu();
        case 7: return accessoryManager.displayMenu();
        case 8: return false;
        default:
            std::cout << "잘못된 선택입니다.\n";
            return true;
    }
}
}

[tuner.h]
#ifndef TUNER_H
#define TUNER_H

#include <string>

class Tuner {
private:
    std::string code;
    std::string model;
    std::string brand;
    int price;
    int stock;

public:
    Tuner() = default;

    Tuner(const std::string& code,
           const std::string& model,
           const std::string& brand,
           int price,
           int stock);

    std::string getCode() const;
    std::string getModel() const;
    std::string getBrand() const;
    int getPrice() const;
    int getStock() const;

    void setPrice(int price);
    void setStock(int stock);

    bool isStockAvailable(int qty) const;
    void reduceStock(int qty);
    void addStock(int qty);
};

#endif // TUNER_H

[tuner.cpp]
#include "tuner.h"

Tuner::Tuner(const std::string& code,
                const std::string& model,
                const std::string& brand,
                int price,
                int stock)
    : code(code), model(model), brand(brand),
      price(price), stock(stock) {}

std::string Tuner::getCode() const { return code; }
std::string Tuner::getModel() const { return model; }
std::string Tuner::getBrand() const { return brand; }
int Tuner::getPrice() const { return price; }
int Tuner::getStock() const { return stock; }

void Tuner::setPrice(int price) { this->price = price; }
void Tuner::setStock(int stock) { this->stock = stock; }

bool Tuner::isStockAvailable(int qty) const {
    return stock >= qty;
}

void Tuner::reduceStock(int qty) {
    if (qty <= stock)
        stock -= qty;
}
void Tuner::addStock(int qty) {
    stock += qty;
}

[tunermanager.h]
#ifndef TUNERMANAGER_H
#define TUNERMANAGER_H

#include <vector>
#include <string>
#include "tuner.h"

class TunerManager {
private:
    std::vector<Tuner> tuners;

public:
    TunerManager();

    void loadFromFile();
    void saveToFile() const;
    // 파일 이름을 인자로 받는 오버로딩된 함수

//    void loadFromFile(const std::string& filename = "data/pdList_tuners.txt");
//    void saveToFile(const std::string& filename = "data/pdList_tuners.txt") const;

    void inputTuner();    // 콘솔 입력
    void deleteTuner();   // 코드 기준 삭제
    void displayTuner() const;

    const Tuner* findByCode(const std::string& code) const;
    Tuner* findByCode(const std::string& code);

    bool displayMenu();    // 내부 메뉴 루프
};

#endif // TUNERMANAGER_H

[tunermanager.cpp]
#include "tunermanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

const std::string TUNER_FILE = "data/pdList_tuners.txt";

inline std::string addComma(int number) {
    std::ostringstream oss;
    oss.imbue(std::locale(""));
    oss << std::fixed << number;
    return oss.str();
}

TunerManager::TunerManager() {
    loadFromFile();
}

void TunerManager::loadFromFile() {
    tuners.clear();
    std::ifstream file(TUNER_FILE);
    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string code, model, brand;
        int price, stock;

        getline(ss, code, ',');
        getline(ss, model, ',');
        getline(ss, brand, ',');
        ss >> price; ss.ignore();
        ss >> stock;

        tuners.emplace_back(code, model, brand, price, stock);
    }
}

void TunerManager::saveToFile() const {
    std::ofstream file(TUNER_FILE);
    for (const auto& t : tuners) {
        file << t.getCode() << ","
             << t.getModel() << ","
             << t.getBrand() << ","
             << t.getPrice() << ","
             << t.getStock() << "\n";
    }
}

void TunerManager::inputTuner() {
    std::string code, model, brand;
    int price, stock;

    std::cin.ignore(); // 버퍼 초기화
    std::cout << "코드: ";
    std::getline(std::cin, code);

    std::cout << "모델명: ";
    std::getline(std::cin, model);

    std::cout << "브랜드: ";
    std::getline(std::cin, brand);

    std::cout << "가격: ";
    std::cin >> price;
    std::cin.ignore(); // 버퍼 초기화

    std::cout << "재고: ";
    std::cin >> stock;
    std::cin.ignore(); // 버퍼 초기화

    tuners.emplace_back(code, model, brand, price, stock);
    saveToFile();
}

void TunerManager::deleteTuner() {
    std::string code;
    std::cout << "삭제할 코드: ";
    std::cin >> code;

    auto it = std::remove_if(tuners.begin(), tuners.end(),
        [&](const Tuner& t) { return t.getCode() == code; });

    if (it != tuners.end()) {
        tuners.erase(it, tuners.end());
        std::cout << "삭제되었습니다.\n";
        saveToFile();
    } else {
        std::cout << "해당 코드를 찾을 수 없습니다.\n";
    }
}

bool TunerManager::displayMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- 튜너 관리 ---\n";
        std::cout << "1. 등록\n";
        std::cout << "2. 삭제\n";
        std::cout << "3. 전체 목록 보기\n";
        std::cout << "4. 이전 메뉴로 돌아가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: inputTuner(); break;
            case 2: deleteTuner(); break;
            case 3: displayTuner(); break;
            case 4: return true; // ProductManager로 돌아가기
            default: std::cout << "잘못된 선택입니다.\n"; break;
        }
    }
    return true;
}

void TunerManager::displayTuner() const {
    while (true) {
        std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
        std::cout << "------------------------------------------------------------\n";
        for (const auto& t : tuners) {
            std::cout << std::setw(10) << t.getCode() << " | "
                      << std::setw(12) << t.getModel() << " | "
                      << std::setw(12) << t.getBrand() << " | "
                      << std::setw(10) << addComma(t.getPrice()) << " | "
                      << std::setw(5) << addComma(t.getStock()) << "\n";
        }

        std::cout << "\n========= 키워드 검색 =========\n";
        std::cout << "1. 검색하기\n";
        std::cout << "2. 되돌아가기\n";
        std::cout << "선택: ";

        int opt;
        std::cin >> opt;

        if (opt == 1) {
            std::cin.ignore();
            std::string keyword;
            std::cout << "검색할 키워드 입력: ";
            std::getline(std::cin, keyword);

            std::cout << "\n[검색 결과]\n";
            std::cout << "\n코드       | 모델명         | 브랜드     | 가격       | 재고\n";
            std::cout << "------------------------------------------------------------\n";

            bool found = false;
            for (const auto& t : tuners) {
                if (t.getModel().find(keyword) != std::string::npos ||
                    t.getBrand().find(keyword) != std::string::npos ||
                    t.getCode().find(keyword) != std::string::npos) {
                    std::cout << std::setw(10) << t.getCode() << " | "
                              << std::setw(12) << t.getModel() << " | "
                              << std::setw(12) << t.getBrand() << " | "
                              << std::setw(10) << addComma(t.getPrice()) << " | "
                              << std::setw(5)  << addComma(t.getStock()) << "\n";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "일치하는 항목이 없습니다.\n";
            }

            std::cout << "\n확인을 했다면 Enter 키를 입력하세요";
            std::cin.get();
            return; // 검색 결과만 보여주고 종료

        } else if (opt == 2) {
            return; // displayMenu로 돌아감
        } else {
            std::cout << "잘못된 선택입니다.\n";
        }
    }
}

const Tuner* TunerManager::findByCode(const std::string& code) const{
    for (auto& t : tuners) {
        if (t.getCode() == code)
            return &t;
    }
    return nullptr;
}

Tuner* TunerManager::findByCode(const std::string& code) {
    for (auto& t : tuners) {
        if (t.getCode() == code)
            return &t;
    }
    return nullptr;
}

[main.cpp]
#include <iostream>
#include "clientmanager.h"
#include "productmanager.h"
#include "ordermanager.h"
#include "genrestarterset.h"

using namespace std;
using namespace ClientSystem;
using namespace ProductSystem;
using namespace OrderSystem;
using namespace GenreStarter;

int main() {
    ClientManager clientManager;
    ProductManager productManager;
    OrderManager orderManager;
    GenreStarterSet starterSet;

    while (true) {
        cout << "\n========= Main Menu =========\n";
        cout << "1. 고객 관리\n";
        cout << "2. 제품 관리\n";
        cout << "3. 주문 생성\n";
        cout << "4. 주문 목록 보기\n";
        cout << "5. 주문 환불 처리\n";
        cout << "6. Genre Starter Set\n";  // ✅ 추가된 메뉴
        cout << "7. 종료\n";
        cout << "=============================\n";
        cout << "선택: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                while (clientManager.displayMenu());
                break;
            case 2:
                while (productManager.displayMenu());
                break;
            case 3: {
                int clientId, quantity;
                string productCode;

                cout << "고객 ID: ";
                cin >> clientId;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "숫자 입력이 필요합니다. 주문 생성을 취소합니다.\n";
                    break;
                }
                cout << "제품 코드: ";
                cin >> productCode;
                cout << "수량: ";
                cin >> quantity;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "숫자 입력이 필요합니다. 주문 생성을 취소합니다.\n";
                    break;
                }

                orderManager.createOrder(clientId, productCode, quantity, clientManager, productManager);
                break;
            }
            case 4:
                orderManager.showAllOrders(clientManager, productManager);
                break;
            case 5: {
                int orderId;
                cout << "환불할 주문번호 입력: ";
                cin >> orderId;
                orderManager.refundOrder(orderId, productManager);
                break;
            }
            case 6:
                starterSet.displayGenreMenu(&clientManager, &productManager, &orderManager);
                break;
            case 7:
                cout << "프로그램을 종료합니다.\n";
                return 0;
            default:
                cout << "잘못된 선택입니다.\n";
                break;
        }
    }
}
 *
 */







/*
---
config:
  theme: default
  layout: elk
  class:
    hideEmptyMembersBox: false
---
classDiagram
direction BT

  class ProductManager {
    - guitarManager: GuitarManager
    - effectManager: EffectManager
    - tunerManager: TunerManager
    - ampManager: AmpManager
    - powerSupplyManager: PowersupplyManager
    - cableManager: CableManager
    - accessoryManager: AccessoryManager
    + ProductManager()
    + ~ProductManager()
    + saveToFile(): void
    + loadFromFile(): void
    + displayMenu(): bool
    + getGuitarManager(): GuitarManager&
    + getGuitarManager() const: const GuitarManager&
    + getEffectManager(): EffectManager&
    + getEffectManager() const: const EffectManager&
    + getTunerManager(): TunerManager&
    + getTunerManager() const: const TunerManager&
    + getAmpManager(): AmpManager&
    + getAmpManager() const: const AmpManager&
    + getPowersupplyManager(): PowersupplyManager&
    + getPowersupplyManager() const: const PowersupplyManager&
    + getCableManager(): CableManager&
    + getCableManager() const: const CableManager&
    + getAccessoryManager(): AccessoryManager&
    + getAccessoryManager() const: const AccessoryManager&
  }
  class GuitarManager {
    - guitars: vector~Guitar~
    + GuitarManager()
    + loadFromFile(): void
    + saveToFile() const: void
    + inputGuitar(): void
    + deleteGuitar(): void
    + displayGuitar() const: void
    + findByCode(code: string) const: Guitar*
    + findByCode(code: string): Guitar*
    + displayMenu(): bool
  }
  class Guitar {
    - code: string
    - model: string
    - brand: string
    - type: string
    - price: int
    - stock: int
    + Guitar()
    + Guitar(code: string, model: string, brand: string, type: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getType(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  GuitarManager --> Guitar : manages
  GuitarManager --> ProductManager

  class Effect {
    - code: string
    - model: string
    - brand: string
    - effectType: string
    - price: int
    - stock: int
    + Effect()
    + Effect(code: string, model: string, brand: string, effectType: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getEffectType(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class EffectManager {
    - effects: vector~Effect~
    + EffectManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputEffect(): void
    + deleteEffect(): void
    + displayEffect(): void
    + findByCode(code: string): Effect*
    + findByCode(code: string) const: const Effect*
    + displayMenu(): bool
  }
  EffectManager --> Effect : manages
  EffectManager --> ProductManager

  class Accessory {
    - code: string
    - model: string
    - purpose: string
    - price: int
    - stock: int
    + Accessory()
    + Accessory(code: string, model: string, purpose: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getPurpose(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class AccessoryManager {
    - accessories: vector~Accessory~
    + AccessoryManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputAccessory(): void
    + deleteAccessory(): void
    + displayAccessory(): void
    + findByCode(code: string): Accessory*
    + findByCode(code: string) const: const Accessory*
    + displayMenu(): bool
  }
  AccessoryManager --> Accessory : manages
  AccessoryManager --> ProductManager

  class Amp {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
    + Amp()
    + Amp(code: string, model: string, brand: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class AmpManager {
    - amps: vector~Amp~
    + AmpManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputAmp(): void
    + deleteAmp(): void
    + displayAmp(): void
    + findByCode(code: string): Amp*
    + findByCode(code: string) const: const Amp*
    + displayMenu(): bool
  }
  AmpManager --> Amp : manages
  AmpManager --> ProductManager

  class Powersupply {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
    + Powersupply()
    + Powersupply(code: string, model: string, brand: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class PowersupplyManager {
    - powersupplies: vector~Powersupply~
    + PowersupplyManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputPowerSupply(): void
    + deletePowerSupply(): void
    + displayPowerSupply(): void
    + findByCode(code: string): Powersupply*
    + findByCode(code: string) const: const Powersupply*
    + displayMenu(): bool
  }
  PowersupplyManager --> Powersupply : manages
  PowersupplyManager --> ProductManager

  class Cable {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
    + Cable()
    + Cable(code: string, model: string, brand: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class CableManager {
    - cables: vector~Cable~
    + CableManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputCable(): void
    + deleteCable(): void
    + displayCable(): void
    + findByCode(code: string): Cable*
    + findByCode(code: string) const: const Cable*
    + displayMenu(): bool
  }
  CableManager --> Cable : manages
  CableManager --> ProductManager

  class Tuner {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
    + Tuner()
    + Tuner(code: string, model: string, brand: string, price: int, stock: int)
    + getCode(): string
    + getModel(): string
    + getBrand(): string
    + getPrice(): int
    + getStock(): int
    + setPrice(price: int): void
    + setStock(stock: int): void
    + isStockAvailable(qty: int): bool
    + reduceStock(qty: int): void
    + addStock(qty: int): void
  }
  class TunerManager {
    - tuners: vector~Tuner~
    + TunerManager()
    + loadFromFile(): void
    + saveToFile(): void
    + inputTuner(): void
    + deleteTuner(): void
    + displayTuner(): void
    + findByCode(code: string): Tuner*
    + findByCode(code: string) const: const Tuner*
    + displayMenu(): bool
  }
  TunerManager --> Tuner : manages
  TunerManager --> ProductManager

  class Client {
    - m_id: int
    - m_name: string
    - m_phoneNumber: string
    - m_address: string
    + Client(id: int, name: string, phone: string, address: string)
    + getName(): string
    + setName(name: string): void
    + getPhoneNumber(): string
    + setPhoneNumber(phone: string): void
    + getAddress(): string
    + setAddress(address: string): void
    + id(): int
    + operator==(other: Client): bool
  }

  %%class ClientSystem::ClientManager {
  %%ClientSystem::ClientManager
  class ClientManager {
    - clientList: map~int, Client*~
    + ClientManager()
    + ~ClientManager()
    + inputClient(): void
    + addClient(Client*): void
    + deleteClient(int): void
    + modifyClient(int): void
    + makeId(): int
    + displayInfo(): void
    + saveToFile(): void
    + parseCSV(istream&, char): vector~string~
    + findClientById(int): Client*
    + findClientByName(name: string): Client*
    + displayMenu(): bool
  }
  ClientManager --> Client : manages

  class Order {
    - orderId: int
    - clientId: int
    - productCode: string
    - quantity: int
    - date: string
    - status: string
    + Order(orderId: int, clientId: int, productCode: string, quantity: int, date: string, status: string)
    + getOrderId(): int
    + getClientId(): int
    + getProductCode(): string
    + getQuantity(): int
    + getDate(): string
    + getStatus(): string
    + setStatus(newStatus: string): void
    + setDate(newDate: string): void
  }

  class OrderManager {
    - orders: vector~Order*~
    - nextOrderId: int
    - currentBundleOrderId: int
    + OrderManager()
    + createOrder(clientId: int, productCode: string, quantity: int, clientManager: ClientManager, productManager: ProductManager): bool
    + refundOrder(orderId: int, productManager: ProductManager): bool
    + loadFromFile(): void
    + saveToFile(): void
    + showAllOrders(clientManager: ClientManager, productManager: ProductManager): void
    + getNextOrderId(): int
    + getTodayDateTime(): string
    + findOrderById(orderId: int): Order*
    + startNewOrderBundle(): void
    + endOrderBundle(): void
  }
  OrderManager --> Order : handles
  OrderManager --> ClientManager : uses
  OrderManager --> ProductManager : uses

  class GenreStarterSet {
    - genreNames: map~int, string~
    - genreConfigs: map~int, GenreConfig~
    + GenreStarterSet()
    + displayGenreMenu(clientManager: ClientManager*, productManager: ProductManager*, orderManager: OrderManager*): void
    - processGenreSelection(genreId: int, clientManager: ClientManager*, productManager: ProductManager*, orderManager: OrderManager*): void
    - loadGuitarMatches(type: string): void
    - loadEffectMatches(types: vector~string~): void
    - createGuitarOrder(clientManager: ClientManager*, productManager: ProductManager*, orderManager: OrderManager*): void
    - createEffectOrders(types: vector~string~, clientManager: ClientManager*, productManager: ProductManager*, orderManager: OrderManager*): void
  }
  GenreStarterSet --> ClientManager : uses
  GenreStarterSet --> ProductManager : uses
  GenreStarterSet --> OrderManager : uses
 */








/*
 *
 *
---
config:
  theme: default
  layout: elk
  class:
    hideEmptyMembersBox: false
---
classDiagram
direction BT

  %% Client
  class Client {
    - m_id: int
    - m_name: string
    - m_phoneNumber: string
    - m_address: string
    + getName(): string
    + getPhoneNumber(): string
    + getAddress(): string
    + id(): int
  }

  class ClientManager {
    - clientList: map~int, Client*~
    + inputClient(): void
    + addClient(Client*): void
    + deleteClient(int): void
    + displayInfo(): void
    + findClientById(int): Client*
    + findClientByName(string): Client*
  }

  ClientManager --> Client : manages

  %% Product (7종)
  class Guitar {
    - code: string
    - model: string
    - brand: string
    - type: string
    - price: int
    - stock: int
  }

  class Effect {
    - code: string
    - model: string
    - brand: string
    - effectType: string
    - price: int
    - stock: int
  }

  class Accessory {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
  }

    class Tuner {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
  }

    class Amp {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
  }

    class Powersupply {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
  }

    class Cable {
    - code: string
    - model: string
    - brand: string
    - price: int
    - stock: int
  }

  class GuitarManager {
    - guitars: vector~Guitar~
  }

  class EffectManager {
    - effects: vector~Effect~
  }

  class TunerManager {
    - tuners: vector~Tuner~
  }

  class AmpManager {
    - amps: vector~Amp~
  }

  class PowersupplyManager {
    - powersupplies: vector~Powersupply~
  }

  class CableManager {
    - cables: vector~Cable~
  }

  class AccessoryManager {
    - accessories: vector~Accessory~
  }

  GuitarManager --> Guitar : manages
  EffectManager --> Effect : manages
  TunerManager --> Tuner : manages
  AmpManager --> Amp : manages
  PowersupplyManager --> Powersupply : manages
  CableManager --> Cable : manages
  AccessoryManager --> Accessory : manages

  class ProductManager {
    - guitarManager: GuitarManager
    - effectManager: EffectManager
    - tunerManager: TunerManager
    - ampManager: AmpManager
    - powerSupplyManager: PowersupplyManager
    - cableManager: CableManager
    - accessoryManager: AccessoryManager
    + getGuitarManager(): GuitarManager&
    + getEffectManager(): EffectManager&
  }

  ProductManager --> GuitarManager : includes
  ProductManager --> EffectManager : includes
  ProductManager --> TunerManager : includes
  ProductManager --> AmpManager : includes
  ProductManager --> PowersupplyManager : includes
  ProductManager --> CableManager : includes
  ProductManager --> AccessoryManager : includes

  %% Order
  class Order {
    - orderId: int
    - clientId: int
    - productCode: string
    - quantity: int
    - date: string
    - status: string
  }

  class OrderManager {
    - orders: vector~Order*~
    + createOrder(...)
    + refundOrder(...)
    + showAllOrders(...)
    + loadFromFile(): void
  }

  OrderManager --> Order : manages
  OrderManager --> ClientManager : uses
  OrderManager --> ProductManager : uses

  %% GenreStarter
  class GenreStarterSet {
    - genreNames: map~int, string~
    - genreConfigs: map~int, GenreConfig~
    + displayGenreMenu(...)
  }

  GenreStarterSet --> ClientManager : uses
  GenreStarterSet --> ProductManager : uses
  GenreStarterSet --> OrderManager : uses
 *
 *
 *
 *
 *
 *
 *
 *
*/

/*
 *
 *
 *
 *
classDiagram
  class Client {
    - m_id: int
    - m_name: string
    - m_phoneNumber: string
    - m_address: string
    + getName(): string
    + getPhoneNumber(): string
    + getAddress(): string
    + id(): int
  }

  class ClientManager {
    - clientList: map~int, Client*~
    + inputClient(): void
    + addClient(Client*): void
    + deleteClient(int): void
    + findClientById(int): Client*
    + findClientByName(string): Client*
  }

  ClientManager --> Client : manages


  class ProductManager {
    - guitarManager: GuitarManager
    - effectManager: EffectManager
    - tunerManager: TunerManager
    - ampManager: AmpManager
    - powerSupplyManager: PowersupplyManager
    - cableManager: CableManager
    - accessoryManager: AccessoryManager
  }

  ProductManager --> GuitarManager : includes
  ProductManager --> EffectManager : includes
  ProductManager --> TunerManager : includes
  ProductManager --> AmpManager : includes
  ProductManager --> PowersupplyManager : includes
  ProductManager --> CableManager : includes
  ProductManager --> AccessoryManager : includes

  GuitarManager --> Guitar : manages
  EffectManager --> Effect : manages
  TunerManager --> Tuner : manages
  AmpManager --> Amp : manages
  PowersupplyManager --> Powersupply : manages
  CableManager --> Cable : manages
  AccessoryManager --> Accessory : manages

    class Order {
    - orderId: int
    - clientId: int
    - productCode: string
    - quantity: int
    - date: string
    - status: string
  }

  class OrderManager {
    - orders: vector~Order*~
    + createOrder(...)
    + refundOrder(...)
    + showAllOrders(...)
  }

  OrderManager --> Order : manages
  OrderManager --> ClientManager : uses
  OrderManager --> ProductManager : uses

  class GenreStarterSet {
    - genreNames: map~int, string~
    - genreConfigs: map~int, GenreConfig~
    + displayGenreMenu(...)
  }

  GenreStarterSet --> ClientManager : uses
  GenreStarterSet --> ProductManager : uses
  GenreStarterSet --> OrderManager : uses
 *
 *
 *
 *
 *
 */

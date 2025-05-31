#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

/*
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

%% ProductManager
class ProductManager {
  - guitarManager: GuitarManager
  - effectManager: EffectManager
  - accessoryManager: AccessoryManager
  - ampManager: AmpManager
  - powerSupplyManager: PowerSupplyManager
  - cableManager: CableManager
  - tunerManager: TunerManager
  + saveToFile(filename): void
  + loadFromFile(filename): void
  + applyDiscountToProduct(code, percent): void
  + formatStockWithComma(): void
}

%% Guitar (Merged)
class GuitarManager {
  - guitars: vector~Guitar~
  + inputGuitar(): void
  + deleteGuitar(): void
  + findGuitarByCode(code): Guitar
  + applyDiscount(code, percent): void
}
class Guitar {
  +code: string
  +model: string
  +brand: string
  +type: string
  +price: int
  +stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getType(): string
  +getPrice(): int
  +getStock(): int
}
GuitarManager --> Guitar
GuitarManager --> ProductManager

%% Effect (Merged)
class EffectManager {
  - effects: vector~Effect~
  + inputEffect(): void
  + deleteEffect(): void
  + findEffectByCode(code): Effect
  + applyDiscount(code, percent): void
}
class Effect {
  +code: string
  +model: string
  +brand: string
  +effectType: string
  +price: int
  +stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getEffectType(): string
  +getPrice(): int
  +getStock(): int
}
EffectManager --> Effect
EffectManager --> ProductManager

%% Accessory
class AccessoryManager {
  - accessories: vector~Accessory~
  + inputAccessory(): void
  + deleteAccessory(): void
  + findAccessoryByPurpose(purpose): Accessory
}
class Accessory {
  - code: string
  - model: string
  - purpose: string
  - price: int
  - stock: int
  +getCode(): string
  +getModel(): string
  +getPurpose(): string
  +getPrice(): int
  +getStock(): int
}
AccessoryManager --> Accessory
AccessoryManager --> ProductManager

%% Amp
class AmpManager {
  - amps: vector~Amp~
  + inputAmp(): void
  + deleteAmp(): void
  + findAmpByCode(code): Amp
}
class Amp {
  - code: string
  - model: string
  - brand: string
  - price: int
  - stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
AmpManager --> Amp
AmpManager --> ProductManager

%% PowerSupply
class PowerSupplyManager {
  - powerSupplies: vector~PowerSupply~
  + inputPowerSupply(): void
  + deletePowerSupply(): void
  + findPowerSupplyByCode(code): PowerSupply
}
class PowerSupply {
  - code: string
  - model: string
  - brand: string
  - price: int
  - stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
PowerSupplyManager --> PowerSupply
PowerSupplyManager --> ProductManager

%% Cable
class CableManager {
  - cables: vector~Cable~
  + inputCable(): void
  + deleteCable(): void
  + findCableByCode(code): Cable
}
class Cable {
  - code: string
  - model: string
  - brand: string
  - price: int
  - stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
CableManager --> Cable
CableManager --> ProductManager

%% Tuner
class TunerManager {
  - tuners: vector~Tuner~
  + inputTuner(): void
  + deleteTuner(): void
  + findTunerByCode(code): Tuner
}
class Tuner {
  - code: string
  - model: string
  - brand: string
  - price: int
  - stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
TunerManager --> Tuner
TunerManager --> ProductManager

%% Client
class ClientManager {
  - clientList: map~int, Client~
  + inputClient(): void
  + inputClient(Client): void
  + deleteClient(): void
  + findClientById(id): Client
}
class Client {
  - id: int
  - name: string
  - phone: string
  - address: string
  + getId(): int
  + getName(): string
  + getPhoneNumber(): string
  + getAddress(): string
}
ClientManager --> Client

%% Order
class Order {
  - orderId: int
  - clientId: int
  - clientName: string
  - productCode: string
  - quantity: int
  - date: string
  - status: string
  + isRefunded(): bool
  + isPurchased(): bool
  + updateDate(): void
}
class OrderManager {
  - orderList: vector~Order~
  - orderCounter: int
  + createOrder(): void
  + createOrder(Client, Product): void
  + refundOrder(): void
  + listOrders(): void
  + checkStock(): bool
}
OrderManager --> Order
Order --> Client
Order ..> ProductManager : references

%% GenreStarterSet
class GenreStarterSet {
  +genre: string
  +guitarType: string
  +effectTypes: vector~string~
  +starterSetId: string
  +saveToFile(): void
  +loadFromFile(): void
  +searchByGenre(genre): GenreStarterSet
  +searchByGuitarType(type): GenreStarterSet
}
Order --> GenreStarterSet : includes
 *
 * /

/*
 *
 *
cmake_minimum_required(VERSION 3.16)
project(miniProj01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include headers
include_directories(${PROJECT_SOURCE_DIR}/header)

# collect source files
file(GLOB_RECURSE SOURCES "source/*.cpp")

# create executable
add_executable(mP01 main.cpp ${SOURCES})
 *
 *
 *
 *
 *
 *
 *
 *
*/

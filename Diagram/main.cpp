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
  - guitars: vector~Guitar~ [ordered]
  - effects: vector~Effect~ [ordered]
  - accessories: vector~Accessory~ [ordered]
  - amps: vector~Amp~ [ordered]
  - powerSupplies: vector~PowerSupply~ [ordered]
  - cables: vector~Cable~ [ordered]
  - tuners: vector~Tuner~ [ordered]
  + inputGuitar(): void
  + inputGuitar(GuitarModel): void
  + deleteGuitar(): void
  + findGuitarByCode(code): GuitarModel
  + inputEffect(): void
  + inputEffect(EffectModel): void
  + deleteEffect(): void
  + findEffectByCode(code): EffectModel
  + inputAccessory(): void
  + inputAccessory(Accessory): void
  + deleteAccessory(): void
  + findAccessoryByPurpose(purpose): Accessory
  + inputAmp(): void
  + inputAmp(Amp): void
  + deleteAmp(): void
  + findAmpByCode(code): Amp
  + inputPowerSupply(): void
  + inputPowerSupply(PowerSupply): void
  + deletePowerSupply(): void
  + findPowerSupplyByCode(code): PowerSupply
  + inputCable(): void
  + inputCable(Cable): void
  + deleteCable(): void
  + findCableByCode(code): Cable
  + inputTuner(): void
  + inputTuner(Tuner): void
  + deleteTuner(): void
  + findTunerByCode(code): Tuner
  + saveToFile(filename): void
  + loadFromFile(filename): void
  + applyDiscountToProduct(code, percent): void
  + formatStockWithComma(): void
}

class Guitar {
  +type: string
  +models: vector~GuitarModel~ [ordered]
}
class GuitarModel {
  +code: string
  +model: string
  +brand: string
  +price: int
  +stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
Guitar *--> GuitarModel : contains

class Effect {
  +effectType: string
  +models: vector~EffectModel~ [ordered]
}
class EffectModel {
  +code: string
  +model: string
  +brand: string
  +price: int
  +stock: int
  +getCode(): string
  +getModel(): string
  +getBrand(): string
  +getPrice(): int
  +getStock(): int
}
Effect *--> EffectModel : contains

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

ProductManager o--> Guitar : manages
ProductManager o--> Effect : manages
ProductManager o--> Accessory : manages
ProductManager o--> Amp : manages
ProductManager o--> PowerSupply : manages
ProductManager o--> Cable : manages
ProductManager o--> Tuner : manages

%% ClientManager & OrderManager
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
  - orderList: vector~Order~ [ordered]
  - orderCounter: int
  + createOrder(): void
  + createOrder(Client, Product): void
  + refundOrder(): void
  + listOrders(): void
  + checkStock(): bool
}

ClientManager --> Client : manages
OrderManager --> Order : manages
Order --> Client : references
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

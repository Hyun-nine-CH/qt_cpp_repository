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

%% ProductManager와 관련된 구성
class ProductManager {
  - guitars: vector~Guitar~
  - effects: vector~Effect~
  - accessories: vector~Accessory~
  - amps: vector~Amp~
  - powerSupplies: vector~PowerSupply~
  - cables: vector~Cable~
  - tuners: vector~Tuner~
  + inputGuitar(): void
  + deleteGuitar(): void
  + findGuitarByCode(code): GuitarModel
  + inputEffect(): void
  + deleteEffect(): void
  + findEffectByCode(code): EffectModel
  + inputAccessory(): void
  + deleteAccessory(): void
  + findAccessoryByPurpose(purpose): Accessory
  + inputStarterSet(): void
  + findStarterSetByGuitarType(type): GenreStarterSet
  + inputAmp(): void
  + deleteAmp(): void
  + findAmpByCode(code): Amp
  + saveAmpListToFile(): void
  + loadAmpListFromFile(): void
  + inputPowerSupply(): void
  + deletePowerSupply(): void
  + findPowerSupplyByCode(code): PowerSupply
  + savePowerSupplyListToFile(): void
  + loadPowerSupplyListFromFile(): void
  + inputCable(): void
  + deleteCable(): void
  + findCableByCode(code): Cable
  + saveCableListToFile(): void
  + loadCableListFromFile(): void
  + inputTuner(): void
  + deleteTuner(): void
  + findTunerByCode(code): Tuner
  + saveTunerListToFile(): void
  + loadTunerListFromFile(): void
  + saveGuitarListToFile(): void
  + loadGuitarListFromFile(): void
  + saveEffectListToFile(): void
  + loadEffectListFromFile(): void
  + applyDiscountToProduct(code, percentage): void
  + formatStockWithComma(): void
}

class Guitar {
  +type: string
  +models: vector~GuitarModel~
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
Guitar --> GuitarModel : contains

class Effect {
  +effectType: string
  +models: vector~EffectModel~
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
Effect --> EffectModel : contains

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

ProductManager --> Guitar : manages
ProductManager --> Effect : manages
ProductManager --> Accessory : manages
ProductManager --> Amp : manages
ProductManager --> PowerSupply : manages
ProductManager --> Cable : manages
ProductManager --> Tuner : manages

%% OrderManager 및 ClientManager 통합
class OrderManager {
  - orderList: vector~Order~
  - orderCounter: int
  + createOrder(): void
  + refundOrder(): void
  + listOrders(): void
  + checkStock(): bool
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

class ClientManager {
  - clientList: map~int, Client~
  + inputClient(): void
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

OrderManager --> Order : manages
ClientManager --> Client : manages
Order --> Client : references
Order --> ProductManager : references

%% 장르 기반 스타터 패키지 옵션을 Order와 연결
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

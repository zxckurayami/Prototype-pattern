// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>
#include <string>
#include <unordered_map>

// Абстрактний клас прототипу
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void showInfo() const = 0;
    virtual ~Prototype() {}
};

// Конкретний клас прототипу
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(const std::string& name, int value) : name_(name), value_(value) {}

    // Реалізація методу клонування
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void showInfo() const override {
        std::cout << "Name: " << name_ << ", Value: " << value_ << std::endl;
    }

private:
    std::string name_;
    int value_;
};

// Клас, який управляє прототипами
class PrototypeManager {
public:
    PrototypeManager() {
        // Ініціалізація деяких початкових прототипів
        prototypes_["Prototype1"] = new ConcretePrototype("Prototype1", 1);
        prototypes_["Prototype2"] = new ConcretePrototype("Prototype2", 2);
        prototypes_["Prototype3"] = new ConcretePrototype("Prototype3", 3);
    }

    // Метод для отримання клонованого прототипу за його іменем
    Prototype* getPrototype(const std::string& name) const {
        auto it = prototypes_.find(name);
        if (it != prototypes_.end()) {
            return it->second->clone();
        }
        return nullptr;
    }

    ~PrototypeManager() {
        // Вивільнення пам'яті від прототипів
        for (auto& entry : prototypes_) {
            delete entry.second;
        }
    }

private:
    std::unordered_map<std::string, Prototype*> prototypes_;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    PrototypeManager manager;

    // Використання прототипів
    Prototype* clone1 = manager.getPrototype("Prototype1");
    if (clone1) {
        clone1->showInfo();
        delete clone1;
    }

    Prototype* clone2 = manager.getPrototype("Prototype2");
    if (clone2) {
        clone2->showInfo();
        delete clone2;
    }

    Prototype* clone3 = manager.getPrototype("Prototype3");
    if (clone3) {
        clone3->showInfo();
        delete clone3;
    }

    return 0;
}

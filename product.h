using namespace std;

#include <string>

namespace MySpace { // создаём пространство имён, для безошибочного обращения к функции
    void Test();
}

class Product {
private:
    string name; // Название продукта
    double mass; // Масса продукта
    double temperature; // Текущая температура продукта
    const double maxTemperature; // Максимальная температура продукта
    const double minTemperature; // Минимальная температура продукта
    enum State { FROZEN, OVERHEATED, NORMAL }; // Перечисление для состояния продукта
    State state; // Текущее состояние продукта
    double heatCapacity; // Теплоемкость продукта

public:

    Product(const string& name, double mass, double temperature, double maxTemperature, double minTemperature, double heatCapacity); // Конструктор класса
    string getName() const; // Метод для получения названия продукта
    double getMass() const; // Метод для получения массы продукта
    double getTemperature() const; // Метод для получения текущей температуры продукта
    double getMaxTemperature() const; // Метод для получения максимальной температуры продукта
    double getMinTemperature() const; // Метод для получения минимальной температуры продукта
    string getState() const; // Метод для получения состояния продукта (замерзший, перегретый или нормальный)
    double getHeatCapacity() const; // Метод для получения теплоемкости продукта
    void transferHeat(double heat); // Метод для передачи тепла продукту
    double getFinalTemperatureAfterHeatTransfer(double heat) const; // Метод для вычисления конечной температуры после передачи тепла
};


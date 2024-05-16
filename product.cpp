#include <iostream>
#include "product.h"
using namespace std;


// Реализация конструктора класса Product
Product::Product(const string& name, double mass, double temperature, double maxTemperature, double minTemperature, double heatCapacity)
    : name(name), mass(mass), temperature(temperature), maxTemperature(maxTemperature), minTemperature(minTemperature), heatCapacity(heatCapacity) {
    state = NORMAL; // Устанавливаем начальное состояние продукта как "нормальное"
}

// Методы доступа к приватным полям класса
string Product::getName() const {
    return name;
}

double Product::getMass() const {
    return mass;
}

double Product::getTemperature() const {
    return temperature;
}

double Product::getMaxTemperature() const {
    return maxTemperature;
}

double Product::getMinTemperature() const {
    return minTemperature;
}

// Метод для получения текущего состояния продукта
string Product::getState() const {
    setlocale(LC_ALL, "Russian");
    if (state == FROZEN) {
        return "Frozen";
    }
    else if (state == OVERHEATED) {
        return "Overheated";
    }
    else {
        return "Normal";
    }
}

double Product::getHeatCapacity() const {
    return heatCapacity;
}

// Метод для передачи тепла продукту
void Product::transferHeat(double heat) {
    temperature += heat / (heatCapacity * mass); // Изменяем температуру продукта в зависимости от переданного тепла

    if (temperature > maxTemperature) { // Проверка на перегрев
        state = OVERHEATED;
        temperature = maxTemperature;
    }
    else if (temperature < minTemperature) { // Проверка на замерзание
        state = FROZEN;
        temperature = minTemperature;
    }
}

// То же самое прописано в transferHeat
// Метод для вычисления конечной температуры после передачи тепла
double Product::getFinalTemperatureAfterHeatTransfer(double heat) const {
    double finalTemp = temperature + heat / (heatCapacity * mass); // Вычисляем конечную температуру

    if (finalTemp > maxTemperature) { // Проверка на перегрев
        return maxTemperature;
    }
    else if (finalTemp < minTemperature) { // Проверка на замерзание
        return minTemperature;
    }
    else {
        return finalTemp;
    }
}

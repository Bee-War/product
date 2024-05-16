#include <iostream>
#include "product.h"

using namespace std;

namespace MySpace {

	void Test() {
		setlocale(LC_ALL, "Russian");

		Product milk("Milk", 1.0, 10.0, 20.0, 1.0, 3900.0); // имя; масса; температура; макс.темп; мин.темп; теплоёмкость; // состояние по стандарту : нормальное
		Product water("water", 5.0, 5.0, 30.0, 1.0, 4200.0); // имя; масса; температура; макс.темп; мин.темп; теплоёмкость; // состояние по стандарту : нормальное
		Product bread("bread", 0.5, 20.0, 35.0, 5.0, 3100.0); // имя; масса; температура; макс.темп; мин.темп; теплоёмкость; // состояние по стандарту : нормальное

		cout << "имя: " << milk.getName() << "; масса :" << milk.getMass() << "; температура :" << milk.getTemperature() << "; макс.темп :" << milk.getMaxTemperature() << "; мин.темп :" << milk.getMinTemperature() << "; теплоёмкость :" << milk.getHeatCapacity() << "; состояние : " << milk.getState() << endl;
		cout << "имя: " << water.getName() << "; масса : " << water.getMass() << "; температура :" << water.getTemperature() << "; макс.темп :" << water.getMaxTemperature() << "; мин.темп :" << water.getMinTemperature() << "; теплоёмкость :" << water.getHeatCapacity() << "; состояние : " << water.getState() << endl;
		cout << "имя: " << bread.getName() << "; масса : " << bread.getMass() << "; температура :" << bread.getTemperature() << "; макс.темп :" << bread.getMaxTemperature() << "; мин.темп :" << bread.getMinTemperature() << "; теплоёмкость :" << bread.getHeatCapacity() << "; состояние : " << bread.getState() << endl << endl;

		cout << "Добавим температуру продуктам каждому отдельно, на случайные величины" << endl;
		double buf;
		buf = (rand() % 20001) + 30000;
		milk.transferHeat(buf);
		cout << milk.getName() << " получило: " << buf << " Тепла" << endl;

		buf = rand() % 30001;
		water.transferHeat(buf);
		cout << water.getName() << " получило: " << buf << " Тепла" << endl;

		buf = (rand() % 30001) - 30000;
		bread.transferHeat(buf);
		cout << bread.getName() << " получило: " << buf << " Тепла" << endl;

		cout << "Проверим состояния и температуры продуктов" << endl << endl;
		
		cout << "имя: " << milk.getName() << "; температура :" << milk.getTemperature() << "; состояние : " << milk.getState() << endl;
		cout << "имя: " << water.getName() << "; температура :" << water.getTemperature() << "; состояние : " << water.getState() << endl;
		cout << "имя: " << bread.getName() << "; температура :" << bread.getTemperature() << "; состояние : " << bread.getState() << endl;

		system("pause"); // удержание консоли для удобства чтения

	}
}

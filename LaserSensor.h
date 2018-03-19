#pragma once
#include "RangeSensor.h"
/**
 * @brief Lazer sensorlerinin kullanimi icin LaserSensor sinifi.
 * RangeSensor sinifindan turetilmistir.
 */
class LaserSensor : public RangeSensor {
private:
    float min,max;
public:
    /**
    * @brief Sensor bilgisini yenileyen fonksiyon.
    * Lazer sensoru icin minimum ve maximum degerleri guncellenir.
    * @param ranges - yeni degerleri iceren dizi
    */
    void updateSensor(float ranges[]);
    /**
     * @brief Maximum lazer yolu icin getter fonksiyonu.
     * 
     * @return float - Kayitli en uzun lazer yolu.
     */
    float getMax();
    /**
     * @brief Minimum lazer yolu icin getter fonksiyonu.
     * 
     * @return float - Kayitli en kisa lazer yolu.
     */
    float getMin();
    /**
     * @brief Dizi tanimli getter fonksiyonu.
     * 
     * @param index - Istenen mesafe indexi.
     * @return float - Istenen indexe ait mesafe degeri.
     */
    float getRange(int index);
    /**
     * @brief Dizi operatoru overloadi.
     * getRange fonksiyonunu kullanarak istenen index degerindeki mesafeyi gonderir.
     * @param i - Istenen mesafe indexi.
     * @return float - Istenen indexe ait mesafe degeri.
     */
    float operator[](int i);
};
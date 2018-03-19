#pragma once
#include "RangeSensor.h"
/**
 * @brief Sonar sensorlerinin kullanimini saglayan sinif.
 * RangeSensor sinifindan turetilmistir.
 */
class SonarSensor : public RangeSensor {
private:
    float ranges[16];
public:
    /**
    * @brief Sensor bilgisini yenileyen fonksiyon.
    * Sonar sensorler icin 16 kafa degeri.
    * @param ranges - yeni degerleri iceren dizi
    */
    void updateSensor(float ranges[]);
    /**
     * @brief Maximum sonar mesafesi icin getter fonksiyonu.
     * 
     * @return float - Kayitli en uzun sonar mesafesi.
     */
    float getMax();
    /**
     * @brief Minimum sonar mesafesi icin getter fonksiyonu.
     * 
     * @return float - Kayitli en kisa sonar mesafesi.
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

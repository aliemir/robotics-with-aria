#pragma once
#include <iostream>
using namespace std;

/**
 * @brief Sensorler icin template sinif.
 */
class RangeSensor {
private:
    string type;
public:
    /**
     * @brief Sensor bilgilerinin guncellenmesi icin gereken fonksiyon.
     * @param ranges - Yeni sensor bilgilerini iceren dizi.
     */
    virtual void updateSensor(float ranges[]) = 0;
    /**
     * @brief Okunan en kisa sensor mesafesi icin getter fonksiyonu.
     * @return float - Okunan en kisa sensor mesafesi
     */
    virtual float getMin() = 0;
    /**
     * @brief Okunan en uzun sensor mesafesi icin getter fonksiyonu.
     * @return float - Okunan en uzun sensor mesafesi
     */
    virtual float getMax() = 0;
    /**
     * @brief Dizi tanimli getter fonksiyonu.
     * @param index - Mesafesi istenen index degeri.
     * @return float - Indexte tanimli mesafe degeri.
     */
    virtual float getRange(int index) = 0;
    /**
     * @brief Dizi operatoru overloadi.
     * @param i - Istenen index degeri.
     * @return float - Indexte tanimli mesafe degeri.
     */
    virtual float operator[](int i) = 0;
    /**
     * @brief Sensor tipini gosteren type uyesi icin getter fonksiyonu.
     * @return string - Sensor tipi.
     */
    const string &getType() const;
    /**
     * @brief Sensor tipi icin setter fonksiyonu.
     * @param type - Atanmak istenen tip.
     */
    void setType(const string &type);
};
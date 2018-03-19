#pragma once
#include "RangeSensor.h"
#include "Position.h"
#include "Direction.h"
/**
 * @brief Arayuz olusturmak icin template sinif.
 */
class RobotInterface {
protected:
    Position * position;
    RangeSensor * sonarSensor;
    RangeSensor * laserSensor;
public:
    /**
     * @brief Arayuzun kullanacagi pozisyon objesi icin setter fonksiyonu.
     * Siniflar arasi baglanti icin, RobotControl'e ait pozisyon degeri atanmalidir.
     * @param position - Atanacak pozisyon objesi.
     */
    void setPosition(Position *position);
    /**
     * @brief Arayuzun kullanacagi sensorler icin setter fonksiyonu.
     * Siniflar arasi baglanti icin, RobotControl'e ait sensorler kullanilmalidir.
     * @param sonar - Sonar sensor objesi.
     * @param laser  - Lazer sensor objesi.
     */
    void setRangeSensor(RangeSensor *sonar,RangeSensor *laser);
    /**
     * @brief Bilgileri guncellemek icin update fonksiyonu.
     */
    virtual void update() = 0;
    /**
     * @brief Robotla baglantiyi kuran fonksiyon.
     * 
     * @return true Basariliysa
     * @return false Basarisizsa
     */
    virtual bool open() = 0;
    /**
     * @brief Robotla baglantiyi koparan fonksiyon.
     * 
     * @return true Basariliysa
     * @return false Basarisizsa
     */
    virtual bool close() = 0;
    /**
     * @brief Robotu verilen hizda harekete baslatan fonksiyon.
     * @param speed Milimetre / Saniye cinsinden hiz degeri.
     */
    virtual void move(float speed) = 0;
    /**
     * @brief Robotu istenen yonde donme hareketine baslatan fonksiyon.
     * @param dir - DIRECTION enumeratoruyle yon tayini.
     */
    virtual void turn(DIRECTION dir) = 0;
    /**
     * @brief Robotun varsa hareketini durduran fonksiyon.
     */
    virtual void stop() = 0;
};
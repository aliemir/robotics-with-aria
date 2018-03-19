#pragma once
#include "RangeSensor.h"
#include "LaserSensor.h"
#include "SonarSensor.h"
#include "Position.h"
#include "RobotInterface.h"
#include "Direction.h"
#include "vector"
#include <chrono>
#include <thread>
/**
 * @brief Robot - Kullanici arasi baglanti kontrolleri.
 */
class RobotControl {
private:
    vector<RangeSensor*> sensor;
    Position * position;
    RobotInterface * robot;
    /**
     * @brief Carpismayi engellemek icin sensorleri kontrol eden fonksiyon.
     * @return true - Sensorlerde tehlike durumu yoksa
     * @return false - Sensorlerde tehlike durumu oldugunda
     */
    bool collisionSafe();
public:
    /**
    * @brief Kontrol kumandasi icin constructor fonksiyonu.
    * Robot arayuzu constructor icinde tanimlanir. Arayuzle paylasilacak pozisyon ve sensor degerleri burada ayarlanir. 
    * @param robot - Robota bagli arayuz.
    */
    RobotControl(RobotInterface *robot);
    /**
     * @brief Hareket fonksiyonu, girilen hiz degerine gore harekete baslatir.
     * @param speed - Milimetre / Saniye cinsinden hiz degeri.
     */
    void safeMove(int speed);
    /**
     * @brief Robotun varsa hareketini durduran fonksiyon.
     * 
     */
	void stop();
    /**
     * @brief Server baglantisini baslatan fonksiyon.
     */
    void connect();
    /**
     * @brief Server baglantisini kesen fonksiyon.
     */
    void disconnect();
    /**
     * @brief Robotu sola dogru dondurmeye baslayan fonksiyon.
     */
    void turnLeft();
    /**
     * @brief Robotu saga dogru dondurmeye baslayan fonksiyon.
     */
    void turnRight();
    /**
     * @brief 
     */
    void forward();
    /**
     * @brief Robota ait sensor ve pozisyon bilgisini ekrana yazdiran fonksiyon.
     */
    void print();
    /**
     * @brief Girilen mesafe degeri kadar robotu hareket ettiren fonksiyon.
     * @param distance - Ilerlemek istenen mesafe degeri.
     */
    void moveDistance(float distance);
    /**
     * @brief Robot, bir duvarla karsilasana kadar ilerler, karsilasinca durur.
     */
    void closeWall();
};

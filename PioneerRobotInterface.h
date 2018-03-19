#pragma once
#include "PioneerRobotAPI.h"
#include "RobotInterface.h"

/**
 * @brief Pioneer Robotla iletisime gecmek icin arayuz
 * 
 */
class PioneerRobotInterface : public PioneerRobotAPI, public RobotInterface {
public:
    /**
     * @brief Constructor icinde, API ile iletisim kurar.
     * Bu objeyirobottan sorumlu interface olarak ayarlar.
     */
    PioneerRobotInterface();
    /**
     * @brief Bilgileri guncellemek icin update fonksiyonu.
     */
    void update();
    /**
     * @brief Robotla baglantiyi kuran fonksiyon.
     * 
     * @return true Basariliysa
     * @return false Basarisizsa
     */
    bool open();
    /**
     * @brief Robotu verilen hizda harekete baslatan fonksiyon.
     * @param speed Milimetre / Saniye cinsinden hiz degeri.
     */
    void move(float speed);
    /**
     * @brief Robotla baglantiyi koparan fonksiyon.
     * 
     * @return true Basariliysa
     * @return false Basarisizsa
     */
    bool close();
    /**
     * @brief Robotu istenen yonde donme hareketine baslatan fonksiyon.
     * @param dir - DIRECTION enumeratoruyle yon tayini.
     */
    void turn(DIRECTION dir);
    /**
     * @brief Robotun varsa hareketini durduran fonksiyon.
     */
    void stop();
    /**
     * @brief PioneerRobotAPI sinifindan devsirilen update fonksiyonu.
     * API tarafindan her saniye cagirilir. Override yaparak pozisyon ve sensor bilgileri esitlenir.
     */
    void updateRobot();
    /**
     * @brief Robot icin carpisma kontrolu, tehlikeli mesafelere karsi carpmayi onler.
     * 
     * @return true - Tehlikeli yakinlikla bir cisim yoksa 
     * @return false - Tehlikeli yakinlikta bir cisim sensorler tarafindan algilandiysa
     */
    bool CollisionSafe();
};

#pragma once

/**
 * @brief Pozisyon bilgilerini tutan sinif
 * 
 */
class Position {
private:
    float x,y,th;
public:
    /**
     * @brief X pozisyonu icin getter fonksiyonu.
     * 
     * @return float - Tanimli koordinat.
     */
    float getX() const;
    /**
     * @brief X pozisyonu icin setter fonksiyonu.
     * 
     * @param x - Atanacak koordinat.
     */
    void setX(float x);
    /**
     * @brief Y pozisyonu icin getter fonksiyonu.
     * 
     * @return float - Tanimli koordinat.
     */
    float getY() const;
    /**
     * @brief Y pozisyonu icin setter fonksiyonu.
     * 
     * @param Y - Atanacak koordinat.
     */
    void setY(float y);
    /**
     * @brief Sahip olunan aci degeri icin getter fonksiyonu.
     * 
     * @return float getTh - Derece cinsinden aci.
     */
    float getTh() const;
    /**
     * @brief Pozisyonun aci degeri icin setter fonksiyonu.
     * 
     * @param th - Atanacak derece.
     */
    void setTh(float th);
    /**
     * @brief Pozisyonlar arasi karsilastirma icin operator overloadi.
     * @param rhs - Karsilastirilacak pozisyon degeri
     * @return true - Tum degerlerin esit olmasi durumunda dondurulur.
     * @return false - Tum degerler esit degilse dondurulur.
     */
    bool operator==(const Position &rhs) const;
};
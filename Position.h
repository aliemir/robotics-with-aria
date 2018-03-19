#pragma once

class Position {
private:
    float x,y,th;
public:
    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getTh() const;

    void setTh(float th);

    bool operator==(const Position &rhs) const;
};
#include "Position.h"

bool Position::operator==(const Position &rhs) const { return x == rhs.x && y == rhs.y && th == rhs.th; }

float Position::getX() const { return x; }

void Position::setX(float x) { Position::x = x; }

float Position::getY() const { return y; }

void Position::setY(float y) { Position::y = y; }

float Position::getTh() const { return th; }

void Position::setTh(float th) { Position::th = th; }

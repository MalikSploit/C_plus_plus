//
// Created by root on 12/7/23.
//

#ifndef C_POINT_HPP
#define C_POINT_HPP


class Point {
private:
    int x, y;
public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    static const Point ORIGINE;
};


#endif //C_POINT_HPP

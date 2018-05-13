#ifndef VECTOR2_H
#define VECTOR2_H
#include<iostream>

class Vector2
{
public:

    float x;
    float y;

    Vector2();
    Vector2(float newX, float newY );
    float distance ();
    float dotProduct(const Vector2 &v1, const Vector2 &v2);
    float crossProduct(const Vector2 &v1, const Vector2 &v2);
    void normalise(float &dist);
    ~Vector2();
    void setPos (float new_X, float new_Y)
    {
        x = new_X;
        y= new_Y;
    };

    Vector2& operator +=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;

        return *this;
    }

    Vector2& operator -=(const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;

        return *this;
    }
    Vector2& operator *=(const Vector2& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;

        return *this;
    }

    Vector2& operator /=(const Vector2& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    bool operator ==(const Vector2& rhs)
    {
        if(x == rhs.x && y == rhs.y)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    bool operator !=(const Vector2& rhs)
    {
        if(x != rhs.x && y != rhs.y)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

protected:

private:
};

inline std::ostream & operator <<(std::ostream& os, const Vector2&v)
{
    os << "["<<v.x<<","<<v.y<<"]";
    return os;
}

inline Vector2 operator + (Vector2 lhs, const Vector2 & rhs)
{
    lhs += rhs;
    return lhs;
}
inline Vector2  operator - (Vector2 lhs, const Vector2 & rhs)
{
    lhs -= rhs;
    return lhs;
}

inline Vector2  operator / (Vector2 lhs, const Vector2 & rhs)
{
    lhs /= rhs;
    return lhs;
}

inline Vector2  operator * (Vector2 lhs, const Vector2 & rhs)
{
    lhs *= rhs;
    return lhs;
}
inline Vector2 operator * (Vector2 lhs, float rhs)
{


    return Vector2(lhs.x*rhs, lhs.y * rhs);
}

#endif // VECTOR2_H

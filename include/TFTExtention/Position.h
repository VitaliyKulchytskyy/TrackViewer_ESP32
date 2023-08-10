#pragma once

class Position {
public:
    /**
     * Set the position of the object
     * @param x X-pos
     * @param y Y-pos
     * @return Ref to this Position (obj)
     */
    Position& setPosition(int x, int y);

    /**
     * Get the X-pos
     * @return X-pos
     */
    int getX() const;

    /**
     * Get the Y-pos
     * @return Y-pos
     */
    int getY() const;

protected:
    int m_x{};
    int m_y{};
};
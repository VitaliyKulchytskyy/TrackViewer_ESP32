#pragma once

class Size {
public:
    Size& setSize(int width, int height);

    int getWidth() const;

    int getHeight() const;

protected:
    int m_width{};
    int m_height{};
};
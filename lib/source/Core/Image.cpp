#include "Core/Image.h"

void Image::saveAsPPM(std::ostream& output) const
{
    output << "P3\n" << m_width << " " << m_height << "\n25\n";
    for (size_t i = 0; i < m_height; i++)
        for (size_t j = 0; j < m_width; j++)
        {
            auto color = (*this)(i, j);
            int ir = int(255.99 * sqrt(color.r()));
            int ig = int(255.99 * sqrt(color.g()));
            int ib = int(255.99 * sqrt(color.b()));

            output << ir << " " << ig << " " << ib << "\n";
        }
}
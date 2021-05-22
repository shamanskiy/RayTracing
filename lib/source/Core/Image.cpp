#include "Core/Image.h"

#include <fstream>

namespace
{
    int colorFloatToInt(float x) { return int(255.99 * x); }
    float gammaCorrection(float x) { return sqrt(x); }
}

void Image::save(const std::string& fileName) const
{
    std::ofstream file(fileName);
    saveAsPPM(file);
    file.close();
}

void Image::saveAsPPM(std::ostream& output) const
{
    output << "P3\n" << m_width << " " << m_height << "\n255\n";
    for (size_t i = 0; i < m_height; i++)
        for (size_t j = 0; j < m_width; j++)
        {
            auto color = (*this)(i, j);
            int red = colorFloatToInt(gammaCorrection(color.r()));
            int green = colorFloatToInt(gammaCorrection(color.g()));
            int blue = colorFloatToInt(gammaCorrection(color.b()));

            output << red << " " << green << " " << blue << "\n";
        }
}
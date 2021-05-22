#pragma once

#include <vector>
#include <ostream>

#include "Core/SmallBaseClasses.h"

class Image
{
	size_t m_height;
	size_t m_width;
	std::vector<Vec3> m_pixels;

public:
	Image(size_t height, size_t width) :  m_height(height), m_width(width)
	{
		m_pixels.resize(m_height * m_width);
	}

	size_t height() const { return m_height; }
	size_t width() const { return m_width; }

	const Vec3& operator()(size_t row, size_t col) const
	{
		return m_pixels.at(row * m_width + col);
	}

	Vec3& operator()(size_t row, size_t col)
	{
		return m_pixels.at(row * m_width + col);
	}

	void saveAsPPM(std::ostream& output) const;
	void save(const std::string& fileName) const;
};
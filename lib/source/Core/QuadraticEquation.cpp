#include "Core/QuadraticEquation.h"

#include <math.h>

QuadraticEquation::QuadraticEquation(float a, float b, float c) :
	m_a(a), m_b(b), m_c(c),
	m_discriminant(0.0),
	m_sqrtDiscriminant(0.0),
	m_leftSolution(0.0),
	m_rightSolution(0.0) 
{
	solve();
}

int QuadraticEquation::numberOfSolutions() const 
{
	if (m_discriminant > 0.0)
		return 2;
	else if (m_discriminant < 0.0)
		return 0;
	else return 1;
}

void QuadraticEquation::solve()
{
	m_discriminant = m_b * m_b - 4 * m_a * m_c;
	
	if (m_discriminant < 0)
		return;

	m_sqrtDiscriminant = sqrt(m_discriminant);
}

float QuadraticEquation::leftSolution() const
{
	return (-m_b - m_sqrtDiscriminant) / (2.0 * m_a);
}

float QuadraticEquation::rightSolution() const
{
	return (-m_b + m_sqrtDiscriminant) / (2.0 * m_a);
}
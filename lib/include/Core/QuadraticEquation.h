#pragma once

class QuadraticEquation {
	float m_a, m_b, m_c;
	float m_discriminant;
	float m_sqrtDiscriminant;
	float m_leftSolution;
	float m_rightSolution;

public:
	QuadraticEquation(float a, float b, float c);

	int numberOfSolutions() const;
	float leftSolution() const;
	float rightSolution() const;

private:
	void solve();
};
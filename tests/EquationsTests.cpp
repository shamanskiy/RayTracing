#include "catch_utils.hpp"

#include "Equations.h"

TEST_CASE("Quadratic equation: two solutions", "[QuadraticEquation]")
{
    QuadraticEquation equation(1.0, -6.0, 5.0);
    
    REQUIRE(equation.numberOfSolutions() == 2);
    REQUIRE(equation.leftSolution() == 1.0_a);
    REQUIRE(equation.rightSolution() == 5.0_a);
}

TEST_CASE("Quadratic equation: no solutions", "[QuadraticEquation]")
{
    QuadraticEquation equation(1.0, 0.0, 1.0);
    
    REQUIRE(equation.numberOfSolutions() == 0);
    REQUIRE(equation.leftSolution() == 0.0_a);
    REQUIRE(equation.rightSolution() == 0.0_a);
}

TEST_CASE("Quadratic equation: one solution", "[QuadraticEquation]")
{
    QuadraticEquation equation(1.0, -2.0, 1.0);

    REQUIRE(equation.numberOfSolutions() == 1);
    REQUIRE(equation.leftSolution() == 1.0_a);
    REQUIRE(equation.rightSolution() == 1.0_a);
}
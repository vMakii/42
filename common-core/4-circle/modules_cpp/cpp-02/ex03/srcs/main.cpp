/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:21 by mivogel           #+#    #+#             */
/*   Updated: 2025/10/17 13:28:07 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//https://hackmd.io/@ChloeIsCoding/r19Mge-fll
//https://planetcalc.com/8108/

bool bsp(const Point a, const Point b, const Point c, const Point point);

void testBSP(const Point& a, const Point& b, const Point& c, const Point& point, const std::string& description)
{
    bool result = bsp(a, b, c, point);
    std::cout << "Test: " << description << std::endl;
    std::cout << "Triangle: A(" << a.getX() << ", " << a.getY() << "), "
              << "B(" << b.getX() << ", " << b.getY() << "), "
              << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << "Point: (" << point.getX() << ", " << point.getY() << ")" << std::endl;
    std::cout << "Result: " << (result ? "INSIDE" : "OUTSIDE/EDGE") << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

int main(void)
{
    std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl << std::endl;

    // Triangle de référence
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test 1: Point clairement à l'intérieur
    Point inside(5.0f, 3.0f);
    testBSP(a, b, c, inside, "Point clearly inside");

    // Test 2: Point clairement à l'extérieur
    Point outside(15.0f, 5.0f);
    testBSP(a, b, c, outside, "Point clearly outside");

    // Test 3: Point sur un sommet
    Point vertex(0.0f, 0.0f);
    testBSP(a, b, c, vertex, "Point on vertex A");

    // Test 4: Point sur une arête
    Point edge(5.0f, 0.0f);
    testBSP(a, b, c, edge, "Point on edge AB");

    // Test 5: Point sur une arête (milieu)
    Point edgeMiddle(2.5f, 5.0f);
    testBSP(a, b, c, edgeMiddle, "Point on edge AC");

    // Test 6: Point très proche du centre
    Point center(5.0f, 3.33f);
    testBSP(a, b, c, center, "Point near triangle center");

    // Test 7: Avec un triangle différent
    std::cout << "\n=== Tests with different triangle ===" << std::endl;
    Point a2(-2.0f, -2.0f);
    Point b2(4.0f, -2.0f);
    Point c2(1.0f, 4.0f);

    Point test1(1.0f, 0.0f);
    testBSP(a2, b2, c2, test1, "Point inside triangle 2");

    Point test2(0.0f, 0.0f);
    testBSP(a2, b2, c2, test2, "Origin point with triangle 2");

    // Test 8: Triangle dégénéré (tous les points alignés)
    std::cout << "\n=== Edge case: Degenerate triangle ===" << std::endl;
    Point d1(0.0f, 0.0f);
    Point d2(5.0f, 0.0f);
    Point d3(10.0f, 0.0f);
    Point testPoint(5.0f, 1.0f);
    testBSP(d1, d2, d3, testPoint, "Degenerate triangle (collinear points)");

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 02:57:36 by sbansacc          #+#    #+#             */
/*   Updated: 2025/11/25 17:50:07 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void printResult(std::string testName, bool result, bool expected) {
	std::cout << testName << ": " << (result ? "INSIDE" : "OUTSIDE");
	if (result == expected)
		std::cout << " ✓" << std::endl;
	else
		std::cout << " ✗ (expected " << (expected ? "INSIDE" : "OUTSIDE") << ")" << std::endl;
}

int main()
{
	// Triangle de base
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << "=== Triangle: A(0,0), B(10,0), C(0,10) ===" << std::endl << std::endl;

	// Test 1: Point clairement à l'intérieur
	Point inside1(3, 3);
	printResult("Inside (3,3)", bsp(a, b, c, inside1), true);

	Point inside2(2, 2);
	printResult("Inside (2,2)", bsp(a, b, c, inside2), true);

	Point inside3(1, 1);
	printResult("Inside (1,1)", bsp(a, b, c, inside3), true);

	Point inside4(5, 2);
	printResult("Inside (5,2)", bsp(a, b, c, inside4), true);

	std::cout << std::endl;

	// Test 2: Points clairement à l'extérieur
	Point outside1(10, 10);
	printResult("Outside (10,10)", bsp(a, b, c, outside1), false);

	Point outside2(-1, -1);
	printResult("Outside (-1,-1)", bsp(a, b, c, outside2), false);

	Point outside3(11, 0);
	printResult("Outside (11,0)", bsp(a, b, c, outside3), false);

	Point outside4(0, 11);
	printResult("Outside (0,11)", bsp(a, b, c, outside4), false);

	Point outside5(6, 6);
	printResult("Outside (6,6)", bsp(a, b, c, outside5), false);

	std::cout << std::endl;

	// Test 3: Points sur les arêtes (doivent retourner false)
	Point edgeAB(5, 0);
	printResult("Edge AB (5,0)", bsp(a, b, c, edgeAB), false);

	Point edgeBC(5, 5);
	printResult("Edge BC (5,5)", bsp(a, b, c, edgeBC), false);

	Point edgeCA(0, 5);
	printResult("Edge CA (0,5)", bsp(a, b, c, edgeCA), false);

	std::cout << std::endl;

	// Test 4: Points sur les sommets (doivent retourner false)
	Point vertexA(0, 0);
	printResult("Vertex A (0,0)", bsp(a, b, c, vertexA), false);

	Point vertexB(10, 0);
	printResult("Vertex B (10,0)", bsp(a, b, c, vertexB), false);

	Point vertexC(0, 10);
	printResult("Vertex C (0,10)", bsp(a, b, c, vertexC), false);

	std::cout << std::endl;

	// Test 5: Triangle différent
	std::cout << "=== Triangle 2: A(-5,-5), B(5,-5), C(0,5) ===" << std::endl << std::endl;
	Point a2(-5, -5);
	Point b2(5, -5);
	Point c2(0, 5);

	Point inside5(0, 0);
	printResult("Inside (0,0)", bsp(a2, b2, c2, inside5), true);

	Point inside6(2, 0);
	printResult("Inside (2,0)", bsp(a2, b2, c2, inside6), true);

	Point outside6(0, 6);
	printResult("Outside (0,6)", bsp(a2, b2, c2, outside6), false);

	Point outside7(6, 0);
	printResult("Outside (6,0)", bsp(a2, b2, c2, outside7), false);

	std::cout << std::endl;

	// Test 6: Triangle avec valeurs flottantes
	std::cout << "=== Triangle 3: A(0.5,0.5), B(5.5,0.5), C(3,4) ===" << std::endl << std::endl;
	Point a3(0.5f, 0.5f);
	Point b3(5.5f, 0.5f);
	Point c3(3, 4);

	Point inside7(3, 2);
	printResult("Inside (3,2)", bsp(a3, b3, c3, inside7), true);

	Point outside8(0, 0);
	printResult("Outside (0,0)", bsp(a3, b3, c3, outside8), false);

	Point edge2(3, 0.5f);
	printResult("Edge (3,0.5)", bsp(a3, b3, c3, edge2), false);

	return 0;
}
/*
int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point outside(10, 10);
	Point edge(5, 0);

	std::cout << "inside: " << bsp(a, b, c, inside) << std::endl;  // 1
	std::cout << "outside: " << bsp(a, b, c, outside) << std::endl; // 0
	std::cout << "edge: " << bsp(a, b, c, edge) << std::endl; // 0
}
*/
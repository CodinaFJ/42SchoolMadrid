/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:13:28 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/13 19:13:28 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

int main(void)
{
	std::string str1 = "HI THIS IS BRAIN";
	std::string *stringPTR = &str1;
	std::string& stringREF = *stringPTR;

	std::cout << "Memory address string variable: " << &str1 << std::endl;
	std::cout << "Memory address stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address stringREF.: " << &stringREF << std::endl;

	std::cout << "Value string var: " << str1 << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF.: " << stringREF << std::endl;

	return(EXIT_SUCCESS);
}
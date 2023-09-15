/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:27:53 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/14 11:27:53 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int nInputError(int argc)
{
	if (argc != 4)
	{
		std::cout << "WRONG PARAMETER INPUT" << std::endl;
		std::cout << "Please enter three parameters in the following order:" << std::endl;
		std::cout << "1. Filename" << std::endl;
		std::cout << "2. String 1" << std::endl;
		std::cout << "3. String 2" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void Replace(std::string str1, std::string str2)
{
	std::string auxString = str1;
	std::string restString = str1;
	size_t findPos = restString.find(str2);

	while(findPos != std::string::npos)
	{
		auxString = restString.substr(0, findPos);
		restString = restString.substr(findPos + str2.size(), str1.size());
		if (auxString.size() > 0)
			std::cout <<  auxString << std::endl;
		std::cout << "XX" << std::endl;
		findPos = restString.find(str2);
	}
	if (restString.size() > 0)
		std::cout << restString << std::endl;
}

int main(int argc, char** argv)
{
	if (nInputError(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	std::string toFind(argv[2]);
	std::string toReplace(argv[3]);

	Sed sed(argv[1]);
	sed.replace(toFind, toReplace);

	return (EXIT_SUCCESS);
}
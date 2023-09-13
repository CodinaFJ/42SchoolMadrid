/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:28:11 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/12 17:28:11 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	command = "";

	// TODO: Learn about std library in C++
	std::cout << "Thanks for using PhoneBook services." << std::endl;
	while (1)
	{
		std::cout << "Select command: ADD/SEARCH/EXIT" << std::endl;
		std::cin >> command;

		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			phoneBook.AddContact();
		else if(command.compare("SEARCH") == 0 || command.compare("search") == 0)
			phoneBook.Search();
		else if(command.compare("EXIT") == 0 || command.compare("exit") == 0)
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	std::cout << "See you next time." << std::endl;
	return (EXIT_SUCCESS);
}
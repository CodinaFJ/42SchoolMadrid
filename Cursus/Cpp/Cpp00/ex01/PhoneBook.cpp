/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:46:30 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/12 13:46:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		PhoneBook::_displayContactsTable(void)
{
	int i = 0;

	std::cout << std::setfill (' ') << std::setw (11) << "INDEX|";
	std::cout << std::setfill (' ') << std::setw (11) <<"FIRST NAME|";
	std::cout << std::setfill (' ') << std::setw (11) << "LAST NAME|";
	std::cout << std::setfill (' ') << std::setw (10) << "NICKNAME" << std::endl;

	for (; i < 8; i++)
	{
		if (_contacts[i].ShowContact() == -1)
			break;
	}
	return (i);
}

PhoneBook::PhoneBook()
{
	_nextContactIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::AddContact(void)
{
	if (_nextContactIndex == 8)
		_nextContactIndex = 0;
	_contacts[_nextContactIndex].Init(_nextContactIndex);
	_nextContactIndex++;
}

void	PhoneBook::Search(void)
{
	int i, selectIndex;

	i = _displayContactsTable();
	std::cout << "Select contact index: ";
	std::cin >> selectIndex;
	if (selectIndex >= 0 && selectIndex < i)
		_contacts[selectIndex].DisplayDetails();
	else
		std::cout << "Invalid index" << std::endl;
}
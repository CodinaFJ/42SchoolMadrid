/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:44:30 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/12 13:44:30 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// TODO: Learn about const + &
void	Contact::_displayTrimmedLine(const std::string& str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setfill (' ') << std::setw (10) << str;
}

Contact::Contact()
{
	_index = -1;
}

Contact::~Contact()
{
}

void	Contact::Init(int _index)
{
	//TODO: learn about ->
	//TODO: learn about cin.good() and so on
	this->_index = _index; 
	std::cout << "Fill the fields for the new contact: " << std::endl;
	std::cout << "First Name: ";
	std::cin >> this->_firstName;
	std::cout << "Last Name: ";
	std::cin >> this->_lastName;
	std::cout << "Nickname: ";
	std::cin >> this->_nickname;
	std::cout << "Phone Number: ";
	std::cin >> this->_phoneNumber;
	std::cout << "Darkest Secret: ";
	std::cin >> this->_darkestSecret;
	std::cout << "Contact added" << std::endl;
}

int		Contact::ShowContact(void)
{
	// ?: Is there a better way to return success or failure?
	if (_index == -1)
		return (-1);
	std::cout << std::setfill (' ') << std::setw (10) << _index << "|";
	this->_displayTrimmedLine(_firstName);
	std::cout << '|';
	this->_displayTrimmedLine(_lastName);
	std::cout << '|';
	this->_displayTrimmedLine(_nickname);
	std::cout << std::endl;
	return (0);
}

void	Contact::DisplayDetails(void)
{
	std::cout << "INDEX: " << _index << std::endl;
	std::cout << "FIRST NAME: " << _firstName << std::endl;
	std::cout << "LAST NAME: " << _lastName << std::endl;
	std::cout << "NICKNAME: " << _nickname << std::endl;
	std::cout << "PHONE NUMBER: " << _phoneNumber << std::endl;
	std::cout << "DARKEST SECRET: " << _darkestSecret << std::endl;
}

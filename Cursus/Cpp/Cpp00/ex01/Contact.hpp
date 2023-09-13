/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:46:56 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/12 13:46:56 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CONTACT_HPP)
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	void	_displayTrimmedLine(const std::string& str);
public:
	Contact();
	~Contact();
	void	Init(int _index);
	int		ShowContact(void);
	void	DisplayDetails(void);
};

#endif // CONTACT_HPP
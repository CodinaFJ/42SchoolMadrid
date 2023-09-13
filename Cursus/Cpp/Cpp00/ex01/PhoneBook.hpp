/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:45:02 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/12 13:45:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(_PHONEBOOK_)
#define _PHONEBOOK_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_nextContactIndex;
	int		_displayContactsTable(void);
public:
	PhoneBook();
	~PhoneBook();
	void	AddContact(void);
	void	Search(void);
};

#endif // _PHONEBOOK_

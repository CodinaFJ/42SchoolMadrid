/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:34:35 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:35 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_
#define _ZOMBIE_

#include <string>
#include <iostream>
#include <cstdlib>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(/* args */);
	~Zombie();
	void SetName(std::string name);
	void Announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif //_ZOMBIE_
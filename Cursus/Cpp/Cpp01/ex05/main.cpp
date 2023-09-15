/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:06:21 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/15 16:06:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	if (argc < 2)
	{
		std::cout << "FAILURE" << std::endl;
		return EXIT_FAILURE;
	}

	Harl harl;
	std::string complain(argv[1]);
	harl.complain(complain);
	return EXIT_SUCCESS;
}

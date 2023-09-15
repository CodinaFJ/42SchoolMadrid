/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/14 17:27:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SED_H_
#define _SED_H_

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class Sed
{
private:
	std::string _iFilename;
	std::string _oFilename;
	void error(std::string message);
public:
	Sed(char* input_file);
	~Sed();
	void replace(std::string toFind, std::string replace);
};

#endif // _SED_H_
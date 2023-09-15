/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:28:02 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/14 17:28:02 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void Sed::error(std::string message)
{
	std::cout << "ERROR: " << message << std::endl;
}

Sed::Sed(char *input_file)
{
	this->_iFilename.assign(input_file);
	this->_oFilename.assign(input_file);
	this->_oFilename.append(".replace");
}

Sed::~Sed()
{
}

void Sed::replace(std::string toFind, std::string replace)
{
	(void) toFind;
	(void) replace;
	std::ifstream ifs(this->_iFilename.c_str());
	if (ifs.is_open())
	{
		std::string content;

		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream ofs(this->_oFilename.c_str());
			if (ofs.is_open())
			{
				size_t findPos = content.find(toFind);
				size_t eraseSize = toFind.size();
				//size_t replaceSize = replace.size();

				while (findPos != std::string::npos)
				{
					content.erase(findPos, eraseSize);
					content.insert(findPos, replace);
					findPos = content.find(toFind);
				}
				ofs << content;
				ofs.close();
			}
			else
				this-> error("Wrong output file path");
		}
		ifs.close();
	}
	else
		this->error("Wrong input file path");
}

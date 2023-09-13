/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:21:26 by jcodina-          #+#    #+#             */
/*   Updated: 2023/09/13 17:21:26 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// OK
int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

//OK
int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

//OK
int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

//OK
int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
}

Account::Account(int initial_deposit)
{
}

Account::Account(void)
{
}

Account::~Account(void)
{
}

void Account::makeDeposit(int deposit)
{
}

bool Account::makeWithdrawal(int withdrawal)
{
	return false;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
}

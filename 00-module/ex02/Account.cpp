/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:40:15 by julberna          #+#    #+#             */
/*   Updated: 2024/05/04 18:20:04 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

//Initialization of static variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


/**
 * Constructs a new Account object and prints a message to the console
 *
 * #### Parameters:
 * - `int initial_deposit`: the initial deposit to create the account
 */
Account::Account(int initial_deposit)
	: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_displayTimestamp();

	this->_accountIndex = _nbAccounts++;
	_totalAmount += this->_amount;

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

/**
 * Destructs an Account object and prints a message to the console
 */
Account::~Account(void) {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

/**
 * Makes a deposit to the account and prints a message to the console
 *
 * #### Parameters:
 * - `int deposit`: the amount to deposit
 */
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount << std::flush;

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
 * Makes a withdrawal from the account and prints a message to the console
 *
 * #### Parameters:
 * - `int withdrawal`: the amount to withdraw
 *
 * #### Returns:
 * - `bool`: `true` if the withdrawal was successful, `false` otherwise
 */
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:" << std::flush;

	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

/**
 * Displays the account information to the console
 * (total accounts, total amount, total deposits, total withdrawals)
 */
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/**
 * Returns the number of accounts created
 *
 * #### Returns:
 * - `int`: total accounts
 */
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

/**
 * Returns the total balance of all accounts
 *
 * #### Returns:
 * - `int`: amount of money in all of the accounts
*/
int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

/**
 * Returns the total number of deposits
 *
 * #### Returns:
 * - `int`: total deposits
 */
int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

/**
 * Returns the total number of withdrawals
 *
 * #### Returns:
 * - `int`: total withdrawals
 */
int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

/**
 * Returns the balance of the account
 *
 * #### Returns:
 * - `int`: the amount of money in the account
 */
int	Account::checkAmount(void) const { //const because it doesnt modify any value of the class
	return (this->_amount);
}

/**
 * Displays the account status to the console
 * (index, amount, deposits, withdrawals)
 */
void	Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/**
 * Displays the current timestamp to the console
 */
void	Account::_displayTimestamp(void) {

	time_t	now = time(0);

	tm		*ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	std::cout << "] " << std::flush;
}

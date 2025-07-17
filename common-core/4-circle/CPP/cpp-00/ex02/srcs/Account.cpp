/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:55:18 by mivogel           #+#    #+#             */
/*   Updated: 2025/07/17 14:22:23 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Definition of static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount - deposit)
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount + withdrawal)
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t now = std::time(0);
    std::tm *tm = std::localtime(&now);
    std::cout << "[" << (1900 + tm->tm_year);
    if (tm->tm_mon + 1 < 10) std::cout << "0";
    std::cout << (tm->tm_mon + 1);
    if (tm->tm_mday < 10) std::cout << "0";
    std::cout << tm->tm_mday << "_";
    if (tm->tm_hour < 10) std::cout << "0";
    std::cout << tm->tm_hour;
    if (tm->tm_min < 10) std::cout << "0";
    std::cout << tm->tm_min;
    if (tm->tm_sec < 10) std::cout << "0";
    std::cout << tm->tm_sec << "] ";
}
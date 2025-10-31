#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) 
{
    return _nbAccounts;
}
int Account::getTotalAmount(void) 
{
    return _totalAmount;
}
int Account::getNbDeposits(void) 
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void) 
{
    return _totalNbWithdrawals;
}

void Account :: displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";"<< "deposits:" << getNbDeposits() << ";"<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account :: Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
}
Account ::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

void Account ::	makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    _amount = _amount + deposit;
    _totalAmount = _totalAmount + deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
bool Account ::	makeWithdrawal( int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount = _amount - withdrawal;
    _totalAmount = _totalAmount - withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal<< ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int	 Account ::	checkAmount( void ) const
{
    return _amount;
}

void Account ::	displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account ::_displayTimestamp( void )
{
    std::time_t Time = std::time(0);
    std::tm *nowtime = std::localtime(&Time);
    std::cout << "[" << 1900 + nowtime->tm_year << std::setfill('0') << std::setw(2) << 1 + nowtime->tm_mon << std::setw(2) << nowtime->tm_mday << "_" << std::setw(2) << nowtime->tm_hour << std::setw(2) << nowtime->tm_min << std::setw(2) << nowtime->tm_sec << "]";
}
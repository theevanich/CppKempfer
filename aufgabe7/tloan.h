#ifndef TLOAN_H
#define TLOAN_H

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "tmedium.h"
#include "tperson.h"
#include "tdate.h"
#include "xml.h"

class TLoan
{
    private:
    TMedium *Medium;
    TPerson *Customer;
    TDate  *LoanDate;
    TDate  *Expiration;
    string customerNumber, signatur;
    int loanDays;

    public:
    TLoan();
    TLoan(ifstream&);
    ~TLoan();

    void load(ifstream&);
    void print();

    string get_customerNumber();
    void set_customerNumber(string);
    
    string get_signatur();
    void set_signatur(string);
    
    TMedium* getMedium();
    void setMedium(TMedium*);

    TPerson* getCustomer();
    void setCustomer(TPerson*);

    TDate* getLoanDate();
    void setLoanDate(TDate*);

    TDate* getExpiration();
    void setExpiration(TDate*);
};

#endif
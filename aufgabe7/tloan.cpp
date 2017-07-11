using namespace std;

#include "tloan.h"

TLoan::TLoan()
:Medium(nullptr), Customer(nullptr), LoanDate(nullptr), Expiration(nullptr)
{}


TLoan::TLoan(ifstream& inFile)
{
   load(inFile);
}


void TLoan::load(ifstream& inFile) 
{
    string tagToLookFor[] = {"<CustomerNr>", "<Signatur>", "<LoanDate>", "<LoanDays>"};
    int maxTag = sizeof(tagToLookFor) / sizeof(*tagToLookFor);
    string line;
    while (getline(inFile, line))
    {
        // detect end of Loan to prevent any problems
        if (line.find("</Loan>") != string::npos)
        {
            break;
        }
        for(int i = 0; i < maxTag; i++)
        {
            if (line.find(tagToLookFor[i]) != string::npos )
            {
                switch(i)
                {
                    case 0:
                        customerNumber = parseLine(line, tagToLookFor[i]);
                        break;
                    case 1:
                        signatur = parseLine(line, tagToLookFor[i]);
                        break;
                    case 2:
                        LoanDate = new TDate(inFile);
                        break;
                    case 3:
                        loanDays = atoi(parseLine(line, tagToLookFor[i]).c_str());
                        Expiration = *LoanDate + loanDays;
                        cout << "Expiration = LoanDate: " << LoanDate << " + loanDays: " << loanDays << endl;
                        cout << "Expiration: " << Expiration << endl;
                        break;
                    default:
                        cout << "Nothing found... in Medium" << endl;
                        break;
                }
            }
        }
    }
}


TLoan::~TLoan()
{
    cout << "Destructing TLoan for medium \"" << this->Medium->get_name() << "\"..." << endl;
    delete LoanDate;
}

void TLoan::print()
{
    cout.fill(' ');
    cout << setw(15) << left << "Ausleihe vom: " << LoanDate << endl;
    cout << "Rueckgabe bis spaetestens: " << Expiration << endl;
    Medium->print(); cout << endl;
    cout << "ausgeliehen von: " << Customer->get_name() << endl;
}

string TLoan::get_signatur() {return signatur;}
string TLoan::get_customerNumber() {return customerNumber;}
TMedium* TLoan::getMedium() {return Medium;}
TPerson* TLoan::getCustomer() {return Customer;}
TDate* TLoan::getLoanDate() {return LoanDate;}
TDate* TLoan::getExpiration() {return Expiration;}

void TLoan::setMedium(TMedium* m) {Medium = m;}
void TLoan::setCustomer(TPerson* p) {Customer = p;}
void TLoan::setLoanDate(TDate* d) {LoanDate = d;}
void TLoan::setExpiration(TDate* d) {Expiration = d;}
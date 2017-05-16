#ifndef TPERSON_H
#define TPERSON_H

class TPerson
{
    private:
        string Name;
        TAddress Address;
        TDate Birthday;
        
    public:
        TPerson(string, TDate, TAddress);
        string get_name() const;
        TAddress get_address() const;
        TDate get_birthday() const;
        void set_name(string);
        void set_address(TAddress);
        void set_birthday(TDate);
        void print();
        
};

#endif

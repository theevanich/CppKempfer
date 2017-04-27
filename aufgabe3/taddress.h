#ifndef TADDRESS_H
#define TADDRESS_H

class TAddress
{
    private:
        std::string Street;
        std::string Number;
        std::string Zipcode;
        std::string Town;
        
    public:
        TAddress(std::string, std::string, std::string, std::string);
        std::string get_street() const;
        std::string get_number() const;
        std::string get_zipcode() const;
        std::string get_town() const;
        void set_street(std::string);
        void set_number(std::string);
        void set_zipcode(std::string);
        void set_town(std::string);
        void print();
};


#endif
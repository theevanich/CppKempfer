#ifndef TLOCATION_H
#define TLOCATION_H

class TLocation
{
    private:
        std::string section;
        std::string rack;
        
    public:
        TLocation();
        TLocation(std::string section, std::string rack);
        void print();
        std::string get_section() const;
        std::string get_rack() const;
        void set_section(std::string section);
        void set_rack(std::string section);
};

#endif
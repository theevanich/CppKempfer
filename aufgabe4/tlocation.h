#ifndef TLOCATION_H
#define TLOCATION_H

class TLocation
{
    private:
        string section;
        string rack;
        
    public:
        TLocation();
        TLocation(string section, string rack);
        void print();
        string get_section() const;
        string get_rack() const;
        void set_section(string section);
        void set_rack(string section);
};

#endif
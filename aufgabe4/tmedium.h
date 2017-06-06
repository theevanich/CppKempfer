#ifndef TMEDIUM_H
#define TMEDIUM_H

class TMedium
{
    protected:
        string parseLine(string, string);
        
    public:
        enum Status {verfuegbar, ausgeliehen, bestellt, reserviert};

    private:
        string Name;
        string Signature;
        TLocation* Location;
        int FSK;
        Status status;
        void load(ifstream&);
        
    public:
        TMedium();
        ~TMedium();
        TMedium(string, string, TLocation*, int, Status);
        TMedium(ifstream&);
        void print();
        
        void set_status(Status);
        void set_status(int);
        void set_name(string);
        void set_signature(string);
        void set_FSK(int);
        void set_location(TLocation*);
        
        string get_status() const;
        string get_name() const;
        string get_signature() const;
        int get_FSK() const;    
        
};

#endif
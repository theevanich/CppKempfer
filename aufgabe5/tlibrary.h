#ifndef TLIBRARY_H
#define TLIBRARY_H

class TLibrary
{
    protected:
        string parseLine(string, string);
        
    private:
        string Name;
        TAddress* address;
        TPerson* Manager;
        vector<TMedium*>MediumList;
        void load(ifstream&);

    public:
        TLibrary(string, TAddress*, TPerson*);
        TLibrary(ifstream&);
        ~TLibrary();
        void setName(string);
        void setAddress(TAddress*);
        void setManager(TPerson*);
        void setMediumList(vector<TMedium*>);
        void print();

        string get_name() const;
        TAddress* get_address() const;
        TPerson* get_manager() const;
        vector<TMedium*>getMediumList() const;
        void add(TMedium*);

};


#endif // TLibrary_h
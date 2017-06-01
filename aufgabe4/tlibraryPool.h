#ifndef TLIBRARYPOOL_H
#define TLIBRARYPOOL_H

class TLibraryPool
{
    private:
        string Name;
        TPerson *Boss;
        vector<TLibrary*> LibraryList;
        vector<TPerson*> CustomerList;

    public:
        TLibraryPool(string, TPerson*);
        ~TLibraryPool();

        void add(TLibrary*);
        void add(TPerson*);
        void print();

        void set_name(string);
        void set_boss(TPerson*);
        void set_customer(vector<TPerson*>);
        void set_libraryList(vector<TLibrary*>);

        string get_name() const;
        TPerson* get_boss() const;
        vector <TLibrary*> get_libraryList() const;
        vector <TPerson*> get_customerList() const;
};
#endif // TLIBRARYPOOL
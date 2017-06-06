#ifndef TDATE_H
#define TDATE_H

class TDate
{
    protected:
        string parseLine(string, string);
        
    private:
        int dd, mm, yyyy;
        time_t now;
        string date;
        void load(ifstream&);
        
    public:
        TDate();
        TDate(ifstream&);
        TDate(int dd, int mm, int yyyy);
        //int get_dd() const;
        //int get_mm() const;
        //int get_yyyy() const;
        //void set_dd(int dd);
        //void set_mm(int mm);
        //void set_yyyy(int yyyy);
        void print();
    
};

#endif
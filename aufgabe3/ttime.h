#ifndef TTIME_H
#define TTIME_H

class TTime
{
    private:
        int hh, mm, ss;
        time_t now;
        string myTime;
        
    public:
        TTime();
        TTime(int hh, int mm);
        TTime(int hh, int mm, int ss);
        int get_hh() const;
        int get_mm() const;
        int get_ss() const;
        void set_hh(int hh);
        void set_mm(int mm);
        void set_ss(int ss);
        void print();
    
};

#endif
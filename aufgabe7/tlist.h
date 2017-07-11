#ifndef TList_H
#define TList_H TList_H
#include <cstddef>     // für NULL
#include <cassert>     // für assert

template<class T> class TList
{
   private:
      struct ListElement
      {
         T Data;
         ListElement *Next, *Prev;
         ListElement(): Next(NULL), Prev(NULL) // Konstruktur
         { }
      };

      ListElement *First, *Last;
      unsigned Anzahl;

   public:
      TList();                // Konstruktor
      TList(const TList&);    // Kopierkonstruktor
      virtual ~TList();       // Destruktor

      TList& operator=(const TList&);

      bool empty() const { return Anzahl == 0; }
      unsigned size() const { return Anzahl; }

      // am Anfang bzw. Ende einfügen
      void push_front(const T&);
      void push_back(const T&);

      // am Anfang bzw. Ende entnehmen
      void pop_front();
      void pop_back();

      // am Anfang bzw. Ende lesen
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      // ========================================
      // Jetzt kommt die geschachtelte
      // Klasse für den Iterator:
      class Iterator
      {
         private:
            ListElement* aktuell;   // Zeiger auf
                                    // aktuelles Element
         public:
            friend class TList<T>;  // wg. erase-Zugriff
                                    // auf aktuell
            Iterator(ListElement* Init = NULL)
            : aktuell(Init)
            { }

            Iterator(const TList& L)
            {  *this = L.begin(); }

            //Dereferenzierung:
            const T& operator*() const
            {  return aktuell->Data; }

            T& operator*()
            {  return aktuell->Data; }

            Iterator& operator++() // prefix
            {
               if (aktuell)
                  aktuell = aktuell->Next;
               return *this;
            }

            Iterator operator++(int) // postfix
            {
               Iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const Iterator& x) const
            {  return aktuell == x.aktuell; }

            bool operator!=(const Iterator& x) const
            {  return aktuell != x.aktuell; }

      }; // Iterator
      // Hier ist Deklaration und Definition
      // des Iterators zu Ende!
      // ========================================

      // Methoden der Klasse TList,
      // die die Klasse Iterator benutzen:

      Iterator begin() const
      {  return Iterator(First); }

      Iterator end() const
      {  return Iterator(); } // NULL-Iterator

      void erase(Iterator& pos) // Element löschen
      {
         if (pos.aktuell == First)
         {
            pop_front();
            pos.aktuell = First; // neuer Anfang
         }
         else
            if (pos.aktuell == Last)
            {
               pop_back();
               pos.aktuell = Last;
            }
            else
            {
               // zwischen 2 Elementen ausketten
               pos.aktuell->Next->Prev = pos.aktuell->Prev;
               pos.aktuell->Prev->Next = pos.aktuell->Next;
               ListElement *temp = pos.aktuell;
               pos.aktuell = pos.aktuell->Next;
               delete temp;
               Anzahl--;
            }
      }

      // Vor pos einfügen
      Iterator insert(Iterator pos, const T& Wert)
      {
         if (pos == begin())
         {
            push_front(Wert);
            return Iterator(First);
         }
         if (pos == end())
         {
            push_back(Wert);
            return Iterator(Last);
         }
         // zwischen 2 Elementen einketten
         ListElement *temp = new ListElement;
         temp->Data = Wert;
         temp->Next = pos.aktuell;
         temp->Prev = pos.aktuell->Prev;
         pos.aktuell->Prev->Next = temp;
         pos.aktuell->Prev = temp;
         Anzahl++;
         return Iterator(temp);
      }
};

// ===== Implementierung der Klasse TList =====
// soweit nicht schon geschehen

template<class T>           // Konstruktor
inline TList<T>::TList()
: First(NULL), Last(NULL), Anzahl(0)
{ }

template<class T>           // Kopierkonstruktor
inline TList<T>::TList(const TList<T>& L)
: First(NULL), Last(NULL), Anzahl(0)
{
   ListElement *temp = L.Last;
   while (temp)
   {
      push_front(temp->Data);
      temp = temp->Prev;
   }
}

template<class T>           // Destruktor
inline TList<T>::~TList()
{
   while (!empty())
      pop_front();
}

template<class T>           // Zuweisungsoperator
inline TList<T>& TList<T>::operator=(const TList<T>& L)
{
   if (this != &L) // Selbstzuweisung ausschließen
   {
      while (!empty())
         pop_front(); // alles löschen
      // ... und neu aufbauen
      ListElement *temp = L.Last;
      while (temp)
      {
         push_front(temp->Data);
         temp = temp->Prev;
      }
   }
   return *this;
}

template<class T>
inline void TList<T>::push_front(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = NULL;
   temp->Next = First;
   if (!First)
      Last=temp; // einziges Element
   else
      First->Prev = temp;
   First = temp;
   Anzahl++;
}

template<class T>
inline void TList<T>::push_back(const T& Dat)
{
   ListElement *temp = new ListElement;
   temp->Data = Dat;
   temp->Prev = Last;
   temp->Next = NULL;
   if (!Last)
      First = temp; // einziges Element
   else
      temp->Prev->Next = temp;
   Last = temp;
   Anzahl++;
}

template<class T>
inline void TList<T>::pop_front()
{
   assert(!empty());
   ListElement *temp = First;
   First = temp->Next;
   if (!First)
      // d.h. kein weiteres Element vorhanden
      Last = NULL;
   else
      First->Prev = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline void TList<T>::pop_back()
{
   assert(!empty());
   ListElement *temp = Last;
   Last = temp->Prev;
   if (!Last)
      // d.h. kein weiteres Element vorhanden
      First = NULL;
   else
      Last->Next = NULL;
   delete temp;
   Anzahl--;
}

template<class T>
inline T& TList<T>::front()
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline const T& TList<T>::front() const
{
   assert(!empty());
   return First->Data;
}

template<class T>
inline T& TList<T>::back()
{
   assert(!empty());
   return Last->Data;
}

template<class T>
inline const T& TList<T>::back() const
{
   assert(!empty());
   return Last->Data;
}

#endif

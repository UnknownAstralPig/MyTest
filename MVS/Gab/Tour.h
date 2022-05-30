#ifndef TRAVELBUSINESSH
#define TRAVELBUSINESSH

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace TravelBusiness
{
    template <typename tip>
    struct data {
        tip *dat;
        data *next;
    };

    template <typename tip>
    class list {
        private:
            data<tip> *head, *tail;
            int size;
        public:
            list();
            list(list<tip>&);
            ~list() ;

            void push(tip);
            void remove(int);
            tip* get_data(int);
            int get_size();

            list<tip>& operator=(list<tip>&);
    };
    
    class agreement {
        private:
            string  tourist_firstName,
                    tourist_secondName;
        public:
            agreement();
            agreement(string,string);
            agreement(const agreement&);
            ~agreement();

            void set_touristFirstName(string);
            void set_touristSecondName(string);
            string get_touristFirstName() const;
            string get_touristSecondName() const;

            bool operator==(agreement&);
    };

    class tourist_group {
        private:
            string group_name;
            list<agreement> agreements;
        public:
            tourist_group();
            tourist_group(string);
            tourist_group(string, list<agreement>&);
            tourist_group(tourist_group&);
            ~tourist_group();

            void set_gname(string);
            void set_agreements(list<agreement>&);

            string get_gname();
            list<agreement>* get_agreements();
    };

    class tour {
        private:
            list<tourist_group> groups;
            string country;
        public:
            tour();
            tour(string);
            tour(string, list<tourist_group>&);
            tour(tour&);
            ~tour();

            void set_country(string);
            void set_groups(list<tourist_group>&);

            list<tourist_group>* get_groups();
            string get_country();
    };

    class TourOgranisation {
        private:
            list<tour> tours;
        public:
            TourOgranisation();
            ~TourOgranisation();

            list<tour>& get_tours();
            TourOgranisation* find_tourists(list<agreement>&);
    } ;

}

namespace std {
    template <typename tip>
    ostream& operator<<(ostream&, TravelBusiness::list<tip>&);
    template <typename tip>
    ofstream& operator<<(ofstream&, TravelBusiness::list<tip>&);
    template <typename tip>
    istream& operator>>(istream&, TravelBusiness::list<tip>&);
    template <typename tip>
    ifstream& operator>>(ifstream&, TravelBusiness::list<tip>&);

    ostream& operator<<(ostream&, TravelBusiness::agreement&);
    ofstream& operator<<(ofstream&, TravelBusiness::agreement&);
    istream& operator>>(istream&, TravelBusiness::agreement&);
    ifstream& operator>>(ifstream&, TravelBusiness::agreement&);

    ostream& operator<<(ostream&, TravelBusiness::tourist_group&);
    ofstream& operator<<(ofstream&, TravelBusiness::tourist_group&);
    istream& operator>>(istream&, TravelBusiness::tourist_group&);
    ifstream& operator>>(ifstream&, TravelBusiness::tourist_group&);

    ostream& operator<<(ostream&, TravelBusiness::tour&);
    ofstream& operator<<(ofstream&, TravelBusiness::tour&);
    istream& operator>>(istream&, TravelBusiness::tour&);
    ifstream& operator>>(ifstream&, TravelBusiness::tour&);

    ostream& operator<<(ostream&, TravelBusiness::TourOgranisation&);
    ofstream& operator<<(ofstream&, TravelBusiness::TourOgranisation&);
    istream& operator>>(istream&, TravelBusiness::TourOgranisation&);
    ifstream& operator>>(ifstream&, TravelBusiness::TourOgranisation&);
}

#endif
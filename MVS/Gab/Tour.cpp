#ifndef TRAVELBUSINESSCPP
#define TRAVELBUSINESSCPP

#include "Tour.h"

template <typename tip>
TravelBusiness::list<tip>::list() : head(nullptr), tail(nullptr), size(0) {
}

template <typename tip>
TravelBusiness::list<tip>::list(list<tip>& other) : head(nullptr), tail(nullptr), size(0) {
    for(int i = 0;i < other.get_size();++i)
        this->push(*other.get_data(i));
}

template <typename tip>
TravelBusiness::list<tip>::~list() {
    if( !size )
        return;

    for(int i = 0;i < size;++i)
        remove(0);
}

template <typename tip>
void TravelBusiness::list<tip>::push(tip d) {
    if(head == nullptr) {
        head = new TravelBusiness::data<tip>;
        head->next = nullptr;
        head->dat = new tip(d);
        tail = head;
    } else {
        tail->next = new TravelBusiness::data<tip>;
        tail = tail->next;
        tail->next = nullptr;
        tail->dat = new tip(d);
    }
    ++size;
}

template <typename tip>
void TravelBusiness::list<tip>::remove(int ind) {
    if(!size || ind < 0 || ind >= size)
        return;

    TravelBusiness::data<tip>* iter,*t;
    for(iter = head,--ind;ind>0;--ind) {
        iter = iter->next;
    }


    if(iter == head) {
        head = head->next;
        delete iter->dat;
        delete iter;
    } else {
        if(iter->next)
            t = iter->next->next;
        else
            t = nullptr;
        delete iter->next->dat;
        delete iter->next;
        iter->next = t;
    }
    --size;

}
template <typename tip>
tip* TravelBusiness::list<tip>::get_data(int ind) {
    if(!size || ind < 0 || ind >= size)
        return nullptr;
    TravelBusiness::data<tip>* iter,*t;
    for(iter = head;ind>0;--ind) {
        iter = iter->next;
    }
    return iter->dat;
}

template <typename tip>
int TravelBusiness::list<tip>::get_size() {
    return size;
}

template <typename tip>
TravelBusiness::list<tip>& TravelBusiness::list<tip>::operator=(TravelBusiness::list<tip>& other) {
    if(size)
        for(;size;)
            remove(0);
    

    for(int i = 0;i < other.get_size();++i)
        this->push(*other.get_data(i));

    return *this;
}

template <typename tip>
ostream& std::operator<<(ostream& out, TravelBusiness::list<tip>& list) {
    for(int i = 0;i<list.get_size();++i)
        out << *list.get_data(i) << '\n';
    return out;
}

template <typename tip>
ofstream& std::operator<<(ofstream& out, TravelBusiness::list<tip>& list) {
    for(int i = 0;i<list.get_size();++i)
        out << *list.get_data(i) << '\n';
    return out;
}

template <typename tip>
istream& std::operator>>(istream& in, TravelBusiness::list<tip>& list) {
    int size;
    tip vrem;
    in >> size;
    for(int i = 0;i<size;++i) {
        in >> vrem;
        list.push(vrem);
    }

    return in;
}

template <typename tip>
ifstream& std::operator>>(ifstream& in, TravelBusiness::list<tip>& list) {
    int size;
    tip vrem;
    in >> size;
    for(int i = 0;i<size;++i) {
        in >> vrem;
        list.push(vrem);
    }

    return in;
}

TravelBusiness::agreement::agreement() : tourist_firstName("") , tourist_secondName("") {
}

TravelBusiness::agreement::agreement(string f_name, string s_name) : tourist_firstName(f_name) , tourist_secondName(s_name) {
}

TravelBusiness::agreement::agreement(const agreement& other_tourist) : tourist_firstName(other_tourist.get_touristFirstName()) , tourist_secondName(other_tourist.get_touristSecondName()) {
}

TravelBusiness::agreement::~agreement() {
}

void TravelBusiness::agreement::set_touristFirstName(string name) {
    tourist_firstName = name;
}

void TravelBusiness::agreement::set_touristSecondName(string name) {
    tourist_secondName = name;
}

string TravelBusiness::agreement::get_touristFirstName() const {
    return tourist_firstName;
}

string TravelBusiness::agreement::get_touristSecondName() const {
    return tourist_secondName;
}

bool TravelBusiness::agreement::operator==(agreement& other) {
    return ( other.get_touristFirstName() == this->get_touristFirstName() &&
    other.get_touristSecondName() == this->get_touristSecondName() ? true : false );
}

ostream& std::operator<<(ostream& out, TravelBusiness::agreement& agr) {
    out << agr.get_touristFirstName() << " " << agr.get_touristSecondName() ;
    return out;
}
ofstream& std::operator<<(ofstream& out, TravelBusiness::agreement& agr) {
    out << agr.get_touristFirstName() << " " << agr.get_touristSecondName() ;
    return out;
}
istream& std::operator>>(istream& in, TravelBusiness::agreement& agr) {
    string name;
    in >> name;
    agr.set_touristFirstName(name);
    in >> name;
    agr.set_touristSecondName(name);
    return in;
}
ifstream& std::operator>>(ifstream& in, TravelBusiness::agreement& agr) {
    string name;
    in >> name;
    agr.set_touristFirstName(name);
    in >> name;
    agr.set_touristSecondName(name);
    return in;
}

TravelBusiness::tourist_group::tourist_group() : group_name("") { 
}

TravelBusiness::tourist_group::tourist_group(string g_name) : group_name(g_name) { 
}

TravelBusiness::tourist_group::tourist_group(string g_name, TravelBusiness::list<TravelBusiness::agreement>& o_agres) : group_name(g_name) , agreements(o_agres) { 
}

TravelBusiness::tourist_group::tourist_group(TravelBusiness::tourist_group& ot_tourist_group) : group_name(ot_tourist_group.get_gname()) , agreements(*ot_tourist_group.get_agreements()) {
}

TravelBusiness::tourist_group::~tourist_group() { 
}

void TravelBusiness::tourist_group::set_gname(string ot_name)
{
    group_name = ot_name;
}

void TravelBusiness::tourist_group::set_agreements(TravelBusiness::list<TravelBusiness::agreement>& other_agres)
{
    agreements = other_agres;
}

TravelBusiness::list<TravelBusiness::agreement>* TravelBusiness::tourist_group::get_agreements() {
    return &agreements;
}

string TravelBusiness::tourist_group::get_gname() {
    return group_name;
}

ostream& std::operator<<(ostream& out, TravelBusiness::tourist_group& group) {
    out << "Touristgroup: " << group.get_gname() << "\n" << *group.get_agreements();
    return out;
}
ofstream& std::operator<<(ofstream& out, TravelBusiness::tourist_group& group) {
    out << "Touristgroup: " << group.get_gname() << "\n" << *group.get_agreements();
    return out;
}
istream& std::operator>>(istream& in, TravelBusiness::tourist_group& group) {
    string name;
    TravelBusiness::list<TravelBusiness::agreement> vrem;
    in >> name >> vrem;
    group.set_gname(name);
    group.set_agreements(vrem);
    return in;
}
ifstream& std::operator>>(ifstream& in, TravelBusiness::tourist_group& group) {
    string name;
    TravelBusiness::list<TravelBusiness::agreement> vrem;
    in >> name;
    in>>  vrem;
    group.set_gname(name);
    group.set_agreements(vrem);
    return in;
}

TravelBusiness::tour::tour() : country("") { 
}

TravelBusiness::tour::tour(string contr) : country(contr) { 
}

TravelBusiness::tour::tour(string contr, TravelBusiness::list<TravelBusiness::tourist_group>& ot_grps) : country(contr) , groups(ot_grps) { 
}

TravelBusiness::tour::tour(TravelBusiness::tour& ot_tour) : country(ot_tour.get_country()) , groups(*ot_tour.get_groups()) { 
}

TravelBusiness::tour::~tour() { 
}

void TravelBusiness::tour::set_country(string ot_country) {
    country = ot_country;
}

void TravelBusiness::tour::set_groups(TravelBusiness::list<TravelBusiness::tourist_group>& tourist_groups) {
    this->groups = tourist_groups;
}

TravelBusiness::list<TravelBusiness::tourist_group>* TravelBusiness::tour::get_groups() {
    return &this->groups;
}

string TravelBusiness::tour::get_country() {
    return country;
}

ostream& std::operator<<(ostream& out, TravelBusiness::tour& tour) {
    out << "Tours in : " << tour.get_country() << "\n" << *tour.get_groups();
    return out;
}

ofstream& std::operator<<(ofstream& out, TravelBusiness::tour& tour) {
    out << "Tours in : " << tour.get_country() << "\n" << *tour.get_groups();
    return out;
}

istream& std::operator>>(istream& in, TravelBusiness::tour& tour) {
    string countr;
    TravelBusiness::list<TravelBusiness::tourist_group> tourist_groups;
    in >> countr >> tourist_groups;
    tour.set_country(countr);
    tour.set_groups(tourist_groups);
    return in;
}
ifstream& std::operator>>(ifstream& in, TravelBusiness::tour& tour) {
    string countr;
    TravelBusiness::list<TravelBusiness::tourist_group> tourist_groups;
    in >> countr >> tourist_groups;
    tour.set_country(countr);
    tour.set_groups(tourist_groups);
    return in;
}

TravelBusiness::TourOgranisation::TourOgranisation() {
}

TravelBusiness::TourOgranisation::~TourOgranisation() {
}

TravelBusiness::list<TravelBusiness::tour>& TravelBusiness::TourOgranisation::get_tours() {
    return tours;
}

TravelBusiness::TourOgranisation* TravelBusiness::TourOgranisation::find_tourists(TravelBusiness::list<TravelBusiness::agreement>& agreements ) {
    TravelBusiness::TourOgranisation *to = new TravelBusiness::TourOgranisation;
    TravelBusiness::tour* cur_tour;
    TravelBusiness::tourist_group* cur_group;
    TravelBusiness::agreement *cur_agr;
    int tours_size, groups_size, agreems_size;

    tours_size = this->get_tours().get_size();
    for(int i = 0;i<tours_size;++i) {
        cur_tour = this->get_tours().get_data(i);
        TravelBusiness::tour tour_new(cur_tour->get_country());
        groups_size = cur_tour->get_groups()->get_size();
        for(int j = 0;j<groups_size;++j) {
            cur_group = cur_tour->get_groups()->get_data(j);
            TravelBusiness::tourist_group tgroup_new(cur_group->get_gname());
            agreems_size = cur_group->get_agreements()->get_size();
            for(int z = 0;z<agreems_size;++z) {
                cur_agr = cur_group->get_agreements()->get_data(z);
                for(int k = 0;k < agreements.get_size();++k)
                    if(*cur_agr == *agreements.get_data(k))
                        tgroup_new.get_agreements()->push(*cur_agr);
            }
            if(tgroup_new.get_agreements()->get_size())
                tour_new.get_groups()->push(tgroup_new);
        }
        if(tour_new.get_groups()->get_size())
        to->get_tours().push(tour_new);
    }
    return to;
}

ostream& std::operator<<(ostream& out, TravelBusiness::TourOgranisation& to) {
    out << to.get_tours();
    return out;
}
ofstream& std::operator<<(ofstream& out, TravelBusiness::TourOgranisation& to) {
    out << to.get_tours();
    return out;
}
istream& std::operator>>(istream& in, TravelBusiness::TourOgranisation& to) {
    in >> to.get_tours();
    return in;
}
ifstream& std::operator>>(ifstream& in, TravelBusiness::TourOgranisation& to) {
    in >> to.get_tours();
    return in;
}

#endif
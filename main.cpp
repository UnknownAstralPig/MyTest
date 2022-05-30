#include "Tour.h"

int main()
{
    ifstream ifs("Tours.txt");
    TravelBusiness::TourOgranisation to;
    TravelBusiness::TourOgranisation *found;
    TravelBusiness::list<TravelBusiness::agreement> find;
    ifs >> to ;

    find.push(TravelBusiness::agreement(string("Ivan"), string("Ivanov")));
    find.push(TravelBusiness::agreement(string("Kirill"), string("Nedolybov")));
    find.push(TravelBusiness::agreement(string("Semen"), string("Alinov")));
    found = to.find_tourists(find);

    std::cout << *found;

}
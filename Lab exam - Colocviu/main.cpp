/// Stan Bianca-Mihaela grupa 132
/// rulat cu Codeblocks  g++ C++14
/// Tutore: Lupascu Marian
#include "Masca.h"
#include "Chirurgicala.h"
#include "MascaChirurgicala.h"
#include "MascaPolicarbonat.h"
#include "Dezinfectatnt.h"
#include "DezinfectantBacterii.h"
#include "DezinfectantVirusuri.h"
#include "DezinfectantFungi.h"
#include "Achizitie.h"
#include "Afacere.h"

Afacere* Afacere::instance=nullptr;
int Afacere::venit=0;

using namespace std;

int main()
{
    MascaChirurgicala mc1, mc2("ffp2", "verde brotăcel", 55), mc3(mc1), mc4, mc5;
    mc4 = mc2;
    std::cin >> mc5;
    std::cout << mc1 << mc2;
    MascaPolicarbonat* mp1=new MascaPolicarbonat(), * mp2=new MascaPolicarbonat();
    MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");
    std::cin >> *mp1 >> *mp2;
    std::cout <<*mp3;
    Dezinfectant* d1 = new DezinfectantBacterii(100000000, std::vector<string>({"sulfatinon-ionici", "sulfati cationici", "parfumuri", "Linalool", "Metilpropanol butilpentil"}),std::vector<string>({"lemn", "sticla", "metal", "ceramica", "marmura"}));
    Dezinfectant* d2 = new DezinfectantVirusuri(50000000, std::vector<string>({"AlkilDimetilm Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<string>({"lemn", "sticla", "ceramica", "marmura"}));
    Dezinfectant* d3 = new DezinfectantFungi(1400000, std::vector<string>({"Alkil EtilBenzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<string>({"sticla", "plastic"}));
    std::cout << d1->eficienta() << " " << d2->eficienta() << " " << d3->eficienta() << "\n";
    Achizitie* a1 = new Achizitie(26, 5, 2020, "PlushBio SRL");
    *a1 += mp1; //se adauga masca de policarbonat mp1 in lista de masti achizitionate
    *a1 += (&mc1); //se adauga masca chirugicala mc1 in lista
    *a1 += d3; // se adauga dezinfectantu de fungi d3 in lista de dezinfectanti achizitionati
    Achizitie* a2 = new Achizitie(25, 5, 2020, "Gucci");
    *a2 += d1;
    *a2 += d2;
    *a2 += d2;
    Achizitie a3, a4(*a1);
    a3 = *a2;
    if(*a1 < *a2) {
    std::cout << a1->get_nume() << " are valoarea facturii mai mica.\n";
    }else if (*a1 == *a2) {
    std::cout << a1->get_nume() << " si " << a2->get_nume() << " au aceasi valoare afacturii.\n";}
    else {
    std::cout << a2->get_nume() << " are valoarea facturii mai mica.\n";
    }

    Afacere::get_instance()->adauga_masca();
    Afacere::get_instance()->adauga_dezinfectant();
    Afacere::get_instance()->adauga_achizitie();
    Afacere::get_instance()->venitul_din_luna(8);
    Afacere::get_instance()->cle_mai_fidel_client();
    return 0;
}

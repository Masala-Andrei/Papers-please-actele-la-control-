#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <ostream>
#include <random>


class Imigrant
{
private:
    int inaltime, greutate;

public:
    Imigrant(int inaltime,int greutate) : inaltime(inaltime),greutate(greutate){}

    ~Imigrant() = default;

    friend std::ostream &operator<<(std::ostream &out, const Imigrant &imigrant)
    {
        out << "Date despre individ"<< std::endl << "Inaltimea:" << imigrant.inaltime << std::endl << "Greutate:" << imigrant.greutate << std::endl;
        return out;
    }
};

class Pasaport
{
private:
    std::string nume, data_expirare, zona, cod, oras, sex;

public:
    Pasaport(
            const std::string& nume,
            const std::string& sex,
            const std::string& cod,
            const std::string& zona,
            const std::string& oras,
            const std::string& data_expirare) : nume(nume),sex(sex), data_expirare(data_expirare),zona(zona),cod(cod),oras(oras) {}

    ~Pasaport() {
        std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl
        <<std::endl<<std::endl<<std::endl<<std::endl<<std::endl
        <<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<"Urmatorul Pasaport";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout<<".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout<<".";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout<<"."<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    };
    friend std::ostream &operator<<(std::ostream &out, const Pasaport &pasaport)
    {
        out << "Pasaport" << std::endl
        << "Nume: " << pasaport.nume << std::endl
        << "Sex: " << pasaport.sex << std::endl
        << "Cod: " << pasaport.cod << std::endl
        << "Zona: " << pasaport.zona << std::endl
        << "Oras: " << pasaport.oras << std::endl
        << "Data_expr.: " << pasaport.data_expirare << std::endl;
        return out;
    }

};

class Statistici
{
private:
    int corecte, gresite, credit;

public:
    Statistici(int corecte, int gresite, int credit) :corecte(corecte), gresite(gresite), credit(credit) {}
    void corect()
    {
        this->corecte++;
        this->credit = this->credit + 5;
    }
    void gresit()
    {
        this->gresite--;
        this->credit = this->credit - 7;
    }

    friend std::ostream &operator<<(std::ostream &out, const Statistici &stat)
    {
        out <<"Statisticile rundei:" << std::endl
        <<"Greseli: " << stat.gresite << std::endl
        <<"Admiteri/Respingeri corecte: " << stat.corecte << std::endl
        <<"Scor: " << stat.credit << std::endl;
        return out;
    }

};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd()); ///Setez un generator
    std::ifstream N("Nume - proiect.txt");
    std::ifstream Z("Zona.txt");
    std::ifstream O("Orase.txt");

    std::string DATA_CURENTA = "1-4-2231";  ///Data de inceput a jocului
    std::cout<< "Data curenta: " << DATA_CURENTA << std::endl << std::endl;
    int GRESELI;
/// O singura runda (momentan) care se termina cand scriu "Exit"

    Statistici stat(0,0,0);

    while(true)
    {
        GRESELI = 0;
        N.seekg(0);
        Z.seekg(0);
        O.seekg(0); ///pun bufferele la inceputul fileului

        std::uniform_int_distribution<int> _g(50,140);
        std::uniform_int_distribution<int> _i(150,215);
        Imigrant persoana(_i(gen), _g(gen));
        operator<<(std::cout,persoana);

        int linia, l, oras_aux;
        std::string Nume,Oras,Zona,Sex,Cod,Data_expirare;

        ///Generez un nume
        std::uniform_int_distribution<int> _n(0,248);
        linia = _n(gen);
        l = 0;
        while (l < linia)
        {
            std::getline(N,Nume);
            l++;
        }
        std::getline(N,Nume);
        Sex.assign(Nume.substr(Nume.length()-1,1));
        Nume.erase(Nume.length()-2,Nume.length());

        ///Generez o Zona
        std::uniform_int_distribution<int> _z(0,9);
        linia = _z(gen);
        l = 0;
        while (l < linia)
        {
            std::getline(Z,Zona);
            l++;
        }
        std::getline(Z,Zona);

        ///Generez un Oras
        l = 0;
        while (l < linia)
        {
            std::getline(O,Oras);
            std::getline(O,Oras);
            std::getline(O,Oras);
            l++;
        }
        std::uniform_int_distribution<int> _o(0,2);
        oras_aux = _o(gen);
        l = 0;
        while(l < oras_aux)
        {
            std::getline(O,Oras);
            l++;
        }
        std::getline(O,Oras);

        ///Generez cod
        std::uniform_int_distribution<int> _c(65,90);
        std::string litera;
        l = 0;
        while (l<7)
        {
            char c = _c(gen);
            Cod.append(1,c);
            l++;
        }

        ///Generez o data de expirare (exista o sansa 1/7 ca aceasta sa nu fie corecta fac functie in clasa pasaport)


        int zi = stoi(DATA_CURENTA.substr(0,1));
        int luna = stoi(DATA_CURENTA.substr(2,1));
        int an = stoi(DATA_CURENTA.substr(4,4)); ///Despart data curenta
        std::cout << std::endl;

        std::uniform_int_distribution<int> _zi(zi,30);
        std::uniform_int_distribution<int> _luna(luna,12);
        std::uniform_int_distribution<int> _an(an,2240);
        std::string szi,sluna,san,sdata;
        szi = std::to_string(_zi(gen));
        sluna = std::to_string(_luna(gen));
        san = std::to_string(_an(gen));

        std::uniform_int_distribution<int> _sansa(1,7);
        int sansa = _sansa(gen);
        if (sansa == 1)
        {
            GRESELI ++;
            std::uniform_int_distribution<int> _a(0,4);
            std::uniform_int_distribution<int> _b(0,4);
            int b = _b(gen);
            int a = _a(gen);
            if (a == 0 || b == 2)
            {
                std::uniform_int_distribution<int> wrong_zi(0,zi-1);
                szi = std::to_string(wrong_zi(gen));
            }
            if (a == 1 || b == 2)
            {
                std::uniform_int_distribution<int> wrong_luna(1,luna-1);
                sluna = std::to_string(wrong_luna(gen));
            }
            if (a % 2 == 0 && a != 0 || b%2 == 1)
            {
                std::uniform_int_distribution<int> wrong_an(2200,an-1);
                san = std::to_string(wrong_an(gen));
            } ///Generez o greseala in data
        }

        sdata.append(szi);
        sdata.append("-");
        sdata.append(sluna);
        sdata.append("-");
        sdata.append(san);

        Pasaport pasaport(Nume,Sex,Cod,Zona,Oras,sdata);
        operator<<(std::cout,pasaport);



        std::string input;
        std::cout << "Scrie 'Accepta' pentru a accepta, 'Refuza' pentru a refuza sau 'Exit' pentru a iesi din joc"<< std::endl;
        getline(std::cin,input);
        while (!(input != "Exit" || input != "Accepta" || input != "Refuza"))
            getline(std::cin,input);

        if (input == "Exit")
            break;
        if (input == "Accepta")
        {
            if (GRESELI == 0) {
                std::cout << "Corect!" << std::endl;
                stat.corect();

            }
            else
            {
                std::cout<< "Gresit!" << std::endl;
                stat.gresit();
            }
        }
        else
            if (input == "Refuza")
            {
                if (GRESELI == 1) {
                    std::cout << "Corect!" << std::endl;
                    stat.corect();

                }
                else
                {
                    std::cout<< "Gresit!" << std::endl;
                    stat.gresit();

                }
            }
         std::cout << "Scrie 'Enter' pentru a continua sau 'Exit' pentru a iesi"<<std::endl;
        getline(std::cin,input);
        while (!(input != "Enter" || input != "Exit"))
            getline(std::cin,input);
        if (input == "Exit")
            break;
    }
    operator<<(std::cout,stat);

    return 0;
}

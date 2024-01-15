#include<iostream>
using namespace std;

//domeniu: microeconomie

//afacere

//angajat

//client

class Afacere{
private:
    string nume;
    float profit; //mii de euro
    int manageri;
    static int TVA;
    const int anInfiintare;
    int* vechime; //pt manageri

public:

    //constructor fara parametri
    Afacere():anInfiintare(2000){
        this->nume = "Lolo";
        this->profit = 40;
        this->manageri = 3;
        this->vechime = new int[this->manageri];
		for (int i = 0; i < this->manageri; i++) {
			this->vechime[i] = i + 10;
		}
    }

    //constructor cu toti parametrii
    Afacere(string nume, float profit, int manageri, int* vechime, const int anInfiintare) : anInfiintare(anInfiintare){
        this->nume = nume;
        this->profit = profit;
        this->manageri = manageri;
        this->vechime = new int[this->manageri];
        for (int i=0; i < this->manageri; i++){
            this->vechime[i] = vechime[i] + 2;
        }
    }

    //constructor cu un parametru
    Afacere(int*vechime) : nume("Sumo"), profit(30), manageri(2), anInfiintare(1999){
        this->vechime = new int[this->manageri];
        for(int i=0; i < this->manageri; i++){
            this->vechime[i] = i + 15;
        }
    }

    //contructor de copiere
    Afacere(const Afacere& A1) : anInfiintare(A1.anInfiintare){
        this->nume = A1.nume;
        this->profit = A1.profit;
        this->manageri = A1.manageri;
        this->vechime = new int[manageri];
        for (int i=0; i<this->manageri; i++){
            this->vechime[i] = A1.vechime[i];
        }
    }

    void afisareFirma() {
		cout << "Nume: " << this->nume << "\nProfit: " << this->profit << "\nNumar manageri: " << this->manageri << "\nTVA: " << this->TVA << "\nAnul infiintarii: " << this->anInfiintare << "\nVechimea managerilor: ";
		for (int i = 0; i < this->manageri; i++) {
			cout << this->vechime[i] - 1 << ", ";
		}
		cout << this->vechime[this->manageri - 1] << endl;
	}
    
    //destructor
    ~Afacere() {
        if (this->vechime != NULL) {
            delete[]this->vechime;
        }
    }


    //Getters
    string getNume() {
        return this->nume;
    }

    float getProfit() {
        return this->profit;
    }

    int getManageri() {
        return this->manageri;
    }

    static int getTVA() {
        return TVA;
    }

    const int getAnInfiintare() {
        return anInfiintare;
    }

    int* getVechime() {
        return this->vechime;
    }

    //Setters
    static void setTVA(int TVAnou) {
		TVA = TVAnou;
	}

    void setNume(string numeS){
        if(numeS != " ")
            this->nume = numeS;
    }

    void setProfit(float profitS){
        if(profitS > 0)
            this->profit = profitS;
    }

    void setManageri(int manageriS){
        if(manageriS > 1)
            this->manageri = manageriS;
    }

    void setVechime (int* vechimeS){
        if(this->vechime != NULL)
            delete[]this->vechime;
        this->vechime = new int(manageri);
        for(int i=0; i<this->manageri; i++){
            if(vechimeS[i] >=1)
                this->vechime[i] = vechimeS[i];
        }
    }

    //Supraincarcare operator =
    Afacere& operator=(const Afacere& A1){
        if(this != &A1){
            this->nume = A1.nume;
            this->profit = A1.profit;
            this->manageri = A1.manageri;
            if (this->vechime != NULL){
                delete[]this->vechime;
            }
            this->vechime = new int(A1.manageri);
            for(int i=0; i<A1.manageri; i++){
                this->vechime[i] = A1.vechime[i];
            } 
        }
        return *this;
    }

};
int Afacere :: TVA = 19;

class Angajat{
private:
    string nume;
    int nrProiecte;
    float salariu; //mii de lei
    const int anAngajare;
    static int experientaMin; //necesara angajarii, in ani
    int* tasks; //pentru fiecare proiect

public:

    //constructor fara parametrii
    Angajat() : anAngajare(2005){
        this->nume = "Florin Popescu";
        this->nrProiecte = 4;
        this->salariu = 13;
        this->tasks = new int[this->nrProiecte];
        for(int i=0; i< this->nrProiecte; i++){
            this->tasks[i] = i + 5;
        }
    }

    //constructor cu toti parametrii
    Angajat(string nume, int nrProiecte, float salariu, const int anAngajare, int* tasks) : anAngajare(anAngajare){
        this->nume = nume;
        this->nrProiecte = nrProiecte;
        this->salariu = salariu;
        this->tasks = new int[this->nrProiecte];
        for (int i=0; i< this->nrProiecte; i++){
            this->tasks[i] = tasks[i] + 8;
        } 
    }

    //constructor cu un parametru
    Angajat(int* tasks) : nume("Marius Damian"), nrProiecte(3), salariu(8), anAngajare(2007){
        this->tasks = new int[this->nrProiecte];
        for(int i=0; i< this->nrProiecte; i++){
            this->tasks[i] = i + 2;
        }
    }

    //constructor de copiere
    Angajat(const Angajat& a1) : anAngajare(a1.anAngajare){
        this->nume = a1.nume;
        this->nrProiecte = a1.nrProiecte;
        this->salariu = a1.salariu;
        this->tasks = new int[nrProiecte];
        for (int i=0; i<this->nrProiecte; i++){
            this->tasks[i] = a1.tasks[i];
        }
    }

    void afisareAngajat() {
		cout << "Nume: " << this->nume << "\nNumar de proiecte: " << this->nrProiecte << "\nSalariu: " << this->salariu << "\nAnul angajarii: " << this->anAngajare << "\nExperienta minima necesara: " << this->experientaMin << "\nNumar de taskuri per proiect: ";
		for (int i = 0; i < this->nrProiecte; i++) {
			cout << this->tasks[i] - 1 << ", ";
		}
		cout << this->tasks[this->nrProiecte - 1] << endl;
	}
    
    //destructor
     ~Angajat() {
        if (this->tasks != NULL) {
            delete[]this->tasks;
        }
    }

    static void setExperienta(int experientaNoua){
        experientaMin = experientaNoua;
    }
};

int Angajat :: experientaMin = 3;

class Client{
private:
    string nume;
    int idClient;
    int nrComenzi;
    const int anDevenireClient;
    static int nrMinComenzi; //ca sa fie client
    int* produse; //in fiecare comanda

public:
    //constructor fara parametrii
    Client() : anDevenireClient(2009){
        this->nume = "Ada";
        this->idClient = 3;
        this->nrComenzi = 6;
        this->produse = new int[this->nrComenzi];
        for (int i=0; i< this->nrComenzi; i++){
            this->produse[i] = i + i + 5;
        }
    }

    //constructor cu toti parametrii
    Client(string nume, int idClient, int nrComenzi, const int anDevenireClient, int* produse) : anDevenireClient(anDevenireClient){
        this->nume = nume;
        this->idClient = idClient;
        this->nrComenzi = nrComenzi;
        this->produse = new int[this->nrComenzi];
        for(int i=0; i<this->nrComenzi; i++){
            this->produse[i] = produse[i] + 3;
        }
    }

    //constructor cu un parametru
    Client(int*produse) : nume("Mario"), idClient(9), nrComenzi(3), anDevenireClient(2022){
        this->produse = new int[this->nrComenzi];
        for(int i=0; i<this->nrComenzi; i++){
            this->produse[i] = (i + 2) * 2;
        }
    }

    //constructor de copiere
    Client(const Client& c1) : anDevenireClient(c1.anDevenireClient){
        this->nume = c1.nume;
        this->idClient = c1.idClient;
        this->nrComenzi = c1.nrComenzi;
        this->produse = new int[nrComenzi];
        for (int i=0; i<this->nrComenzi; i++){
            this->produse[i] = c1.produse[i];
        }
    }

    void afisareClient() {
		cout << "Nume: " << this->nume << "\nId-ul clientului: " << this->idClient << "\nNr de comenzi plasate: " << this->nrComenzi << "\nAnul in care a devenit client: " << this->anDevenireClient << "\nNumar de produse per comanda: ";
		for (int i = 0; i < this->nrComenzi; i++) {
			cout << this->produse[i] - 1 << ", ";
		}
		cout << this->produse[this->nrComenzi - 1] << endl;
	}

    //destructor
     ~Client() {
        if (this->produse != NULL) {
            delete[]this->produse;
        }
    }

    static void setComenzi(int nrNouComenzi){
        nrMinComenzi = nrNouComenzi;
    }
};

int Client :: nrMinComenzi = 1;

int main(){
    Afacere A1;
    int* vechime = new int[3];
    for(int i=0; i<3; i++){
        vechime[i] = i + 5;
    }
    Afacere A2("Bambo", 55, 4, vechime, 2019);
    Afacere A3(vechime);
    A1.afisareFirma(); //fara parametrii
    A2.afisareFirma(); //cu toti parametrii
    A3.afisareFirma(); //cu un parametru

    A1.setTVA(21);

    Afacere A4(A1); //constructor de copiere
    cout << "----------------"<< endl;
    A4.afisareFirma();

    //Setters Afacere
    Afacere A5;
    int* vechime2 = new int[8];
    for (int i=0; i<8; i++){
        vechime2[i] = i+100;
    }
    A5.setNume("OMV");
    A5.setProfit(12);
    A5.setTVA(6);
    A5.setManageri(8);
    A5.setVechime(vechime2);

    //Getters Afacere
    cout << "................." << endl;
    cout << "Numele afacerii este " << A5.getNume() << endl;
    cout << "Profitul afacerii este de " << A5.getProfit() << endl;
    cout << "TVA aferent: " << A5.getTVA() << endl;
    cout << "Numarul de manageri din firma este de " << A5.getManageri() << endl;
    cout << "Vechimea managerilor este de: ";
    for (int i=0; i<A5.getManageri(); i++ ){
        cout << A5.getVechime()[i] << " ";
    }
    cout << endl;

    Angajat a1;
    int* tasks = new int[6];
    for(int i=0; i<6; i++){
        tasks[i] = i + 3;
    }
    Angajat a2("Lavinia Lupu", 5, 20, 2020, tasks);
    Angajat a3(tasks);
    a1.afisareAngajat(); //fara parametrii
    a2.afisareAngajat(); //cu toti parametrii
    a3.afisareAngajat(); //cu un parametru

    a1.setExperienta(5);

    Angajat a4(a1); //constructor de copiere
    cout << "----------------"<< endl;
    a4.afisareAngajat();

    Client c1;
    int* produse = new int[3];
    for(int i=0; i<3; i++){
        produse[i] = i + 1 ;
    }
    Client c2("Mara", 2, 6, 2019, produse);
    Client c3(produse);
    c1.afisareClient(); //fara parametrii
    c2.afisareClient(); //cu toti parametrii
    c3.afisareClient(); //cu un parametru

    c1.setComenzi(2);

    Client c4(c1); //constructor de copiere
    cout << "----------------"<< endl;
    c4.afisareClient();


    //Apelare opertor = supraincarcat
    Afacere A6;
    A6 = A1;
    cout << "---------" << endl;
    A6.afisareFirma();    

return 0;
}
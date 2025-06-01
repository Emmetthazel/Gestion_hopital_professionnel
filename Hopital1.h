#ifndef HOPITAL1_H
#define HOPITAL1_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;


// Classe de base
class Prestation {
private:
    string nom;
    string departement;
    int code;
public:
    Prestation(const string& nom, const string& departement, int code) 
    : nom(nom), departement(departement), code(code) {}
    virtual ~Prestation() = default;

    virtual void afficher() const;
    virtual void saisir();

    int getCode() const { return code; }
    const string& getNom() const { return nom; }

    bool operator==(const Prestation& other) const { return code == other.code; }
    friend bool operator<(const Prestation& lhs, const Prestation& rhs) { return lhs.nom < rhs.nom; }
};



// Classe dérivée 1
class PrestationConsultation : public Prestation {
    string nomMedecin;
    string specialite;

public:
    PrestationConsultation(const string& nom, const string& departement, int code, const string& nomMedecin, const string& specialite) 
    : Prestation(nom, departement, code), nomMedecin(nomMedecin), specialite(specialite) {}
    void afficher() const override;
    void saisir() override;
};


// Classe dérivée 2
class PrestationUrgence : public Prestation {
    string typeUrgence;
    string medicamentsInjectes;

public:
    PrestationUrgence(const string& nom, const string& departement, int code, const string& typeUrgence, const string& medicamentsInjectes) 
    : Prestation(nom, departement, code), typeUrgence(typeUrgence), medicamentsInjectes(medicamentsInjectes) {}
    void afficher() const override;
    void saisir() override;
};


// Classe dérivée 3
class PrestationChirurgie : public Prestation {
    string nomChirurgien;
    int numeroSalle;

public:
    PrestationChirurgie(const string& nom, const string& departement, int code, const string& nomChirurgien, int numeroSalle) 
    : Prestation(nom, departement, code), nomChirurgien(nomChirurgien), numeroSalle(numeroSalle) {}
    void afficher() const override;
    void saisir() override;
};


// Classe dérivée 4
class PrestationAnalyse : public Prestation {
    int quantiteSang;
    string typeAnalyse;

public:
    PrestationAnalyse(const string& nom, const string& departement, int code, int quantiteSang, const string& typeAnalyse) 
    : Prestation(nom, departement, code), quantiteSang(quantiteSang), typeAnalyse(typeAnalyse) {}
    void afficher() const override;
    void saisir() override;
};


// Classe dérivée 5
class PrestationRadio : public Prestation {
    double dosageRadiation;
    string typeRadio;

public:
    PrestationRadio(const string& nom, const string& departement, int code, double dosageRadiation, const string& typeRadio) 
    : Prestation(nom, departement, code), dosageRadiation(dosageRadiation), typeRadio(typeRadio) {}
    void afficher() const override;
    void saisir() override;
};



// Classe principale
class Hopital {
    vector<Prestation*> prestations;

public:
    ~Hopital();
    void ajouterPrestation(Prestation* prestation);
    void supprimerPrestation(int code);
    void afficherPrestations() const;
    void trierPrestations();
    void sauvegarderDansFichier(const string& nomFichier) const;
    void reinitialiserBase();
    void afficherStatistiques() const;
};


#endif









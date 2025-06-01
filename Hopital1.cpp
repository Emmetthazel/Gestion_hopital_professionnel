#include "Hopital1.h"
using namespace std;

// Méthode de la classe de base Prestation
void Prestation::afficher() const {
    cout << "Nom: " << nom << ", Département: " << departement << ", Code: " << code << endl;
}

void Prestation::saisir() {
    cout << "Saisir le nom: ";
    cin.ignore();
    getline(cin, nom);
    cout << "Saisir le département: ";
    getline(cin, departement);
    cout << "Saisir le code: ";
    cin >> code;
}

// Méthode de la classe dérivée 1
void PrestationConsultation::afficher() const {
    Prestation::afficher();
    cout << "Médecin: " << nomMedecin << ", Spécialité: " << specialite << endl;
}

void PrestationConsultation::saisir() {
    Prestation::saisir();
    cout << "Saisir le nom du médecin: ";
    cin.ignore();
    getline(cin, nomMedecin);
    cout << "Saisir la spécialité: ";
    getline(cin, specialite);
}

// Méthode de la classe dérivée 2
void PrestationUrgence::afficher() const {
    Prestation::afficher();
    cout << "Type d'urgence: " << typeUrgence << ", Médicaments injectés: " << medicamentsInjectes << endl;
}

void PrestationUrgence::saisir() {
    Prestation::saisir();
    cout << "Saisir le type d'urgence: ";
    cin.ignore();
    getline(cin, typeUrgence);
    cout << "Saisir les médicaments injectés: ";
    getline(cin, medicamentsInjectes);
}

// Méthode de la classe dérivée 3
void PrestationChirurgie::afficher() const {
    Prestation::afficher();
    cout << "Chirurgien: " << nomChirurgien << ", Salle: " << numeroSalle << endl;
}

void PrestationChirurgie::saisir() {
    Prestation::saisir();
    cout << "Saisir le nom du chirurgien: ";
    cin.ignore();
    getline(cin, nomChirurgien);
    cout << "Saisir le numéro de la salle: ";
    cin >> numeroSalle;
}

// Méthode de la classe dérivée 4
void PrestationAnalyse::afficher() const {
    Prestation::afficher();
    cout << "Quantité de sang: " << quantiteSang << ", Type d'analyse: " << typeAnalyse << endl;
}

void PrestationAnalyse::saisir() {
    Prestation::saisir();
    cout << "Saisir la quantité de sang (en ml): ";
    cin >> quantiteSang;
    cout << "Saisir le type d'analyse: ";
    cin.ignore();
    getline(cin, typeAnalyse);
}

// Méthode de la classe dérivée 5
void PrestationRadio::afficher() const {
    Prestation::afficher();
    cout << "Dosage de radiation: " << dosageRadiation << ", Type de radio: " << typeRadio << endl;
}

void PrestationRadio::saisir() {
    Prestation::saisir();
    cout << "Saisir le dosage de radiation: ";
    cin >> dosageRadiation;
    cout << "Saisir le type de radio: ";
    cin.ignore();
    getline(cin, typeRadio);
}

// Méthodes de la classe principale Hopital
Hopital::~Hopital() {
    for (Prestation* prestation : prestations)
        delete prestation;
}

void Hopital::ajouterPrestation(Prestation* prestation) {
    prestations.push_back(prestation);
}

void Hopital::supprimerPrestation(int code) {
    for (auto it = prestations.begin(); it != prestations.end(); ++it) {
        if ((*it)->getCode() == code) {
            delete *it;
            prestations.erase(it);
            cout << "Prestation supprimée avec succès.\n";
            return;
        }
    }
    cout << "Code non trouvé.\n";
}

void Hopital::afficherPrestations() const {
    if (prestations.empty()) {
        cout << "Aucune prestation enregistrée.\n";
        return;
    }
    for (const Prestation* prestation : prestations) {
        prestation->afficher();
        cout << "-----------------\n";
    }
}

void Hopital::trierPrestations() {
    sort(prestations.begin(), prestations.end(), [](Prestation* a, Prestation* b) {
        return *a < *b;
    });
    cout << "Prestations triées avec succès.\n";
}

void Hopital::sauvegarderDansFichier(const string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (!fichier) {
        cout << "Erreur lors de l'ouverture du fichier.\n";
        return;
    }
    for (const Prestation* prestation : prestations) {
        fichier << prestation->getNom() << "\n";
    }
    cout << "Données sauvegardées dans le fichier " << nomFichier << " avec succès.\n";
}

void Hopital::reinitialiserBase() {
    for (Prestation* prestation : prestations)
        delete prestation;
    prestations.clear();
    cout << "Base de données réinitialisée.\n";
}

void Hopital::afficherStatistiques() const {
    int consultations = 0, urgences = 0, chirurgies = 0, analyses = 0, radios = 0;
    for (const Prestation* prestation : prestations) {
        if (dynamic_cast<const PrestationConsultation*>(prestation)) ++consultations;
        else if (dynamic_cast<const PrestationUrgence*>(prestation)) ++urgences;
        else if (dynamic_cast<const PrestationChirurgie*>(prestation)) ++chirurgies;
        else if (dynamic_cast<const PrestationAnalyse*>(prestation)) ++analyses;
        else if (dynamic_cast<const PrestationRadio*>(prestation)) ++radios;
    }
    cout << "Statistiques:\n";
    cout << "Consultations: " << consultations << "\n";
    cout << "Urgences: " << urgences << "\n";
    cout << "Chirurgies: " << chirurgies << "\n";
    cout << "Analyses: " << analyses << "\n";
    cout << "Radios: " << radios << "\n";
}

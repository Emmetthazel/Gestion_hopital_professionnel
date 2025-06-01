#include "Hopital1.h"
#include <limits> // Pour gérer les erreurs d'entrée

using namespace std;

void afficherMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Ajouter une prestation\n";
    cout << "2. Afficher toutes les prestations\n";
    cout << "3. Supprimer une prestation\n";
    cout << "4. Trier les prestations\n";
    cout << "5. Sauvegarder les prestations dans un fichier\n";
    cout << "6. Réinitialiser la base\n";
    cout << "7. Afficher les statistiques\n";
    cout << "8. Quitter\n";
    cout << "Votre choix : ";
}

Prestation* creerPrestation() {
    int choix;
    cout << "\nType de prestation à ajouter :\n";
    cout << "1. Consultation\n";
    cout << "2. Urgence\n";
    cout << "3. Chirurgie\n";
    cout << "4. Analyse biologique\n";
    cout << "5. Radio\n";
    cout << "Votre choix : ";
    cin >> choix;

    string nom, departement;
    int code;

    cout << "Nom de la prestation : ";
    cin.ignore();
    getline(cin, nom);
    cout << "Département : ";
    getline(cin, departement);
    cout << "Code : ";
    cin >> code;

    switch (choix) {
        case 1: {
            string nomMedecin, specialite;
            cout << "Nom du médecin : ";
            cin.ignore();
            getline(cin, nomMedecin);
            cout << "Spécialité : ";
            getline(cin, specialite);
            return new PrestationConsultation(nom, departement, code, nomMedecin, specialite);
        }
        case 2: {
            string typeUrgence, medicamentsInjectes;
            cout << "Type d'urgence : ";
            cin.ignore();
            getline(cin, typeUrgence);
            cout << "Médicaments injectés : ";
            getline(cin, medicamentsInjectes);
            return new PrestationUrgence(nom, departement, code, typeUrgence, medicamentsInjectes);
        }
        case 3: {
            string nomChirurgien;
            int numeroSalle;
            cout << "Nom du chirurgien : ";
            cin.ignore();
            getline(cin, nomChirurgien);
            cout << "Numéro de la salle : ";
            cin >> numeroSalle;
            return new PrestationChirurgie(nom, departement, code, nomChirurgien, numeroSalle);
        }
        case 4: {
            int quantiteSang;
            string typeAnalyse;
            cout << "Quantité de sang (en ml) : ";
            cin >> quantiteSang;
            cout << "Type d'analyse : ";
            cin.ignore();
            getline(cin, typeAnalyse);
            return new PrestationAnalyse(nom, departement, code, quantiteSang, typeAnalyse);
        }
        case 5: {
            double dosageRadiation;
            string typeRadio;
            cout << "Dosage de radiation : ";
            cin >> dosageRadiation;
            cout << "Type de radio : ";
            cin.ignore();
            getline(cin, typeRadio);
            return new PrestationRadio(nom, departement, code, dosageRadiation, typeRadio);
        }
        default:
            cout << "Choix invalide. Aucune prestation créée.\n";
            return nullptr;
    }
}

int main() {
    Hopital hopital;
    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
            case 1: {
                Prestation* prestation = creerPrestation();
                if (prestation) {
                    hopital.ajouterPrestation(prestation);
                    cout << "Prestation ajoutée avec succès !\n";
                }
                break;
            }
            case 2:
                cout << "\nListe des prestations :\n";
                hopital.afficherPrestations();
                break;
            case 3: {
                int code;
                cout << "Entrez le code de la prestation à supprimer : ";
                cin >> code;
                hopital.supprimerPrestation(code);
                break;
            }
            case 4:
                hopital.trierPrestations();
                cout << "Prestations triées avec succès !\n";
                break;
            case 5: {
                string nomFichier;
                cout << "Entrez le nom du fichier : ";
                cin >> nomFichier;
                hopital.sauvegarderDansFichier(nomFichier);
                cout << "Prestations sauvegardées dans le fichier " << nomFichier << " avec succès !\n";
                break;
            }
            case 6:
                hopital.reinitialiserBase();
                cout << "Base de données réinitialisée avec succès !\n";
                break;
            case 7:
                hopital.afficherStatistiques();
                break;
            case 8:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }

        // Gestion des erreurs d'entrée
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Erreur d'entrée. Veuillez réessayer.\n";
        }
    } while (choix != 8);

    return 0;
}

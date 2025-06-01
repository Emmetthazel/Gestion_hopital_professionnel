
# 🏥 Cahier des charges

## 🎯 Projet : Système de gestion d’un hôpital

### 🎯 Objectif

Développer un système de gestion en C++ qui permet de gérer les prestations offertes par un hôpital, notamment :

- Consultation
- Urgence
- Chirurgie
- Analyse biologique
- Radiologie

Le système doit permettre :

- l’ajout de prestations
- la suppression d’une prestation
- l’affichage des détails de toutes les prestations

---

## 🧱 Classes identifiées

### 1. Classe `Prestation` (classe de base)

**Attributs communs :**

- `std::string nom` : nom de la prestation
- `std::string departement` : département concerné
- `int code` : code unique de la prestation

**Méthodes :**

- Constructeur de base
- Méthodes virtuelles pour affichage (`virtual void afficher() const;`)
- Getters / Setters de base

---

### 2. Classes dérivées de `Prestation`

#### a. `PrestationConsultation`

- `std::string nomMedecin`
- `std::string specialite`

#### b. `PrestationUrgence`

- `std::string typeUrgence`
- `std::vector<std::string> medicamentsInjectes`

#### c. `PrestationChirurgie`

- `std::string nomChirurgien`
- `int numeroSalle`

#### d. `PrestationAnalyse`

- `float quantiteSang`
- `std::string typeAnalyse`

#### e. `PrestationRadio`

- `float dosageRadiation`
- `std::string typeRadio`

---

### 3. Classe `Hopital`

**Attributs :**

- `std::vector<Prestation*> prestations;`

**Méthodes :**

- `void ajouterPrestation(Prestation* prestation);`
- `void supprimerPrestation(int code);`
- `void afficherPrestations() const;`
- Destructeur pour libérer la mémoire

---

## 🔧 Travail demandé dans `main()`

1. Créer un objet `Hopital`
2. Ajouter plusieurs prestations (tous types confondus)
3. Supprimer une prestation par son code
4. Afficher toutes les prestations existantes

---

Souhaites-tu que je t’aide maintenant à créer les fichiers `.h` / `.cpp` correspondants pour ce projet ?

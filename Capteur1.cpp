/*
  Titre      : Titre du programme
  Auteur     : Boladji ODELOUI
  Date       : 17/01/2025
  Description: Créer un système de surveillance de capteur
  Version    : 0.0.1
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*+-----------------------+
|       **Capteur1**    |
+-----------------------+
| - Capteurid: int     |
| - typeCapteur: string|
| - valeur: float      |
| + Capteur(my_id, nameCapteur)|
| + setCapteurId(id)   |
| + setTypeCapteur(type)|
| + setVal(my_value)|
| + getCapteurId()     |
| + getCapteurType()   |
| + getVal()|
+-----------------------+

+-----------------------+
|  **ManageCaptors**  |
+-----------------------+
| - nbrCaptors:    |
|   vector<Capteur1*>  |
| + ManageCaptors()  |
| + add_captors(id) |
| + delete_captors(id)|
| + print_captors() |
| + compare_captors(obj1, obj2)|
+-----------------------+*/

class Capteur1
{
private:
    int capteurId;
    string typeCapteur;
    float val;

public:
    // Constructeur
    Capteur1(int my_Id, string nameCapteur) : capteurId(my_Id), typeCapteur(nameCapteur), val(0.0)
    {
    }

    // Destructeur
    ~Capteur1()
    {
        cout << "Les capteurs ne fournissent pas de données" << endl;
    }

    // Setter
    void setCapteurId(int my_Id)
    {
        capteurId = my_Id;
    }

    void settypeCapteur(string nameCapteur)
    {
        typeCapteur = nameCapteur;
    }

    void setVal(float my_value)
    {
        val = my_value;
    }

    // Getter

    int getCapteurId() const
    {
        return (capteurId);
    }

    string getTypeCapteur() const
    {
        return (typeCapteur);
    }

    float getVal() const
    {
        return (val);
    }

    // Operateur de flux

    friend ostream &operator<<(ostream &os, const Capteur1 obj)
    {
        os << "Capteur" << obj.capteurId << "Type" << obj.typeCapteur << "Valeur" << obj.val << endl;
        return (os);
    }

    // Operateur de comparaison

    friend bool operator==(const Capteur1 &obj1, const Capteur1 &obj2)
    {
        return (obj1.capteurId == obj2.capteurId && obj1.typeCapteur == obj2.typeCapteur);
    }
};

class ManageCaptors
{
private:
    vector<Capteur1 *> nbrCapteurs;

public:
    ManageCaptors()
    {
    }
    ~ManageCaptors()
    {
    }

    // fonction pour ajouter des capteurs à liste

    int add_captors(Capteur1 *obj)
    {
        nbrCapteurs.push_back(obj);
        return (0);
    }

    // fonction pour supprimer un capteur de la liste par son identifiant

    int delete_captors(int id)
    {
        for (auto i = nbrCapteurs.begin(); i < nbrCapteurs.end(); ++i)
        {
            if ((*i)->getCapteurId() == id)
            {
                delete (*i);
                nbrCapteurs.erase(i);
                break;
            }
        }
        return (0);
    }

    // Fonction pour afficher la liste des capteurs

    int print_captors() const
    {
        for (const auto &captors : nbrCapteurs)
        {
            cout << "Voici la liste des capteurs" << *captors << endl;
        }
        return (0);
    }

    // Fonction pour comparer les capteurs
    bool compare_captors(const Capteur1 &obj1, const Capteur1 &obj2) const
    {
        return (obj1 == obj2);
    }
};

int main()
{
    ManageCaptors managecap;

    // Création des capteurs
    Capteur1 *cap1 = new Capteur1(1, "Humidité");
    Capteur1 *cap2 = new Capteur1(1, "Température");

    cap1->setVal(25.00);
    cap2->setVal(35.00);

    managecap.add_captors(cap1);
    managecap.add_captors(cap2);

    managecap.print_captors();
    bool comp = managecap.compare_captors(*cap1, *cap2);
    if (comp == true)
    {
        cout << "Les capteurs sont égaux" << endl;
    }
    else
    {
        cout << "Les capteurs sont différents" << endl;
    }

    managecap.delete_captors(1);
    managecap.print_captors();
    managecap.delete_captors(2);
    managecap.print_captors();
    return (0);
}
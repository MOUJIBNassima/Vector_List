#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;

const int N = 50000;

/// Afficher les temps d'execution
void afficherTemps(const string& operation,
                   double tempsVector,
                   double tempsList)
{
    cout << "\n--- " << operation << " ---\n";
    cout << "vector : " << tempsVector << " ms\n";
    cout << "list   : " << tempsList << " ms\n";
}

/// 1. Insertion a la fin
void insertionFin()
{
    vector<int> v;
    list<int> l;

    auto debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        v.push_back(i);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        l.push_back(i);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Insertion a la fin", tv, tl);
}

/// 2. Insertion au debut
void insertionDebut()
{
    vector<int> v;
    list<int> l;

    auto debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        v.insert(v.begin(), i);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        l.push_front(i);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Insertion au debut", tv, tl);
}

/// 3. Insertion au milieu
void insertionMilieu()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    auto debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        v.insert(v.begin() + v.size() / 2, i);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        auto it = l.begin();
        advance(it, l.size() / 2);
        l.insert(it, i);
    }
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Insertion au milieu", tv, tl);
}

/// 4. Recherche d'une valeur
void recherche()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    int valeur = N / 2;

    auto debut = high_resolution_clock::now();
    auto itV = find(v.begin(), v.end(), valeur);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    auto itL = find(l.begin(), l.end(), valeur);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Recherche d'une valeur", tv, tl);

    cout << "Valeur recherchee : " << valeur << '\n';
    cout << "vector : " << (itV != v.end() ? "Trouvee" : "Non trouvee") << '\n';
    cout << "list   : " << (itL != l.end() ? "Trouvee" : "Non trouvee") << '\n';
}

/// 5. Suppression au debut
void suppressionDebut()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    auto debut = high_resolution_clock::now();
    v.erase(v.begin());
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    l.pop_front();
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Suppression au debut", tv, tl);
}

/// 6. Suppression a la fin
void suppressionFin()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    auto debut = high_resolution_clock::now();
    v.pop_back();
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    l.pop_back();
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Suppression a la fin", tv, tl);
}

/// 7. Suppression au milieu
void suppressionMilieu()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    auto debut = high_resolution_clock::now();
    v.erase(v.begin() + v.size() / 2);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    auto it = l.begin();
    advance(it, l.size() / 2);
    l.erase(it);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Suppression au milieu", tv, tl);
}

/// 8. Recherche puis suppression d'une valeur
void suppressionParValeur()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    int valeur = N / 2;

    auto debut = high_resolution_clock::now();
    auto itV = find(v.begin(), v.end(), valeur);
    if (itV != v.end())
        v.erase(itV);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    auto itL = find(l.begin(), l.end(), valeur);
    if (itL != l.end())
        l.erase(itL);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Recherche et suppression par valeur", tv, tl);
}

/// 9. Suppression avec resize()
void suppressionResize()
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    int nouvelleTaille = N / 2;

    auto debut = high_resolution_clock::now();
    v.resize(nouvelleTaille);
    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    debut = high_resolution_clock::now();
    l.resize(nouvelleTaille);
    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Suppression avec resize()", tv, tl);

    cout << "Nouvelle taille du vector : " << v.size() << '\n';
    cout << "Nouvelle taille de la list   : " << l.size() << '\n';
}

/// 10. Modification d'une valeur
void modification()
{
    vector<int> v;
    list<int> l;

    /// Remplissage des deux structures
    for (int i = 0; i < N; i++) {
        v.push_back(i);
        l.push_back(i);
    }

    int valeur = N / 2;  /// Valeur a modifier : 25000
    int nouvelleValeur = 99999;

    /// Modification dans le vector
    auto debut = high_resolution_clock::now();

    auto itV = find(v.begin(), v.end(), valeur);
    if (itV != v.end())
        *itV = nouvelleValeur;

    auto fin = high_resolution_clock::now();
    double tv = duration<double, milli>(fin - debut).count();

    /// Modification dans la list
    debut = high_resolution_clock::now();

    auto itL = find(l.begin(), l.end(), valeur);
    if (itL != l.end())
        *itL = nouvelleValeur;

    fin = high_resolution_clock::now();
    double tl = duration<double, milli>(fin - debut).count();

    afficherTemps("Modification d'une valeur", tv, tl);

    cout << "Ancienne valeur : " << valeur << '\n';
    cout << "Nouvelle valeur : " << nouvelleValeur << '\n';
}

int main()
{
    cout << fixed << setprecision(4);

    cout << "========================================\n";
    cout << " COMPARAISON ENTRE VECTOR ET LIST\n";
    cout << " Nombre d'elements : " << N << '\n';
    cout << "========================================\n";

    /// Tests d'insertion
    insertionFin();
    insertionDebut();
    insertionMilieu();

    /// Test de recherche
    recherche();

    /// Test de modification
    modification();

    /// Tests de suppression
    suppressionDebut();
    suppressionFin();
    suppressionMilieu();
    suppressionParValeur();
    suppressionResize();

    cout << "\n========================================\n";
    cout << " FIN DES TESTS\n";
    cout << "========================================\n";

    return 0;
}

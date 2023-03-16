#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class Atom {

public:
    const double proton_mass = 1.0073;
    const double neutron_mass = 1.0087;
    const double electron_mass = 0.00054858;
    int protons, neutrons, electrons, atomic_number;
    string type;

public:
    Atom(int p_num, int n_num, int e_num, int atomic_number, string type) :
        protons(p_num), neutrons(n_num), electrons(e_num), atomic_number(atomic_number), type(type) {}


    double get_mass() {
        return ((protons * proton_mass) + (neutrons * neutron_mass) + (electrons * electron_mass));
    }

    int get_protons() {
        return protons;
    }

    int get_neutrons() {
        return neutrons;
    }

    int get_electrons() {
        return electrons;
    }

    int get_atomic_number() {
        return atomic_number;
    }

    string get_type() {
        return type;
    }
};

class Molecule {

public:
    vector<Atom> atoms;
    vector<vector<double>> bond_energy_matrix;

public:
    Molecule(vector<Atom> atoms, vector<vector<double>> bond_energies) :
        atoms(atoms), bond_energy_matrix(bond_energies) {}


    vector<Atom> get_atoms() {
        return atoms;
    }

    double get_total_energy() {
        double total_energy = 0.0;
        for (int i = 0; i < atoms.size(); ++i) {
            for (int j = i + 1; j < atoms.size(); ++j) {
                total_energy += bond_energy_matrix[i][j];
            }
        }
        return total_energy;
    }


    double get_total_mass() {
        double mass = 0.0;
        for (Atom& atom : atoms) {
            mass += atom.get_mass();
        }
        return mass;
    }


    int get_num_bonds() {
        int count = 0;
        for (int i = 0; i < atoms.size(); ++i) {
            for (int j = i + 1; j < atoms.size(); ++j) {
                if (bond_energy_matrix[i][j] > 0.0) {
                    count += 1;
                }
            }
        }
        return count;
    }


    int get_num_atoms_of_type(string type) {
        int count = 0;
        for (Atom& atom : atoms) {
            if (type == atom.get_type()) {
                count += 1;
            }
        }
        return count;
    }
};


int main(int argc, char** argv) {
    cout << "Hello World!\n";
    cout << "Hello World!\n";
    Atom atom1(1, 2, 6, 51, "oxygen");
    Atom atom2(4, 7, 17, 82, "hydrogen");
    Atom atom3(3, 10, 8, 67, "iron");
    Atom atom4(9, 10, 2, 125, "oxygen");
    string type = "oxygen";
    vector<Atom> atoms = { atom1, atom2, atom3, atom4};
    vector<vector<double>> bond_energies{{0.0, 2.1, 1.1, 1.1}, 
                                          {2.1, 0.0, 1.1, 1.1}, 
                                          {1.1, 1.1, 0.0, 1.1}, 
                                          {1.1, 1.1, 7.2, 0.0} };
    Molecule molecule(atoms, bond_energies);
    cout << "Кол-во связей в молекуле: " << molecule.get_num_bonds();
    cout << "\nКол-во атомов типа " << type << ":" << molecule.get_num_atoms_of_type(type);
    cout << "\nМасса молекулы: " << molecule.get_total_mass();
    cout << "\nСуммарная энергия взаимодействия атомов: " << molecule.get_total_energy();

    for (Atom& mass : molecule.get_atoms()) {
        cout << "\nСуммарная масса нуклонов и электронов атома " << mass.get_type() << " : " << mass.get_mass();
    }

    cout << "\nCуммарная масса нуклонов и электронов: " << atom1.get_mass();

}



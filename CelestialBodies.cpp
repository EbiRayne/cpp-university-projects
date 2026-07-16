#include <iostream>
#include <string>
using namespace std;

class Explorer {
    public :
    virtual void explore () = 0;
    virtual ~Explorer () = default;
};

class CelestialBody {
    protected : 
    string name;
    double equator;
    public :
    CelestialBody (string name, double equator) : name (name), equator (equator) {}
    
};

class Planet {
    protected :
    double distanceToSun;
    double gravity;
    bool waterOnSurface;
    public :
    Planet (double distanceToSun, double gravity, bool waterOnSurface) 
        : distanceToSun (distanceToSun), gravity (gravity), waterOnSurface (waterOnSurface) {}
};

class GasGiant : public CelestialBody, public Planet, public Explorer {
    protected :
    string dominantGas;
    string planetType;
    public :
    GasGiant (string name, double equator, double distanceToSun, double gravity, bool waterOnSurface, string dominantGas, string planetType) : 
        CelestialBody (name, equator), 
        Planet (distanceToSun, gravity, waterOnSurface), 
        dominantGas (dominantGas), planetType (planetType) {}
    void explore () override {
        cout << "---- EXPLORING THE PLANET ----" << '\n'
             << "Planet Name:" << name <<'\n'
             << "Equator: " << equator << " km" << '\n'
             << "Distance to the sun: " << distanceToSun << " km" << '\n'
             << "Force of gravity: " << gravity << "G (times the force in earth)" <<'\n'
             << "Water on surface? " << waterOnSurface <<'\n'
             << "Dominant Gas: " << dominantGas << '\n'
             << "Planet Type: " << planetType << '\n';
    }
};

class RockyPlanet : public CelestialBody, public Planet, public Explorer {
    protected :
    string dominantElement;
    string core;
    public :
    RockyPlanet (string name, double equator, double distanceToSun, double gravity, bool waterOnSurface, string dominantElement, string core) : 
        CelestialBody (name, equator), 
        Planet (distanceToSun, gravity, waterOnSurface),
        dominantElement (dominantElement), core (core) {}
    void explore () override {
        cout << "\n---- EXPLORING THE PLANET ----" << '\n'
             << "Planet Name:" << name <<'\n'
             << "Equator: " << equator << " km" << '\n'
             << "Distance to the sun: " << distanceToSun << " km" << '\n'
             << "Force of gravity: " << gravity << "G (times the force in earth)" <<'\n'
             << "Water on surface? " << waterOnSurface <<'\n'
             << "Dominant Element: " << dominantElement << '\n'
             << "Core made of: " << core << '\n';
    }
};

class GasRingPlanet : public GasGiant {
    protected :
    int ringNumber;
    public :
    GasRingPlanet (string name, double equator, double distanceToSun, double gravity, bool waterOnSurface, string dominantGas, string planetType, int ringNumber) :
        GasGiant (name, equator, distanceToSun, gravity, waterOnSurface, dominantGas, planetType),
        ringNumber (ringNumber) {}
        void explore () override {
        cout << "\n---- EXPLORING THE PLANET ----" << '\n'
             << "Planet Name:" << name <<'\n'
             << "Equator: " << equator << " km" << '\n'
             << "Distance to the sun: " << distanceToSun << " km" << '\n'
             << "Force of gravity: " << gravity << "G (times the force in earth)" <<'\n'
             << "Water on surface? " << waterOnSurface <<'\n'
             << "Dominant Gas: " << dominantGas << '\n'
             << "Planet Type: " << planetType << '\n'
             << "Number of rings: " << ringNumber << '\n';
            
        }

};

int main () {
    GasGiant * gasGiant = new GasGiant ("Neptune", 49528, 4500000000, 1.14, true, "hydrogen/helium", "ice giant");
    RockyPlanet * rockyPlanet = new RockyPlanet ("Earth", 12756, 150000000, 1, true, "iron", "iron-nickel alloy");
    GasRingPlanet * gasRingPlanet = new GasRingPlanet ("Saturn", 120536, 1430000000, 1.065, true, "hydorgen/helium", "gas giant", 1000);
    
    gasGiant->explore(); 
    rockyPlanet->explore();
    gasRingPlanet->explore();
    
    delete gasGiant;
    delete rockyPlanet;
    delete gasRingPlanet;
    return 0;
}
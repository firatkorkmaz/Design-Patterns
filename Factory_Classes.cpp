/* Factory Example-3 */

#include <iostream>
#include <cstring>
using namespace std;


// Abstract Base Class: Interface
class Animal {
public:
    virtual void speak() = 0;
    virtual void setVoice(string) = 0;
    virtual ~Animal(){}
};


class Bird : public Animal {
protected:
    string voice;

public:
    Bird():voice("Chirp!"){};   // Default Voice from Constructor

    void setVoice(string voice){          // Voice Updater Method
        this->voice = voice;
    }

    void speak() {
        cout << "Bird: " << this->voice << endl;
    }
};


class Cat : public Animal {
protected:
    string voice;

public:
    Cat():voice("Meow!"){};     // Default Voice from Constructor

    void setVoice(string voice){          // Voice Updater Method
        this->voice = voice;
    }

    void speak() {
        cout << "Cat: " << this->voice << endl;
    }
};


class Dog : public Animal {
protected:
    string voice;

public:
    Dog():voice("Woof!"){};     // Default Voice from Constructor

    void setVoice(string voice){          // Voice Updater Method
        this->voice = voice;
    }

    void speak() {
        cout << "Dog: " << this->voice << endl;
    }
};

/////////////////////////////////////////////////////////////////

// Abstract Base Class: Interface
class AnimalFactory {
public:
    virtual Animal *newAnimal(string type) = 0;
    virtual ~AnimalFactory() {}
};


// Factory Class for Aerial Animals
class aerialAnimals : public AnimalFactory {
public:
    Animal *newAnimal(string type){
        if(strcmpi(type.c_str(), "Bird") == 0)
            return new Bird();

        else{
            throw runtime_error(type + " does Not Exist in the Factory!");
            return nullptr;
        }
    }
};


// Factory Class for Terrestrial Animals
class terrestrialAnimals : public AnimalFactory {
public:
    Animal *newAnimal(string type){
        if(strcmpi(type.c_str(), "Cat") == 0)
            return new Cat();

        else if(strcmpi(type.c_str(), "Dog") == 0)
            return new Dog();

        else{
            throw runtime_error(type + " does Not Exist in the Factory!");
            return nullptr;
        }
    }
};



int main() {

    AnimalFactory *aerialFactory = new aerialAnimals;

    Animal *bird = aerialFactory->newAnimal("Bird");
    bird->speak();
    bird->setVoice("Chirp Chirp!");      // Update Voice of the Bird
    bird->speak();
    cout << endl;
    delete bird;

    delete aerialFactory;


    AnimalFactory *terrestrialFactory = new terrestrialAnimals;

    Animal *cat = terrestrialFactory->newAnimal("CAT");
    cat->speak();
    cat->setVoice("Meow Meow!");         // Update Voice of the Cat
    cat->speak();
    cout << endl;
    delete cat;

	Animal *dog = terrestrialFactory->newAnimal("dog");
    dog->speak();
    dog->setVoice("Woof Woof!");         // Update Voice of the Dog
    dog->speak();
    cout << endl;
    delete dog;

    delete terrestrialFactory;


cout << endl << "-------------" << endl;
system("pause");
return 0;
}

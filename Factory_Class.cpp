/* Factory Example-2 */

#include <iostream>
#include <cstring>
using namespace std;


// Base Abstract Class: Interface
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

// Factory Class
class AnimalFactory{
public:
    Animal *newAnimal(string type){
        if(strcmpi(type.c_str(), "Bird") == 0)
            return new Bird();

        else if(strcmpi(type.c_str(), "Cat") == 0)
            return new Cat();

        else if(strcmpi(type.c_str(), "Dog") == 0)
            return new Dog();

        else{
            throw runtime_error(type + " does Not Exist in the Factory!");
            return nullptr;
        }
    }
    virtual ~AnimalFactory(){}
};



int main() {

    AnimalFactory *factory = new AnimalFactory;

    Animal *bird = factory->newAnimal("Bird");
    bird->speak();
    bird->setVoice("Chirp Chirp!");      // Update Voice of the Bird
    bird->speak();
    cout << endl;
    delete bird;

    Animal *cat = factory->newAnimal("CAT");
    cat->speak();
    cat->setVoice("Meow Meow!");         // Update Voice of the Cat
    cat->speak();
    cout << endl;
    delete cat;

	Animal *dog = factory->newAnimal("dog");
    dog->speak();
    dog->setVoice("Woof Woof!");         // Update Voice of the Dog
    dog->speak();
    cout << endl;
    delete dog;

    delete factory;


cout << endl << "-------------" << endl;
system("pause");
return 0;
}

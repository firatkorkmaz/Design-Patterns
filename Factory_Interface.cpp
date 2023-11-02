/* Factory Example-1 */

#include <iostream>
#include <cstring>
using namespace std;


// Base Abstract Class: Interface
class Animal {
public:
    virtual void speak() = 0;
    virtual void setVoice(string) = 0;
    static Animal *newAnimal(string type);		// Factory Method
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

// Factory Method from Interface
Animal *Animal::newAnimal(string type){
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



int main() {

	Animal *bird = Animal::newAnimal("Bird");
    bird->speak();
    bird->setVoice("Chirp Chirp!");      // Update Voice of the Bird
    bird->speak();
    cout << endl;
    delete bird;

    Animal *cat = Animal::newAnimal("CAT");
    cat->speak();
    cat->setVoice("Meow Meow!");         // Update Voice of the Cat
    cat->speak();
    cout << endl;
    delete cat;

    Animal *dog = Animal::newAnimal("dog");
    dog->speak();
    dog->setVoice("Woof Woof!");         // Update Voice of the Dog
    dog->speak();
    cout << endl;
    delete dog;


cout << endl << "-------------" << endl;
system("pause");
return 0;
}

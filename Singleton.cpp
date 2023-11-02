/* Singleton Example */

#include <iostream>
using namespace std;


class Singleton{
private:
    int data;
    static Singleton *instance;
    Singleton(){data = 0;}                      // Private Constructor Prevents New Object Creation

public:
    static Singleton *getInstance(){            // In the First Call to getInstance()
        if(instance == 0)                       // If the Instance Pointer is Set to Zero
            instance = new Singleton();         // Initialize the Singleton
        return instance;
    }

    void setData(int data){
        this->data = data;
    }

    int getData() {
        return this->data;
    }
};

Singleton *Singleton::instance = 0;             // Set the Singleton Instance Pointer to Zero


int main(){

    Singleton *s1 = Singleton::getInstance();   // Singleton *s1 = s1->getInstance();
	//Singleton *s2 = new Singleton();          // Error: Private Constructor
	Singleton *s2 = Singleton::getInstance();   // Singleton *s2 = s2->getInstance();

    cout << "s1 and s2 are Initialized:\n" << endl;
    cout << "s1 address: " << s1 << '\n';
    cout << "s2 address: " << s2 << '\n';
    cout << endl;

    cout << "Current s1 and s2 Data" << endl;
    cout << "s1->data: " << s1->getData() << '\n';
    cout << "s2->data: " << s2->getData() << '\n';
    cout << endl;

    s1->setData(100);
    cout << "s1->setData(100)" << endl;
    cout << "Current s1 and s2 Data" << endl;
    cout << "s1->data: " << s1->getData() << '\n';
    cout << "s2->data: " << s2->getData() << '\n';
    cout << endl;

    s2->setData(200);
    cout << "s2->setData(200)" << endl;
    cout << "Current s1 and s2 Data" << endl;
    cout << "s1->data: " << s1->getData() << '\n';
    cout << "s2->data: " << s2->getData() << '\n';
    cout << endl;


cout << endl << "-------------" << endl;
system("pause");
return 0;
}

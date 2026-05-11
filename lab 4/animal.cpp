#include <iostream>

class Animal
{
    std::string tail;
    int paws;
    std::string voice;

public:
    int SetTail (std::string tail_type)
    {
        tail = tail_type;
        return 1;
    };

    int SetPaws (int number_of_paws)
    {
        paws = number_of_paws;
        return 1;
    };

    int SetVoice (std::string animal_voice)
    {
        voice = animal_voice;
        return 1;
    };

    int Say ()
    {
        std::cout << "иофтдфд";
        return 1;
    };

protected:
    int CreateAnimal()
    {
        std::cout << "Має " << paws << " лапи та " << tail << ". \n Говорить " << voice << " голосом: ";
        return 1;
    };
};

class Cat : Animal
{
public:
    Cat()
    {
        int e = SetPaws(4);
        e = SetTail("хвіст");
        e = SetVoice("няшним");
        e = CreateAnimal();
        e = Say();
    };

    int Say ()
    {
        std::cout << "М-р-р-р... Мяу-мяу";
        return 1;
    };
};

class Dog : Animal
{
public:
    Dog()
    {
        int e = SetPaws(4);
        e = SetTail("обкусаний хвіст");
        e = SetVoice("грубим");
        e = CreateAnimal();
        e = Say();
    };

    int Say ()
    {
        std::cout << "Гав... Гррр-р-гав";
        return 1;
    };
};

class HighbredCat : Cat
{
protected:
    std::string breed;

public:
    int SetBreed (std::string cats_breed)
    {
        breed = cats_breed;
        return 1;
    };

    HighbredCat (std::string cats_breed)
    {
        int e =  SetBreed (cats_breed);
        std::cout <<"\n Порода кота " << breed;
    }
    HighbredCat(){}
};

class HomeCat: HighbredCat
{
    std::string name;
    std::string colour;

public:
    int SetName (std::string cats_name)
    {
        name = cats_name;
        return 1;
    };

    int SetColour (std::string color)
    {
        colour = color;
        return 1;
    };

    HomeCat (std::string cats_breed, std::string cats_name, std::string color)
    {
        int e =  SetBreed (cats_breed);
        e =  SetColour (color);
        e =  SetName (cats_name);
        std::cout <<"\n То "<< colour << " кіт " << breed << ". Відкликається, коли кличиш " << name;
    }
};

int main()
{
    HomeCat *my_pet = new HomeCat("дворняга", "Вася", "рижий");
}
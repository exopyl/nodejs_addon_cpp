#include <string>

class IAnimal
{
public:
    virtual ~IAnimal();

    virtual const std::string Speak() const = 0;
};

class CDog : public IAnimal
{
public:
    ~CDog();

    const std::string Speak() const;
};

class CCat : public IAnimal
{
public:
    ~CCat();

    const std::string Speak() const;
};

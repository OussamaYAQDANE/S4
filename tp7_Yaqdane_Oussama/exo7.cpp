#include <iostream>


namespace me
{
template<typename T>
class shared_ptr
{
private:
    T* data;
    int* ref_count;

    template<typename... Args>
    explicit shared_ptr(Args&&... args): data(new T(std::forward<Args>(args)...)), ref_count(new int(1)) {};

    template<typename U, typename... Args>
    friend shared_ptr<U> make_shared(Args&&... args);
    
public:

    shared_ptr() : data(nullptr), ref_count(nullptr){};

    shared_ptr(const shared_ptr<T>& other) 
    : data(other.data), ref_count(other.ref_count) 
    {
        (*ref_count)++;
    }

    shared_ptr<T>& operator=(const shared_ptr<T>& other){
        if (this != &other){
            if (data && ref_count)
            {
                (*ref_count)--;
                if (*ref_count == 0)
                {
                    delete ref_count;
                    delete data;
                }
            }
            

            this->data = other.data;
            this->ref_count = other.ref_count;
            (*ref_count)++;
        }
        return *this;
    }

    T& operator*() const
    {
        return *data;
    }

    int use_count() const
    {
        return *ref_count;
    }

    T* operator->() const
    {
        return data;
    }
   
    ~shared_ptr()
    {
        std::cout << "A shared_ptr went out of scope." << std::endl;
        if (data && ref_count)
        {
            (*ref_count)--;
            if (*ref_count == 0) {delete data; delete ref_count;};  
        }
    }
    
        
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args) 
{
    return shared_ptr<T>(std::forward<Args>(args)...);
}
};



class Person{
public:
    std::string name;
    int age;


    Person(std::string name, int age): name(name), age(age)
    {
        std::cout << "Person " << name << " was born." << std::endl;
    }
    ~Person()
    {
        std::cout << "Person " << name << " died" << std::endl;
    }
};


int main()
{
    me::shared_ptr<Person> x = me::make_shared<Person>("Oussama", 19);
    std::cout << "References count: " << x.use_count() << std::endl;

    {   
        std::cout << "Creating a shared_ptr on the object" << std::endl;
        me::shared_ptr<Person> y = x;
        std::cout << "References count: " << x.use_count() << std::endl;
    }
    std::cout << "References count: " << x.use_count() << std::endl;

};




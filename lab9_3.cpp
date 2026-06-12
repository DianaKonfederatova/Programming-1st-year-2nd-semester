#include <iostream>
#include <string>

struct Student {
    std::string surname;
    int grades[4]; 
};

int hash_function(std::string surname){
    int sum = 0;

    for(char c : surname){
        sum += static_cast<int>(c);
    }

    int ostatok = sum % 17;

    return ostatok;
}

int main(){


}
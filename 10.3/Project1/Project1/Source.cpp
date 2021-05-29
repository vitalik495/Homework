#include <iostream> 
#include <string>
#include <fstream> 

int main()
{
    std::string surname;
    int mark1;
    int mark2;
    int mark3;
    int i;

        std::ofstream outfile("name.txt");



    for (i = 0; i < 2; i++)
    {
        std::cout << "Inter surname " << std::endl;
        getline(std::cin, surname);
        std::cout << "Inter a first mark " << std::endl;
        std::cin >> mark1;
        std::cout << "Inter a second mark  " << std::endl;
        std::cin >> mark2;
        std::cout << "Inter a third mark  " << std::endl;
        std::cin >> mark3;
        std::cin.ignore(1);
        outfile << surname << " " << mark1 << " " << mark2 << " " << mark3 << " " << std::endl;
    }

    std::ifstream infile("name.txt");

    if (!infile.is_open())
        std::cout << "Error " << std::endl;
    else
    {

        while (infile >> surname >> mark1 >> mark2 >> mark3)
            std::cout << surname << " " << mark1 << " " << mark2 << " " << mark3 << " " << std::endl;
    }
}
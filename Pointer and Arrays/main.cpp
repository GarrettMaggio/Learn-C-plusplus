#include <iostream>
#include <cstring>

using namespace std;

// Function prototypes
void rev(char[], int);

int main()
{
    // Local variables
    const int Fsize = 100, Nsize = 50, Modsize = 12000;
    char fullname[Fsize], nickName[Nsize], namemodded[Modsize];
    char again = 'y';
    int finder;

    // do-while loop for the entire program
    do
    {
        cout << "Enter your first and last name: " << endl;
        cin.getline(fullname, Fsize);

        cout << "Enter your nickname: " << endl;
        cin >> nickName;

        char* firstName = fullname;
        char* lastname = nullptr;
        char* spacePos = strstr(fullname, " "); // Find the first occurrence of a space in the fullname

        if (spacePos != nullptr)
        {
            *spacePos = '\0'; // Replace the space with a null terminator
            lastname = spacePos + 1; // Assign lastname to start at the next character after the null terminator
        }

        if (lastname == nullptr || *lastname == '\0')
        {
            lastname = fullname + strlen(fullname); // Assign lastname to the end of the fullname if it is empty
        }

        int length = 0;
        while (nickName[length] != '\0')
        {
            nickName[length] = static_cast<char>(toupper(nickName[length])); // Convert nickname characters to uppercase
            length++;
        }

        rev(nickName, length);

        strcpy(namemodded, lastname); // Copy the last name into namemodded
        strcat(namemodded, ", "); // Append the comma and a space
        strcat(namemodded, nickName); // Append the nickname
        strcat(namemodded, " "); // Append a space
        strcat(namemodded, firstName); // Append the first name

        cout << namemodded << endl;

        // Ask the user if they want to continue with another name
        cout << "Do you want to enter another name? (Y/N)" << endl;
        cin >> again;
        //cin.clear();
        cin.ignore();


    } while (again == 'y' || again == 'Y');

    return 0;
}

// Function to reverse the order of characters in nickName
void rev(char nick[], int arrSize)
{
    int sizer = arrSize - 1;

    for (int count = 0; count < sizer; count++, sizer--)
    {
        char temporaryChar = nick[count];
        nick[count] = nick[sizer];
        nick[sizer] = temporaryChar;
    }
}
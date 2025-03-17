#include "../include/global.h"
#include "../include/headers.h"
double globalTime = 0;

// Function that checks if the input is a number and if it is within the specified range.
int NumberCheck(int min, int max)
{
	int number;
	while (true)
	{
		try
		{
			if (cin >> number && number >= min && number <= max)
				break;
			else
			{
				throw std::invalid_argument("Ivestis netinkama. Iveskite dar karta:");
			}
		}
		catch (...)
		{
			ProcessException();
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return number;
}

int Menu()
{
	cout << "Sveiki atvyke i pazymiu skaiciuokle! Pasirinkite veiksma spausdami skaiciu ir tada spauskite Enter." << endl;
	cout << "--------------------------------------------" << endl;
	cout << "0 - baigti darba;" << endl;
	cout << "1 - pildyti duomenis rankiniu budu;" << endl;
	cout << "2 - generuoti pazymius;" << endl;
	cout << "3 - generuoti pazymius, vardus ir pavardes;" << endl;
	cout << "4 - nauduoti duomenis is failo;" << endl;
	cout << "5 - sugeneruoti duomenis ir isvesti i faila;" << endl;
	cout << "6 - surusiuoti studentus i 2 failus." << endl;
	cout << "--------------------------------------------" << endl;
	int action = NumberCheck(0, 6);
	return action;
}

// Function that ends the program.
void ProgramEnd()
{
	cout << " * Programa veike: " << globalTime << " sekundziu. " << endl;
	cout << "Aciu, kad naudojates pazymiu skaiciuokle!" << endl;
	cout << "Paspauskite Enter, kad uzbaigtumete programos darba." << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}

void ProcessException()
{
	try
	{
		throw; // Rethrow the exception to be caught here
	}
	catch (const ios_base::failure &e)
	{
		cerr << "Ivesties/isvesties isimtis: " << e.what() << endl;
		// You can add additional logging or actions if needed
	}
	catch (const system_error &e)
	{
		cerr << "Sistemos isimtis: " << e.what() << endl;
		// Additional handling for system errors
	}
	catch (const future_error &e)
	{
		cerr << "Ateities užduoties isimtis: " << e.what() << endl;
		// Future error handling
	}
	catch (const bad_alloc &e)
	{
		cerr << "Priskyrimo klaida (bad_alloc): " << e.what() << endl;
		// Handling memory allocation errors
	}
	catch (const exception &e)
	{
		cerr << "Klaida: " << e.what() << endl;
		// General exception handling
	}
	catch (...)
	{
		cerr << "Nežinoma klaida. " << endl;
		// Catch any unknown exceptions
	}
}

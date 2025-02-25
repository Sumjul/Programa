#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <system_error>
#include <future>

using std::cerr;
using std::endl;
using std::ios_base;
using std::system_error;
using std::future_error;
using std::bad_alloc;
using std::exception;

// Function to process exceptions and print messages in Lithuanian
void processException()
{
    try
    {
        throw; // Rethrow the exception to be caught here
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Ivesties/isvesties išimtis: " << e.what() << endl;
        // You can add additional logging or actions if needed
    }
    catch (const system_error &e)
    {
        cerr << "Sistemos išimtis: " << e.what() << endl;
        // Additional handling for system errors
    }
    catch (const future_error &e)
    {
        cerr << "Ateities užduoties išimtis: " << e.what() << endl;
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
        cerr << "Nežinoma klaida." << endl;
        // Catch any unknown exceptions
    }
}

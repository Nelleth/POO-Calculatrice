#include "../headers/Display.hpp"
#include "../headers/Stack.hpp"
#include "../headers/Operations.hpp"


/**************** GESTION DES ERREURS ET DES OPERATEUR ****************/


// On vérifie si on a bien un opérateur dans le chaine. On compare donc notre chaine aux différents opérateurs pour trouver un opérateur.
bool isOperator(string buffer)
{
        if(buffer.compare("*") == 0         //compare() :  cette fonction compare la valeur de l'objet buffer à la séquence de caractères spécifiée par ses arguments.
           || buffer.compare("+") == 0
           || buffer.compare("-") == 0
           || buffer.compare("/") == 0
           || buffer.compare("^") == 0
           || buffer.compare("%") == 0)
                return true;
        else
                return false;
}

// On vérifie les opérateurs sans tenir compte du moins pour les chiffres négatifs
bool hasNoOpeUnlessMinus(string buffer)
{
        if(buffer.compare("*") != 0
           && buffer.compare("+") != 0
           && buffer.compare("/") != 0
           && buffer.compare("^") != 0
           && buffer.compare("%") != 0)
                return true;
        else
                return false;
}

// On vérifie si la présenc d'opérateurs
bool hasNoOperator(string buffer)
{
        if(buffer.compare("*") != 0
           && buffer.compare("+") != 0
           && buffer.compare("-") != 0
           && buffer.compare("/") != 0
           && buffer.compare("^") != 0
           && buffer.compare("%") != 0)
                return true;
        else
                return false;
}

// On gère les erreurs
bool isError(string buffer)
{
        if(buffer.compare("ERROR") == 0
           || buffer.compare("inf") == 0
           || buffer.compare("OUT OF RANGE") == 0
           || buffer.compare("NOT ENOUGH ARGUMENTS") == 0)
                return true;
        else
                return false;
}

// On vérifie si l'argument entré par l'utilisateur est valide
bool isValidNumber(string str)
{
        bool result = false;

        while(!str.empty())	// La fonction empty() retourne si la chaîne est vide (c'est-à-dire si sa longueur est 0). Elle ne modifie pas la valeur de la chaîne.
        {
                if(str.back()=='0'      // La fonction Back() retourne une référence au dernier caractère de la chaîne
                   || str.back() == '1'
                   || str.back() == '2'
                   || str.back() == '3'
                   || str.back() == '4'
                   || str.back() == '5'
                   || str.back() == '6'
                   || str.back() == '7'
                   || str.back() == '8'
                   || str.back() == '9'
                   || str.back() == '.'
                   || str.back() == '-')
                {
                        result = true;
                        str.pop_back();     // La fonction pop_back() efface le dernier caractère de la chaîne, réduisant ainsi sa longueur de un.
                }
                else
                        return false;
        }
        return result;
}

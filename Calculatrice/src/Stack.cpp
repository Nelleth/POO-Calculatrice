#include "../headers/Stack.hpp"

Stack::Stack ()		//constructeur de la classe Stack par défaut qui permet de gérer la pile
{
}

Stack::Stack (stack <float> argt)		// constructeur de la classe Stack
{
  this->argument=argt;
}

stack <float> Stack::getArgument()	// getter de l'argument entré
{
	return this->argument;
}

string Stack::Operation(string enter)	// Cette fonction permet de calculer par notation postfixée 
{
    float argument1;
    float argument2;

    map<string,int> operateur;
    operateur["+"]=1;
    operateur["-"]=2;
    operateur["*"]=3;
    operateur["/"]=4;
    operateur["^"]=5;
    operateur["%"]=6;

    switch(operateur[enter])
    {
        case 1: // +
            if(this->argument.size() < 2)
                return "NOT ENOUGH ARGUMENTS";
            else
            {
                argument2 = this->argument.top();
                this->argument.pop();
                argument1 = this->argument.top();
                this->argument.pop();
                cout << "argument1 : " << argument1 << endl;
                cout << "argument2 : " << argument2 << endl;
                cout << "resultat : " << argument1 + argument2 << endl;
                return to_string(argument1 + argument2);
            }
        break;

        case 2: // -
            if(this->argument.size() < 2)
                    return "NOT ENOUGH ARGUMENTS";
            else
            {
                    argument2 = this->argument.top();
                    this->argument.pop();
                    argument1 = this->argument.top();
                    this->argument.pop();
                    cout << "argument1 : " << argument1 << endl;
                    cout << "argument2 : " << argument2 << endl;
                    cout << "resultat : " << argument1 - argument2 << endl;
                    return to_string(argument1 - argument2);
            }
        break;

        case 3:// *
            if(this->argument.size() < 2)
                return "NOT ENOUGH ARGUMENTS";
            else
            {
                argument2 = this->argument.top();
                this->argument.pop();
                argument1 = this->argument.top();
                this->argument.pop();
                cout << "argument1 : " << argument1 << endl;
                cout << "argument2 : " << argument2 << endl;
                cout << "resultat : " << argument1 * argument2 << endl;
                return to_string(argument1 * argument2);
            }
        break;

        case 4: // /
            if(this->argument.size() < 2)
                return "NOT ENOUGH ARGUMENTS";
            else
            {
                argument2 = this->argument.top();
                this->argument.pop();
                argument1 = this->argument.top();
                this->argument.pop();
                cout << "argument1 : " << argument1 << endl;
                cout << "argument2 : " << argument2 << endl;
                cout << "resultat : " << argument1 / argument2 << endl;
                return to_string(argument1 / argument2);
            }
        break;

        case 5: // ^
            if(this->argument.size() < 2)
                return "NOT ENOUGH ARGUMENTS";
            else
            {
                argument2 = this->argument.top();
                this->argument.pop();
                argument1 = this->argument.top();
                this->argument.pop();
                cout << "argument1 : " << argument1 << endl;
                cout << "resultat : " << pow(argument1, argument2) << endl;
                return to_string(pow(argument1, argument2));
            }
        break;

        case 6: // %
            if(this->argument.size() < 1)
                return "NOT ENOUGH ARGUMENTS";
            else
            {
                argument2 = this->argument.top();
                this->argument.pop();
                argument1 = this->argument.top();
                this->argument.pop();
                
                int o1 = argument1; 			                // On cast les nombres pour réaliser la fonction modulo
                int o2 = argument2;
                int modulo = o1 % o2;
                return to_string(modulo);
            }
        break;

        default:
            return "ERROR";
    }
	return "ERROR";
}

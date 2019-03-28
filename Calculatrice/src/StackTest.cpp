#define CATCH_CONFIG_MAIN
#include "../headers/catch.hpp"
#include "../headers/Stack.hpp"


TEST_CASE( "Simulation du calcul 5 + 4 = 9", "All" )
{	

	stack <float> argt;
 	Stack stack_1(argt);	

        string buffer = "5";
        stack_1.argument.push(stof(buffer));		// On empile 5

        buffer = "4";
        stack_1.argument.push(stof(buffer));		// On empile 4

        buffer = "+";                                   // On rentre notre operateur
 	
        CHECK(stack_1.Operation(buffer)=="9.000000");  	// On vérifie le résultat
	while(!stack_1.argument.empty())
	{
		stack_1.argument.pop();
	}

}

TEST_CASE( "Simulation du calcul (3 * 2 + 5 * 2) = 16 ", "All" )
{	

	stack <float> argt;
        Stack stack_1(argt);

 	string buffer = "3";
        stack_1.argument.push(stof(buffer));		// On empile 3
        buffer = "2";
        stack_1.argument.push(stof(buffer));		// On empile le premier 2
        buffer = "*";					// On rentre notre operateur
	buffer=stack_1.Operation(buffer);
        CHECK(buffer=="6.000000");                      // On vérifie le résultat
        stack_1.argument.push(stof(buffer));		// On empile notre operande de second niveau : 6

	buffer = "5";
        stack_1.argument.push(stof(buffer));		// On empile 5
        buffer = "2";
        stack_1.argument.push(stof(buffer));		// On empile le second 2
        buffer = "*";					// On rentre notre operateur *
 	buffer=stack_1.Operation(buffer);
        CHECK(buffer=="10.000000"); 			// On vérifie le résultat
        stack_1.argument.push(stof(buffer));		// On empile notre operande de second niveau : 10

        buffer = "+";                                   // On rentre notre operateur
	/*On initialise le camion de pompier avec le code top secret*/
        CHECK(stack_1.Operation(buffer)=="16.000000"); 	// On vérifie le résultat

	while(!stack_1.argument.empty())
	{
		stack_1.argument.pop();
	}

}

TEST_CASE( "Simulation d'erreur , All" )
{	

	stack <float> argt;
 	Stack stack_1(argt);	

 	string buffer = "5";
        stack_1.argument.push(stof(buffer));		// On empile 5
 	buffer = "6";
        stack_1.argument.push(stof(buffer));		// On empile 6
        buffer = "7";					// On rentre notre operateur (ici un 7 pour provoquer l'erreur)
	buffer=stack_1.Operation(buffer);
        CHECK(buffer=="ERROR");                     //  On vérifie le résultat

	while(!stack_1.argument.empty())
	{
		stack_1.argument.pop();
	}
	
}

TEST_CASE( "Simulation du calcul 5 6 7 * + 1 - ", "All" )
{	

	stack <float> argt;
 	Stack stack_1(argt);	

 	string buffer = "5";
        stack_1.argument.push(stof(buffer));		// On empile 5
 	buffer = "6";
        stack_1.argument.push(stof(buffer));		// On empile 6
 	buffer = "7";
        stack_1.argument.push(stof(buffer));		// On empile 7
        buffer = "*";                                   // On rentre notre operateur
	buffer=stack_1.Operation(buffer);
        CHECK(buffer=="42.000000");             // On vérifie le résultat
        stack_1.argument.push(stof(buffer));		// On empile notre operande de second niveau : 42
        buffer = "+";					// On rentre notre operateur
	buffer=stack_1.Operation(buffer);
	CHECK(buffer=="47.000000");
	stack_1.argument.push(stof(buffer));
	CHECK(buffer=="47.000000");
	buffer = "1";
        stack_1.argument.push(stof(buffer));		// On empile 1
        buffer = "-";                                   // On rentre notre operateur
	buffer=stack_1.Operation(buffer);
        CHECK(buffer=="46.000000");          // On vérifie le résultat

	while(!stack_1.argument.empty())
	{
		stack_1.argument.pop();
	}



}

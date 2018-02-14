/* 
 * DonutCashRegister.cpp
 * Joe Runser - 28 September 2017
 *
 * The program is meant to be the initial developement of a POS system for a
 * donut shop. It takes the number of filled and regular donuts and provides
 * the change owed in a broken down form.
 */

#include <iostream>

using namespace std;

int main() {

	// Donut prices
	const int PRICE_REGULAR_SINGLE = 50;
	const int PRICE_REGULAR_DOZEN  = 525;
	const int PRICE_FILLED_SINGLE  = 75;
	const int PRICE_FILLED_DOZEN   = 825;

	// Denomination values
	const int DOLLAR  = 100;
	const int QUARTER = 25;
	const int DIME    = 10;
	const int NICKLE  = 5;
	const int PENNY   = 1;

	const int TAX_RATE = 0.04;

	const int DOZEN = 12;

	// Counts of realtated deals
	int regularDozen = 0;
	int regularDonut = 0;
	int filledDozen  = 0;
	int filledDonut  = 0;

	int numDonut = 0;
	
	int cost = 0;
	int change = 0;

	// The count of the coins that need returned
	int dollars  = 0;
	int quarters = 0;
	int dimes    = 0;
	int nickels  = 0;
	int pennies  = 0;

	int int_paymentRecived = 0;
	double dbl_paymentRecived = 0;

    // Sets the precision on a gloabaly.
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    
    // This keeps the program running until certain criteria are met.
    while(true) {

		// Reset everything to 0
		regularDozen = 0;
		regularDonut = 0;
		filledDozen = 0;
		filledDonut = 0;
		numDonut = 0;
		cost = 0;
		change = 0;
		dollars = 0;
		quarters = 0;
		dimes = 0;
		nickels = 0;
		pennies = 0;
		int_paymentRecived = 0;
		dbl_paymentRecived = 0;

        // Regular donuts.
        cout << "How many regular donuts would you like: ";
        cin >> numDonut;
        
        // Breaks out of the while loop.
        if(cin.fail()) break;
        
		regularDozen = numDonut / DOZEN;
		regularDonut = numDonut % DOZEN;
        
        // Filled donuts.
        cout << "How many filled donuts would you like: ";
        cin >> numDonut;
        
        // Break out of the while loop.
        if(cin.fail()) break;
        
		filledDozen = numDonut / DOZEN;
		filledDonut = numDonut % DOZEN;

		// Tabulate cost.
		cost =  0;
		cost += regularDonut * PRICE_REGULAR_SINGLE;
		cost += regularDozen * PRICE_REGULAR_DOZEN;
		cost += filledDonut  * PRICE_FILLED_SINGLE;
		cost += filledDozen  * PRICE_FILLED_DOZEN;
		cost += cost * 0.04;
        
        // Display the total and input the money recived.
        cout << "Customer owes $" << (double)cost / DOLLAR << endl;
        cout << "Customer pays $";
        cin >> dbl_paymentRecived;
        
		// Convert the payment recived to an integer
		int_paymentRecived = dbl_paymentRecived * DOLLAR;

		change = int_paymentRecived - cost;

        // Formatting the output for the chnage due.
        if(change > 0) {
            cout << "Change owed is $" << (double)change / DOLLAR << " - ";

			// Compute dollars
			dollars = change / DOLLAR;
			change = change % DOLLAR;
			// Compute quarters
			quarters = change / QUARTER;
			change = change % QUARTER;
			// Compute dimes
			dimes = change / DIME;
			change = change % DIME;
			// Compute nickles
			nickels = change / NICKLE;
			change = change % NICKLE;
			// Compute pennies
			pennies = change / PENNY;

			int totalCoin = dollars + quarters + dimes + nickels + pennies;
            
			// Output for dollars
			if (dollars > 0) {
				cout << dollars;
				if (dollars > 1) cout << " dollars";
				else cout << " dollar";
				totalCoin = totalCoin - dollars;
				if (totalCoin > 0) cout << ", ";
			}
			// Output for quarters
			if (quarters > 0) {
				cout << quarters;
				if (quarters > 1) cout << " quarters";
				else cout << " quarter";
				totalCoin = totalCoin - quarters;
				if (totalCoin > 0) cout << ", ";
			}
			// Output for dimes
			if (dimes > 0) {
				cout << dimes; 
				if (dimes > 1) cout << " dimes";
				else cout << " dime";
				totalCoin = totalCoin - dimes;
				if (totalCoin > 0) cout << ", ";
			}
			// Output for nickels
			if (nickels > 0) {
				cout << nickels;
				if (nickels > 1) cout << " nickels";
				else cout << " nickel";
				totalCoin = totalCoin - nickels;
				if (totalCoin > 0) cout << ", ";
			}
			// Output for pennies
			if (pennies > 0) {
				cout << pennies;
				if (pennies > 1) cout << " pennies";
				else cout << " penny";
			}
            
            cout << "." << endl << endl;
        }
        // If there is no change.
        else { cout << "Exact payment recived - no change owed." << endl << endl; }
        
    } // while loop
    
    return 0;
    
} // main

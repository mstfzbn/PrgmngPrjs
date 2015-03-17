#include "Family.h"
#include "Luxury.h"
#include <string>
#include <vector>

int main (){
	//                                         nomer shasi         razhod, izminati km, taksa za den, dni
	Family famKola1("VW", "Passat", "Sedan", "Black", 210695, "PB9595MK", 6.7, 600, 50, 4);
	Luxury luxKola ("Mercedes", "S320", "Sedan", "Black", 120690, "CM5475MC", 8.7, 600, 50, 4, "Vino");
	famKola1.getPayment();
	luxKola.getPayment();

	vector<Auto*> carsContainer(2);
	carsContainer[0] = &famKola1;
	carsContainer[1] = &luxKola;

	cout << endl;
	return 0;
}

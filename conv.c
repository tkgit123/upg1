#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

bool input_fail = false;
bool main_loop = true;
double fahrenheit = 0;
char input[10];

//Konvertera till celcius
float convert(float faren) {
	return (faren-32) * 5/9;
}

//menu val
void choice(void) {
	char choice; bool loop = true;
	while(loop) {
		printf("\nEn gang till (J/N)?\n");
		choice = getchar();
		if(choice == 'J' || choice == 'j') {
			loop = false;
		} else if(choice == 'N' || choice == 'n') {
			main_loop = false;
			loop = false;
		}
		system("cls");
	}
}

//input filter
void check_input(char* chk) {

	char mid_storage[10];

	int nr_of_decimals = 0; int nr_of_punctuations = 0;
	int pos = 0;
	bool decimal_found = false;
	char *p;

	for(p = chk; *p; ++p) {


		if(*p != '.' || *p != ',') {
			if(!(*p >= 48) && !(*p <= 57)) {
				printf("Inne\x86ller ok\x84nd tecken! V\x84nligen ange temperatur p\x86 nytt!\n");
				system("pause");
				input_fail = true;
				break;
			}
		}


		if(*p == 44) { // omvandla komma till punkt
			mid_storage[pos] = 46;
		} else {
			mid_storage[pos] = *p;
		}
		pos++;

	}

	// omvandla till float bara om ovanstående inte failar
	if(input_fail != true) {
		mid_storage[pos++] = '\0';
		fahrenheit = (float)atof(mid_storage);
	}
}


int main() {
	while(main_loop) {
		input_fail = false;
		printf("FARENHEIT - CELCIUS\n");
		printf("====================\n");

		printf("Ange temperatur i Farenheit : ");
		char c; int pos = 0;
		while ((c = getchar()) != '\n' && c != EOF) {
			input[pos] = c;
			pos++;
		}

		check_input(input);
		if(input_fail != true) {
			printf("\nTemperaturen \x84r %.1f C", convert(fahrenheit));
			choice();
			char throw_away = getchar();
		}

		system("cls");

	}

	return 0;
}

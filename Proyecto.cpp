//Proyecto de Funda
#include <iostream>
#include <string>
using namespace std;

bool leapYear(int year) {

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {

		return true;
	}
	return false;
}

int monthDays(int month, int year) {
	if (month == 2) {
		return leapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

void askDate(int& year1, int& year2, int& month1, int& month2, int& day1, int& day2) {

	cout << "Ingrese el primer anio: " << endl;
	cin >> year1;

	if (year1 <= 999) {

		year1 += 2000;
	}

	while (year1 > 9999)
	{
		cout << "Anio invalido, intente de nuevo: ";
		cin >> year1;
	}

	cout << "Ingrese el primer mes: " << endl;
	cin >> month1;

	while (month1 < 1 || month1 > 12)
	{
		cout << "Mes invalido, intente de nuevo: ";
		cin >> month1;

	}

	cout << "Ingrese el primer dia: " << endl;
	cin >> day1;

	if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12) {

		while (day1 < 1 || day1 > 31) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day1;
		}
	}

	if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) {

		while (day1 < 1 || day1 > 30) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day1;
		}
	}

	if (leapYear(year1) == true && month1 == 2) {

		while (day1 < 1 || day1 > 29) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day1;
		}
	}

	cout << "Ingrese el segundo anio: " << endl;
	cin >> year2;

	if (year2 <= 999) {

		year2 += 2000;
	}

	while (year2 > 9999)
	{
		cout << "Anio invalido, intente de nuevo: ";
		cin >> year2;
	}

	cout << "Ingrese el segundo mes: " << endl;
	cin >> month2;


	while (month2 < 1 || month2 > 12)
	{
		cout << "Mes invalido, intente de nuevo: ";
		cin >> month2;
	}


	cout << "Ingrese el segundo dia: " << endl;
	cin >> day2;

	if (month2 == 1 || month2 == 3 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12) {

		while (day2 < 1 || day2 > 31) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day1;
		}
	}

	if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) {

		while (day2 < 1 || day2 > 30) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day2;
		}
	}

	if (leapYear(year2) == true && month2 == 2) {

		while (day2 < 1 || day2 > 29) {
			cout << "Dia invalido, intente de nuevo: ";
			cin >> day2;
		}
	}
}

void majorDate(int day1, int day2, int month1, int month2, int year1, int year2) {
	if (year1 > year2)
	{
		cout << "La fecha 1 es mayor " << endl;
	}
	else if (year1 < year2) {
		cout << "La fecha 2 es mayor " << endl;
	}
	else {
		if (month1 > month2)
		{
			cout << "La fecha 1 es mayor " << endl;
		}
		else if (month1 < month2) {
			cout << "El fecha 2 es mayor " << endl;
		}
		else {
			if (day1 > day2)
			{
				cout << "La fecha 1 es mayor " << endl;
			}
			else if (day1 < day2) {
				cout << "La fecha 2 es mayor " << endl;
			}
			else {
				cout << "Las fechas son iguales" << endl;
			}
		}
	}
}

void difference(int day1, int day2, int month1, int month2, int year1, int year2) {

	int differenceDay1 = 0;
	int differenceDay2 = 0;
	int finalDifferenceDays = 0;
	int finalDifferenceMonth = 0;
	int finalDifferenceYear = 0;

	differenceDay1 = (month1 - 1) * 30 + day1;
	differenceDay2 = (month2 - 1) * 30 + day2;

	if (year1 > year2) {

		finalDifferenceDays = (year1 - year2) * 365 - differenceDay2 + differenceDay1;
		cout << "La diferencia de dias entre las fechas es de: " << finalDifferenceDays << endl;

		finalDifferenceMonth = finalDifferenceDays / 30;
		cout << "La diferencia de meses entre las fechas es de: " << finalDifferenceMonth << endl;

		finalDifferenceYear = finalDifferenceDays / 365;
		cout << "La diferencia de anios entre las fechas es de: " << finalDifferenceYear << endl;
	}
	else {

		finalDifferenceDays = (year2 - year1) * 365 - differenceDay1 + differenceDay2;
		cout << "La diferencia de dias entre las fechas es de: " << finalDifferenceDays << endl;

		finalDifferenceMonth = finalDifferenceDays / 30;
		cout << "La diferencia de meses entre las fechas es de: " << finalDifferenceMonth << endl;

		finalDifferenceYear = finalDifferenceDays / 365;
		cout << "La diferencia de anios entre las fechas es de: " << finalDifferenceYear << endl;

	}

}

void difeferenceDates(int day1, int month1, int year1, int day2, int month2, int year2) {
	int totalDays = day1;

	for (int i = 1; i <= month1; ++i) {
		totalDays += monthDays(i, year1);
	}
	totalDays += year1 * 365;

	int totalDiasFecha2 = day2;
	for (int i = 1; i <= month2; ++i) {
		totalDiasFecha2 += monthDays(i, year2);
	}
	totalDiasFecha2 += year2 * 365;

	int differenceDays = totalDiasFecha2 - totalDays;

	int year = differenceDays / 365;
	differenceDays %= 365;
	int month = differenceDays / 30;
	int day = differenceDays % 30;
	if (year < 0 || month < 0 || day < 0)
	{
		year = -year;
		month = -month;
		day = -day;
		cout << "La diferencia entre las fechas es de " << year << " anios, " << month << " meses y " << day << " dias." << endl;
	}
	else
	{
		cout << "La diferencia entre las fechas es de " << year << " anios, " << month << " meses y " << day << " dias." << endl;
	}

}

void plusDates(int day1, int day2, int month1, int month2, int year1, int year2) {

	int daysInMonth1 = 0;
	int daysInMonth2 = 0;
	int daysToAdd = 0;
	if (month1 == 2) {
		daysInMonth1 = leapYear(year1) ? 29 : 28;
	}
	else {
		daysInMonth1 = (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) ? 30 : 31;
	}

	cout << "Cuantos dias desea sumar: ";
	cin >> daysToAdd;
	day1 += daysToAdd;

	while (day1 > daysInMonth1)
	{
		day1 -= daysInMonth1;
		month1++;
		if (month1 > 12) {
			month1 = 1;
			year1++;
		}
		if (month1 == 2) {
			daysInMonth1 = leapYear(year1) ? 29 : 28;
		}
		else {
			daysInMonth1 = (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) ? 30 : 31;
		}
	}

	if (month2 == 2) {
		daysInMonth2 = leapYear(year2) ? 29 : 28;
	}
	else {
		daysInMonth2 = (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) ? 30 : 31;
	}

	day2 += daysToAdd;
	while (day2 > daysInMonth2)
	{
		day2 -= daysInMonth2;
		month2++;
		if (month2 > 12) {
			month2 = 1;
			year2++;
		}
		if (month2 == 2) {
			daysInMonth2 = leapYear(year2) ? 29 : 28;
		}
		else {
			daysInMonth2 = (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) ? 30 : 31;
		}
	}

	cout << "La fecha sumada es: ";
	if (day1 < 10) {
		cout << "0";
	}
	cout << day1 << "/";
	if (month1 < 10) {
		cout << "0";
	}
	cout << month1 << "/" << year1 << endl;

	cout << "La fecha sumada es: ";
	if (day2 < 10) {
		cout << "0";
	}
	cout << day2 << "/";
	if (month2 < 10) {
		cout << "0";
	}
	cout << month2 << "/" << year2 << endl;


}

void minusDates(int day1, int day2, int month1, int month2, int year1, int year2) {

	int daysInMonth1 = 0;
	int daysInMonth2 = 0;
	int daysToSubstract = 0;
	if (month1 == 2) {
		daysInMonth1 = leapYear(year1) ? 29 : 28;
	}
	else if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) {
		daysInMonth1 = 30;
	}
	else {
		daysInMonth1 = 31;
	}
	cout << "Cuantos dias desea restar: ";
	cin >> daysToSubstract;
	day1 -= daysToSubstract;

	while (day1 < 1)
	{
		month1--;
		if (month1 < 1) {
			month1 = 12;
			year1--;
			leapYear(year1);
		}
		daysInMonth1 = (month1 == 2) ? (leapYear(year1) ? 29 : 28) : ((month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) ? 30 : 31);
		day1 += daysInMonth1;
	}


	if (month2 == 2) {
		daysInMonth2 = leapYear(year1) ? 29 : 28;
	}
	else if (month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) {
		daysInMonth2 = 30;
	}
	else {
		daysInMonth2 = 31;
	}
	day2 -= daysToSubstract;

	while (day2 < 1)
	{
		month2--;
		if (month2 < 1) {
			month2 = 12;
			year2--;
			leapYear(year2);
		}
		daysInMonth2 = (month2 == 2) ? (leapYear(year2) ? 28 : 29) : ((month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) ? 30 : 31);
		day2 += daysInMonth2;
	}

	cout << "La fecha restada es: ";
	if (day1 < 10) {
		cout << "0";
	}
	cout << day1 << "/";
	if (month1 < 10) {
		cout << "0";
	}
	cout << month1 << "/" << year1 << endl;

	cout << "La fecha restada es: ";
	if (day2 < 10) {
		cout << "0";
	}
	cout << day2 << "/";
	if (month2 < 10) {
		cout << "0";
	}
	cout << month2 << "/" << year2 << endl;

}

string monthToString(int month, int day)
{
	string monthString = " ";
	switch (month)
	{
	case 1:
		monthString = "Enero";
		break;
	case 2:
		monthString = "Febrero";
		break;
	case 3:
		monthString = "Marzo";
		break;
	case 4:
		monthString = "Abril";
		break;
	case 5:
		monthString = "Mayo";
		break;
	case 6:
		monthString = "Junio";
		break;
	case 7:
		monthString = "Julio";
		break;
	case 8:
		monthString = "Agosto";
		break;
	case 9:
		monthString = "Septiembre";
		break;
	case 10:
		monthString = "Octubre";
		break;
	case 11:
		monthString = "Noviembre";
		break;
	case 12:
		monthString = "Diciembre";
		break;
	}
	return monthString;
}

void shortFormat(int year, int month, int day) {

	if (day < 10 && month < 10) {

		cout << "0" << day << "-" << "0" << month << "-" << year << endl;
	}
	else if (day < 10) {

		cout << "0" << day << "-" << month << "-" << year << endl;
	}
	else if (month < 10) {

		cout << day << "-" << "0" << month << "-" << year << endl;
	}

	else {

		cout << day << "-" << month << "-" << year << endl;

	}
}

int main()
{
	int day1 = 0;
	int day2 = 0;

	int month1 = 0;
	int month2 = 0;

	int year1 = 0;
	int year2 = 0;

	bool open = true;

	while (open)
	{
		int opcion = 0;
		cout << "Seleccione una de las siguientes opciones: " << endl;
		cout << "1.Digite las 2 fechas" << endl;
		cout << "2.Saber cual fecha es mayor" << endl;
		cout << "3.Diferencia entre ambas" << endl;
		cout << "4.Sumar X dias" << endl;
		cout << "5.Restar X dias" << endl;
		cout << "6.Bisiesto o no" << endl;
		cout << "7.Formato largo" << endl;
		cout << "8.Formato normal" << endl;
		cout << "9.Salir" << endl;
		cin >> opcion;
		system("CLS");

		switch (opcion)
		{
		case 1:
			askDate(year1, year2, month1, month2, day1, day2);
			break;

		case 2:
			majorDate(day1, day2, month1, month2, year1, year2);
			break;

		case 3:
			/*difference(day1, day2, month1, month2, year1, year2);*/
			difeferenceDates(day1, month1, year1, day2, month2, year2);

			break;

		case 4:
			plusDates(day1, day2, month1, month2, year1, year2);
			break;

		case 5:
			minusDates(day1, day2, month1, month2, year1, year2);
			break;

		case 6:
			if (leapYear(year1)) {

				cout << "El anio es bisiesto" << endl;
			}
			else {
				cout << "El anio no es bisiesto" << endl;
			}

			if (leapYear(year2)) {

				cout << "El anio es bisiesto" << endl;
			}
			else {
				cout << "El anio no es bisiesto" << endl;
			}
			break;

		case 7:
			cout << "Formato largo: " << endl;

			if (day1 < 10) {

				cout << "Fecha 1: " << "0" << day1 << " " << monthToString(month1, day1) << " " << year1 << endl;
			}
			else {

				cout << "Fecha 1: " << day1 << " " << monthToString(month1, day1) << " " << year1 << endl;

			}
			if (day2 < 10) {

				cout << "Fecha 2: " << "0" << day2 << " " << monthToString(month2, day2) << " " << year2 << endl;

			}
			else {

				cout << "Fecha 2: " << day2 << " " << monthToString(month2, day2) << " " << year2 << endl;

			}

			break;

		case 8:
			cout << "Formato normal: " << endl;
			cout << "Fecha 1: "; shortFormat(year1, month1, day1);
			cout << "Fecha 2: "; shortFormat(year2, month2, day2);
			break;

		case 9:
			open = false;
			cout << "Hasta luego";
			break;
		}
	}
}
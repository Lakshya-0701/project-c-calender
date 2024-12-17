#include <stdio.h>

int getFirstDayOfMonth(int year, int month) {
    int day = 1;
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void printCalendar(int year, int month) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    co nst int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year)) {
        days = 29;
    }

    int firstDay = getFirstDayOfMonth(year, month);

    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < firstDay; i++) {
        printf("     ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%5d", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month! Please enter a month between 1 and 12.\n");
        return 1;
    }

    printCalendar(year, month);
    return 0;
}
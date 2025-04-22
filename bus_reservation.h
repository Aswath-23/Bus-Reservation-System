#ifndef BUS_RESERVATION_H
#define BUS_RESERVATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUSES 10
#define MAX_SEATS 40
#define MAX_PASSENGERS 100
#define MAX_BOOKINGS 50
#define MAX_PASSENGERS_PER_BOOKING 5

// Structure for Bus
typedef struct {
    int bus_id;
    char name[50];
    char source[50];
    char destination[50];
    char departure_time[10];
    char arrival_time[10];
    float fare;
    char bus_type[20];
    char amenities[100];
    int total_seats;
    int available_seats;
    int seats[MAX_SEATS];  // 1 for booked, 0 for available
} Bus;

// Structure for Passenger
typedef struct {
    int passenger_id;
    char name[50];
    int age;
    char gender;
    int seat_number;
} Passenger;

// Structure for Booking
typedef struct {
    int booking_id;
    int bus_id;
    int total_passengers;
    int passenger_ids[MAX_PASSENGERS_PER_BOOKING];
    int seat_numbers[MAX_PASSENGERS_PER_BOOKING];
    time_t booking_time;
    float total_fare;
} Booking;

// Function declarations
void initialize_system();
void display_main_menu();
void display_buses();
void book_ticket();
void view_bookings();
void cancel_booking();
void display_seat_layout(int bus_id);
int is_seat_available(int bus_id, int seat_number);
float calculate_fare(int bus_id, int num_passengers);
time_t parse_time(const char* time_str);
void format_time(time_t time, char* buffer);
void add_bus();
void remove_bus();
void modify_bus();

#endif // BUS_RESERVATION_H 
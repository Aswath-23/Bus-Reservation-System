#include "bus_reservation.h"
#include <ctype.h>

// Global variables
Bus buses[MAX_BUSES];
Passenger passengers[MAX_PASSENGERS];
Booking bookings[MAX_BOOKINGS];
int num_buses = 0;
int num_passengers = 0;
int num_bookings = 0;

// Initialize the system with sample data
void initialize_system() {
    // Sample bus data with 10 different routes
    Bus bus1 = {
        .bus_id = 1,
        .name = "Mangalore Express",
        .source = "Bangalore",
        .destination = "Mangalore",
        .departure_time = "08:00",
        .arrival_time = "14:00",
        .fare = 1200.0,
        .bus_type = "AC Sleeper",
        .amenities = "WiFi, Charging Points, Blanket",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus1.seats, 0, sizeof(bus1.seats));
    buses[num_buses++] = bus1;

    Bus bus2 = {
        .bus_id = 2,
        .name = "Coorg Deluxe",
        .source = "Bangalore",
        .destination = "Coorg",
        .departure_time = "10:00",
        .arrival_time = "16:00",
        .fare = 1500.0,
        .bus_type = "AC Seater",
        .amenities = "WiFi, Charging Points, Water Bottle",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus2.seats, 0, sizeof(bus2.seats));
    buses[num_buses++] = bus2;

    Bus bus3 = {
        .bus_id = 3,
        .name = "Mysore Express",
        .source = "Bangalore",
        .destination = "Mysore",
        .departure_time = "07:00",
        .arrival_time = "10:00",
        .fare = 800.0,
        .bus_type = "Non-AC Seater",
        .amenities = "Charging Points",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus3.seats, 0, sizeof(bus3.seats));
    buses[num_buses++] = bus3;

    Bus bus4 = {
        .bus_id = 4,
        .name = "Ooty Deluxe",
        .source = "Bangalore",
        .destination = "Ooty",
        .departure_time = "09:00",
        .arrival_time = "17:00",
        .fare = 1800.0,
        .bus_type = "AC Sleeper",
        .amenities = "WiFi, Charging Points, Blanket, Water Bottle",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus4.seats, 0, sizeof(bus4.seats));
    buses[num_buses++] = bus4;

    Bus bus5 = {
        .bus_id = 5,
        .name = "Chennai Express",
        .source = "Bangalore",
        .destination = "Chennai",
        .departure_time = "08:30",
        .arrival_time = "14:30",
        .fare = 1300.0,
        .bus_type = "AC Seater",
        .amenities = "WiFi, Charging Points, Water Bottle",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus5.seats, 0, sizeof(bus5.seats));
    buses[num_buses++] = bus5;

    Bus bus6 = {
        .bus_id = 6,
        .name = "Hyderabad Super",
        .source = "Bangalore",
        .destination = "Hyderabad",
        .departure_time = "20:00",
        .arrival_time = "06:00",
        .fare = 2000.0,
        .bus_type = "AC Sleeper",
        .amenities = "WiFi, Charging Points, Blanket, Water Bottle, Dinner",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus6.seats, 0, sizeof(bus6.seats));
    buses[num_buses++] = bus6;

    Bus bus7 = {
        .bus_id = 7,
        .name = "Goa Express",
        .source = "Bangalore",
        .destination = "Goa",
        .departure_time = "19:00",
        .arrival_time = "07:00",
        .fare = 2200.0,
        .bus_type = "AC Sleeper",
        .amenities = "WiFi, Charging Points, Blanket, Water Bottle, Dinner",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus7.seats, 0, sizeof(bus7.seats));
    buses[num_buses++] = bus7;

    Bus bus8 = {
        .bus_id = 8,
        .name = "Kochi Deluxe",
        .source = "Bangalore",
        .destination = "Kochi",
        .departure_time = "21:00",
        .arrival_time = "08:00",
        .fare = 1900.0,
        .bus_type = "AC Sleeper",
        .amenities = "WiFi, Charging Points, Blanket, Water Bottle, Dinner",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus8.seats, 0, sizeof(bus8.seats));
    buses[num_buses++] = bus8;

    Bus bus9 = {
        .bus_id = 9,
        .name = "Pondicherry Express",
        .source = "Bangalore",
        .destination = "Pondicherry",
        .departure_time = "07:30",
        .arrival_time = "14:00",
        .fare = 1100.0,
        .bus_type = "AC Seater",
        .amenities = "WiFi, Charging Points, Water Bottle",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus9.seats, 0, sizeof(bus9.seats));
    buses[num_buses++] = bus9;

    Bus bus10 = {
        .bus_id = 10,
        .name = "Tirupati Express",
        .source = "Bangalore",
        .destination = "Tirupati",
        .departure_time = "06:00",
        .arrival_time = "12:00",
        .fare = 900.0,
        .bus_type = "Non-AC Seater",
        .amenities = "Charging Points",
        .total_seats = 40,
        .available_seats = 40
    };
    memset(bus10.seats, 0, sizeof(bus10.seats));
    buses[num_buses++] = bus10;
}

// Display the main menu
void display_main_menu() {
    printf("\n=== Bus Reservation System ===\n");
    printf("1. View Available Buses\n");
    printf("2. Book Ticket\n");
    printf("3. View Bookings\n");
    printf("4. Cancel Booking\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Display all available buses
void display_buses() {
    if (num_buses == 0) {
        printf("\nNo buses available!\n");
        return;
    }

    printf("\n=== Available Buses ===\n");
    printf("+----+------------------+------------------+------------------+------------------+------------------+------------------+\n");
    printf("| ID |      Name        |      Route       |    Departure     |     Arrival      |       Fare       | Available Seats  |\n");
    printf("+----+------------------+------------------+------------------+------------------+------------------+------------------+\n");

    for (int i = 0; i < num_buses; i++) {
        char route[50];
        sprintf(route, "%s to %s", buses[i].source, buses[i].destination);
        
        printf("| %2d | %-16s | %-16s | %-16s | %-16s | ₹%-14.2f | %-15d |\n",
               buses[i].bus_id,
               buses[i].name,
               route,
               buses[i].departure_time,
               buses[i].arrival_time,
               buses[i].fare,
               buses[i].available_seats);
    }
    printf("+----+------------------+------------------+------------------+------------------+------------------+------------------+\n");
}

// Book tickets for a bus
void book_ticket() {
    int bus_id, num_passengers;
    printf("\nEnter Bus ID: ");
    scanf("%d", &bus_id);
    
    // Find the bus
    Bus* bus = NULL;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    if (!bus) {
        printf("Invalid Bus ID!\n");
        return;
    }
    
    printf("\nEnter number of passengers (max %d): ", MAX_PASSENGERS_PER_BOOKING);
    scanf("%d", &num_passengers);
    
    if (num_passengers <= 0 || num_passengers > MAX_PASSENGERS_PER_BOOKING) {
        printf("Invalid number of passengers! Please enter between 1 and %d.\n", MAX_PASSENGERS_PER_BOOKING);
        return;
    }
    
    if (bus->available_seats < num_passengers) {
        printf("Not enough seats available! Only %d seats left.\n", bus->available_seats);
        return;
    }
    
    // Create a new booking
    Booking booking;
    booking.booking_id = num_bookings + 1;
    booking.bus_id = bus_id;
    booking.total_passengers = num_passengers;
    booking.booking_time = time(NULL);
    booking.total_fare = bus->fare * num_passengers;
    
    printf("\n=== Bus Details ===\n");
    printf("Bus Name: %s\n", bus->name);
    printf("Route: %s to %s\n", bus->source, bus->destination);
    printf("Departure: %s, Arrival: %s\n", bus->departure_time, bus->arrival_time);
    printf("Fare per passenger: ₹%.2f\n", bus->fare);
    printf("Total Fare: ₹%.2f\n", booking.total_fare);
    
    // Get passenger details and select seats
    for (int i = 0; i < num_passengers; i++) {
        printf("\n=== Passenger %d Details ===\n", i + 1);
        
        Passenger passenger;
        passenger.passenger_id = num_passengers + i + 1;
        
        // Get passenger name
        printf("Name: ");
        scanf(" %[^\n]", passenger.name);
        
        // Get passenger age with validation
        do {
            printf("Age: ");
            scanf("%d", &passenger.age);
            if (passenger.age <= 0 || passenger.age > 100) {
                printf("Invalid age! Please enter age between 1 and 100.\n");
            }
        } while (passenger.age <= 0 || passenger.age > 100);
        
        // Get passenger gender with validation
        do {
            printf("Gender (M/F): ");
            scanf(" %c", &passenger.gender);
            passenger.gender = toupper(passenger.gender);
            if (passenger.gender != 'M' && passenger.gender != 'F') {
                printf("Invalid gender! Please enter M or F.\n");
            }
        } while (passenger.gender != 'M' && passenger.gender != 'F');
        
        // Display seat layout and select seat
        display_seat_layout(bus_id);
        printf("Select seat number (1-40): ");
        scanf("%d", &passenger.seat_number);
        
        if (passenger.seat_number < 1 || passenger.seat_number > 40) {
            printf("Invalid seat number! Please select between 1 and 40.\n");
            i--;
            continue;
        }
        
        if (!is_seat_available(bus_id, passenger.seat_number)) {
            printf("Seat already booked! Please select another seat.\n");
            i--;
            continue;
        }
        
        // Add passenger and update booking
        passengers[num_passengers + i] = passenger;
        booking.passenger_ids[i] = passenger.passenger_id;
        booking.seat_numbers[i] = passenger.seat_number;
        bus->seats[passenger.seat_number - 1] = 1;
        bus->available_seats--;
        
        printf("\nPassenger %d details saved successfully!\n", i + 1);
    }
    
    // Add booking to the system
    bookings[num_bookings++] = booking;
    
    printf("\n=== Booking Confirmation ===\n");
    printf("Booking ID: %d\n", booking.booking_id);
    printf("Bus: %s\n", bus->name);
    printf("Route: %s to %s\n", bus->source, bus->destination);
    printf("Departure: %s\n", bus->departure_time);
    
    char time_str[20];
    format_time(booking.booking_time, time_str);
    printf("Booking Time: %s\n", time_str);
    
    printf("\nPassenger Details:\n");
    for (int i = 0; i < booking.total_passengers; i++) {
        Passenger* passenger = NULL;
        for (int j = 0; j < num_passengers; j++) {
            if (passengers[num_passengers + j].passenger_id == booking.passenger_ids[i]) {
                passenger = &passengers[num_passengers + j];
                break;
            }
        }
        
        if (passenger) {
            printf("%d. %s (Age: %d, Gender: %c, Seat: %d)\n",
                   i + 1, passenger->name, passenger->age,
                   passenger->gender, passenger->seat_number);
        }
    }
    
    printf("\nTotal Fare: ₹%.2f\n", booking.total_fare);
    printf("Thank you for booking with us!\n");
}

// View all bookings
void view_bookings() {
    if (num_bookings == 0) {
        printf("\nNo bookings found!\n");
        return;
    }
    
    printf("\n=== All Bookings ===\n");
    for (int i = 0; i < num_bookings; i++) {
        Booking booking = bookings[i];
        Bus* bus = NULL;
        
        // Find the bus
        for (int j = 0; j < num_buses; j++) {
            if (buses[j].bus_id == booking.bus_id) {
                bus = &buses[j];
                break;
            }
        }
        
        printf("\nBooking ID: %d\n", booking.booking_id);
        printf("Bus: %s\n", bus->name);
        printf("Route: %s to %s\n", bus->source, bus->destination);
        printf("Departure: %s\n", bus->departure_time);
        
        char time_str[20];
        format_time(booking.booking_time, time_str);
        printf("Booking Time: %s\n", time_str);
        
        printf("Total Passengers: %d\n", booking.total_passengers);
        printf("Total Fare: ₹%.2f\n", booking.total_fare);
        
        printf("\nPassenger Details:\n");
        for (int j = 0; j < booking.total_passengers; j++) {
            Passenger* passenger = NULL;
            for (int k = 0; k < num_passengers; k++) {
                if (passengers[k].passenger_id == booking.passenger_ids[j]) {
                    passenger = &passengers[k];
                    break;
                }
            }
            
            if (passenger) {
                printf("%d. %s (Age: %d, Gender: %c, Seat: %d)\n",
                       j + 1, passenger->name, passenger->age,
                       passenger->gender, passenger->seat_number);
            }
        }
        printf("-------------------\n");
    }
}

// Cancel a booking
void cancel_booking() {
    int booking_id;
    printf("\nEnter Booking ID to cancel: ");
    scanf("%d", &booking_id);
    
    // Find the booking
    int booking_index = -1;
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].booking_id == booking_id) {
            booking_index = i;
            break;
        }
    }
    
    if (booking_index == -1) {
        printf("Invalid Booking ID!\n");
        return;
    }
    
    Booking booking = bookings[booking_index];
    Bus* bus = NULL;
    
    // Find the bus
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == booking.bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    // Free up the seats
    for (int i = 0; i < booking.total_passengers; i++) {
        bus->seats[booking.seat_numbers[i] - 1] = 0;
        bus->available_seats++;
    }
    
    // Remove the booking
    for (int i = booking_index; i < num_bookings - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    num_bookings--;
    
    printf("Booking cancelled successfully!\n");
}

// Display seat layout for a bus
void display_seat_layout(int bus_id) {
    Bus* bus = NULL;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    if (!bus) {
        printf("Invalid Bus ID!\n");
        return;
    }
    
    printf("\n=== Seat Layout ===\n");
    printf("D - Driver\n");
    printf("X - Booked\n");
    printf("O - Available\n");
    printf("W - Window Seat\n");
    printf("A - Aisle Seat\n\n");
    
    printf("    D\n");
    printf("    |\n");
    
    // Display seats in 2x2 arrangement
    for (int i = 0; i < bus->total_seats; i += 4) {
        // Left side seats (window and aisle)
        printf("%2d:%c ", i + 1, bus->seats[i] ? 'X' : 'W');
        printf("%2d:%c ", i + 2, bus->seats[i + 1] ? 'X' : 'A');
        
        // Aisle
        printf("  |  ");
        
        // Right side seats (aisle and window)
        printf("%2d:%c ", i + 3, bus->seats[i + 2] ? 'X' : 'A');
        printf("%2d:%c\n", i + 4, bus->seats[i + 3] ? 'X' : 'W');
    }
    printf("\n");
}

// Check if a seat is available
int is_seat_available(int bus_id, int seat_number) {
    Bus* bus = NULL;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    if (!bus || seat_number < 1 || seat_number > bus->total_seats) {
        return 0;
    }
    
    return !bus->seats[seat_number - 1];
}

// Calculate fare for a booking
float calculate_fare(int bus_id, int num_passengers) {
    Bus* bus = NULL;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    if (!bus) {
        return 0.0;
    }
    
    return bus->fare * num_passengers;
}

// Parse time string to time_t
time_t parse_time(const char* time_str) {
    struct tm tm = {0};
    sscanf(time_str, "%d:%d", &tm.tm_hour, &tm.tm_min);
    return mktime(&tm);
}

// Format time_t to string
void format_time(time_t time, char* buffer) {
    struct tm* tm = localtime(&time);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tm);
}

// Add a new bus
void add_bus() {
    if (num_buses >= MAX_BUSES) {
        printf("Maximum number of buses reached!\n");
        return;
    }
    
    Bus new_bus;
    printf("\nEnter Bus Details:\n");
    
    new_bus.bus_id = num_buses + 1;
    
    printf("Name: ");
    scanf(" %[^\n]", new_bus.name);
    
    printf("Source: ");
    scanf(" %[^\n]", new_bus.source);
    
    printf("Destination: ");
    scanf(" %[^\n]", new_bus.destination);
    
    printf("Departure Time (HH:MM): ");
    scanf(" %[^\n]", new_bus.departure_time);
    
    printf("Arrival Time (HH:MM): ");
    scanf(" %[^\n]", new_bus.arrival_time);
    
    printf("Fare: ");
    scanf("%f", &new_bus.fare);
    
    printf("Bus Type: ");
    scanf(" %[^\n]", new_bus.bus_type);
    
    printf("Amenities: ");
    scanf(" %[^\n]", new_bus.amenities);
    
    printf("Total Seats: ");
    scanf("%d", &new_bus.total_seats);
    
    new_bus.available_seats = new_bus.total_seats;
    memset(new_bus.seats, 0, sizeof(new_bus.seats));
    
    buses[num_buses++] = new_bus;
    printf("Bus added successfully!\n");
}

// Remove a bus
void remove_bus() {
    int bus_id;
    printf("\nEnter Bus ID to remove: ");
    scanf("%d", &bus_id);
    
    int bus_index = -1;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus_index = i;
            break;
        }
    }
    
    if (bus_index == -1) {
        printf("Invalid Bus ID!\n");
        return;
    }
    
    // Check if bus has any bookings
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].bus_id == bus_id) {
            printf("Cannot remove bus with active bookings!\n");
            return;
        }
    }
    
    // Remove the bus
    for (int i = bus_index; i < num_buses - 1; i++) {
        buses[i] = buses[i + 1];
    }
    num_buses--;
    
    printf("Bus removed successfully!\n");
}

// Modify bus details
void modify_bus() {
    int bus_id;
    printf("\nEnter Bus ID to modify: ");
    scanf("%d", &bus_id);
    
    Bus* bus = NULL;
    for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus = &buses[i];
            break;
        }
    }
    
    if (!bus) {
        printf("Invalid Bus ID!\n");
        return;
    }
    
    printf("\nCurrent Bus Details:\n");
    printf("1. Name: %s\n", bus->name);
    printf("2. Source: %s\n", bus->source);
    printf("3. Destination: %s\n", bus->destination);
    printf("4. Departure Time: %s\n", bus->departure_time);
    printf("5. Arrival Time: %s\n", bus->arrival_time);
    printf("6. Fare: %.2f\n", bus->fare);
    printf("7. Bus Type: %s\n", bus->bus_type);
    printf("8. Amenities: %s\n", bus->amenities);
    printf("9. Total Seats: %d\n", bus->total_seats);
    
    int choice;
    printf("\nEnter field number to modify (1-9): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("New Name: ");
            scanf(" %[^\n]", bus->name);
            break;
        case 2:
            printf("New Source: ");
            scanf(" %[^\n]", bus->source);
            break;
        case 3:
            printf("New Destination: ");
            scanf(" %[^\n]", bus->destination);
            break;
        case 4:
            printf("New Departure Time (HH:MM): ");
            scanf(" %[^\n]", bus->departure_time);
            break;
        case 5:
            printf("New Arrival Time (HH:MM): ");
            scanf(" %[^\n]", bus->arrival_time);
            break;
        case 6:
            printf("New Fare: ");
            scanf("%f", &bus->fare);
            break;
        case 7:
            printf("New Bus Type: ");
            scanf(" %[^\n]", bus->bus_type);
            break;
        case 8:
            printf("New Amenities: ");
            scanf(" %[^\n]", bus->amenities);
            break;
        case 9:
            printf("New Total Seats: ");
            scanf("%d", &bus->total_seats);
            bus->available_seats = bus->total_seats;
            memset(bus->seats, 0, sizeof(bus->seats));
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    
    printf("Bus details modified successfully!\n");
}

// Main function
int main() {
    initialize_system();
    
    while (1) {
        display_main_menu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_buses();
                break;
            case 2:
                book_ticket();
                break;
            case 3:
                view_bookings();
                break;
            case 4:
                cancel_booking();
                break;
            case 5:
                printf("Thank you for using the Bus Reservation System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
} 
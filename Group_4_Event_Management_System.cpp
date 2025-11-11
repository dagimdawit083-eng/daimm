
#include <iostream>
#include <queue>
#include <string>
using namespace std;

// User structure to store ID and name
struct User {
    int id;
    string name;
};

// Event structure to hold event details and registration queue
struct Event {
    int eventId;               // Unique event identifier
    string eventName;          // Name of the event
    int totalSeats;            // Total seats available for booking
    int bookedSeats;           // Seats that have already been booked
    queue<User> registrationQueue; // Queue to manage user registrations
};

// Function to register a user for the event
void registerUser(Event &e, User u) {
    if (e.bookedSeats >= e.totalSeats) {
        cout << "Event is fully booked. Cannot register user." << endl;
        return;
    }
    e.registrationQueue.push(u); // Add user to the queue
    cout << "User " << u.name << " registered successfully." << endl;
}

// Function to book a seat for the next user in the registration queue
void bookSeat(Event &e) {
    if (e.registrationQueue.empty()) {
        cout << "No users in the registration queue." << endl;
        return;
    }
    if (e.bookedSeats >= e.totalSeats) {
        cout << "All seats are already booked." << endl;
        return;
    }
    User u = e.registrationQueue.front(); // Get the first user
    e.registrationQueue.pop();            // Remove them from the queue
    e.bookedSeats++;                      // Increment the booked seats
    cout << "Seat booked for user: " << u.name << endl;
}

// Function to display event details
void displayEvent(const Event &e) {
    cout << "\nEvent Details:" << endl;
    cout << "Event ID: " << e.eventId << endl;
    cout << "Event Name: " << e.eventName << endl;
    cout << "Total Seats: " << e.totalSeats << endl;
    cout << "Booked Seats: " << e.bookedSeats << endl;
    cout << "Seats Available: " << e.totalSeats - e.bookedSeats << endl;
    cout << "Users waiting in queue: " << e.registrationQueue.size() << endl;
}

// Main function demonstrating registration and booking
int main() {
    // Create an event
    Event e = {1, "Tech Conference", 3, 0};

    // Create users
    User u1 = {101, "Alice"};
    User u2 = {102, "Bob"};
    User u3 = {103, "Charlie"};
    User u4 = {104, "Diana"};

    // Register users
    registerUser(e, u1);
    registerUser(e, u2);
    registerUser(e, u3);
    registerUser(e, u4);  // Will be queued if seat limit reached

    // Book seats
    bookSeat(e);
    bookSeat(e);
    bookSeat(e);

    // Display event information
    displayEvent(e);

    return 0;
}
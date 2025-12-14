#include "splashkit.h"
using std::stod;
using std::stoi;
using std::string;
using std::to_string;

int main()
{
    const int NUM_BUILDINGS = 13;

    string building_names[NUM_BUILDINGS] = {
        "Building_B : Student Service for International Students",
        "Building_W : Clinical Simulation Center",
        "Building_Y : Faculty of health",
        "Building_J : Exercise, Nutrition and Sport science",
        "Building_U : Indoor Exercise",
        "Building_X : Lecture Theatre",
        "Building_I : Hall and Tutorial Room",
        "Building_FA : Art Gallery",
        "Building_V : Library",
        "Building_H : Learning Space",
        "Building_BC : Burwood Corporate Center",
        "Building_A : Student Association Hub",
        "Building_P : Studio building"};

    int building_x[NUM_BUILDINGS] = {5, 4, 4, 1, 1, 9, 12, 1, 9, 10, 10, 9, 1};
    int building_y[NUM_BUILDINGS] = {9, 6, 4, 7, 5, 10, 10, 13, 12, 6, 2, 8, 10};

    int opening_hours[NUM_BUILDINGS] = {9, 8, 8, 7, 6, 8, 9, 10, 8, 9, 9, 8, 7};
    int closing_hours[NUM_BUILDINGS] = {17, 20, 18, 22, 23, 22, 21, 17, 23, 17, 17, 22, 21};

    // 1=Wifi 2=Library, 4=Cafe, 8=Study Area 16=Printer 32=Computers 64=Parking 128=Gym 256=Student Support
    int facilities[NUM_BUILDINGS] = {9, 265, 265, 129, 128, 25, 57, 1, 306, 41, 273, 277, 5};

    int starting_building_index = -1;
    int ending_building_index = -1;
    int current_time = 0;

    int user_choice;
    string continue_further;

    write_line("Welcome to Campus Navigation Assistant!");
    write_line("This assistant will help you navigate through the campus buildings,");
    write_line("give information about the buildings and give you directions.");

    write_line("Could you please enter the current time in 24-hour format (0-23):");
    current_time = stoi(read_line());

    if (current_time < 0)
        current_time = 0;
    if (current_time > 23)
        current_time = 23;

    write_line("==================================================");
    write_line("      CAMPUS NAVIGATION ASSISTANT");
    write_line("==================================================");
    write_line("Current time: " + to_string(current_time) + ":00");
    write_line("==================================================");
    write_line("");

    write_line("Please select from the following options:");
    write_line("1. View list of all buildings");
    write_line("2. Get information about a building");
    write_line("3. Find facilities available in a building");
    write_line("4. Check if a building is open or not");
    write_line("5. Get directions between two buildings");
    write_line("6. Search buildings by facility");
    write_line("7. Exit Campus Navigation Assistant");
    write_line("");

    write_line("Enter your choice (1-7): ");
    user_choice = stoi(read_line());

    if (user_choice == 1)
    {
        write_line("           ALL CAMPUS BUILDINGS");
        write_line("");

        for (int i = 0; i < NUM_BUILDINGS; i++)
        {
            write_line("Building " + to_string(i + 1) + ": " + building_names[i]);
            write_line("");

        }

        write_line("Press Enter to continue...");
        read_line();
    }
    else if (user_choice == 2)
    {
    write_line("       BUILDING INFORMATION");

    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        write_line(to_string(i + 1) + ". " + building_names[i]);
    }
    write_line("");

    write_line("Enter building number (1-" + to_string(NUM_BUILDINGS) + "): ");
    int building_num = stoi(read_line()) - 1;

    if (building_num >= 0 && building_num < NUM_BUILDINGS)
    {
        write_line("    " + building_names[building_num]);
        write_line("Location: (" + to_string(building_x[building_num]) + ", " + to_string(building_y[building_num]) + ")");
        write_line("Hours: " + to_string(opening_hours[building_num]) + ":00 - " + to_string(closing_hours[building_num]) + ":00");
        if (current_time >= opening_hours[building_num] && current_time < closing_hours[building_num])
            write_line("Current Status: OPEN");
        else
            write_line("Current Status: CLOSED");
        write_line("");
        write_line("Press Enter to continue...");
        read_line();
    }
    else
    {
        write_line("Invalid building number!");
        write_line("Press Enter to continue...");
        read_line();
    }
}
else if (user_choice == 3)
{
    write_line("       BUILDING FACILITIES");
    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        write_line(to_string(i + 1) + ". " + building_names[i]);
    }
    write_line("");
    write_line("Enter building number (1-" + to_string(NUM_BUILDINGS) + "): ");
    int building_num = stoi(read_line()) - 1;

    if (building_num >= 0 && building_num < NUM_BUILDINGS)
    {
        write_line("Facilities available in " + building_names[building_num]);
        int facility_flags = facilities[building_num];
        write_line("Available facilities:");

        if ((facility_flags & 1) != 0){
            write_line("✓ WiFi");
        }
        else if ((facility_flags & 2) != 0){
            write_line("✓ Library");
        }
        else if ((facility_flags & 4) != 0){
            write_line("✓ Cafe");
        }
        else if ((facility_flags & 8) != 0){
            write_line("✓ Study Area");
        }
        else if ((facility_flags & 16) != 0){
            write_line("✓ Printer");
        }
        else if ((facility_flags & 32) != 0){
            write_line("✓ Computers");
        }
        else if ((facility_flags & 64) != 0){
            write_line("✓ Parking");
        }
        else if ((facility_flags & 128) != 0){
            write_line("✓ Gym");
        }
        else if ((facility_flags & 256) != 0){
            write_line("✓ Student Support");
        }

        write_line("");
        write_line("Press Enter to continue...");
        read_line();
    }
    else
    {
        write_line("Invalid building number!");
        write_line("Press Enter to continue...");
        read_line();
    }
}
else if (user_choice == 4)
{
    write_line("       BUILDING OPEN/CLOSED STATUS");
    write_line("");
    write_line("Current time: " + to_string(current_time) + ":00");
    write_line("");

    write_line("Building Status:");
    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        string status;
        if (current_time >= opening_hours[i] && current_time < closing_hours[i])
            status = "OPEN";
        else
            status = "CLOSED";

        write_line(building_names[i] + ": " + status);
    }

    write_line("");
    write_line("Press Enter to continue...");
    read_line();
}
else if (user_choice == 5)
{
    write_line("       BUILDING DIRECTIONS");
    write_line("");

    write_line("Select STARTING building:");
    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        write_line(to_string(i + 1) + ". " + building_names[i]);
    }
    write_line("");

    write_line("Enter starting building number (1-" + to_string(NUM_BUILDINGS) + "): ");
    starting_building_index = stoi(read_line()) - 1;

    write_line("Select DESTINATION building:");
    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        write_line(to_string(i + 1) + ". " + building_names[i]);
    }
    write_line("");

    write_line("Enter destination building number (1-" + to_string(NUM_BUILDINGS) + "): ");
    ending_building_index= stoi(read_line()) - 1;

    if (starting_building_index >= 0 && starting_building_index < NUM_BUILDINGS &&
        ending_building_index >= 0 && ending_building_index < NUM_BUILDINGS)
    {

        write_line("           DIRECTIONS");
        write_line("");

        write_line("From: " + building_names[starting_building_index]);
        write_line("To: " + building_names[ending_building_index]);
        write_line("");

        int x_distance = building_x[ending_building_index] - building_x[starting_building_index];
        int y_distance = building_y[ending_building_index] - building_y[starting_building_index];

        int abs_x = (x_distance < 0) ? -x_distance : x_distance;
        int abs_y = (y_distance < 0) ? -y_distance : y_distance;

        int total_distance = abs_x + abs_y;
        int walking_minutes = total_distance * 2;

        write_line("Grid Distance: " + to_string(total_distance) + " units");
        write_line("Estimated walking time: " + to_string(walking_minutes) + " minutes");
        write_line("");

        write_line("Directions:");
        write_line("-----------");

        if (x_distance > 0){

            write_line("1. Walk " + to_string(abs_x) + " units EAST");
        }
        else if (x_distance < 0){

            write_line("1. Walk " + to_string(abs_x) + " units WEST");
        }

        if (y_distance > 0){

            write_line("2. Walk " + to_string(abs_y) + " units NORTH");
        }
        else if (y_distance < 0){

            write_line("2. Walk " + to_string(abs_y) + " units SOUTH");
        }

        if (x_distance == 0 && y_distance == 0){

            write_line("You are already at this building!");
        }

        write_line("");
        write_line("Note: Each unit is approximately 100 meters.");
        write_line("");

        write_line("Press Enter to continue...");
        read_line();
    }
    else
    {
        write_line("Invalid building selection!");
        write_line("Press Enter to continue...");
        read_line();
    }
}
else if (user_choice == 6)
{
    write_line("       SEARCH BUILDINGS BY FACILITY");
    write_line("");

    write_line("Select facility to search for:");
    write_line("1. WiFi");
    write_line("2. Library");
    write_line("3. Cafe");
    write_line("4. Study Area");
    write_line("5. Printer");
    write_line("6. Computers");
    write_line("7. Parking");
    write_line("8. Gym");
    write_line("9. Student Support");
    write_line("");

    write_line("Enter facility number (1-9): ");
    int facility_choice = stoi(read_line());

    int facility_bit = 1;
    if (facility_choice == 2){

        facility_bit = 2;
    }
    else if (facility_choice == 3){
        facility_bit = 4;
    }
    else if (facility_choice == 4){
        facility_bit = 8;
    }
    else if (facility_choice == 5){
        facility_bit = 16; 
    }
    else if (facility_choice == 6)
        facility_bit = 32;
    else if (facility_choice == 7)
        facility_bit = 64;
    else if (facility_choice == 8)
        facility_bit = 128;
    else if (facility_choice == 9)
        facility_bit = 256;

    
    write_line("");

    string facility_name;
    if (facility_choice == 1)
        facility_name = "WiFi";
    else if (facility_choice == 2)
        facility_name = "Library";
    else if (facility_choice == 3)
        facility_name = "Cafe";
    else if (facility_choice == 4)
        facility_name = "Study Area";
    else if (facility_choice == 5)
        facility_name = "Printer";
    else if (facility_choice == 6)
        facility_name = "Computers";
    else if (facility_choice == 7)
        facility_name = "Parking";
    else if (facility_choice == 8)
        facility_name = "Gym";
    else if (facility_choice == 9)
        facility_name = "Student Support";
    else
        facility_name = "Unknown Facility";

    write_line("Buildings with " + facility_name);
    write_line("");

    int found_count = 0;
    for (int i = 0; i < NUM_BUILDINGS; i++)
    {
        if ((facilities[i] & facility_bit) != 0)
        {
            write_line("• " + building_names[i]);
            found_count = found_count + 1;
        }
    }

    if (found_count == 0)
        write_line("No buildings have this facility.");
    else
        write_line("\nFound " + to_string(found_count) + " building(s) with this facility.");

    write_line("");
    write_line("Press Enter to continue...");
    read_line();
}
else if (user_choice == 7)
{
    write_line("");
    write_line("Thank you for using Campus Navigation Assistant!");
}
else
{
    write_line("Invalid choice! Please enter a number between 1 and 7.");
    write_line("Press Enter to continue...");
    read_line();
}
return 0;
}

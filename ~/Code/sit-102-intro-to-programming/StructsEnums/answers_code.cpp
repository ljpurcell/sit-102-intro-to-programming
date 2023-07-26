#include "splashkit.h"
#include "string.h"

using namespace std;

// Struct to hold basic user details, which all users will have
struct account_details
{
    string name;
    string email;
    string password;
    int age;
    unsigned long followers;
    unsigned long following;
};

enum update_personal_details
{
    CHANGE_NAME,
    CHANGE_EMAIL,
    CHANGE_AGE
};

enum update_social_details
{
    START_FOLLOWING,
    STOP_FOLLOWING,
    RECEIVED_FOLLOWER,
    LOST_FOLLOWER
}; 



int main()
{

    return 0;
}
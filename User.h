#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User
{
    private:
        static int userCount;
        string name,email,password;
    public:
    	User() {}
    	int userId;
        User(string n, string e, string p);
        virtual void displaydetails() const;
        string getName() { return name; }
        string getEmail() { return email; }
        string getPassword() { return password; }
        static getUserCount() { return userCount; }
        virtual ~User() {}
};
#endif
//Pantu Mihnea-Andrei 322AC
//Comfort_Flights: An application that helps costumers to book flights from
//the national airport Henri Coanda, Otopeni, Bucharest to multiple locations of the world.

#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

int remove_val(string arr[], string arr2[], string arr3[], int size1, string val)
{
  int i, count1 = 0;

  for (i = 0; i < size1; i++) {
    if (arr[i + count1] == val) count1++;
    arr[i] = arr[i+ count1];
    arr2[i] = arr2[i+count1];
    arr3[i] = arr3[i+count1];
  }
  return size1-count1;
}


long int p = 47, q = 53, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
void decrypt();

int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
        {
            if (pr % i == 0)
                return 0;
        }
    return 1;
}


string admin_usernames[100] = {"admin1","admin2","admin3"};
string admin_passwords[100] = {"ADMIN1","ADMIN2","ADMIN3",};

string common_usernames[100] = {"john", "luca2306", "michael_23", "dana45", "andrew56", "marcus22", "amanda12"};
string common_passwords[100] = {"john32", "paris1", "lara455", "car2345", "fastcar435", "mypass23", "holden33"};
string emails[100] = {"john@yahoo.com","luca@yahoo.com","dana_work@yahoo.com","andrew@yahoo.com", "marcus24@gmail.com", "amanda21@outlook.com"};


string flights[100] = {"Wien", "Paris", "Dubai", "Athens", "Rome", "Berlin", "Wien", "Dubai"};
string countries[100] = {"Austria", "France", "UAE", "Greece", "Italy", "Germany", "Austria", "UAE"};
string dates[100] = {"23052022","24062022","12122021","16032022","05042022","19012022","01012022","30092022"};

int nOfAdminUsers = 3, nOfAdminPass = 3, nOfCommUser = 7, nOfCountries = 8;
int nOfCommPass = 7, nOfFlights = 8, nOfDates = 8, nOfEmails = 7;

char good_chars [100] = {"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM"};




int userCheck(string username)
{
    int i,checker = 1;

    for(i = 0; i < nOfCommUser; i++)
    {
        if(username == common_usernames[i])
        {
            checker--;
            break;
        }
    }

    return checker;
}


int textChecker(string text)
{
    int i,checker = 0, j;

    int ts = text.size();
    int gc = strlen(good_chars);

    for(i = 0; i < ts; i++)
    {
        for(j = 0; j < gc; j++)
        {
            if (text[i] == good_chars[j])
            {
                checker++;
            }
        }
    }

    if(checker == ts) return 1;
    else return 0;


}



int format_date(string date)
{
    int day,month,checker = 0,year;
    string dayc,monthc,yearc;

    dayc[0] = date[0];
    dayc[1] = date[1];

    monthc[0] = date[2];
    monthc[1] = date[3];

    yearc[0] = date[4];
    yearc[1] = date[5];
    yearc[2] = date[6];
    yearc[3] = date[7];

    day = stoi(dayc);
    month = stoi(monthc);
    year = stoi(yearc);


    time_t now = time(0);

    tm *ltm = localtime(&now);

    int current_day, current_month, current_year;

    current_day = ltm->tm_mday;
    current_month = 1 + ltm->tm_mon;
    current_year = 1900 + ltm->tm_year;

    if(year < current_year) checker++;

    if(year == current_year)
    {
        if(month < current_month) checker++;
        else if (month >= current_month)
        {
            if(day < current_day) checker++;
        }
    }


    if(day < 1 || day > 31) checker++;
    if(month < 1 || month > 12 ) checker++;

    if(checker == 0) return 1;
    else return 0;

}




class Account
{
private:
    string username;
    string password;
    string booked_flight;
    string country;
    string date;
    string email;
public:

    Account()
    {
        username = "Empty";
        booked_flight = "Empty";
        country = "Empty";
        date = "0";
        email = "Empty";
    }

    void setUserPass(string user, string pass)
    {
        this->username = user;
        this->password = pass;
    }

    void setEmail(string mail)
    {
         this->email = mail;
    }

    void setCountry(string country)
    {
        this->country = country;
    }

    void addAccount(string username, string password, string mail)
    {
        common_usernames[nOfCommUser] = username;
        nOfCommUser++;

        common_passwords[nOfCommPass] = password;
        nOfCommPass++;

        emails[nOfEmails] = mail;
        nOfEmails++;
    }


    void bookFlight_and_Date(string country, string destination, string date)
    {
        this->country = country;
        this->booked_flight = destination;
        this->date = date;
    }


    int checkLogin ()
    {
        int i, checker = 0;

        for(i = 0; i < nOfCommUser; i++)
        {
            if(this->username == common_usernames[i] && this->password == common_passwords[i])
            {
                checker++;
                this->email = emails[i];
                break;
            }
        }

        return checker;
    }



      int checkFlight(string destination)
        {
            int i,checker = 0;
            for(i = 0; i < nOfFlights; i++)
            {
                if(destination == countries[i])
                {
                    checker++;
                    break;
                }
            }

            return checker;
        }


        int checkEmail(string mail)
        {
            int i,checker = 0, length, poz;

            length = mail.length();

            for(i = 0; i < length; i++)
            {
                if(mail[i] == '@' && i < length - 5)
                {
                    checker++;
                    poz = i;
                }
            }

            for(i = poz +  2; i < length; i++)
            {
                if(mail[i] == '.' && i < length - 3)
                {
                    checker++;
                    poz = i;
                }

            }

            if (checker == 2) return 1;
            else return 0;
        }


        string getUsername()
        {
            return this->username;
        }

        string getCountry()
        {
            return this->country;
        }

        string getFlight()
        {
            return this->booked_flight;
        }

        void getDate()
        {
            string format;
            format = this->date;

            cout << format[0] << format[1] << " ";
            cout << format[2] << format[3] << " ";
            cout << format[4] << format[5] <<  format[6] << format[7];

        }

        string getEmail()
        {
            return this->email;
        }
};



class AdminAccount
{
private:
    string username;
    string password;

public:

    void setUserPass(string user, string pass)  //Principiul de incapsulare a datelor pentru a oferi o mai buna securitate a datelor.
    {
        this->username = user;
        this->password = pass;
    }

    void addAccount(string username, string password)
    {

        admin_usernames[nOfAdminUsers] = username;
        nOfAdminUsers++;

        admin_passwords[nOfAdminPass] = password;
        nOfAdminPass++;

    }

    int checkLogin ()
    {
        int i, checker = 0;

        for(i = 0; i < nOfCommUser; i++)
        {
            if(this->username == admin_usernames[i] && this->password == admin_passwords[i])
            {
                checker++;
                break;
            }

        }
        return checker;
    }

    void addFlights(string destination, string date, string country)
    {
        flights[nOfFlights++] = destination;
        dates[nOfDates++] = date;
        countries[nOfCountries++] = country;
    }

    void deleteFlights(string destination)
    {
      int i,checkDest = 0;

      for(i = 0; i < nOfFlights; i++)
      {
        if(flights[i] == destination)
        {
            checkDest = 1;
            break;
        }
      }

     if(checkDest == 1)
     {
         nOfFlights = remove_val(flights,dates, countries, nOfFlights,destination);
         nOfDates = nOfFlights;
         nOfCountries = nOfFlights;

         cout << "Flights to " << destination << " has been removed successfully!";


     }
     else if(checkDest == 0) cout << "No flights to this destination!";
    }

};




int main()
{

string username, password,email,copy_pass;
int choice;

    p = 47;
    q = 53;

do{


    cout << "\t\t\t\tWelcome to Comfort_Flights! \n\n" << "Please introudce one option: \n\n";

    cout << endl
    <<"1.Log in as a user.\n"
    <<"2.Log in as an operator.\n"
    <<"3.Create an account.\n"
    <<"4.End of program.\n\n";


    cin >> choice;


    switch(choice)
    {
    case 1:
        {
        cout << "USERNAME: ";
        cin >> username;
        cout << "PASSWORD: ";
        cin >> password;

        Account account1;
        string dest;
        char answer1;
        int logcheck,answer2,answer;


        account1.setUserPass(username,password);

        logcheck = account1.checkLogin();


        while (logcheck == 0)
        {
            try{
                if(logcheck == 0)
                {
                    cout << "Can't log in! Wrong username or password! "
                    << "If you do not have an account you can create one!\n";

                    throw logcheck;
                }
            }
                catch (int logcheck)
                {
                    cout << "Press 1 to try again or any number to get out of login session: ";
                }

                cin >> answer2;

                if(answer2 == 1)
                {
                    cout << "USERNAME: ";
                    cin >> username;
                    cout << "PASSWORD: ";
                    cin >> password;

                    account1.setUserPass(username,password);

                    logcheck = account1.checkLogin();
                }
                else break;

        }


        if(logcheck == 1)
        {

            cout << "Loged in successfully!\n";
            cout << "Enter your country destination: ";

            cin >> dest;

            int check;

            check = account1.checkFlight(dest);

            while (check == 0)
            {
                try{
                    if(check == 0)
                    {
                        cout << "Unavailable flights to this country!\n";
                        throw check;
                    }
                }
                catch(int check)
                {
                    cout << "Press 1 to enter another destination or any number to get out of your session: ";
                }

                cin >> answer;

                if(answer == 1)
                {
                    cout << "New destination: ";
                    cin >> dest;
                    check = account1.checkFlight(dest);
                }
                else break;

            }

            if (check == 1)
            {
                cout << "There are flights available for this destination!\n";
                cout << "Dates:\n";
                for(int i = 0; i < nOfCountries; i++)
                {
                    if(dest == countries[i])
                    {
                        cout << flights[i] << " ";
                        cout << dates[i][0] << dates[i][1] << " ";
                        cout << dates[i][2] << dates[i][3] << " ";
                        cout << dates[i][4] << dates[i][5] << dates[i][6] << dates[i][7];
                        cout << endl;

                        cout<<"Do you want to book this flight? Y/N";
                        cin >> answer1;

                        if(answer1 == 'Y' or answer1 == 'y')
                        {
                            account1.bookFlight_and_Date(dest,flights[i],dates[i]);
                            cout << "\nFlight booked successfully!\n\n";

                            break;

                        }
                    }
                }


            }

        }



        cout << "\nAccount information:\n"
        << "Username: " << account1.getUsername() << "\n"
        << "Email: " << account1.getEmail() << "\n"
        <<"Booked flight: " <<account1.getCountry() << "  (Bucharest --> " << account1.getFlight() << ")" <<"\n"
        << "Date: ";
        account1.getDate();

        cout << "\n\n\n";

        break;
        }



    case 2:
        {

        int newFlights, logcheck, spellcheck,checkd1;

        cout << "USERNAME: ";
        cin >> username;
        cout << "PASSWORD: ";
        cin >> password;

        AdminAccount account;
        string dest,date,dest2,country;
        char answer,answer2;
        int answer3;

        account.setUserPass(username,password);

        logcheck = account.checkLogin();


        while (logcheck == 0)
        {
            try{
                if(logcheck == 0)
                {
                    cout << "Can't log in! Wrong username or password! "
                    << "If you do not have an account you can create one!\n";

                    throw logcheck;
                }
            }
                catch (int logcheck)
                {
                    cout << "Press 1 to try again or any number to get out of login session: ";
                }

                cin >> answer3;

                if(answer3 == 1)
                {
                    cout << "USERNAME: ";
                    cin >> username;
                    cout << "PASSWORD: ";
                    cin >> password;

                    account.setUserPass(username,password);

                    logcheck = account.checkLogin();
                }
                else break;

        }



        if(account.checkLogin() == 1)
        {
            cout << "Loged in! *ADMIN ACCOUNT*\n\n";
            cout << "Do you want to add new flights? Y/N";
            cin >> answer;

            if(answer == 'Y' or answer == 'y')
            {
                cout << "How many flights do you want to add? ";
                cin >> newFlights;

                for(int i = 0; i < newFlights; i++)
                {
                   cout << "Country: ";
                   cin >> country;

                   spellcheck = textChecker(country);

                   while(spellcheck == 0)
                   {
                       try{
                           if (spellcheck == 0)
                           {
                               cout << "You introduced wrong characters in country's name.\n";
                               throw spellcheck;
                           }
                       }
                       catch (int spellcheck)
                       {
                           cout << "Enter the country again: \n";
                       }

                       cin >> country;
                       spellcheck = textChecker(dest);
                   }



                   cout << "New destination: ";
                   cin >> dest;

                   spellcheck = textChecker(dest);


                   while(spellcheck == 0)
                   {
                       try{
                           if (spellcheck == 0)
                           {
                               cout << "You introduced wrong characters in destiantion's name.\n";
                               throw spellcheck;
                           }
                       }
                       catch (int spellcheck)
                       {
                           cout << "Enter the destination again: \n";
                       }

                       cin >> dest;
                       spellcheck = textChecker(dest);
                   }



                   cout << "Date of flight: ";
                   cin >> date;

                   checkd1 = format_date(date);

                   while(checkd1 == 0)
                   {
                       try{
                           if(checkd1 == 0)
                           {
                               cout << "You introduced date in a wrong format or a date in the past!\n";
                               throw checkd1;
                           }
                       }
                       catch (int checkd1)
                       {
                           cout << "Enter the date again: ";
                       }

                       cin >> date;
                       checkd1 = format_date(date);
                   }


                   account.addFlights(dest,date,country);
                }
            }

            cout << "Do you want to delete existing flights? Y/N";

            cin >> answer2;

            while (answer2 == 'Y' || answer2 == 'y')
            {

                cout << "Choose the destination for the cancelled flights: ";
                cin >> dest2;

                account.deleteFlights(dest2);

                cout << "\nThe flights to this destination were removed succesfully!\n";

                cout << "Do you want to continue? Y/N \n";
                cin >> answer2;
            }

            cout << "Your session as an admin has ended.\n";

        }


        break;
        }


    case 3:
        {
        Account account2;

        int user_checker,echeck;


        cout << "Write your username: ";
        cin >> username;

        user_checker = userCheck(username);

        while(user_checker != 1)
        {
            try{
                if(user_checker != 1)
                {
                    cout << "\nUsername already exists!\n";
                    throw user_checker;
                }
            }
            catch(int user_checker)
            {
                cout << "\nEnter another username\n";
            }

            cin >> username;
            user_checker = userCheck(username);
        }



        cout << "Write your password: ";
        cin >> password;


         while(password.size() < 5 || password == username)
        {
            try{
                if(password.size() < 5)
                {
                    cout << "Password is too short!";
                    throw password;
                }
            }
            catch (string password)
            {
                cout << "Enter a stronger password ";
            }

            try{
                if(password == username)
                {
                    cout << "Password is too weak!";
                    throw password;
                }
            }
            catch (string password)
            {
                cout << " Enter a stronger password: ";
            }

            cin >> password;

        }


        cout << "Enter your password again: ";
        cin >> copy_pass;



        while(password != copy_pass)
        {
         try{
             if(password != copy_pass)
             {
                 cout << "You need to introduce the same password twice.\n";
                 throw copy_pass;
             }
          }
          catch (string copy_pass)
          {
          cout << "Enter the password again: ";
          }

          cin >> copy_pass;

        }


        cout << "Please enter your email: ";
        cin >> email;

        echeck = account2.checkEmail(email);

        while(echeck != 1)
        {
            try{
                if(echeck != 1)
                {
                    cout << "Incorrect email format! Write your email in this format: somebody@yahoo.com\n";
                    throw echeck;
                }
            }
            catch(int echeck)
            {
                cout << "Please enter your email: ";
            }

            cin >> email;
            echeck = account2.checkEmail(email);
        }



        int psize = password.size();

        for(i = 0; i < psize; i++)
        {
            msg[i] = password[i];
        }

        for (i = 0; msg[i] != NULL; i++)
        m[i] = msg[i];
        n = p * q;
        t = (p - 1) * (q - 1);
        ce();

        encrypt();
        decrypt();



        cout << "\nAccount created sucessfully! Press 1 to log in!\n\n";


        account2.setUserPass(username,password);
        account2.setEmail(email);
        account2.addAccount(username,password,email);


        break;
        }

    case 4:
        {
        cout << "End of program! Thank you for using Comfort_Flights!\n";
        break;
        }

    default:
        {
        cout << "\nIncorrect option! Please introduce your option again!\n\n";
        break;
        }



    }

}while(choice != 4);



    return 0;
}



void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
        {
            if (t % i == 0)
                continue;
            flag = prime(i);
            if (flag == 1 && i != p && i != q)
                {
                    e[k] = i;
                    flag = cd(e[k]);
                    if (flag > 0)
                        {
                            d[k] = flag;
                            k++;
                        }
                    if (k == 99)
                        break;
                }
        }
}



long int cd(long int x)
{
    long int k = 1;
    while (1)
        {
            k = k + t;
            if (k % x == 0)
                return (k/x);
        }
}



void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
        {
            pt = m[i];
            pt = pt - 96;
            k = 1;
            for (j = 0; j < key; j++)
                {
                    k = k * pt;
                    k = k % n;
                }
            temp[i] = k;
            ct = k + 96;
            en[i] = ct;
            i++;
        }
    en[i] = -1;
    cout << "\nLOADING THE ENCRYPTION PROCESS...\n";
    cout << "\nTHE ENCRYPTED PASSWORD IS:\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);

    cout << "\n";
}


void decrypt()
{
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
        {
            ct = temp[i];
            k = 1;
            for (j = 0; j < key; j++)
                {
                    k = k * ct;
                    k = k % n;
                }
            pt = k + 96;
            m[i] = pt;
            i++;
        }
    m[i] = -1;
    cout << "\nTHE DECRYPTED PASSWORD IS: \n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);

    cout << "\n";
}

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

string usernames[10];
string passWord[10];
string name[10];
string nameInList[10];
string regNumber[10];
int regNumberInList[10];
float aggrigate[10];
int ecatMarks[10];

int index = 0;
int idx = 0;
string stuUserName, stuPassword, adminUserName, adminPassword;
string stuname, fname, gender, address, religion, matricBoard, interBoard, email, cnic, phoneNo, preference;
int interMarks, matricMarks, age;

string home();
string loginPage(string option);
string adminRegistration();
string studentRegistration();
string getField(string record, int field);
void readData(string option);
bool isPresent(string namess, string passwordss);
string login(string option);
string adminIndex();
string applications();
string addStudent();
string searchStudent();
string updateRollNo();
string deleteStudent();
string addList();
string meritList();
string studentIndex();
string applyForAdmission();
string profile();
string schedule();
string testResult();
float meritCalculator();
string admissionCriteria();
string meritDivision();

int main()
{
    system("color 02");
    string userOption, loginOption, adminOption, studentOption;
    float aggrigate;
home:
    userOption = home();
    system("cls");
    if (userOption == "1")
    {
    adminLoginBack:
        loginOption = loginPage(userOption);
        system("cls");

        if (loginOption == "1")
        {
            string reg = adminRegistration();
            cout << reg;
            getch();
            system("cls");
            readData(userOption);
            string logIn = login(userOption);
            if (logIn == "No" || logIn == "no")
            {
                system("cls");
                goto loginBack;
            }
        }
        else if (loginOption == "2")
        {
            readData(userOption);
            string logIn = login(userOption);
            if (logIn == "No" || logIn == "no")
            {
                system("cls");
                goto adminLoginBack;
            }
        }
        else if (loginOption == "3")
        {
            goto home;
        }
        else if (loginOption == "4")
        {
            return 0;
        }
        getch();
        system("cls");

        while (true)
        {
            adminOption = adminIndex();
            cout << endl;
            if (adminOption == "1")
            {
                cout << "You have choosen Option 1: View all Students" << endl
                     << endl;
                string appli = applications();
                cout << appli;
            }
            else if (adminOption == "2")
            {
                cout << "You have choosen Option 2: Add Student" << endl
                     << endl;
                string add = addStudent();
                cout << add;
            }
            else if (adminOption == "3")
            {
                cout << "You have choosen Option 3: Search a Student by Name" << endl
                     << endl;
                string output = searchStudent();
                cout << output;
            }
            else if (adminOption == "4")
            {
                cout << "You have choosen Option 4: Change the Registration number of Student" << endl
                     << endl;
                string update = updateRollNo();
                cout << update;
            }
            else if (adminOption == "5")
            {
                cout << "You have choosen Option 5: Delete the Student by Name" << endl
                     << endl;
                string del = deleteStudent();
                cout << del;
            }
            else if (adminOption == "6")
            {
                cout << "You have choosen Option 6: Add Merit List" << endl
                     << endl;
                string list = addList();
                cout << list;
            }
            else if (adminOption == "7")
            {
                cout << "You have choosen Option 7: Print Merit List" << endl
                     << endl;
                string merit = meritList();
                cout << merit;
            }
            else if (adminOption == "8")
            {
                system("cls");
                goto home;
            }
            else if (adminOption == "9")
            {
                return 0;
            }
            else
            {
                system("cls");
                continue;
            }
            getch();
            system("cls");
        }
    }
    if (userOption == "2")
    {
    loginBack:
        loginOption = loginPage(userOption);
        system("cls");

        if (loginOption == "1")
        {
            string reg = studentRegistration();
            cout << reg;
            getch();
            system("cls");
            readData(userOption);
            string logIn = login(userOption);
            if (logIn == "No" || logIn == "no")
            {
                system("cls");
                goto loginBack;
            }
        }
        else if (loginOption == "2")
        {
            readData(userOption);
            string logIn = login(userOption);
            if (logIn == "No" || logIn == "no")
            {
                system("cls");
                goto loginBack;
            }
        }
        else if (loginOption == "3")
        {
            goto home;
        }
        else if (loginOption == "4")
        {
            return 0;
        }
        getch();
        system("cls");
        while (true)
        {
            studentOption = studentIndex();
            cout << endl;
            if (studentOption == "1")
            {
                cout << "You have choosen Option 1: Apply for admission" << endl
                     << endl;
                string form = applyForAdmission();
                cout << form;
            }
            else if (studentOption == "2")
            {
                cout << "You have choosen Option 2: View Application Profile" << endl
                     << endl;
                string prof = profile();
                cout << prof;
            }
            else if (studentOption == "3")
            {
                cout << "You have choosen Option 3: Admission test Schedule" << endl
                     << endl;
                string sched = schedule();
                cout << sched;
            }
            else if (studentOption == "4")
            {
                cout << "You have choosen Option 4: Check results" << endl
                     << endl;
                string output = testResult();
                cout << output;
            }
            else if (studentOption == "5")
            {
                cout << "You have choosen Option 5: Merit Calculator" << endl
                     << endl;
                aggrigate = meritCalculator();
                cout << "Aggrigate: " << aggrigate << "%";
            }
            else if (studentOption == "6")
            {
                cout << "You have choosen Option 6: Check merit list" << endl
                     << endl;
                string list = meritList();
                cout << list;
            }
            else if (studentOption == "7")
            {
                cout << "You have choosen Option 7: Admission criteria" << endl
                     << endl;
                string criteria = admissionCriteria();
                cout << criteria;
            }
            else if (studentOption == "8")
            {
                cout << "You have choosen Option 8: Aggrigate Divison" << endl
                     << endl;
                string div = meritDivision();
                cout << div;
            }
            else if (studentOption == "9")
            {
                system("cls");
                goto home;
            }
            else if (studentOption == "10")
            {
                return 0;
            }
            else
            {
                system("cls");
                continue;
            }
            getch();
            system("cls");
        }
    }
    return 0;
}

string home()
{
    string userOption;
    do
    {
        system("cls");
        cout << "               _________________________________________________________________________________________ " << endl;
        cout << "              |               ###   ####   ###   ### ##  ####    ####  ##  #####  ###   ##              |" << endl;
        cout << "              |              ## ##  ## ##  ## # # ## ## ##   #  ##   # ## ##   ## ####  ##              |" << endl;
        cout << "              |             ####### ##  ## ##  #  ## ##   ##      ##   ## ##   ## ## ## ##              |" << endl;
        cout << "              |             ##   ## ## ##  ##     ## ## #   ##  #   ## ## ##   ## ##  ####              |" << endl;
        cout << "              |             ##   ## ####   ##     ## ##  ####    ####  ##  #####  ##   ###              |" << endl;
        cout << "              |                                                                                         |" << endl;
        cout << "              | ###   ###   ###   ###   ##   ###    ######  ####### ###   ### ####### ###   ## ######## |" << endl;
        cout << "              | ## # # ##  ## ##  ####  ##  ## ##  ##    ## ##      ## # # ## ##      ####  ##    ##    |" << endl;
        cout << "              | ##  #  ## ####### ## ## ## ####### ##       #####   ##  #  ## #####   ## ## ##    ##    |" << endl;
        cout << "              | ##     ## ##   ## ##  #### ##   ## ##  #### ##      ##     ## ##      ##  ####    ##    |" << endl;
        cout << "              | ##     ## ##   ## ##   ### ##   ##  ######  ####### ##     ## ####### ##   ###    ##    |" << endl;
        cout << "              |                                                                                         |" << endl;
        cout << "              |                    ####  ##   ##  ####  ######## ####### ###   ###                      |" << endl;
        cout << "              |                   ##   #  ## ##  ##   #    ##    ##      ## # # ##                      |" << endl;
        cout << "              |                     ##     ##      ##      ##    #####   ##  #  ##                      |" << endl;
        cout << "              |                   #   ##   ##    #   ##    ##    ##      ##     ##                      |" << endl;
        cout << "              |                    ####    ##     ####     ##    ####### ##     ##                      |" << endl;
        cout << "              |_________________________________________________________________________________________|" << endl
             << endl;
        cout << "                                               1: Admin " << endl;
        cout << "                                               2: Student" << endl;
        cout << "                                               3: Exit" << endl;
        cout << "                                               Enter your option: ";
        cin >> userOption;
    } while (userOption != "1" && userOption != "2" && userOption != "3");
    return userOption;
}
string loginPage(string option)
{
    string loginOption;
    do
    {
        if (option == "1")
        {
            cout << "You have choosen Option 1: Admin" << endl
                 << endl;
        }
        else if (option == "2")
        {
            cout << "You have choosen Option 2: Student" << endl
                 << endl;
        }
        cout << "Option 1: Register " << endl;
        cout << "Option 2: Login" << endl;
        cout << "Option 3: Back" << endl;
        cout << "Option 4: Exit" << endl;
        cout << "Enter your option: ";
        cin >> loginOption;
        system("cls");
    } while (loginOption != "1" && loginOption != "2" && loginOption != "3" && loginOption != "4");
    return loginOption;
}
string adminRegistration()
{
    bool isPasswordStrong = false;
    cout << "You have choosen Option 1: Register" << endl
         << endl;
    cout << "Create your Username: ";
    cin >> adminUserName;
    while (true)
    {
        cout << "Create your Password: ";
        cin >> adminPassword;
        int i = 0;
        while (adminPassword[i] != '\0')
        {
            if (adminPassword[i] == '@' || adminPassword[i] == '#' || adminPassword[i] == '$' || adminPassword[i] == '%' || adminPassword[i] == '*' || adminPassword[i] == '!' || adminPassword[i] == '&')
            {
                isPasswordStrong = true;
            }
            i++;
        }
        if (isPasswordStrong == true)
        {
            break;
        }
        else
        {
            cout << "Your passwod is weak, Please use special characters(@,#,$,%,&,*,!) to make your password strong." << endl;
        }
    }
    fstream adminReg;
    adminReg.open("adminlogin.txt", ios::app);
    adminReg << adminUserName << "," << adminPassword << "\n";
    adminReg.close();

    return "You have successfuly registered yourself!\nPress Enter to open login page..";
}
string studentRegistration()
{
    bool isPasswordStrong = false;
    cout << "You have choosen Option 1: Register" << endl
         << endl;
    cout << "Create your Username: ";
    cin >> stuUserName;
    while (true)
    {
        cout << "Create your Password: ";
        cin >> stuPassword;
        int i = 0;
        while (stuPassword[i] != '\0')
        {
            if (stuPassword[i] == '@' || stuPassword[i] == '#' || stuPassword[i] == '$' || stuPassword[i] == '%' || stuPassword[i] == '*' || stuPassword[i] == '!' || stuPassword[i] == '&')
            {
                isPasswordStrong = true;
            }
            i++;
        }
        if (isPasswordStrong == true)
        {
            break;
        }
        else
        {
            cout << "Your passwod is weak, Please use special characters(@,#,$,%,&,*,!) to make your password strong." << endl;
        }
    }
    fstream studentReg;
    studentReg.open("studentlogin.txt", ios::app);
    studentReg << stuUserName << "," << stuPassword << "\n";
    studentReg.close();

    return "You have successfuly registered yourself!\nPress Enter to open login page..";
}
string getField(string record, int field)
{
    int count = 0;
    while (record[count] != '\0')
    {
        count++;
    }
    int commaCount = 1;
    string item;
    for (int x = 0; x < count; x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }

    return item;
}
void readData(string option)
{
    int index = 0;
    fstream data;
    if (option == "1")
    {
        data.open("adminlogin.txt", ios::in);
    }
    if (option == "2")
    {
        data.open("studentlogin.txt", ios::in);
    }
    string record;
    while (!(data.eof()))
    {
        getline(data, record);
        usernames[index] = getField(record, 1);
        passWord[index] = getField(record, 2);
        index = index + 1;
    }
    data.close();
}
bool isPresent(string namess, string passwordss)
{
    bool isUserPresent = false;
    for (int x = 0; usernames[x] != "\0"; x++)
    {
        if (namess == usernames[x] && passwordss == passWord[x])
        {
            isUserPresent = true;
        }
    }
    return isUserPresent;
}
string login(string option)
{
    string remarks;
    while (true)
    {
        string stuUsername, stupassword, adminUsername, adminpassword;
        bool stupresent, adminpresent;
        cout << "You have choosen Option 2: Login" << endl
             << endl;
        cout << "LOGIN" << endl;
        if (option == "2")
        {
            cout << "Enter Username: ";
            cin >> stuUsername;
            cout << "Enter Password: ";
            cin >> stupassword;
            stupresent = isPresent(stuUsername, stupassword);
        }
        if (option == "1")
        {
            cout << "Enter Username: ";
            cin >> adminUsername;
            cout << "Enter Password: ";
            cin >> adminpassword;
            adminpresent = isPresent(adminUsername, adminpassword);
        }
        if (adminpresent == true || (option == "1" && adminUsername == adminUserName && adminpassword == adminPassword))
        {
            cout << "you have successfully logged in!" << endl;
            cout << "Press enter to continue..";
            break;
        }
        else if (stupresent == true || (option == "2" && stuUsername == stuUserName && stupassword == stuPassword))
        {
            cout << "you have successfully logged in!" << endl;
            cout << "Press enter to continue..";
            break;
        }
        else
        {
            cout << "Invalid username or password." << endl;
            while (true)
            {
                cout << "Do you want to re-enter username and password (Yes/No): ";
                cin >> remarks;
                if (remarks == "No" || remarks == "no" || remarks == "Yes" || remarks == "yes")
                {
                    break;
                }
                else
                {
                    cout << "Invalid input,Please re-Enter." << endl;
                }
            }
            if (remarks == "No" || remarks == "no")
            {
                break;
            }
            system("cls");
        }
    }
    return remarks;
}
string adminIndex()
{
    string adminOption;
    do
    {
        system("cls");
        cout << "------------------------------------------------------" << endl;
        cout << "                      ADMIN MENU                      " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Option 1: View all Students" << endl;
        cout << "Option 2: Add Student" << endl;
        cout << "Option 3: Search a Student by Name" << endl;
        cout << "Option 4: Change the Registration number of Student" << endl;
        cout << "Option 5: Delete the Student by Name" << endl;
        cout << "Option 6: Add Merit List" << endl;
        cout << "Option 7: Print merit list" << endl;
        cout << "Option 8: Log Out" << endl;
        cout << "Option 9: Exit" << endl;
        cout << "Enter your option:";
        cin >> adminOption;
    } while (adminOption != "1" && adminOption != "2" && adminOption != "3" && adminOption != "4" && adminOption != "5" && adminOption != "6" && adminOption != "7" && adminOption != "8" && adminOption != "9");
    return adminOption;
}
string applications()
{
    if (name[0] == "\0")
    {
        return "No record found.";
    }
    else
    {
        for (int idx = 0; name[idx] != "\0"; idx++)
        {
            cout << "Application number " << idx + 1 << endl;
            cout << "Name: " << name[idx] << endl;
            cout << "Registration no: " << regNumber[idx] << endl;
            cout << endl;
        }
    }
    return "Press Enter to continue.";
}
string addStudent()
{

    int i = 1;
    while (i == 1)
    {
        cout << "Enter the name of Student: ";
        getline(cin, name[idx]);
        getline(cin, name[idx]);
        cout << "Enter the registration number of student: ";
        cin >> regNumber[idx];
        while (true)
        {
            cout << "Enter ECAT marks: ";
            cin >> ecatMarks[idx];
            if (ecatMarks[idx] >= 0 && ecatMarks[idx] <= 400)
            {
                break;
            }
            else
            {
                cout << "Invalid marks, ECAT marks should be between 0 and 400!" << endl;
            }
        }

        cout << "Do you want to add another student? Press 1 for Yes and 0 for No: ";
        cin >> i;
        idx++;
    }
    return "Press Enter to continue..";
}
string searchStudent()
{
    string stuName;
    cout << "Enter the name of student you want to search: ";
    getline(cin, stuName);
    getline(cin, stuName);
    int idx = 0;
    while (idx < 10)
    {
        if (stuName == name[idx])
        {
            return "Student Exists!\nRegistration Number: " + regNumber[idx] + "\nECAT Marks: " + to_string(ecatMarks[idx]);
            break;
        }
        idx++;
    }
    return "No such student exists.";
}
string updateRollNo()
{
    int i = 0;
    string stuName;
    cout << "Enter the name of student you want to update: ";
    getline(cin, stuName);
    getline(cin, stuName);
    while (i < 10)
    {
        if (stuName == name[i])
        {
            cout << "Enter new Registration number: ";
            cin >> regNumber[i];
            return "Student record has been updated.";
            break;
        }
        i++;
    }
    return "No record found";
}
string deleteStudent()
{
    bool isFound = false;
    string remarks;
    string stuName;
    cout << "Enter the name of student you want to delete: ";
    getline(cin, stuName);
    getline(cin, stuName);
    for (int x = 0; x <= idx; x++)
    {
        if (isFound == true || stuName == name[x])
        {
            name[x] = "\0";
            regNumber[x] = '\0';
            name[x] = name[x + 1];
            regNumber[x] = regNumber[x + 1];
            ecatMarks[x] = ecatMarks[x + 1];
            isFound = true;
            remarks = "Student record has been deleted.";
        }
    }
    if (isFound == false)
    {
        remarks = "Student not found!";
    }
    return remarks;
}
string addList()
{
    int i = 1;
    while (i != 0 && index < 9)
    {
        cout << "Name: ";
        getline(cin, nameInList[index]);
        getline(cin, nameInList[index]);
        cout << "Registeration No: ";
        cin >> regNumberInList[index];
        while (true)
        {
            cout << "Aggrigate: ";
            cin >> aggrigate[index];
            aggrigate[index + 1] = 0.0;
            if (aggrigate[index] >= 0.0 && aggrigate[index] <= 100.0)
            {
                break;
            }
            else
            {
                cout << "Invalid input, Plrease enter aggrigate between 0 and 100!" << endl;
            }
        }
        cout << "Do you want to add another student(1 or 0): ";
        cin >> i;
        index++;
    }
    return "Press Enter to continue..";
}
string meritList()
{
    int count = 0;
    while (aggrigate[idx] != 0.0)
    {
        count++;
        idx++;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (aggrigate[j] < aggrigate[j + 1])
            {
                int temp = aggrigate[j];
                aggrigate[j] = aggrigate[j + 1];
                aggrigate[j + 1] = temp;
                string tempName = nameInList[j];
                nameInList[j] = nameInList[j + 1];
                nameInList[j + 1] = tempName;
                int tempNum = regNumberInList[j];
                regNumberInList[j] = regNumberInList[j + 1];
                regNumberInList[j + 1] = tempNum;
            }
        }
    }
    cout << "Position" << "\t" << "Name" << "\t\t" << "Reg.No" << "\t" << "Aggrigate" << endl;
    int position = 1;
    for (int i = 0; aggrigate[i] != 0.0; i++)
    {
        cout << position << "\t" << "\t" << nameInList[i] << "\t" << regNumberInList[i] << "\t" << aggrigate[i] << endl;
        position++;
    }
    return "Press Enter to continue..";
}
string studentIndex()
{
    string studentOption;
    do
    {
        system("cls");
        cout << "------------------------------------------------------" << endl;
        cout << "                     STUDENT MENU                     " << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Option 1: Apply for admission" << endl;
        cout << "Option 2: View Application Profile" << endl;
        cout << "Option 3: Admission test Schedule" << endl;
        cout << "Option 4: Check results" << endl;
        cout << "Option 5: Merit Calculator" << endl;
        cout << "Option 6: Check merit list" << endl;
        cout << "Option 7: Admission criteria" << endl;
        cout << "Option 8: Aggrigate Divison" << endl;
        cout << "Option 9: Log Out" << endl;
        cout << "Option 10: Exit" << endl;
        cout << "Enter your option:";
        cin >> studentOption;
    } while (studentOption != "1" && studentOption != "2" && studentOption != "3" && studentOption != "4" && studentOption != "5" && studentOption != "6" && studentOption != "7" && studentOption != "8" && studentOption != "9" && studentOption != "10");
    return studentOption;
}
string applyForAdmission()
{
    //----------------------------------------PERSONAL INFORMATION----------------------------------------//
    cout << "PERSONAL INFORMATION" << endl;
    //--------------------------------------------STUDENT NAME--------------------------------------------//
    cout << "Enter Name: ";
    getline(cin, stuname);
    getline(cin, stuname);
    //---------------------------------------------FATHER NAME--------------------------------------------//
    cout << "Enter Father name: ";
    getline(cin, fname);
    //------------------------------------------------AGE-------------------------------------------------//
    while (true)
    {
        cout << "Age(16-28): ";
        cin >> age;
        if (age >= 16 && age <= 28)
        {
            break;
        }
        else
        {
            cout << "Invalid input, please re-Enter!" << endl;
        }
    }
    //------------------------------------------------CNIC------------------------------------------------//
    while (true)
    {
        bool cnicCheck = true;
        cout << "CNIC: ";
        cin >> cnic;
        int i = 0;
        while (cnic[i] != '\0')
        {
            if (cnic[i] != '0' && cnic[i] != '1' && cnic[i] != '2' && cnic[i] != '3' && cnic[i] != '4' && cnic[i] != '5' && cnic[i] != '6' && cnic[i] != '7' && cnic[i] != '8' && cnic[i] != '9' && cnic[i] != '\0')
            {
                cnicCheck = false;
            }
            i++;
        }
        if (i == 13 && cnicCheck == true)
        {
            break;
        }
        else
        {
            cout << "Invalid CNIC, please make sure your CNIC don't have any dash'-'!" << endl;
        }
    }
    //-----------------------------------------------EMAIL------------------------------------------------//
    while (true)
    {
        bool emailCheck = false;
        cout << "Email: ";
        cin >> email;
        int i = 0;
        while (email[i] != '\0')
        {
            if (email[i] == '@')
            {
                emailCheck = true;
            }
            i++;
        }
        if (emailCheck == true)
        {
            break;
        }
        else
        {
            cout << "Invalid Email, please re-Enter!" << endl;
        }
    }
    //-----------------------------------------------GENDER-----------------------------------------------//
    while (true)
    {
        cout << "Gender(Male or Female): ";
        cin >> gender;
        if (gender == "Male" || gender == "Female" || gender == "male" || gender == "female")
        {
            break;
        }
        else
        {
            cout << "Invalid gender, please enter one of the genders mentioned above!" << endl;
        }
    }
    //----------------------------------------------RELIGION----------------------------------------------//
    while (true)
    {
        cout << "Religion: ";
        cin >> religion;
        if (religion == "islam" || religion == "hinduism" || religion == "christianity" || religion == "buddhism" || religion == "atheist" || religion == "jewish" || religion == "Islam" || religion == "Hinduism" || religion == "Christianity" || religion == "Buddhism" || religion == "Atheist" || religion == "Jewish")
        {
            break;
        }
        else
        {
            cout << "Invalid input, please enter one of these(Islam,Hinduism,Christianity,Buddhism,Atheist,Jewish)!" << endl;
        }
    }
    //-----------------------------------------------ADDRESS-----------------------------------------------//
    cout << "Address: ";
    getline(cin, address);
    getline(cin, address);
    //--------------------------------------------PHONE NUMBER---------------------------------------------//
    while (true)
    {
        bool phoneNoCheck = true;
        cout << "Phone Number: ";
        cin >> phoneNo;
        int i = 0;
        while (phoneNo[i] != '\0')
        {
            if (phoneNo[i] != '0' && phoneNo[i] != '1' && phoneNo[i] != '2' && phoneNo[i] != '3' && phoneNo[i] != '4' && phoneNo[i] != '5' && phoneNo[i] != '6' && phoneNo[i] != '7' && phoneNo[i] != '8' && phoneNo[i] != '9')
            {
                phoneNoCheck = false;
            }
            i++;
        }
        if (phoneNo[0] == '0' && phoneNo[1] == '3' && i == 11 && phoneNoCheck == true)
        {
            break;
        }
        else
        {
            cout << "Invalid Phone Number, please enter Phone number in 03XXXXXXXXX format!" << endl;
        }
    }
    cout << endl;
    //---------------------------------------ACADEMIC INFORMATION-----------------------------------------//
    cout << "ACADEMIC INFORMATION" << endl;
    //----------------------------------------------MATRIC------------------------------------------------//
    while (true)
    {
        cout << "Matric or O-level marks : ";
        cin >> matricMarks;
        if (matricMarks >= 0 && matricMarks <= 1200)
        {
            break;
        }
        else
        {
            cout << "Invalid marks, please re-enter marks between 0 and 1200!!" << endl;
        }
    }
    while (true)
    {
        cout << "Board(lahore,gujranwala,faisalabad,fedral,multan,sahiwal): ";
        cin >> matricBoard;
        if (matricBoard == "lahore" || matricBoard == "gujranwala" || matricBoard == "faisalabad" || matricBoard == "fedral" || matricBoard == "multan" || matricBoard == "sahiwal")
        {
            break;
        }
        else
        {
            cout << "Invalid board, please re-enter one of the boards mentioned above!" << endl;
        }
    }
    //------------------------------------------------INTER-----------------------------------------------//
    while (true)
    {
        cout << "Inter or A-level marks: ";
        cin >> interMarks;
        if (interMarks >= 0 && interMarks <= 1200)
        {
            break;
        }
        else
        {
            cout << "Invalid marks, please re-enter marks between 0 and 1200!" << endl;
        }
    }
    while (true)
    {
        cout << "Board(lahore,gujranwala,faisalabad,fedral,multan,sahiwal): ";
        cin >> interBoard;
        if (interBoard == "lahore" || matricBoard == "gujranwala" || matricBoard == "faisalabad" || matricBoard == "fedral" || matricBoard == "multan" || matricBoard == "sahiwal")
        {
            break;
        }
        else
        {
            cout << "Invalid board, please re-enter one of the boards mentioned above!" << endl;
        }
    }
    //------------------------------------------COURSE PREFERENCE-----------------------------------------//
    cout << "\nCOURSE PREFERENCE" << endl;
    cout << "1: Computer Science" << endl;
    cout << "2: Software Engineering" << endl;
    cout << "3: Data Science" << endl;
    cout << "4: Computer Engineering" << endl;
    cout << "5: Cyber Security" << endl;
    while (true)
    {
        cout << "Number your top preference(like 1 or 2): ";
        cin >> preference;
        if (preference == "1" || preference == "2" || preference == "3" || preference == "4" || preference == "5")
        {
            break;
        }
        else
        {
            cout << "Course not found, please enter one of the courses mentioned above!" << endl;
        }
    }
    cout << endl;
    return "Press Enter to submit Application Form";
}
string profile()
{
    cout << "PERSONAL INFORMATION" << endl;
    cout << "Name: " << stuname << endl;
    cout << "Father Name: " << fname << endl;
    cout << "Age: " << age << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Gender(Male or Female): " << gender << endl;
    cout << "Religion: " << religion << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNo << endl
         << endl;
    cout << "ACADEMIC INFORMATION" << endl;
    cout << "Matric marks: " << matricMarks << endl;
    cout << "Board: " << matricBoard << endl;
    cout << "Inter marks: " << interMarks << endl;
    cout << "Board: " << interBoard << endl
         << endl;
    cout << "COURSE PREFERENCE" << endl;
    cout << "Main Preference: ";
    if (preference == "1")
    {
        cout << "Computer Science";
    }
    if (preference == "2")
    {
        cout << "Software Engineering";
    }
    if (preference == "3")
    {
        cout << "Data Science";
    }
    if (preference == "4")
    {
        cout << "Computer Engineering";
    }
    if (preference == "5")
    {
        cout << "Cyber Security";
    }
    cout << endl;
    return "Press Enter to continue..";
}
string schedule()
{
    cout << "TEST NO   APPLY DATES      TEST DATE    TEST CITY    RESULT DATE" << endl;
    cout << "   1      01-10 Dec 2024  15 Dec 2024    Lahore      25 Dec 2024" << endl;
    cout << "   2      17-27 Jan 2025  02 Feb 2025    Lahore      12 Feb 2025" << endl;
    cout << "   3      01-09 May 2025  12 May 2025    Lahore      22 May 2025" << endl;
    cout << "   4      11-20 Jun 2025  24 Jun 2025    Lahore      04 Jul 2025" << endl;
    return "Press Enter to continue..";
}
string testResult()
{
    int x = 0;
    string stuName;
    cout << "Enter your name: ";
    getline(cin, stuName);
    getline(cin, stuName);
    while (name[x] != "\0")
    {
        if (stuName == name[x])
        {
            return "Ecat marks:" + to_string(ecatMarks[x]);
            break;
        }
        x++;
    }
    return "No such student exists.";
}
float meritCalculator()
{
    float matricMarks, interMarks, testMarks, aggrigate;
    while (true)
    {
        cout << "Enter matric marks out of 1200: ";
        cin >> matricMarks;
        if (matricMarks >= 0 && matricMarks <= 1200)
        {
            break;
        }
        else
        {
            cout << "Invalid input, Please enter marks between 0 and 1200!" << endl;
        }
    }
    while (true)
    {
        cout << "Enter inter marks out of 1200: ";
        cin >> interMarks;
        if (interMarks >= 0 && interMarks <= 1200)
        {
            break;
        }
        else
        {
            cout << "Invalid input, Please enter marks between 0 and 1200!" << endl;
        }
    }
    while (true)
    {
        cout << "Enter admission test marks out of 400: ";
        cin >> testMarks;
        if (testMarks >= 0 && testMarks <= 400)
        {
            break;
        }
        else
        {
            cout << "Invalid input, Please enter marks between 0 and 400!" << endl;
        }
    }
    aggrigate = (matricMarks / 1200) * 17 + (interMarks / 1200) * 50 + (testMarks / 400) * 33;
    return aggrigate;
}
string admissionCriteria()
{
    cout << "Minimum marks in matric must be above 60%." << endl;
    cout << "Minimum marks in inter must be above 60%." << endl;
    cout << "Minimum marks in entry test must be above 150 out of 400." << endl;
    cout << "Age must be above 16 and below 28." << endl;
    return "Press Enter to continue..";
}
string meritDivision()
{
    cout << "Matric marks division= 17%." << endl;
    cout << "Inter marks division= 50%." << endl;
    cout << "Entry Test marks division= 33%." << endl;
    return "Press Enter to continue..";
}
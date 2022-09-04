/* Developed BY AKT 4.9.22 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
//User-Defined Function
//If You are Using Window change "clear" to "cls" in clean() function;
void clean();
void scan(char *p);
int StrLen(char *p);
int cmp(char *p1, char *p2);
int CheckCredential(char *name, char *pass);
void StrAdd(char *p1, char *p2);
int ScanfIntHandling();
void Register();
void ViewAllData(char *p);
void AddData(char *p);
void Continue();
void ViewData(char *p);

//Global Var
char PM[10][3][100] = {{"john@gmail.com","Johnny","pass111"},
                       {"david@gmail.com","David","111"},
                       {"william@gmail.com","William","Apple112"},
                       {"admin@gmail.com", "Admin", "Admin!!@111"} ,
};
char UserDescription[10][100] = {"GitHub","Email","Dicord","Facebook"};
char UserEmail[10][10][100]   = {{"Johnny",  "john133@gmail.com",    "Test@gmail.com",    "John@gmail.com",     "testing@gmail.com",},
                                 {"David",   "Davide1234@gmail.com", "Dav@gmal.com",      "Pro@gmail.com",      "test111@gmail.com"},
                                 {"William", "WillDev@gmail.com",    "william@gmail.com", "WIllI11@gmail.com",  "WillSmit@gmail.com"},
                                 {"Admin",   "ThomasDev@gmail.com",  "thomas@gmail.com",  "thomasec@gmail.com", "thomasfb@gmail.com"}
};
char UserPass[10][10][100] = {{"Johnny", "ThomasDevGit11","1323424","write1232", "IloveYou1232"},
                              {"David","BlaBla34", "33dwd", "dwadfw23",  "thmacwda23e2"},
                              {"William","wewewf2332","iamtp3424","123435355","sheetpap123232"},
                              {"Admin","BuiltDream123@@","ewefwd22","edwa222","eater2323"}
};
int counter = 4;
char curr_usr[100];

int main()
{

    char usr_inp[100];
    char usr_pass[100];

    while(1)
    {
        clean();
        int op =0, op1 = 0, op2 = 1;
        printf("\nPassword Manager\n---------------------\n1. Login\n2. Register\n3. Exit\n");
        printf("Enter the number ::> ");
        op = ScanfIntHandling();
//LOGIN
        if(op == 1)
        {
            clean();
            printf("Welcome From Login Session\n---------------------------\n");
            printf("Enter your username or email ::> ");
            scanf("%s", usr_inp);
            printf("Enter your password ::> ");
            scanf("%s", usr_pass);
            int Status = CheckCredential(usr_inp, usr_pass);
            if(Status == 1)
            {
                char CurrUsr[100];
                StrAdd(CurrUsr, curr_usr);
                while(op2 == 1)
                {
                    clean();
                    printf("\nWelcome %s\n----------------------\n1. Add Data\n2. View Data\n3. View All Data\n4. Exit\nEnter the number ::> ", CurrUsr);
                    op1 = ScanfIntHandling();
                    switch (op1)
                    {
                        case 1:
                            clean();
                            AddData(CurrUsr);
                            Continue();
                            break;
                        case 2:
                            clean();
                            ViewData(CurrUsr);
                            Continue();
                            break;
                        case 3:
                            clean();
                            ViewAllData(CurrUsr);
                            Continue();
                            break;
                        case 4:
                            op2 = 0;
                            break;
                        default:
                            printf("\n!!!Invalid Input!!!\n");
                            break;
                    }

                }

            }

        }
//Register
        else if( op == 2)
        {
            clean();
            Register();
        }
//Exit
        else if(op == 3)
        {
            break;
        }
        else
        {
            printf("Invallid Input");
        }

    }
}

void scan(char *p)
{
    char tmp[SIZE];
    while(getchar() != '\n');
    scanf("%[^\n]s", tmp);
    StrAdd(p, tmp);
}

int ScanfIntHandling()
{
    int inp = 0;
    int status = scanf("%d", &inp);
    if(status != 1)
    {
        scanf( "%*[^\n]" );
        inp = 0;
    }
    return  inp;

}

int StrLen(char *p)
{
    int c =0;
    while(*p != '\0')
    {
        c++;
        p++;
    }

    return c;

}

int CheckCredential(char *input, char *pass)
{
    int status = 0, usr_status = 0, pass_status = 0;
    for(int i = 0; i < counter; i++)
    {
        int z = 0;
        if( cmp(input, PM[i][z]) == 1 | cmp(input, PM[i][z+1]) == 1)
        {

            if(cmp(pass, PM[i][z+2]) == 1)
            {
                status = 1;
                pass_status = 1;
                StrAdd(curr_usr, PM[i][z+1]);
            }
            usr_status = 12;

        }
    }
    if(usr_status == 0)
    {
        printf("\n!!!Invalid Username and Password!!!\n");
        Continue();

    }
    if(usr_status == 12)
    {
        if(pass_status ==0 )
        {
            printf("\n!!!Password is incorrect!!!\n");
            Continue();
        }

    }


    return status;
}

int cmp(char *p1, char *p2)
{
    int i = 1;
    char *x,*y;
    if(StrLen(p1) < StrLen(p2))
    {
        x = p2;
        y = p1;
    }
    else
    {
        x = p1;
        y = p2;
    }

    while(*x)
    {

        if( *x == *y)
        {
            i =1;
        }
        else if( *x != *y)
        {
            i =0;
            break;
        }
        x++;
        y++;
    }

    return i;
}

void StrAdd(char *p1, char *p2)
{
    while(*p2 != '\0')
    {
        *p1++ = *p2++;
    }
    *p1 = '\0';

}

void Register()
{
    char usrname[100];
    char email[100];
    char pass[100];
    int tmp = counter;
    int us=0,es =0;
    int status = 1;
    printf("\nWELCOME FORM REGISTERRING SESSION\n--------------------------------------\n");
    printf("Enter UserName ::> ");
    scan(usrname);
    printf("Enter Email ::>");
    scan(email);
    printf("Enter Password ::> ");
    scan(pass);

    for(int i = 0; i <= tmp; i++)
    {
        if( cmp(usrname, PM[i][1]) == 1)
        {
            status = 0;
            printf("!!!%s is already exit in Database!!!\n", usrname);
        }
        else if( cmp(email,PM[i][0]) == 1)
        {
            status = 0;
            es++;
        }

    }

    if(status == 1)
    {
        StrAdd(PM[counter][0], email);
        StrAdd(PM[counter][1], usrname);
        StrAdd(PM[counter][2], pass);
        printf("!!Registerring is done!!\n");
        counter++;
    }
    if(es > 0)
    {
        printf("!!!%s is already exit in Database!!!\n", email);
    }
    /*
    else if (status == 0)
    {
        if(us == 1)
        {
            printf("!!!%s is already exit in ViewAllData!!!\n", usrname);
        }
        if(es == 1)
        {
            printf("!!!%s is already used by another user!!!\n", email);
        }

    }
     */

}

void ViewAllData(char *p)
{
    int z = 0;
    int s = 0;
    int status = 0;
    for(int i = 0; i < counter; i++)
    {
        if(cmp(p,UserEmail[i][s]) == 1)
        {
            printf("Database For %s \n----------------------\n", UserEmail[i][0]);
            for(int x =0; x < 4; x++)
            {
                printf("\nDescription ::> %s\n", UserDescription[x]);
                printf("Email ::> %s\n", UserEmail[i][x+1]);
                printf("Password ::> %s\n", UserPass[i][x+1]);

            }
            status = 1;

        }
        z++;
    }

    if(status != 1)
    {
        printf("\n!!Sorry There is No Dat for %s\n!!", p);
    }


}

void AddData(char *p)
{
    int z = 0, status = 1;
    int s = 0;
    for(int i = 0; i < counter; i++)
    {
        if(cmp(p,UserEmail[i][0]) == 1)
        {
            printf("\n!!!Sorry You Can't Add More Data!!!");
            status = 0;
        }
        z++;
    }
    if(status == 1)
    {
        int op = 0;int op1 = 1;
        //printf("\nCurrent User ::> %s", p);
        while(1)
        {
            clean();
            printf("Add Data For %s\n-------------------\n!!!Warning You Can Add Data Just For One Time!!!\n1. GitHub\n2. Email\n3. Discord\n4. Facebook\n5. Exit\n", p);
            printf("Enter the account type ::> ");
            op = ScanfIntHandling();
            if(op == 1)
            {
                StrAdd(UserEmail[counter-1][s], p);
                StrAdd(UserPass[counter-1][s], p);
                printf("Enter the email ::> ");
                scan(UserEmail[counter-1][s +1]);
                printf("Enter the Password ::> ");
                scan(UserPass[counter-1][s + 1]);
                printf("\nAdding Done\n");
            }
            else if(op == 2)
            {
                StrAdd(UserEmail[counter-1][s], p);
                StrAdd(UserPass[counter-1][s], p);
                printf("Enter the email ::> ");
                scan(UserEmail[counter-1][s +2]);
                printf("Enter the Password ::> ");
                scan(UserPass[counter-1][s + 2]);
            }
            else if(op == 3)
            {
                StrAdd(UserEmail[counter-1][s], p);
                StrAdd(UserPass[counter-1][s], p);
                printf("Enter the email ::> ");
                scan(UserEmail[counter-1][s +3]);
                printf("Enter the Password ::> ");
                scan(UserPass[counter-1][s + 3]);
            }
            else if(op == 4)
            {
                StrAdd(UserEmail[counter-1][s], p);
                StrAdd(UserPass[counter-1][s], p);
                printf("Enter the email ::> ");
                scan(UserEmail[counter-1][s +4]);
                printf("Enter the Password ::> ");
                scan(UserPass[counter-1][s + 4]);
            }
            else if(op == 5)
            {
                break;
            }
            else
            {
                printf("\n!!!Invalid Input!!!\n");
                break;
            }
            Continue();


        }

    }
}

void clean()
{
    system("clear");
}

void Continue()
{
    char op[10];
    printf("\n---- Press Enter to continue ----\n");
    scan(op);
}

void ViewData(char *p)
{
    int z = 0;
    int s = 0;
    int status = 0;
    int op = 0;
    //printf("Curent User ::> %s", UserEmail[counter-1][0]);
    for(int i = 0; i < counter; i++)
    {
        if(cmp(p,UserEmail[i][s]) == 1)
        {
            //printf("Current User ::> %s\n", UserEmail[i][0]);
            printf("Database For %s\n-----------------------\n1.Git Hub\n2.Email\n3.Discord\n4.Facebook\nEnter the number ::> ", UserEmail[i][0]);
            op = ScanfIntHandling();
            switch (op)
            {
                case 1:
                    printf("\nDesciption ::> %s\n", UserDescription[s]);
                    printf("Email ::> %s\n", UserEmail[i][s+1]);
                    printf("Password ::> %s\n", UserPass[i][s+1]);
                    break;
                case 2:
                    printf("\nDesciption ::> %s\n", UserDescription[s+1]);
                    printf("Email ::> %s\n", UserEmail[i][s+2]);
                    printf("Password ::> %s\n", UserPass[i][s+2]);
                    break;
                case 3:
                    printf("\nDesciption ::> %s\n", UserDescription[s+2]);
                    printf("Email ::> %s\n", UserEmail[i][s+3]);
                    printf("Password ::> %s\n", UserPass[i][s+3]);
                    break;
                case 4:
                    printf("\nDesciption ::> %s\n", UserDescription[s+3]);
                    printf("Email ::> %s\n", UserEmail[i][s+4]);
                    printf("Password ::> %s\n", UserPass[i][s+4]);
                    break;
                default:
                    printf("\n!!!Invalid Input!!!\n");
                    break;

            }

        }
        z++;
    }
}

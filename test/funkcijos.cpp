#include "struct.h"

ifstream in("kursiokai.txt");

void exists_test(const string& name)
{
    ifstream file(name);
    if (!file)
    {
        file.close();
        throw "Failas neegzistuoja";
    }
    file.close();
}

void skaicius(int& a) //funkcija neleidzianti ivesti raides ten kur reikia skaiciaus
{
    cin >> a;
    while (!cin)
    {
        cin.clear(); // reset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziame neteisinga ivesti
        cout << "Prasome ivesti skaiciu: ";
        cin >> a;
    }
}

void ivestisranka(vector <studentas>& stud)
{
    int i = 0;
    while (1 > 0)
    {
        stud.push_back(studentas());
        cout << "Iveskite varda: ";
        cin >> stud[i].vard;
        cout << "Iveskite pavarde: ";
        cin >> stud[i].pavard;
        char ar;
        cout << "Ar sugeneruoti pazymius atsitiktinai? (T/N)";
        while (1 > 0)
        {
            cin >> ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout << "Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar == 't' || ar == 'T')
        {
            cout << "Kiek norite sugeneruoti namu darbu pazymiu? ";
            int kiek;
            cin >> kiek;
            while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
            {
                cin.clear(); // istrina fail reiksme
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                cout << "Iveskite skaiciu: ";
                cin >> kiek;
            }
            while (1 > 0)
            {
                if (kiek == 0)
                    cout << "Isveskite skaiciu didesni uz 0: ";
                else break;
                cin >> kiek;
            }
            float vid = 0, med;
            for (int j = 0; j < kiek; j++)
            {
                stud[i].nd.push_back(rand() % 10 + 1);
                cout << stud[i].nd[j] << " ";
                vid = vid + stud[i].nd[j];
            }
            cout << endl;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiek % 2 == 0)
            {
                med = (stud[i].nd[kiek / 2] + stud[i].nd[kiek / 2 - 1]) / 2.0;
            }
            else
            {
                med = stud[i].nd[kiek / 2];
            }
            vid = vid / kiek;
            cout << "Egzamino rezultatas: ";
            stud[i].egz = rand() % 10 + 1;
            cout << stud[i].egz << endl;
            stud[i].gal = vid * 0.4 + stud[i].egz * 0.6;
            stud[i].galmed = med * 0.4 + stud[i].egz * 0.6;
        }
        else
        {
            cout << "Iveskite studento pazymius, norint baigti iveskite 0: ";
            int a, kiekpaz = 0;
            float vid = 0, med;
            while (1 > 0)
            {
                cin >> a;
                while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                {
                    cin.clear(); // istrina fail reiksme
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                    cout << "Iveskite skaiciu: ";
                    cin >> a;
                }
                if (a != 0)
                {
                    while (a < 0 || a>10)
                    {
                        cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                        cin >> a;
                    }
                    stud[i].nd.push_back(a);
                    kiekpaz++;
                    vid += a;
                }
                else
                {
                    while (kiekpaz == 0)
                    {
                        cout << "Prasome ivesti bent viena pazymi: ";
                        cin >> a;
                        while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                        {
                            cin.clear(); // istrina fail reiksme
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                            cout << "Iveskite skaiciu: ";
                            cin >> a;
                            while (a < 0 || a>10)
                            {
                                cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                                cin >> a;
                            }
                        }
                        if (a > 0 && a <= 10)
                        {
                            stud[i].nd.push_back(a);
                            kiekpaz++;
                            vid += a;
                        }

                    }
                    if (kiekpaz != 0)
                        break;
                }
            }
            vid = vid / kiekpaz;
            sort(stud[i].nd.begin(), stud[i].nd.end());
            if (kiekpaz % 2 == 0)
            {
                med = (stud[i].nd[kiekpaz / 2] + stud[i].nd[kiekpaz / 2 - 1]) / 2.0;
            }
            else
            {
                med = stud[i].nd[kiekpaz / 2];
            }
            cout << "Iveskite egzamino rezultata: ";
            cin >> a;
            while (1 > 0)
            {
                while (!cin)//susiradau sprendima internete (tikrina ar ivestis yra int tipo)
                {
                    cin.clear(); // istrina fail reiksme
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziamas ne int input'as
                    cout << "Iveskite skaiciu: ";
                    cin >> a;
                }
                if (a <= 0 || a > 10)
                {
                    cout << "Prasome ivesti skaiciu tarp [1, 10]: ";
                    cin >> a;
                }
                else
                {
                    break;
                }
            }
            stud[i].egz = a;
            stud[i].gal = vid * 0.4 + stud[i].egz * 0.6;
            stud[i].galmed = med * 0.4 + stud[i].egz * 0.6;
        }
        i++;
        cout << "Ar norite ivesti nauja studenta? (T/N)";
        while (1 > 0)
        {
            cin >> ar;
            if (ar != 't' && ar != 'n' && ar != 'T' && ar != 'N')
                cout << "Irasykite atitinkamai T arba N: ";
            else break;
        }
        if (ar == 'n' || ar == 'N')
            break;
    }

}

int kiekpazymiu()
{
    int i = 0;
    string a;
    while (true)
    {
        in >> a;
        i++;
        if (a == "Egz.")
        {
            break;
        }
    }
    return i - 3;
}

void ivestis(vector <studentas>& stud)
{
    int kieknd;
    kieknd = kiekpazymiu();
    int kiekstud = 0;
    while (!in.eof())
    {
        stud.push_back(studentas());
        in >> stud[kiekstud].vard;
        in >> stud[kiekstud].pavard;
        int a;
        float vid = 0, med;
        for (int i = 0; i < kieknd; i++)
        {
            in >> a;
            stud[kiekstud].nd.push_back(a);
            vid += a;
        }
        sort(stud[kiekstud].nd.begin(), stud[kiekstud].nd.end());
        if (kieknd % 2 == 0)
        {
            med = (stud[kiekstud].nd[kieknd / 2] + stud[kiekstud].nd[kieknd / 2 - 1]) / 2.0;
        }
        else
        {
            med = stud[kiekstud].nd[kieknd / 2];
        }
        stud[kiekstud].nd.clear();

        vid = vid / kieknd;
        in >> stud[kiekstud].egz;
        stud[kiekstud].gal = vid * 0.4 + stud[kiekstud].egz * 0.6;
        stud[kiekstud].galmed = med * 0.4 + stud[kiekstud].egz * 0.6;
        kiekstud++;

    }
    /*for (int i = 0; i < kiekstud; i++) //nuskaitytu duomenu isvedimas
    {
        cout << stud[i].vard << " " << stud[i].pavard << " ";
        for (int j = 0; j < kieknd; j++)
        {
            cout << stud[i].nd[j] << " ";
        }
        cout << stud[i].egz << endl;
    }*/
}

bool palyginimas(studentas& a, studentas& b)
{
    return a.gal < b.gal;
}

void isvestis(vector <studentas> stud)
{
    sort(stud.begin(), stud.end(), palyginimas);
    stringstream my_buffer;
    my_buffer << "|" << left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)" << "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int i = 0; i < stud.size(); i++)
    {
        my_buffer << "|" << left << setw(20) << stud[i].vard << "|" << left << setw(20) << stud[i].pavard << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].gal << "|" << left << setw(20) << fixed << setprecision(2) << stud[i].galmed << endl;
    }
    cout << my_buffer.str();
    my_buffer.clear();
}

void failugeneracija(int kieknd)
{
    for (int i = 1000; i <= 10000000; i = i * 10)
    {
        failgen(kieknd, i);
    }
}

void failgen(int kieknd, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    stringstream buffer;
    string vardas, pavarde;
    for (int i = 1; i <= kiekstud; i++)
    {
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        buffer << left << setw(20) << vardas << " " << left << setw(20) << pavarde << " ";
        for (int j = 0; j < kieknd; j++)
        {
            buffer << left << setw(20) << rand() % 10 + 1 << " ";
        }
        buffer << left << setw(20) << rand() % 10 + 1 << endl;
    }
    string out1 = "kursiokai" + to_string(kiekstud) + ".txt";
    ofstream out(out1);
    out << left << setw(20) << "Vardas" << " " << left << setw(20) << "Pavarde" << " ";
    for (int j = 1; j <= kieknd; j++)
    {
        out << left << setw(20) << "ND" + to_string(j) << " ";
    }
    out << left << setw(20) <<"Egz." << endl;
    out << buffer.str();
    
    out.close();
    buffer.str("");
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " generavimas i faila: " << diff.count() << endl;
    system("Pause");
}

void greicioanalizevector(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid=0;
    vector <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout<< kiekstud<<" nuskaitymas uztruko: " << diff.count() << endl;

    vector <studentas> nend, kiet;
    auto rus = high_resolution_clock::now();
    rusiavimasvector(stud, nend, kiet);
    stud.clear();
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;
    

    nendartiolaiifaila(kieknd, nend, kiekstud);
    kietiakaiifaila(kieknd, kiet, kiekstud);
    
    diff = high_resolution_clock::now() - pradzia;
    cout << endl<< kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasvector (vector <studentas> &stud, vector <studentas> &nend, vector <studentas> &kiet)
{
    sort(stud.begin(), stud.end(), palyginimas);
    for (auto& s : stud)//(auto &temp:stud)
    {
        if (s.gal < 5.0)
        {
            nend.push_back(s);
        }
        else
        {
            kiet.push_back(s);
        }
    }
    stud.clear();
    nend.shrink_to_fit();
    kiet.shrink_to_fit();
}

void greicioanalizelist(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    list <studentas> stud;
    studentas s;
    for (int i = 0; i < kiekstud; i++)
    {
        in >> s.vard >> s.pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> s.egz;
        s.gal = vid / kieknd * 0.4 + s.egz * 0.6;
        vid = 0;
        stud.push_back(s);
    }
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    list <studentas> nend, kiet;
    auto rus = high_resolution_clock::now();
    rusiavimaslist(stud, nend, kiet);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;
    kiet.clear();
    nend.clear();

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimaslist (list <studentas> &stud, list <studentas>& nend, list <studentas>& kiet)
{
    stud.sort(palyginimas);
    for (auto &s:stud )//(auto &temp:stud)
    {
        if (s.gal < 5.0)
        {
            nend.push_back(s);
        }
        else
        {
            kiet.push_back(s);
        }
    }
    stud.clear();
}

void greicioanalizedeque(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    deque <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    deque <studentas> nend, kiet;
    auto rus = high_resolution_clock::now();
    rusiavimasdeque(stud, nend, kiet);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;
    kiet.clear();
    nend.clear();

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasdeque(deque <studentas> &stud, deque <studentas>& nend, deque <studentas>& kiet)
{
    sort(stud.begin(), stud.end(), palyginimas);
    for (auto& s : stud)//(auto &temp:stud)
    {
        if (s.gal < 5.0)
        {
            nend.push_back(s);
        }
        else
        {
            kiet.push_back(s);
        }
    }
    stud.clear();
    nend.shrink_to_fit();
    kiet.shrink_to_fit();
}

void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai"+to_string(kiekstud)+".txt");
    stringstream buffer;
    for (int i = 0; i < nend.size(); i++)
    {
        buffer << left << setw(20) << nend[i].vard << " " << left << setw(20) << nend[i].pavard << " " << left << setw(20) << fixed << setprecision(2)<< nend[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout <<kiekstud<< " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifaila(int kieknd, vector <studentas> kiet, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < kiet.size(); i++)
    {
        buffer << left << setw(20) << kiet[i].vard << " " << left << setw(20) << kiet[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << kiet[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}

void greicioanalizevector2(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    vector <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    vector <studentas> nend;
    auto rus = high_resolution_clock::now();
    rusiavimasvector2(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifaila2(kieknd, nend, kiekstud);
    kietiakaiifaila2(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasvector2(vector <studentas>& stud, vector <studentas>& nend)
{
    sort(stud.begin(), stud.end(), palyginimas);
    int i = 0;
    for (int i = 0; i < stud.size(); i++)//(auto &temp:stud)
    {
        if (stud[i].gal < 5.0)
        {
            nend.push_back(stud[i]);
            stud.erase(stud.begin() + i);
            i--;
        }
    }
    stud.shrink_to_fit();
    nend.shrink_to_fit();
}

void nendartiolaiifaila2(int kieknd, vector <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < nend.size(); i++)
    {
        buffer << left << setw(20) << nend[i].vard << " " << left << setw(20) << nend[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << nend[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifaila2(int kieknd, vector <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < stud.size(); i++)
    {
        buffer << left << setw(20) << stud[i].vard << " " << left << setw(20) << stud[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << stud[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}


void greicioanalizelist2(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a;
    float vid = 0;
    list <studentas> stud;
    studentas s;
    for (int i = 0; i < kiekstud; i++)
    {
        in >> s.vard >> s.pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> s.egz;
        s.gal = vid / kieknd * 0.4 + s.egz * 0.6;
        vid = 0;
        stud.push_back(s);
    }
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    list <studentas> nend;
    auto rus = high_resolution_clock::now();
    rusiavimaslist2(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifailalist2(kieknd, nend, kiekstud);
    kietiakaiifailalist2(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimaslist2(list <studentas>& stud, list <studentas>& nend)
{
    stud.sort(palyginimas);
    list<studentas>::iterator it = stud.begin();
    while (it->gal < 5.0)
    {
        nend.push_back(*it);
        stud.pop_front();
        it = stud.begin();
    }
    //int i = 0;
    /*for (auto& s : stud)//(auto &temp:stud)
    {
        it = stud.begin();
        advance(it, i);
        if (s.gal < 5.0)
        {
            nend.splice(nend.begin(), stud, it);
            i--;
        }
        i++;
    }*/
}

void nendartiolaiifailalist2(int kieknd, list <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (list<studentas>::iterator it = nend.begin(); it != nend.end(); it++)
    {
        buffer << left << setw(20) << it->vard << " " << left << setw(20) << it->pavard << " " << left << setw(20) << fixed << setprecision(2) << it->gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifailalist2(int kieknd, list <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (list<studentas>::iterator it = stud.begin(); it != stud.end(); it++)
    {
        buffer << left << setw(20) << it->vard << " " << left << setw(20) << it->pavard << " " << left << setw(20) << fixed << setprecision(2) << it->gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}

void greicioanalizedeque2(int kiekstud)
{
    ifstream in("kursiokai" + to_string(kiekstud) + ".txt");
    auto pradzia = high_resolution_clock::now();
    int kieknd = 0;
    string zod;
    while (true)
    {
        in >> zod;
        kieknd++;
        if (zod == "Egz.")
        {
            break;
        }
    }
    kieknd += -3;
    int a, vid = 0;
    deque <studentas> stud;
    for (int i = 0; i < kiekstud; i++)
    {
        stud.push_back(studentas());
        in >> stud[i].vard >> stud[i].pavard;
        for (int j = 0; j < kieknd; j++)
        {
            in >> a;
            vid += a;
        }
        in >> stud[i].egz;
        stud[i].gal = vid / kieknd * 0.4 + stud[i].egz * 0.6;
        vid = 0;
    }
    stud.shrink_to_fit();
    in.close();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nuskaitymas uztruko: " << diff.count() << endl;

    deque <studentas> nend, kiet;
    auto rus = high_resolution_clock::now();
    rusiavimasdeque2(stud, nend);
    diff = high_resolution_clock::now() - rus;
    cout << kiekstud << " rusiavimas i dvi kategorijas: " << diff.count() << endl;

    nendartiolaiifailadeque2(kieknd, nend, kiekstud);
    kietiakaiifailadeque2(kieknd, stud, kiekstud);

    diff = high_resolution_clock::now() - pradzia;
    cout << endl << kiekstud << " visas testo laikas: " << diff.count() << endl << endl;
    system("Pause");
}

void rusiavimasdeque2(deque <studentas>& stud, deque <studentas>& nend)
{
    sort(stud.begin(), stud.end(), palyginimas);
    int i = 0;
    for (int i = 0; i < stud.size(); i++)//(auto &temp:stud)
    {
        if (stud[i].gal < 5.0)
        {
            nend.push_back(stud[i]);
            stud.erase(stud.begin() + i);
            i--;
        }
    }
    stud.shrink_to_fit();
    nend.shrink_to_fit();
}

void nendartiolaiifailadeque2(int kieknd, deque <studentas> nend, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("nendartiolai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < nend.size(); i++)
    {
        buffer << left << setw(20) << nend[i].vard << " " << left << setw(20) << nend[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << nend[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    nend.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " nendartiolu isvedimas i faila: " << diff.count() << endl;
}

void kietiakaiifailadeque2(int kieknd, deque <studentas> stud, int kiekstud)
{
    auto pradzia = high_resolution_clock::now();
    ofstream out("kietiakai" + to_string(kiekstud) + ".txt");
    stringstream buffer;
    for (int i = 0; i < stud.size(); i++)
    {
        buffer << left << setw(20) << stud[i].vard << " " << left << setw(20) << stud[i].pavard << " " << left << setw(20) << fixed << setprecision(2) << stud[i].gal << endl;
    }
    out << buffer.str();
    buffer.str("");
    out.close();
    stud.clear();
    duration<double> diff = high_resolution_clock::now() - pradzia;
    cout << kiekstud << " kietiakai isvedimas i faila: " << diff.count() << endl;
}


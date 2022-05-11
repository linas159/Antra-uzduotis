


# Programa skirta studentų pažymių vidurkiui ir medianai apskaičiuoti.

1. Pirmojoje versijos dalyje naudojant vektorius yra apskaiciuojamas ivestu studentu galutinis balas naudojant namu darbu vidurki.

2. Antrojoje versijoje galutinis balas apskaiciuojamas ir naudojant namu darbu ivertinimu mediana.

3. Treciojoje versijoje namu darbu ir egzamino ivertinimas yra sugeneruojami atsitiktinai.

4. Galutineje sios programos versijoje viskas sudeta i viena visuma. Taip pat vartotojas gali pasirinkti ar nori jog namu darbu ivertinimai butu sugeneruoti atsitiktinai ar ivesti juos ranka. Taip pat vietoj skaiciaus ivedus koki kita simboli programa praso ivesti skaiciu.


v0.5:

Programa papildyta su vector list ir deque konteineriais.

Istestavus programos greicio veikimo analize galima padaryti tokia isvada:

Greiciausiai sudirba list po jo seka deque ir leciausias yra vector konteineris.

MANO NAUDOJO KOMPIUTERIO PARAMETRAI:

CPU (Intel Core i5-12500) 

GPU (NVIDIA GeForce RTX 3060 Ti)

16 RAM

SSD

v1.0:

Programa galima paleisti dviem strategijomis:

1: Skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius.

2: Skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį.

Naudojant PIRMA strategija gauti tokie rezultatai:

Vector:

![image](https://cdn.discordapp.com/attachments/940892487365591070/960161247330967602/unknown.png)

List:

![image](https://media.discordapp.net/attachments/940892487365591070/960162741270765578/unknown.png)

Deque:

![image](https://cdn.discordapp.com/attachments/940892487365591070/960163931199012964/unknown.png)

ISVADA: Vector uztrunka ilgiausiai ir skirtumas yra labai ryskus. List yra greiciausias taciau nezymiai deque yra letesnis.

Naudojant PIRMA strategija gauti tokie rezultatai:

Vector:

![image](https://media.discordapp.net/attachments/940892487365591070/968027035173785600/unknown.png)

List:

![image](https://media.discordapp.net/attachments/940892487365591070/968027355757051975/unknown.png)

Deque:

![image](https://media.discordapp.net/attachments/940892487365591070/968027714193879100/unknown.png?width=414&height=676)

ISVADA: Su vector konteineriu uztrunka labai ilgai, net nesulaukta pabaigos. Taciau su list ir deque konteineriais laikas trumpesnis 10 kartu lyginant su pirma strategija.

v1.1:

Ankstesnės atliktos užduoties pagrindu susikurti naują repoziciją, t.y., visa git istorija iki v1.0 turi išlikti. Įprastinė procedūra būtų:

Nusikopijuoti lokaliai (kompiuteryje) visą antrosios užduoties repoziciją (katalogą); Susikurti naują repoziciją GitHub'e. Pasikeiskite nusikopijuotos repozicijos nuotolinį adresą panaudojant git remote set-url origin komandą terminale: git remote set-url origin https://github.com/USERNAME/NAUJA_REPOZICIJA.git Nupushinkite nusikopijuotą repoziciją į GitHub'ą: git push -u origin master Realizuokite programą pagal rekomendacijas ir reikalavimus pateiktus aprašė. Manau suprantate, kad parėjus iš struktūros į klasę, reikės atlikti atitinkamus pakeitimus visame kode!

Palyginkite abiejų Jūsų programų: naudojančios struct iš ankstesniojo darbo ir naudojančio class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus. Gautus rezultatus aprašykite README.md faile.

Atlikite eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 ir papildykite README.md failą gautais rezultatais su optimizavimo flag'ais.

Be flag'ų:

![image](https://user-images.githubusercontent.com/93277316/167713021-216da0eb-27a0-455f-a37f-3a20c1d0e953.png)

Flag -01:

![image](https://user-images.githubusercontent.com/93277316/167713075-1337c7c0-802c-4848-94aa-4976faf3c480.png)

Flag -02:

![image](https://user-images.githubusercontent.com/93277316/167713114-9cd3a257-c563-480d-859e-f7cf3e5fbb71.png)

Flag -03:

![image](https://user-images.githubusercontent.com/93277316/167713165-c2d56d85-0591-4d94-943b-67c10e6ba929.png)

Flag'ai greičiui įtakos neturi.

v1.2

Realizuokite visus reikiamus (realizuokitė "Rule of three") ir tinkamus (turinčius prasmę) ir tik šiuos operatorius Jūsų turimai Studentas klasei. Pažymiu, kad nebūtinai visi realizuoti operatoriai turi būti panaudoti Jūsų programose - atminkite, kad Jūs kuriate/kursite programas ne tik sau, todėl įvertinkite ko gali prireikti ateities vartotojams naudojantiems Jūsų Studentas klasę!

v1.2.1

Patverkyta versija

v1.5

Vietoje Jūsų turimos vienos Studentas (ar kažkaip kitaip pavadintos) klasės sukurkite dvi: bazinę klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Studentas.
Padarykite, kad žmogui skirta bazinė klasė būtų abstrakčioji klasė, t.y. nebūtų galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių.

![image](https://user-images.githubusercontent.com/93277316/167713990-482d9fc4-48f2-49e8-b8e0-364413f727ba.png)

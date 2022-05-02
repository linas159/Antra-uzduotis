


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

![](https://cdn.discordapp.com/attachments/940892487365591070/960161247330967602/unknown.png)

List:

![](https://media.discordapp.net/attachments/940892487365591070/960162741270765578/unknown.png)

Deque:

![](https://cdn.discordapp.com/attachments/940892487365591070/960163931199012964/unknown.png)

ISVADA: Vector uztrunka ilgiausiai ir skirtumas yra labai ryskus. List yra greiciausias taciau nezymiai deque yra letesnis.

Naudojant PIRMA strategija gauti tokie rezultatai:

Vector:

![](https://media.discordapp.net/attachments/940892487365591070/968027035173785600/unknown.png)

List:

![](https://media.discordapp.net/attachments/940892487365591070/968027355757051975/unknown.png)

Deque:

![](https://media.discordapp.net/attachments/940892487365591070/968027714193879100/unknown.png?width=414&height=676)

ISVADA: Su vector konteineriu uztrunka labai ilgai, net nesulaukta pabaigos. Taciau su list ir deque konteineriais laikas trumpesnis 10 kartu lyginant su pirma strategija.

v1.1:

Ankstesnės atliktos užduoties pagrindu susikurti naują repoziciją, t.y., visa git istorija iki v1.0 turi išlikti. Įprastinė procedūra būtų:

Nusikopijuoti lokaliai (kompiuteryje) visą antrosios užduoties repoziciją (katalogą);
Susikurti naują repoziciją GitHub'e.
Pasikeiskite nusikopijuotos repozicijos nuotolinį adresą panaudojant git remote set-url origin komandą terminale:
git remote set-url origin https://github.com/USERNAME/NAUJA_REPOZICIJA.git
Nupushinkite nusikopijuotą repoziciją į GitHub'ą:
git push -u origin master
Realizuokite programą pagal rekomendacijas ir reikalavimus pateiktus aprašė. Manau suprantate, kad parėjus iš struktūros į klasę, reikės atlikti atitinkamus pakeitimus visame kode!

Palyginkite abiejų Jūsų programų: naudojančios struct iš ankstesniojo darbo ir naudojančio class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus. Gautus rezultatus aprašykite README.md faile.

Atlikite eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 ir papildykite README.md failą gautais rezultatais su optimizavimo flag'ais.

Be flag'ų:

![image](https://user-images.githubusercontent.com/93277316/166300671-69617917-b7a5-4202-85fa-cda31c65a93e.png)

Flag -01:

![image](https://user-images.githubusercontent.com/93277316/166300750-45c69f01-06b2-4972-aced-344b89bc4d40.png)

Flag -02:

![image](https://user-images.githubusercontent.com/93277316/166300790-e41e0301-4788-4b00-971b-a798af86d3d3.png)

Flag -03:

![image](https://user-images.githubusercontent.com/93277316/166300835-5337f734-2695-4f46-b6a0-f6c422dd7798.png)

Flag'ai greičiui įtakos neturi.

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <thread>
#include <iomanip>

using namespace std;

const static string CODIGO = "ZI10";
int Respuestas_Correctas;

int charToInt(char caracter)
{
    switch (caracter)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return -987654321;
    }
}

bool isNumber(const string& str)
{
    for (char const& c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

int Num_Entero(string Num)
{
    if (Num == "") { return -987654321; }
    int EsNumero = 0;
    int EsPositivo = 0;
    char CaracterSigno = Num[0];
    int Resultado;
    if (CaracterSigno == '-')
    {
        Num.erase(0, 1);
        EsPositivo = 1;
    }
    isNumber(Num) ? EsNumero = 0 : EsNumero = 1;
    if (EsNumero == 1)
    {
        return -987654321;
    }
    else
    {
        Resultado = stoi(Num);
        if (EsPositivo == 1)
        {
            Resultado = Resultado * (-1);
        }
        return Resultado;
    }
}

struct Preguntas//Deportes, Historia, Geografia, Entretenimiento, Arte, Ciencia, Eleccion
{
    string Pregunta;
    string O1;
    string O2;
    string O3;
    string OC;
    bool Contador;
}Pregunta[120];

void setFalse() {
    for (int i = 0; i < 120; i++) Pregunta[i].Contador = false;
}

void Iniciar_programa()
{
    system("color 0A");
    setFalse();

    Pregunta[0].Pregunta = "Cuantos Roland Garros gano Rafael Nadal?";
    Pregunta[0].O1 = "9";
    Pregunta[0].O2 = "12";
    Pregunta[0].O3 = "16";
    Pregunta[0].OC = "14";

    Pregunta[1].Pregunta = "Cuantas participaciones en mundiales tiene Chile en toda su historia?";
    Pregunta[1].O1 = "5";
    Pregunta[1].O2 = "13";
    Pregunta[1].O3 = "2";
    Pregunta[1].OC = "9";

    Pregunta[2].Pregunta = "Cual fue el campeon de la NBA en 2022?";
    Pregunta[2].O1 = "Boston Celtics";
    Pregunta[2].O2 = "Milwaukee Bucks";
    Pregunta[2].O3 = "Ninguna de las opciones es correcta";
    Pregunta[2].OC = "Golden State Warriors";

    Pregunta[3].Pregunta = "Cual es el equipo de futbol con mas titulos internacionales?";
    Pregunta[3].O1 = "Boca Juniors";
    Pregunta[3].O2 = "Manchester United";
    Pregunta[3].O3 = "Milan";
    Pregunta[3].OC = "Real Madrid";

    Pregunta[4].Pregunta = "Cuantos balones de oro tiene Lionel Andres Messi";
    Pregunta[4].O1 = "6";
    Pregunta[4].O2 = "10";
    Pregunta[4].O3 = "4";
    Pregunta[4].OC = "7";

    Pregunta[5].Pregunta = "Cual es el maximo goleador de la historia del futbol?";
    Pregunta[5].O1 = "Pele";
    Pregunta[5].O2 = "Josef Bican";
    Pregunta[5].O3 = "Messi";
    Pregunta[5].OC = "Cristiano ronaldo";

    Pregunta[6].Pregunta = "En que equipo de la NBA jugo Ginobili?";
    Pregunta[6].O1 = "Los Angeles Lakers";
    Pregunta[6].O2 = "Atlanta Hawks";
    Pregunta[6].O3 = "Houston Rocket";
    Pregunta[6].OC = "San Antonio Spurs";

    Pregunta[7].Pregunta = "Quien fue el mejor armador de Voley en 2021?";
    Pregunta[7].O1 = "Hugo Conte";
    Pregunta[7].O2 = "Lorenzo Bernardi";
    Pregunta[7].O3 = "Josef Musil";
    Pregunta[7].OC = "Luciano De Cecco";

    Pregunta[8].Pregunta = "Cual es el largo de una cancha de futbol reglamentaria?";
    Pregunta[8].O1 = "100-110";
    Pregunta[8].O2 = "100";
    Pregunta[8].O3 = "80-100";
    Pregunta[8].OC = "90-120";

    Pregunta[9].Pregunta = "Cual es el ancho de una cancha de futbol reglamentaria?";
    Pregunta[9].O1 = "55-85";
    Pregunta[9].O2 = "80-100";
    Pregunta[9].O3 = "50-70";
    Pregunta[9].OC = "45-90";

    Pregunta[10].Pregunta = "Que equipo fue conocido como los invencibles?";
    Pregunta[10].O1 = "Barcelona";
    Pregunta[10].O2 = "Real Madrid";
    Pregunta[10].O3 = "Liverpool";
    Pregunta[10].OC = "Arsenal";

    Pregunta[11].Pregunta = "Cuantos balones de oro tiene Maradona?";
    Pregunta[11].O1 = "7";
    Pregunta[11].O2 = "3";
    Pregunta[11].O3 = "0";
    Pregunta[11].OC = "2";

    Pregunta[12].Pregunta = "Cual fue el primer equipo argentino de CS:GO en clasificar a una Major?";
    Pregunta[12].O1 = "Boca Juniors";
    Pregunta[12].O2 = "Isurus";
    Pregunta[12].O3 = "Coscu Army";
    Pregunta[12].OC = "9z";

    Pregunta[13].Pregunta = "A que equipo de ESports pertenece Beniju?";
    Pregunta[13].O1 = "Team Liquid";
    Pregunta[13].O2 = "Immortals";
    Pregunta[13].O3 = "SK Gaming";
    Pregunta[13].OC = "Team Queso";

    Pregunta[14].Pregunta = "Que equipo competitivo de Valorant es el que tiene mas ganancias?";
    Pregunta[14].O1 = "Team Liquid";
    Pregunta[14].O2 = "Fnatic";
    Pregunta[14].O3 = "G2 Esports";
    Pregunta[14].OC = "Sentinels";

    Pregunta[15].Pregunta = "Quien es el futbolista que tiene el record de mas goles en un anio natural, contando solo los goles en partidos oficiales?";
    Pregunta[15].O1 = "Cristiano Ronaldo";
    Pregunta[15].O2 = "Pele";
    Pregunta[15].O3 = "Zlatan Ibrahimovic";
    Pregunta[15].OC = "Lionel Andres Messi";

    Pregunta[16].Pregunta = "Cual es el largo maximo de una cancha de Rugby?";
    Pregunta[16].O1 = "120";
    Pregunta[16].O2 = "80";
    Pregunta[16].O3 = "134";
    Pregunta[16].OC = "100";

    Pregunta[17].Pregunta = "Cual es el ancho maximo de una cancha de Rugby?";
    Pregunta[17].O1 = "57";
    Pregunta[17].O2 = "40";
    Pregunta[17].O3 = "100";
    Pregunta[17].OC = "70";

    Pregunta[18].Pregunta = "Cuales son los unicos dos equipos de futbol en conseguir un sextete";
    Pregunta[18].O1 = "Bayern Munich y Liverpool";
    Pregunta[18].O2 = "Manchester United y Real Madrid";
    Pregunta[18].O3 = "Real Madrid y Barcelona";
    Pregunta[18].OC = "Barcelona y Bayern Munich";

    Pregunta[19].Pregunta = "En que pais nacio el futbolista Zlatan Ibrahimovic?";
    Pregunta[19].O1 = "Serbia";
    Pregunta[19].O2 = "Noruega";
    Pregunta[19].O3 = "Reino Unido";
    Pregunta[19].OC = "Suecia";

    Pregunta[20].Pregunta = "En que anio comenzo la Segunda Guerra Mundial?";//Historia
    Pregunta[20].O1 = "1938";
    Pregunta[20].O2 = "1940";
    Pregunta[20].O3 = "1944";
    Pregunta[20].OC = "1939";

    Pregunta[21].Pregunta = "Quien fue el mayor genocida de la historia?";//Historia
    Pregunta[21].O1 = "Gengis Kan";
    Pregunta[21].O2 = "Iosif Stalin";
    Pregunta[21].O3 = "Adolf Hitler";
    Pregunta[21].OC = "Mao Zedong";

    Pregunta[22].Pregunta = "En que anio comenzo la Primera Guerra Mundial?";//Historia
    Pregunta[22].O1 = "1908";
    Pregunta[22].O2 = "1903";
    Pregunta[22].O3 = "1913";
    Pregunta[22].OC = "1914";

    Pregunta[23].Pregunta = "En que anio termino la Segunda Guerra Mundial?";//Historia
    Pregunta[23].O1 = "1944";
    Pregunta[23].O2 = "1953";
    Pregunta[23].O3 = "1946";
    Pregunta[23].OC = "1945";

    Pregunta[24].Pregunta = "En que anio termino la Primera Guerra Mundial?";//Historia
    Pregunta[24].O1 = "1920";
    Pregunta[24].O2 = "1916";
    Pregunta[24].O3 = "1917";
    Pregunta[24].OC = "1918";

    Pregunta[25].Pregunta = "Cuantos anios duro la Guerra de los Cien Anios?";//Historia
    Pregunta[25].O1 = "97";
    Pregunta[25].O2 = "100";
    Pregunta[25].O3 = "103";
    Pregunta[25].OC = "116";

    Pregunta[26].Pregunta = "Quien fue el dictador de la URSS durante la Segunda Guerra Mundial?";//Historia
    Pregunta[26].O1 = "Nikita Jrushchov";
    Pregunta[26].O2 = "Mijail Gorbachov";
    Pregunta[26].O3 = "Vladimir Lenin";
    Pregunta[26].OC = "Iosif Stalin";

    Pregunta[27].Pregunta = "Como se llamaba la Fereracion Rusa cuando pertenecia a la Union de Republicas Socialistas Sovieticas?";//Historia
    Pregunta[27].O1 = "Union de Republicas Socialistas Sovieticas";
    Pregunta[27].O2 = "Federacion Rusa";
    Pregunta[27].O3 = "Rusia";
    Pregunta[27].OC = "Republica Socialista Sovietica de Rusia";

    Pregunta[28].Pregunta = "Cuantos presidentes tuvo la Republica Argentina durante el 2001?";//Historia
    Pregunta[28].O1 = "3";
    Pregunta[28].O2 = "2";
    Pregunta[28].O3 = "4";
    Pregunta[28].OC = "5";

    Pregunta[29].Pregunta = "Cuantos mandatos tuvo Juan Domingo Peron como presidente de Argentina?";//Historia
    Pregunta[29].O1 = "1";
    Pregunta[29].O2 = "2";
    Pregunta[29].O3 = "4";
    Pregunta[29].OC = "3";

    Pregunta[30].Pregunta = "Como se cree que llegaron los primeros humanos a America?";//Historia
    Pregunta[30].O1 = "En barcos desde Africa";
    Pregunta[30].O2 = "Siempre hubo humanos en America";
    Pregunta[30].O3 = "Nadando desde China";
    Pregunta[30].OC = "Caminando por el Estrecho de Bering";

    Pregunta[31].Pregunta = "Como se llamaba el dictador del Terccer Reich durante la Segunda Guerra Mundial?";//Historia
    Pregunta[31].O1 = "Iosif Stalin";
    Pregunta[31].O2 = "Vladimir Lenin";
    Pregunta[31].O3 = "Benito Musolini";
    Pregunta[31].OC = "Adolf Hitler";

    Pregunta[32].Pregunta = "Que era la URSS?";//Historia
    Pregunta[32].O1 = "Union Republicana de Santa Susana";
    Pregunta[32].O2 = "Union Republicana de Siniopes Soleros";
    Pregunta[32].O3 = "Ninguna de las anteriores";
    Pregunta[32].OC = "Union de Republicas Socialistas Sovieticas";

    Pregunta[33].Pregunta = "Que hecho historico es conocido como el 9-11?";//Historia
    Pregunta[33].O1 = "El inicio de la Segunda Guerra Mundial";
    Pregunta[33].O2 = "El hundimiento del Titanic";
    Pregunta[33].O3 = "La disolucion de la URSS";
    Pregunta[33].OC = "El atentado terrorista que derribo las torres gemelas";

    Pregunta[34].Pregunta = "Donde se invento la escritura?";//Historia
    Pregunta[34].O1 = "En el antiguo Egipto";
    Pregunta[34].O2 = "En la antigua Babilonia";
    Pregunta[34].O3 = "En Jerusalen";
    Pregunta[34].OC = "En el Sur de la Mesopotamia";

    Pregunta[35].Pregunta = "En que anio tuvo lugar el ataque a Pearl Harbor?";//Historia
    Pregunta[35].O1 = "1939";
    Pregunta[35].O2 = "1940";
    Pregunta[35].O3 = "1942";
    Pregunta[35].OC = "1941";

    Pregunta[36].Pregunta = "Cuantos soldados argentinos murieron en la Guerra de las Malvinas?";//Historia
    Pregunta[36].O1 = "1452";
    Pregunta[36].O2 = "987";
    Pregunta[36].O3 = "200";
    Pregunta[36].OC = "649";

    Pregunta[37].Pregunta = "Con que emperador estuvo casada Cleopatra?";//Historia
    Pregunta[37].O1 = "Ptolomeo XIV";
    Pregunta[37].O2 = "Julio Cesar";
    Pregunta[37].O3 = "Marco Antonio";
    Pregunta[37].OC = "Todas son correctas";

    Pregunta[38].Pregunta = "Quien escribio la Odisea?";//Historia 
    Pregunta[38].O1 = "Platon";
    Pregunta[38].O2 = "Socrates";
    Pregunta[38].O3 = "Aristoteles";
    Pregunta[38].OC = "Homero";

    Pregunta[39].Pregunta = "Que paso en la catastrofe de Plim Plim?";//Historia
    Pregunta[39].O1 = "Murio Plim Plim";
    Pregunta[39].O2 = "Hubo un terremoto en Plim Plim con 9,1 en la escala de Richter";
    Pregunta[39].O3 = "La ciudad de Plim Plim perdio la guerra contra los sumerios";
    Pregunta[39].OC = "Ninguna opcion es correcta";

    Pregunta[40].Pregunta = "Cual es el rio mas largo del mundo?";
    Pregunta[40].O1 = "Misisipi";
    Pregunta[40].O2 = "Nilo";
    Pregunta[40].O3 = "Yangtze";
    Pregunta[40].OC = "Amazonas";

    Pregunta[41].Pregunta = "Cual es el continente mas grande del mundo?";
    Pregunta[41].O1 = "Europa";
    Pregunta[41].O2 = "America del Norte";
    Pregunta[41].O3 = "Africa";
    Pregunta[41].OC = "Asia";

    Pregunta[42].Pregunta = "Que oceano se encuentra al este de Estados Unidos?";
    Pregunta[42].O1 = "Oceano Pacifico";
    Pregunta[42].O2 = "Oceano indico";
    Pregunta[42].O3 = "Oceano artico";
    Pregunta[42].OC = "Oceano Atlantico";

    Pregunta[43].Pregunta = "Cual es el nombre de la cordillera que se extiende desde Canada hasta Mexico?";
    Pregunta[43].O1 = "Andes";
    Pregunta[43].O2 = "Himalaya";
    Pregunta[43].O3 = "Montes Urales";
    Pregunta[43].OC = "Rocky Mountains";

    Pregunta[44].Pregunta = "Cual es el pais mas poblado de Europa?";
    Pregunta[44].O1 = "Espania";
    Pregunta[44].O2 = "Alemania";
    Pregunta[44].O3 = "Francia";
    Pregunta[44].OC = "Rusia";

    Pregunta[45].Pregunta = "En que pais se encuentra la Torre Eiffel?";
    Pregunta[45].O1 = "Italia";
    Pregunta[45].O2 = "Espania";
    Pregunta[45].O3 = "Reino Unido";
    Pregunta[45].OC = "Francia";

    Pregunta[46].Pregunta = "Que pais es el mas al norte de America Central?";
    Pregunta[46].O1 = "Guatemala";
    Pregunta[46].O2 = "Belice";
    Pregunta[46].O3 = "Mexico";
    Pregunta[46].OC = "Honduras";

    Pregunta[47].Pregunta = "Cual es el punto mas alto de America del Norte?";
    Pregunta[47].O1 = "Popocatepetl";
    Pregunta[47].O2 = "Monte Whitney";
    Pregunta[47].O3 = "Pico de Orizaba";
    Pregunta[47].OC = "Denali";

    Pregunta[48].Pregunta = "En que pais se encuentra la ciudad de Marrakech?";
    Pregunta[48].O1 = "Argelia";
    Pregunta[48].O2 = "Tunez";
    Pregunta[48].O3 = "Egipto";
    Pregunta[48].OC = "Marruecos";

    Pregunta[49].Pregunta = "Que pais es el mas grande de africa?";
    Pregunta[49].O1 = "Sudafrica";
    Pregunta[49].O2 = "Nigeria";
    Pregunta[49].O3 = "Egipto";
    Pregunta[49].OC = "Argelia";

    Pregunta[50].Pregunta = "Cual es la capital de Nueva Zelanda?";
    Pregunta[50].O1 = "Auckland";
    Pregunta[50].O2 = "Christchurch";
    Pregunta[50].O3 = "Queenstown";
    Pregunta[50].OC = "Wellington";

    Pregunta[51].Pregunta = "En que pais se encuentra el Monte Kilimanjaro ? ";
    Pregunta[51].O1 = "Kenia";
    Pregunta[51].O2 = "Uganda";
    Pregunta[51].O3 = "Etiopia";
    Pregunta[51].OC = "Tanzania";

    Pregunta[52].Pregunta = "Que pais es el segundo mas grande del mundo en terminos de superficie terrestre ? ";
    Pregunta[52].O1 = "Rusia";
    Pregunta[52].O2 = "China";
    Pregunta[52].O3 = "Estados Unidos";
    Pregunta[52].OC = "Canada";

    Pregunta[53].Pregunta = "Que rio es conocido como el \"rio de los reyes\"?";
    Pregunta[53].O1 = "Mekong";
    Pregunta[53].O2 = "Amazonas";
    Pregunta[53].O3 = "Ganges";
    Pregunta[53].OC = "Nilo";

    Pregunta[54].Pregunta = "En que continente se encuentra el desierto del Sahara ? ";
    Pregunta[54].O1 = "Asia";
    Pregunta[54].O2 = "Europa";
    Pregunta[54].O3 = "America del Norte";
    Pregunta[54].OC = "africa";

    Pregunta[55].Pregunta = "En que pais se encuentra la ciudad de Petra ? ";
    Pregunta[55].O1 = "Egipto";
    Pregunta[55].O2 = "Arabia Saudita";
    Pregunta[55].O3 = "Israel";
    Pregunta[55].OC = "Jordania";

    Pregunta[56].Pregunta = "Que pais limita con Chile al este ? ";
    Pregunta[56].O1 = "Brasil";
    Pregunta[56].O2 = "Bolivia";
    Pregunta[56].O3 = "Peru";
    Pregunta[56].OC = "Argentina";

    Pregunta[57].Pregunta = "Cual es el pais mas pequenio del mundo por superficie ? ";
    Pregunta[57].O1 = "San Marino";
    Pregunta[57].O2 = "Monaco";
    Pregunta[57].O3 = "Andorra";
    Pregunta[57].OC = "Ciudad del Vaticano";

    Pregunta[58].Pregunta = "En que oceano se encuentra la Isla de Pascua ? ";
    Pregunta[58].O1 = "Oceano Artico";
    Pregunta[58].O2 = "Oceano Atlantico";
    Pregunta[58].O3 = "Oceano Atlantico";
    Pregunta[58].OC = "Oceano Pacifico";

    Pregunta[59].Pregunta = "Cual de los siguientes paises se encuentra en dos continentes al mismo tiempo?";
    Pregunta[59].O1 = "China";
    Pregunta[59].O2 = "Canada";
    Pregunta[59].O3 = "Arabia Saudita";
    Pregunta[59].OC = "Egipto";

    Pregunta[60].Pregunta = "Cuando se esteno la famosa pelicula Fight Club?";
    Pregunta[60].O1 = "1990 ";
    Pregunta[60].O2 = "2000";
    Pregunta[60].O3 = "2005";
    Pregunta[60].OC = "1999";

    Pregunta[61].Pregunta = "Cuando se estreno la famosa pelicula Titanic?";
    Pregunta[61].O1 = "1996";
    Pregunta[61].O2 = "1969";
    Pregunta[61].O3 = "1989";
    Pregunta[61].OC = "1997";

    Pregunta[62].Pregunta = "Cuando se lanzo el primer pac-man?";
    Pregunta[62].O1 = "1920";
    Pregunta[62].O2 = "1933";
    Pregunta[62].O3 = "1977";
    Pregunta[62].OC = "1980";

    Pregunta[63].Pregunta = "A que se dedica el famoso \"Duki\"?";
    Pregunta[63].O1 = "Locutor";
    Pregunta[63].O2 = "Cocinero";
    Pregunta[63].O3 = "Pintor";
    Pregunta[63].OC = "Musico";

    Pregunta[64].Pregunta = "Cuantas peliculas tiene la saga de \"Rapidos y Furioso\"?";
    Pregunta[64].O1 = "11";
    Pregunta[64].O2 = "8";
    Pregunta[64].O3 = "9";
    Pregunta[64].OC = "10";

    Pregunta[65].Pregunta = "Como se llama el protagonista de Bola de Dragon?";
    Pregunta[65].O1 = "Gohan";
    Pregunta[65].O2 = "Vegeta";
    Pregunta[65].O3 = "Lilo";
    Pregunta[65].OC = "Goku";

    Pregunta[66].Pregunta = "Cual es la fruta favorita de los minions?";
    Pregunta[66].O1 = "Naranja";
    Pregunta[66].O2 = "Mandarina";
    Pregunta[66].O3 = "Sandia";
    Pregunta[66].OC = "Banana";

    Pregunta[67].Pregunta = "En que siglo se desarrolla Terminator?";
    Pregunta[67].O1 = "XV";
    Pregunta[67].O2 = "X";
    Pregunta[67].O3 = "V";
    Pregunta[67].OC = "XX";

    Pregunta[68].Pregunta = "Que familia vive en la ciudad de Springfield?";
    Pregunta[68].O1 = "Los Stuarts";
    Pregunta[68].O2 = "Los Esparrach";
    Pregunta[68].O3 = "Los gonzales";
    Pregunta[68].OC = "Los Simpson";

    Pregunta[69].Pregunta = "Que abrievatura se usa para llamar a la banda australiana 5 seconds of summer?";
    Pregunta[69].O1 = "4SOS";
    Pregunta[69].O2 = "3SOS";
    Pregunta[69].O3 = "8SOS";
    Pregunta[69].OC = "5SOS";

    Pregunta[70].Pregunta = "Cuantos anios tenia Harry Potter cuando entro en Hogwarts?";
    Pregunta[70].O1 = "12";
    Pregunta[70].O2 = "13";
    Pregunta[70].O3 = "9";
    Pregunta[70].OC = "11";

    Pregunta[71].Pregunta = "De que color es el pelo de Naruto?";
    Pregunta[71].O1 = "Rojo";
    Pregunta[71].O2 = "Negro";
    Pregunta[71].O3 = "Violeta";
    Pregunta[71].OC = "Amarillo";

    Pregunta[72].Pregunta = "Quien saco la cancion \"Despacito\"?";
    Pregunta[72].O1 = "Mauro zarate";
    Pregunta[72].O2 = "Cristiano ronaldo";
    Pregunta[72].O3 = "Travis scott";
    Pregunta[72].OC = "Luis Fonsi";

    Pregunta[73].Pregunta = "Como se llama la mujer de Shrek?";
    Pregunta[73].O1 = "Lucia";
    Pregunta[73].O2 = "Marta";
    Pregunta[73].O3 = "Guadalupe";
    Pregunta[73].OC = "Fiona";

    Pregunta[74].Pregunta = "Que cantante colombiana va en bicicleta con Carlos Vives?";
    Pregunta[74].O1 = "Marta diaz";
    Pregunta[74].O2 = "Nicky nicole";
    Pregunta[73].O3 = "Cazzu";
    Pregunta[74].OC = "Shakira";

    Pregunta[75].Pregunta = "Quien se considera el \"Rey del pop\"?";
    Pregunta[75].O1 = "Justin Bieber";
    Pregunta[75].O2 = "Julian Canias";
    Pregunta[75].O3 = "Zac Efron";
    Pregunta[75].OC = "Michael Jackson";

    Pregunta[76].Pregunta = "Con que se acompania el fernet?";
    Pregunta[76].O1 = "Ron";
    Pregunta[76].O2 = "Pepsi";
    Pregunta[76].O3 = "Fanta";
    Pregunta[76].OC = "Coca-cola";

    Pregunta[77].Pregunta = "Quien es el novio de la Rosalia?";
    Pregunta[77].O1 = "Eberle";
    Pregunta[77].O2 = "Palavecino";
    Pregunta[77].O3 = "Borja";
    Pregunta[77].OC = "Rauw alejandro";

    Pregunta[78].Pregunta = "Como sigue la frase \" y va el …\"?";
    Pregunta[78].O1 = "Cuarto";
    Pregunta[78].O2 = "Segundo";
    Pregunta[78].O3 = "Primero";
    Pregunta[78].OC = "Tercero";

    Pregunta[79].Pregunta = "Cual es el metodo anticonceptivo mas eficiente?";
    Pregunta[79].O1 = "Una bolsa de nylon";
    Pregunta[79].O2 = "Una bolsa del coto";
    Pregunta[79].O3 = "Una cartuchera";
    Pregunta[79].OC = "El preservativo";

    Pregunta[80].Pregunta = "Quien pinto \"La noche estrellada\"?";
    Pregunta[80].O1 = "Pablo Picasso";
    Pregunta[80].O2 = "Vicent Van Gogh";
    Pregunta[80].O3 = "Claude Monet";
    Pregunta[80].OC = "Salvador Dali";

    Pregunta[81].Pregunta = "Que artista es conocido por sus esculturas de caballos?";
    Pregunta[81].O1 = "Michelangelo";
    Pregunta[81].O2 = "Auguste Rodin";
    Pregunta[81].O3 = "Alexander Calder";
    Pregunta[81].OC = "Jeff Koons";

    Pregunta[82].Pregunta = "Quien escribio \"La Odisea\"?";
    Pregunta[82].O1 = "William Shakespeare";
    Pregunta[82].O2 = "Homer";
    Pregunta[82].O3 = "Dante Alighieri";
    Pregunta[82].OC = "Miguel de Cervantes";

    Pregunta[83].Pregunta = "Que artista es conocido por sus pinturas de latas de sopa?";
    Pregunta[83].O1 = "Jackson Pollock";
    Pregunta[83].O2 = "Andy Warhol";
    Pregunta[83].O3 = "Pablo Picasso";
    Pregunta[83].OC = "Frida Kahlo";

    Pregunta[84].Pregunta = "Quien compuso \"La Traviata\"?";
    Pregunta[84].O1 = "Wolfgang Amadeus Mozart";
    Pregunta[84].O2 = "Giuseppe Verdi";
    Pregunta[84].O3 = "Ludwig van Beethoven";
    Pregunta[84].OC = "Johann Sebastian Bach";

    Pregunta[85].Pregunta = "Que artista es conocido por sus pinturas de flores?";
    Pregunta[85].O1 = "Jackson Pollock";
    Pregunta[85].O2 = "Andy Warhol";
    Pregunta[85].O3 = "Pablo Picasso";
    Pregunta[85].OC = "Salvador Dali";

    Pregunta[86].Pregunta = "Quien escribio \"Romeo y Julieta\"?";
    Pregunta[86].O1 = "William Shakespeare";
    Pregunta[86].O2 = "Gabriel Garcia Marquez";
    Pregunta[86].O3 = "Ernest Hemingway";
    Pregunta[86].OC = "Miguel de Cervantes";

    Pregunta[87].Pregunta = "Que artista es conocido por sus pinturas de \"Campbell's Soup Cans\"?";
    Pregunta[87].O1 = "Jackson Pollock";
    Pregunta[87].O2 = "Andy Warhol";
    Pregunta[87].O3 = "Pablo Picasso";
    Pregunta[87].OC = "Frida Kahlo";

    Pregunta[88].Pregunta = "Quien compuso \"La Primavera\"?";
    Pregunta[88].O1 = "Wolfgang Amadeus Mozart";
    Pregunta[88].O2 = "Giuseppe Verdi";
    Pregunta[88].O3 = "Ludwig van Beethoven";
    Pregunta[88].OC = "Antonio Vivaldi";

    Pregunta[89].Pregunta = "Que artista es conocido por sus esculturas de \"La Victoria de Samotracia\"?";
    Pregunta[89].O1 = "Michelangelo";
    Pregunta[89].O2 = "Auguste Rodin";
    Pregunta[89].O3 = "Alexander Calder";
    Pregunta[89].OC = "Jeff Koons";

    Pregunta[90].Pregunta = "Quien escribio \"La Divina Comedia\"?";
    Pregunta[90].O1 = "William Shakespeare";
    Pregunta[90].O2 = "Homer";
    Pregunta[90].O3 = "Dante Alighieri";
    Pregunta[90].OC = "Miguel de Cervantes";

    Pregunta[91].Pregunta = "Que artista es conocido por sus pinturas de \"Las Senioritas de Avignon\"?";
    Pregunta[91].O1 = "Georgia O'Keeffe";
    Pregunta[91].O2 = "Vincent van Gogh";
    Pregunta[91].O3 = "Claude Monet";
    Pregunta[91].OC = "Pablo Picasso";

    Pregunta[92].Pregunta = "Quien compuso \"El Lago de los Cisnes\"?";
    Pregunta[92].O1 = "Wolfgang Amadeus Mozart";
    Pregunta[92].O2 = "Giuseppe Verdi";
    Pregunta[92].O3 = "Ludwig van Beethoven";
    Pregunta[92].OC = "Pyotr llyich Tchaikovsky";

    Pregunta[93].Pregunta = "Que artista es conocido por sus pinturas de \"La Noche\"?";
    Pregunta[93].O1 = "Jackson Pollock";
    Pregunta[93].O2 = "Vincent van Gogh";
    Pregunta[93].O3 = "Claude Monet";
    Pregunta[93].OC = "Edvard Munch";

    Pregunta[94].Pregunta = "Quien escribio \"Las Aventuras de Tom Sawyer\"?";
    Pregunta[94].O1 = "Antoine de Saint - Exupery";
    Pregunta[94].O2 = "Gabriel Garcia Marquez";
    Pregunta[94].O3 = "Ernest Hemingway";
    Pregunta[94].OC = "Mark Twain";

    Pregunta[95].Pregunta = "Que artista es conocido por sus esculturas de \"EI David\"?";
    Pregunta[95].O1 = "Michelangelo";
    Pregunta[95].O2 = "Auguste Rodin";
    Pregunta[95].O3 = "Alexander Calder";
    Pregunta[95].OC = "Jeff Koons";

    Pregunta[96].Pregunta = "Quien compuso \"La Novena Sinfonia\"?";
    Pregunta[96].O1 = "Wolfgang Amadeus Mozart";
    Pregunta[96].O2 = "Giuseppe Verdi";
    Pregunta[96].O3 = "Ludwig van Beethoven";
    Pregunta[96].OC = "Johann Sebastian Bach";

    Pregunta[97].Pregunta = "Que artista es conocido por sus pinturas de \"La Mona Lisa\"?";
    Pregunta[97].O1 = "Georgia O'Keeffe";
    Pregunta[97].O2 = "Vincent van Gogh";
    Pregunta[97].O3 = "Claude Monet";
    Pregunta[97].OC = "Leonardo da Vinci";

    Pregunta[98].Pregunta = "Quien pinto el cuadro \"El Jardin de las Delicias\"?";
    Pregunta[98].O1 = "Carvaggio";
    Pregunta[98].O2 = "Velazquez";
    Pregunta[98].O3 = "Arcimboldo";
    Pregunta[98].OC = "El Bosco";

    Pregunta[99].Pregunta = "Quien escribio \"El viejo y el mar\"?";
    Pregunta[99].O1 = "Truman Capote";
    Pregunta[99].O2 = "Norman Mailer";
    Pregunta[99].O3 = "Gabriel Garcia Marquez";
    Pregunta[99].OC = "Ernest Hemingway";

    Pregunta[100].Pregunta = "Que tipo de respiracion tiene un tiburon?";
    Pregunta[100].O1 = "Pulmonar";
    Pregunta[100].O2 = "Cutanea";
    Pregunta[100].O3 = "Traqueal";
    Pregunta[100].OC = "Branquial";

    Pregunta[101].Pregunta = "Cual de estos seres vivos es un aracnido?";
    Pregunta[101].O1 = "Escarabajo esmeralda";
    Pregunta[101].O2 = "Hormiga";
    Pregunta[101].O3 = "Mantis Religiosa";
    Pregunta[101].OC = "Escorpion";

    Pregunta[102].Pregunta = "Cual es el animal mas antiguo de la Tierra?";
    Pregunta[102].O1 = "Cangrejo Herradura";
    Pregunta[102].O2 = "Cucaracha";
    Pregunta[102].O3 = "Tiburon Elefante";
    Pregunta[102].OC = "Medusa";

    Pregunta[103].Pregunta = "Cual es la caracteristica exclusiva de los mamiferos?";
    Pregunta[103].O1 = "Son los unicos que se reproducen sexualmente";
    Pregunta[103].O2 = "Tienen pelo";
    Pregunta[103].O3 = "No ponen huevos";
    Pregunta[103].OC = "Producen leche";

    Pregunta[104].Pregunta = "Cuanto es (30x233) / (14 - (7x2))?";
    Pregunta[104].O1 = "1";
    Pregunta[104].O2 = "352";
    Pregunta[104].O3 = "0";
    Pregunta[104].OC = "Tiende a infinito";

    Pregunta[105].Pregunta = "Cual de las siguientes es una funcion cuadratica?";
    Pregunta[105].O1 = "m = f x d";
    Pregunta[105].O2 = "x = b / (a-1)";
    Pregunta[105].O3 = "b - axc - 4xaxc";
    Pregunta[105].OC = "Ninguna de las anteriores";

    Pregunta[106].Pregunta = "Cuantos sistemas tiene un humano (EJ: Circulatorio)?";
    Pregunta[106].O1 = "2";
    Pregunta[106].O2 = "3";
    Pregunta[106].O3 = "5";
    Pregunta[106].OC = "8";

    Pregunta[107].Pregunta = "Cuantos Kb hay en un Mb?";
    Pregunta[107].O1 = "512";
    Pregunta[107].O2 = "1000";
    Pregunta[107].O3 = "Ninguno";
    Pregunta[107].OC = "1024";

    Pregunta[108].Pregunta = "Que representa la C en la tabla periodica?";
    Pregunta[108].O1 = "Potasio";
    Pregunta[108].O2 = "Cobalto";
    Pregunta[108].O3 = "Cromo";
    Pregunta[108].OC = "Carbono";

    Pregunta[109].Pregunta = "Que significa ADN?";
    Pregunta[109].O1 = "Acido ribonucleico";
    Pregunta[109].O2 = "Alternativa deusnumerica";
    Pregunta[109].O3 = "Amonitrato desnitrogenado natural";
    Pregunta[109].OC = "Acido desoxirribonucleico";

    Pregunta[110].Pregunta = "De que esta formado el hormigon ademas del cemento?";
    Pregunta[110].O1 = "Grava";
    Pregunta[110].O2 = "Agua";
    Pregunta[110].O3 = "Arena";
    Pregunta[110].OC = "Todas son correctas";

    Pregunta[111].Pregunta = "Cual es el valor de la aceleracion gravitatoria de la Tierra?";
    Pregunta[111].O1 = "1 N";
    Pregunta[111].O2 = "9,8 K/s";
    Pregunta[111].O3 = "10 N";
    Pregunta[111].OC = "9,8 m/s^2";

    Pregunta[112].Pregunta = "Cual es la ciencia que estudia a los cuerpos celestes?";
    Pregunta[112].O1 = "Astrologia";
    Pregunta[112].O2 = "Cosmologia";
    Pregunta[112].O3 = "Corpologia";
    Pregunta[112].OC = "Astronomia";

    Pregunta[113].Pregunta = "Cual de estas afirmaciones es falsa?";
    Pregunta[113].O1 = "Los reptiles no tienen pelo";
    Pregunta[113].O2 = "El cuerpo humano esta compuesto un 60% por agua";
    Pregunta[113].O3 = "Las unias no son huesos";
    Pregunta[113].OC = "Papa Noel existe";

    Pregunta[114].Pregunta = "Cuales son las pulsaciones por minuto de una persona saludable en reposo";
    Pregunta[114].O1 = "30-70 bpm";
    Pregunta[114].O2 = "130-180 bpm";
    Pregunta[114].O3 = "100-130 bpm";
    Pregunta[114].OC = "60-100 bpm";

    Pregunta[115].Pregunta = "Cual es el gas mas abundante en la atmosfera de la tierra?";
    Pregunta[115].O1 = "Propano";
    Pregunta[115].O2 = "Vapor";
    Pregunta[115].O3 = "Metano";
    Pregunta[115].OC = "Nitrogeno";

    Pregunta[116].Pregunta = "Cual es el animal mas grande terrestre?";
    Pregunta[116].O1 = "Girafa Borja";
    Pregunta[116].O2 = "Yak";
    Pregunta[116].O3 = "Ballena Azul";
    Pregunta[116].OC = "Elefante africano";

    Pregunta[117].Pregunta = "Cual es el punto de ebullicion del agua?";
    Pregunta[117].O1 = "130 C";
    Pregunta[117].O2 = "90 C";
    Pregunta[117].O3 = "180 C";
    Pregunta[117].OC = "100 C";

    Pregunta[118].Pregunta = "Cual es la galaxia espiral mas cercana a la Via Lactea?";
    Pregunta[118].O1 = "Hemingway";
    Pregunta[118].O2 = "No existe una galaxia espiral";
    Pregunta[118].O3 = "Nebulosa";
    Pregunta[118].OC = "Andromeda";

    Pregunta[119].Pregunta = "Cual es el metal que se encuentra en el centro de la Tierra?";
    Pregunta[119].O1 = "Platino";
    Pregunta[119].O2 = "Oro";
    Pregunta[119].O3 = "Plata";
    Pregunta[119].OC = "Hierro";
}

void Introduccion()
{
    cout << "En este desafio tendran que acertar 6 de 10 preguntas\n\n";
    cout << "Tienen 10 segundos para responder o la respuesta no sera valida\n\n";
    cout << "Para que la respuesta sea valida, se debera ingresar el numero que corresponde a la opcion correcta\n\n";
    cout << "Este preguntados esta lleno de errores de ortografia debido a que no podemos mostrar caracteres especiales como las palabras con tildes\n\n";
    system("pause");
    system("cls");
}

void Ruleta()
{
    int Random = rand() % 7, NUM;
    switch (Random)
    {
    case 0:
        do {
            NUM = rand() % 20;
        } while (Pregunta[NUM].Contador);
        break;
    case 1:
        do{
            NUM = (rand() % 20) + 20;
        } while (Pregunta[NUM].Contador);
        break;
    case 2:
        do{
            NUM = (rand() % 20) + 40;
        } while (Pregunta[NUM].Contador);
        break;
    case 3:
        do{
            NUM = (rand() % 20) + 60;
        } while (Pregunta[NUM].Contador);
        break;
    case 4:
        do{
            NUM = (rand() % 20) + 80;
        } while (Pregunta[NUM].Contador);
        break;
    case 5:
        do{
            NUM = (rand() % 20) + 100;
        } while (Pregunta[NUM].Contador);
        break;
    case 6:
        do {
            cout << "\nIngrese el tipo de la pregunta que queres responder:\n\n";
            cout << "1. Deportes\n";
            cout << "2. Historia\n";
            cout << "3. Geografia\n";
            cout << "4. Entretenimiento\n";
            cout << "5. Arte\n";
            cout << "6. Ciencia\n\n";
            NUM = charToInt(_getch());
            system("cls");
        } while (NUM < 1 || NUM > 6);
        NUM--;
        switch (NUM)
        {
        case 0:
            do {
                NUM = rand() % 20;
            } while (Pregunta[NUM].Contador);
            break;
        case 1:
            do {
                NUM = (rand() % 20) + 20;
            } while (Pregunta[NUM].Contador);
            break;
        case 2:
            do {
                NUM = (rand() % 20) + 40;
            } while (Pregunta[NUM].Contador);
            break;
        case 3:
            do {
                NUM = (rand() % 20) + 60;
            } while (Pregunta[NUM].Contador);
            break;
        case 4:
            do {
                NUM = (rand() % 20) + 80;
            } while (Pregunta[NUM].Contador);
            break;
        case 5:
            do {
                NUM = (rand() % 20) + 100;
            } while (Pregunta[NUM].Contador);
            break;
        }
        break;
    }
    Pregunta[NUM].Contador = true;
    int num[4] = { 0,0,0,0 };
    int OC;
    cout << Pregunta[NUM].Pregunta << "\n\n";

    num[0] = (rand() % 4) + 1;

    do
    {
        num[1] = (rand() % 4) + 1;
    } while (num[1] == num[0]);

    do
    {
        num[2] = (rand() % 4) + 1;
    } while (num[2] == num[0] || num[2] == num[1]);

    do
    {
        num[3] = (rand() % 4) + 1;
    } while (num[3] == num[0] || num[3] == num[1] || num[3] == num[2]);



    for (int i = 1; i < 5; i++) {
        switch (num[i - 1])
        {
        case 1:
            cout << i << ". " << Pregunta[NUM].O1 << endl;
            break;
        case 2:
            cout << i << ". " << Pregunta[NUM].O2 << endl;
            break;
        case 3:
            cout << i << ". " << Pregunta[NUM].O3 << endl;
            break;
        case 4:
            cout << i << ". " << Pregunta[NUM].OC << endl;
            OC = i;
            break;
        }
    }
    clock_t t;
    t = clock();
    int rta;
    do {
        rta = charToInt(_getch());
    } while (rta < 1 || rta > 4);
    t = clock() - t;
    if (rta == OC && float(t) / CLOCKS_PER_SEC <= 10.00)
    {
        Respuestas_Correctas++;
        cout << "\n\nAcertaste\n";
    }
    else if (rta == OC)
    {
        cout << "\n\nAcertaste pero tardaste mas de 10 segundos (";
        cout << fixed << setprecision(2) << float(t) / CLOCKS_PER_SEC;
        cout << "s), la respuesta no sera valida\n";
    }
    else
    {
        cout << "\n\nFallaste\nLa respuesta correcta era: " << Pregunta[NUM].OC << "\n";
    }
    cout << endl;
    system("pause");
}

int main()
{
    srand(time(NULL));
    system("cls");
    int contador = 0;
    do
    {
        Sleep(1000);
        contador++;
        if (contador != 1)
        {
            cout << "No logreste acertar al menos 6 de 10 preguntas\n\n";
            cout << "No te preocupes, tenes intentos ilimitados\n\n";
            system("pause");
            system("cls");
            setFalse();
        }
        else {
            Iniciar_programa();
            Introduccion();
        }
        Respuestas_Correctas = 0;
        for (int i = 0; i < 10; i++)
        {
            Ruleta();
            system("cls");
        }
        system("cls");
    } while (Respuestas_Correctas < 6);
    cout << "Lograste completar el preguntados\n\n" << "Codigo: " << CODIGO << endl;
    return 0;
}
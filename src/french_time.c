#include "french_time.h"

static const char* STR_HEURE = "heure";
static const char* STR_H = " h.";
static const char* STR_MOINS = "moins";

static const char* const HEURES[] = {
  "minuit",
  "une",
  "deux",
  "trois",
  "quatre",
  "cinq",
  "six",
  "sept",
  "huit",
  "neuf",
  "dix",
  "onze",
  "midi"
};

static const char* const MINS[] = {
  "pile",
  "cinq",
  "dix",
  "et quart",
  "vingt",
  "et demi",
  "le quart",
  "..."
};

static const char* const JOURS[] = {
  "dimanche",
  "lundi",
  "mardi",
  "mercredi",
  "jeudi",
  "vendredi",
  "samedi"
};

static const char* const MOIS[] = {
  "jan.",
  "fév.",
  "mars",
  "avril",
  "mai",
  "juin",
  "juil.",
  "août",
  "sep.",
  "oct.",
  "nov.",
  "déc."
};

static const char* const JOUR_MOIS[] = {
  "premier",
  "deux",
  "trois",
  "quatre",
  "cinq",
  "six",
  "sept",
  "huit",
  "neuf",
  "dix",
  "onze",
  "douze",
  "treize",
  "quatorze",
  "quinze",
  "seize",
  "dix-sept",
  "dix-huit",
  "dix-neuf",
  "vingt",
  "vingt et un",
  "vingt-deux",
  "vingt-trois",
  "vingt-quatre",
  "vingt-cinq",
  "vingt-six",
  "vingt-sept",
  "vingt-huit",
  "vingt-neuf",
  "trente",
  "trente et un"
};



int fuzzy_time(char* line1, char* line2, char* line3, char* line4, struct tm * t) {

	int hours = t->tm_hour;
	int minutes = t->tm_min;
	int nbLine = 3;
	strncpy(line1, "",LINE_BUFFER_SIZE -1);
	strncpy(line2, "",LINE_BUFFER_SIZE -1);
	strncpy(line3, "",LINE_BUFFER_SIZE -1);
	strncpy(line4, "",LINE_BUFFER_SIZE -1);	
	
  if (minutes >= 33) hours++;
  if (hours >= 24) hours = 0;
  if (hours > 12) hours -= 12;

  strcat(line1, HEURES[hours]); // l'HEURE

  if (minutes >= 0 && minutes < 3) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      if (minutes == 0) strcat(line3, MINS[0]); // pile
    }
    else {
      if (minutes == 0) strcat(line2, MINS[0]); // pile
    }
  }
  else if (minutes < 8) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[1]); // cinq
    }
    else {
      strcat(line2, MINS[1]); // cinq
    }
  }
  else if (minutes < 13) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[2]); // dix
    }
    else {
      strcat(line2, MINS[2]); // dix
    }
  }
  else if (minutes < 18) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[3]); // et quart
    }
    else {
      strcat(line2, MINS[3]); // et quart
    }
  }
  else if (minutes < 23) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[4]); // vingt
    }
    else {
      strcat(line2, MINS[4]); // vingt
    }
  }
  else if (minutes < 28) {
    if(hours > 0 && hours < 12) {
      strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[4]); // vingt
      strcat(line4, MINS[1]); // cinq
    }
    else {
      strcat(line2, MINS[4]); // vingt
      strcat(line3, MINS[1]); // cinq
    }
  }
  else if (minutes < 33) {
    if(hours > 0 && hours < 12) {
        strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, MINS[5]); // et demi
    }
    else {
      strcat(line2, MINS[5]); // et demi
    }
  }
  else if (minutes < 38) {
    if(hours > 0 && hours < 12) strcat(line1, STR_H);
    strcat(line2, STR_MOINS); // moins
    strcat(line3, MINS[4]); // vingt
    strcat(line4, MINS[1]); // cinq
  }
  else if (minutes < 43) {
    if(hours > 0 && hours < 12) {
      strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, STR_MOINS);
      strcat(line4, MINS[4]); // vingt
    }
    else {
      strcat(line2, STR_MOINS);
      strcat(line3, MINS[4]); // vingt
    }
  }
  else if (minutes < 48) {
    if(hours > 0 && hours < 12) {
      strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, STR_MOINS);
      strcat(line4, MINS[6]); // le quart
    }
    else {
      strcat(line2, STR_MOINS);
      strcat(line3, MINS[6]); // le quart
    }
  }
  else if (minutes < 53) {
    if(hours > 0 && hours < 12) {
      strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, STR_MOINS);
      strcat(line4, MINS[2]); // dix
    }
    else {
      strcat(line2, STR_MOINS);
      strcat(line3, MINS[2]); // dix
    }
  }
  else if (minutes < 58) {
    if(hours > 0 && hours < 12) {
      strcat(line2, STR_HEURE);
      if (hours > 1) strcat(line2, "s");
      strcat(line3, STR_MOINS);
      strcat(line4, MINS[1]); // cinq
    }
    else {
      strcat(line2, STR_MOINS);
      strcat(line3, MINS[1]); // cinq
    }
  }
  else if (minutes >= 58) {
    strcpy(line1, MINS[7]); // presque
    strcat(line2, HEURES[hours]);
    if(hours > 0 && hours < 12) {
        strcat(line3, STR_HEURE);
      if (hours > 1) strcat(line3, "s");
    }
  }
  return 4;
}

void info_lines(char* line1,struct tm * t) {
	
	char wday[LINE_BUFFER_SIZE];
	char mday[LINE_BUFFER_SIZE];
	char mon[LINE_BUFFER_SIZE];
	strncpy(line1, "",LINE_BUFFER_SIZE -1);
	snprintf(wday, LINE_BUFFER_SIZE, "%s", JOURS[t->tm_wday]);
	snprintf(mday, LINE_BUFFER_SIZE, "%d", t->tm_mday);
	snprintf(mon, LINE_BUFFER_SIZE, "%s", MOIS[t->tm_mon]);
	strcat(line1, wday);
	strcat(line1, " ");
	strcat(line1, mday);
	strcat(line1, " ");
	strcat(line1, mon);


}

void majMinute(char * str, struct tm * t){
	//str[0] = 'a';
	//strcpy(str, "a");
	snprintf(str, 3, "%d", t->tm_min);
}

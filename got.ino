const int buzzer = 9;

typedef struct
{
    char note;
    int eighth;
    int duration;
} Note;

typedef struct
{
    int size_notes;
    Note *notes;
} Music;

Music m;

void note(int oitava, char nota);

void playMusic(Music m);

void setup()
{
    int eighth = 4;
    m.size_notes = 75;
    m.notes = (Note *)malloc(m.size_notes * sizeof(Note));

    m.notes[0] = m.notes[20] = m.notes[40] = (Note){'E', eighth, 750};
    m.notes[1] = m.notes[21] = m.notes[41] = (Note){'A', eighth, 750};
    m.notes[2] = m.notes[22] = m.notes[42] = (Note){'C', eighth, 250};
    m.notes[3] = m.notes[23] = m.notes[43] = (Note){'D', eighth, 250};
    m.notes[4] = m.notes[24] = m.notes[44] = (Note){'E', eighth, 500};
    m.notes[5] = m.notes[25] = m.notes[45] = (Note){'A', eighth, 500};
    m.notes[6] = m.notes[26] = m.notes[46] = (Note){'C', eighth, 250};
    m.notes[7] = m.notes[27] = m.notes[47] = (Note){'D', eighth, 250};
    m.notes[8] = m.notes[28] = m.notes[48] = (Note){'B', eighth, 3000};

    m.notes[9] = m.notes[29] = m.notes[49] = (Note){'0', eighth, 500};

    m.notes[10] = m.notes[30] = (Note){'D', eighth, 750};
    m.notes[11] = m.notes[31] = (Note){'G', eighth, 750};
    m.notes[12] = m.notes[32] = (Note){'C', eighth, 250};
    m.notes[13] = m.notes[33] = (Note){'B', eighth, 250};
    m.notes[14] = m.notes[34] = (Note){'D', eighth, 500};
    m.notes[15] = m.notes[35] = (Note){'G', eighth, 750};
    m.notes[16] = m.notes[36] = (Note){'C', eighth, 250};
    m.notes[17] = m.notes[37] = (Note){'B', eighth, 250};
    m.notes[18] = m.notes[38] = (Note){'A', eighth, 2750};

    m.notes[19] = m.notes[39] = (Note){'0', eighth, 500};

    m.notes[50] = (Note){'D', eighth, 750};
    m.notes[51] = (Note){'G', eighth, 750};
    m.notes[52] = (Note){'B', eighth, 500};
    m.notes[53] = (Note){'C', eighth, 250};
    m.notes[54] = (Note){'B', eighth, 500};
    m.notes[55] = (Note){'G', eighth, 250};
    m.notes[56] = (Note){'A', eighth, 3000};

    m.notes[57] = (Note){'0', eighth, 500};

    m.notes[58] = m.notes[67] = (Note){'A', eighth, 1500};
    m.notes[59] = m.notes[68] = (Note){'G', eighth, 1500};
    m.notes[60] = m.notes[69] = (Note){'F', eighth, 1500};
    m.notes[61] = m.notes[70] = (Note){'E', eighth, 1500};
    m.notes[62] = m.notes[71] = (Note){'A', eighth, 1500};
    m.notes[63] = m.notes[72] = (Note){'C', eighth, 750};
    m.notes[64] = m.notes[73] = (Note){'B', eighth, 750};
    m.notes[65] = (Note){'A', eighth, 3000};

    m.notes[66] = (Note){'0', eighth, 500};

    m.notes[74] = (Note){'A', eighth, 3250};

    pinMode(buzzer, OUTPUT);
}

void loop()
{
    delay(5000);
    playMusic(m);
}

void playMusic(Music m)
{
    int i;
    for (i = 0; i < m.size_notes; i++)
    {
        note(m.notes[i].eighth, m.notes[i].note);
        delay(m.notes[i].duration);
        noTone(buzzer);
    }
}

void note(int oitava, char nota)
{
    double freq, base;

    switch (nota)
    {
    case 'C':
        base = 33;
        break;
    case 'D':
        base = 37.026;
        break;
    case 'E':
        base = 41.58;
        break;
    case 'F':
        base = 44.055;
        break;
    case 'G':
        base = 49.434;
        break;
    case 'A':
        base = 55.506;
        break;
    case 'B':
        base = 62.304;
        break;
    default:
        noTone(buzzer);
        return;
    }
    freq = base * ((float)pow(2, oitava));

    tone(buzzer, freq);
}
